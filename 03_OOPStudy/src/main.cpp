#include <array>
#include <memory>
#include <vector>
#include <iostream>

#include "Objects.h"

/**
 * スタックメモリ
 *   関数呼び出しでヒープは自動確保、自動開放する
 *   高速だが、サイズが小さい
 *   スコープ外は利用できない
 *   管理はコンパイラ任せ
 * ヒープメモリ
 *   コード内で明示的に確保、解放
 *   サイズが大きい
 *   deleteを忘れるとメモリリークにつながる
 *   deleteを2回すると、未定義動作になる
 *   所有権に気を付ける
 */
void memory()
{
    int x = 10; // Stack

    int *y = new int(20); // Heap <- ポインタは大体これになるらしい クラスインスタンスはスタックに配置することがほとんど
    delete y;             // Free heap
} // Free stack

void pointer_reference()
{
    // *ポインタは場所を扱うイメージ
    int x = 10;      // xはメモリ内のアドレスを保持し、アクセス時にメモリ内のアドレスを見に行き、値を自動で取得する
    std::cout << &x; // アドレス参照：変数などのアドレスIDを参照する

    int *y = &x;     // ポインタ：アドレスを格納する変数 変数ｙはアドレスｘでデータ型はint
    std::cout << y;  // アドレス参照
    std::cout << *y; // 関節参照：デリファレンスで、yにアクセスしたときに、xを参照しに行く また、これを使ってxを変更できる

    int *z = nullptr; // 初期化時にまだどこも指し示すことができない時に利用できる
    pointer_parmeter(z);
    z = &x;
    pointer_parmeter(z);
}
void pointer_parmeter(int *z)
{
    std::cout << *z;
}

void pointer_array()
{
    int a[3] = {10, 20, 30}; // aは&a[0]（配列a[3]の0番目のアドレス）を表す

    std::cout << *(a);     // 値の取得（0番目）
    std::cout << *(a + 1); // 値の取得（1番目） <- + 1すると、sizeof(TYPE)分先のバイトを読む
    std::cout << *(a + 2);

    char str[] = "hello"; // 末尾に'\0'が含まれているため、長さ6
    char *str_p = str;    // ここで代入されるのは、先頭のアドレス
    *str_p = 'H';
    *(str_p + 1) = 'o'; // このようにしか変更できない <- つまり、 str = "Hi"ができない

    int *a = new int[3]{1, 2, 3}; // ヒープで配列を準備するときはdelete[]を忘れない
    delete[] a;

    std::array<int, 3> array_int = {1, 2, 3}; // 固定長の配列ならこれを
    std::vector<int> vector_int = {1, 2, 3};  // 可変長の配列ならこれを使うことで上のポインター周りを簡潔にできる
    std::string text = "Hello";               // 大体の場合文字列はこれでもいい
}
void func_with_array(int a[], int size) // <- サイズ情報は配列の先頭のポインタを渡されるので、失われる
{
    //
}

void reference()
{
    int origin = 10;
    int &ref = origin; // <- 中身はorigin
    ref = 20;
    std::cout << origin; // <- 20

    ref_in_parameter(origin);
    std::cout << origin; // <- 30

    const_ref_in_parameter(origin); // <- 30と表示される
}
void ref_in_parameter(int &x)
{
    x = 30; // ↑の関数originが書き換わる
}
void const_ref_in_parameter(const int &x) // <- 書き換え不可の引数
{
    // x = 40; // <- エラーになる
    std::cout << x;
}

/**
 * ユニークポインター
 *   - コピー不可
 *   - ムーブ（別アドレスへの移動）可能
 *   - 所有権が明確
 * シェアドポインター
 *   - 最後の1つが破棄されたときにdeleteされる
 */
void unique_pointer()
{
    auto x = std::make_unique<int>(10); // スコープ寿命のポインターを作成 デストラクタでdeleteされる
    auto y = std::make_shared<int>(20); // 共有所有可能なポインターを作成 最後の参照が破棄されたら解放される
    auto y2 = y;
    // ここでyがdelete
} // ここでxがdelete

/**
 * 構造体とクラスはデフォルトの公開範囲以外は同じ
 */
void objects()
{
    // 構造体の配置
    // スタック                // with 初期化コンストラクタ
    OOPStudy::SampleStruct ss(10, 20.0f); // 近くのメモリに配置される ss | VAR1 | VAR2 みたいな感じ
    // ヒープ
    auto ssp = std::make_unique<OOPStudy::SampleStruct>(); // onstack ssp -> onheap: ssp | VAR1 | VAR2...

    // 構造体のアクセス
    std::cout << ss.a;   // 実体へのアクセス
    std::cout << ssp->a; // ポインタへのアクセス

    // クラスの配置
    // スタック                // with 初期化コンストラクタ
    OOPStudy::SampleClass sc(10, 20.0f);
    // ヒープ
    auto scp = std::make_unique<OOPStudy::SampleClass>();

    // クラスのアクセス
    std::cout << sc.get_a();
    std::cout << scp->get_a();
}

int main(int, char **)
{
    std::cout << "Hello, from OOPStudy!\n";
}
