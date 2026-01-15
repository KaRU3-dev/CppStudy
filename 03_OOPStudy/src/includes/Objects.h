#include <cstdint>

namespace OOPStudy
{
    /**
     * 構造体
     *   デフォルトアクセスと継承がpublic
     */
    struct SampleStruct
    {
        std::int32_t a;
        float b;

        SampleStruct(std::int32_t a, float b) : a(a), b(b) {}
        SampleStruct() = default; // デフォルトコンストラクタ
    };

    /**
     * クラス
     *   デフォルトアクセスと継承がprivate
     */
    class SampleClass
    {
    private:
        std::int32_t a;
        float b;

    public:
        SampleClass(std::int32_t a, float b) : a(a), b(b) {}
        SampleClass() = default; // デフォルトコンストラクタ

        void set_a(std::int32_t a) { this->a = a; }
        std::int32_t get_a() { return this->a; }

        void set_b(float b) { this->b = b; }
        float get_b() { return this->b; }

        SampleClass get_instance() { return *this; }
    };
}
