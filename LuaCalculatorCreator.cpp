#include <iostream>
#include <fstream>
#include <string>

int main() {
    const char* operations[5] = {"add", "subtract", "multiply", "divide", "power"};
    int numbers;

    std::cout << "How many numbers do you want?\n";
    std::cin >> numbers;

    std::string calculatorScript = "local function calculate(x, y, operation)";

    for (int x = 1; x <= numbers; x++) {
        calculatorScript += "\n\tif (x == " + std::to_string(x) + ") then\n";

        for (int operationAmount = 0; operationAmount <= 4; operationAmount++) {
            const char* stringOperation = operations[operationAmount];
            char operation;

            switch (operationAmount) {
                case 0: operation = '+'; break;
                case 1: operation = '-'; break;
                case 2: operation = '*'; break;
                case 3: operation = '/'; break;
                case 4: operation = '^'; break;
            }

            for (int y = 1; y <= numbers; y++) {
                std::string equation = std::to_string(x) + " " + operation + " " + std::to_string(y);
                calculatorScript += "\t\tif (y == " + std::to_string(y) + ") then\n\t\t\tif (operation == \"" + stringOperation + "\") then\n\t\t\t\treturn " + equation + "\n\t\t\tend\n\t\tend\n";
            };
        };

        calculatorScript += "\tend\n";
    };

    calculatorScript += "end";

    // write file

    std::ofstream calculatorFile("calculator.lua");

    calculatorFile << calculatorScript;
    calculatorFile.close();

    return 0;
}