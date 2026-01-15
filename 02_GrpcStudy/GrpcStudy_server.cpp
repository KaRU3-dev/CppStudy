#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"

#include "logger.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;

// Greeter::Serviceを継承してロジックを実装
class GreeterServiceImpl final : public Greeter::Service
{
    Status SayHello(ServerContext *context, const HelloRequest *request,
                    HelloReply *reply) override
    {
        logger::Log("SayHello called");

        std::string prefix("Hello ");
        reply->set_message(prefix + request->name());

        logger::Log("SayHello response has been written");
        return Status::OK;
    }

    Status SayHelloStreamReply(ServerContext *context, const HelloRequest *request,
                               ServerWriter<HelloReply> *writer) override
    {
        logger::Log("SayHelloStreamReply called sending request....");

        std::string prefix("Hello ");

        for (int i = 0; i < 10; i++)
        {
            HelloReply reply;
            reply.set_message(prefix + request->name());
            writer->Write(reply);

            logger::Log("Index" + std::to_string(i) + " sent");
        }
        return Status::OK;
    }

    Status SayHelloBidiStream(ServerContext *context,
                              ServerReaderWriter<HelloReply, HelloRequest> *stream) override
    {
        logger::Log("SayHelloBidiStream called reading and writing request...");

        std::string prefix("Hello ");
        HelloRequest request;
        HelloReply reply;
        while (stream->Read(&request))
        {
            logger::Log("Request received");

            reply.set_message(prefix + request.name());
            stream->Write(reply);

            logger::Log("Reply sent");
        }

        logger::Log("Stream closed");
        return Status::OK;
    }
};

void RunServer()
{
    std::string server_address("0.0.0.0:50051");
    GreeterServiceImpl service;

    ServerBuilder builder;
    // 認証なしでポートをリッスン
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // サービスを登録
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    logger::Log("Server listening on " + server_address);
    server->Wait();
}

int main()
{
    logger::Log("Starting server...");

    RunServer();

    logger::Log("Server stopped");
    return 0;
}
