#include <iostream>

// 大域変数
int num1, num2;

// 関数定義
void initializeGame(int a, int b) {
    num1 = a;
    num2 = b;
    return;
}

int add(int a, int b) {
    return a+b;
}

int subtract(int a, int b) {
    return a-b;
}

int multiply(int a, int b) {
    return a*b;
}

double divide(double a, int b) {
    if (b == 0) {
        std::cerr << "Division by zero is undefined!" << "\n";
        return 0;
    }
    return a/b;
}

void playGame() {
    int choice;
    bool quit{ false };
    const int maxInvalidAttempts{ 3 }; // 無効な試み(入力)の最大回数(3回)
    int invalidAttempts{ 0 }; // 無効な試み(入力)

    while (!quit) {
        std::cout << "1) Add 2) Subtract 3) Multiply 4) Divide 5) Quit: ";
        std::cin >> choice;

        int val_i;
        double val_d;
        switch ( choice ) {
        case 1:
            val_i = add(num1, num2);
            std::cout << "Result: " << num1 << " + " << num2 << " = " << val_i << "\n";
            invalidAttempts = 0; // 有効な入力の場合，invalidAttempts をリセット
            break;
        case 2:
            val_i = subtract(num1, num2);
            std::cout << "Result: " << num1 << " - " << num2 << " = " << val_i << "\n";
            invalidAttempts = 0; // 有効な入力の場合，invalidAttempts をリセット
            break;
        case 3:
            val_i = multiply(num1, num2);
            std::cout << "Result: " << num1 << " * " << num2 << " = " << val_i << "\n";
            invalidAttempts = 0; // 有効な入力の場合，invalidAttempts をリセット
            break;
        case 4:
            val_d = divide(num1, num2);
            std::cout << "Result: " << num1 << " / " << num2 << " = " << val_d << "\n";
            invalidAttempts = 0; // 有効な入力の場合，invalidAttempts をリセット
            break;
        case 5:
            std::cout << "Finished.\n";
            quit=true;
            break;
        default:
            invalidAttempts++; // 無効な試み(入力)を1回増やす
            if ( invalidAttempts==3 ) { // 無効な試み(入力)が3回になったらゲーム終了
                std::cout << "Too many invalid attempts. Game over!" << "\n";
                quit = true;
            }
            else {
                std::cout << "Invalid choice. Try again." << "\n";
            }
        }
    }
    return;
}

int main(int argc, char* argv[]) {
    if (argc != 3) { // 2つの数値でなければ(コマンドが3つでなければ)即時に終了
        std::cout << "Usage: " << argv[0] << " <num1> <num2>" << "\n";
        return 1;
    }

    int a{ std::stoi(argv[1]) }; // コマンド2つめを a に格納
    int b{ std::stoi(argv[2]) }; // コマンド3つめを b に格納

    initializeGame(a, b); // a, b で num1, num2 を初期化
    playGame();

    return 0;
}