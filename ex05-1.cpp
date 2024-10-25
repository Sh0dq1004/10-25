#include <iostream>
#include <vector>

// (1) 引数あり，戻り値ありの関数 multiply
int multiply(int a,int b){
    return a*b;
}

// (2) 引数あり，戻り値なしの関数 printVector
void printVector(const std::vector<int>& vec) {
    for (int i:vec) std::cout << i << " ";
    std::cout << "\n";
    return;
}

// (3) 引数なし，戻り値ありの関数 getCurrentYear
int getCurrentYear() {
    return 2024;
}

// (4) 引数なし，戻り値なしの関数 printHelloWorld
void printHelloWorld(){
    std::cout<<"Hello, World!\n";
}

// (5) ベクトル（vector）の内積を計算する関数 innerProduct
int innerProduct(const std::vector<int>& vec1, const std::vector<int>& vec2){
    int sum{0};
    for (int i=0; i < vec1.size(); i++){
        sum+=vec1[i]*vec2[i];
    }
    return sum;
}

int main() {
    // (1) 引数あり，戻り値ありの関数 multiply の呼び出し
    // 関数 multiply の戻り値で，変数 mul_val を初期しなさい
    int x{ 3 }, y{ 4 };
    int mul_val{multiply(x,y)};
    std::cout << "Produce of x and y: " << mul_val << "\n";

    // (2) 引数あり，戻り値なしの関数 printVector の呼び出し
    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    // vec を関数 printVector で呼び出す
    printVector(vec);

    // (3) 引数なし，戻り値ありの関数 getCurrentYear の呼び出し
    // 関数 getCurrentYear の戻り値で，変数 year を初期化しなさい
    int year{ getCurrentYear() };
    std::cout << "Current year: " << year << "\n";

    // (4) 引数なし，戻り値なしの関数 printHelloWorld の呼び出し
    printHelloWorld();

    // (5) ベクトル（vector）の内積を計算する関数 innerProduct の呼び出し
    // 関数 innerProduct の戻り値で，変数 ip_val を初期化しなさい
    std::vector<int> vec1{ 2, 2, 2, 2, 2 };
    std::vector<int> vec2{ 2, 4, 6, 8, 10 };
    int ip_val{ innerProduct(vec1,vec2) };
    std::cout << "Inner product of vec1 and vec2: " << ip_val << "\n";

    return 0;
}