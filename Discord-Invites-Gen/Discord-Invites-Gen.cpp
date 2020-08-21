#include <iostream>
#include <fstream>
#include <Windows.h>
#include <random>

void color(int textcolorf, int textcolord)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, textcolord * 16 + textcolorf);
}

static std::string rdmstr() {
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; std::random_device rdm; std::mt19937 e(rdm()); std::uniform_int_distribution<> dist(0, chars.size() - 1); std::string result = "";
    for (int i = 0; i < 6; i++) {
        result += chars[dist(e)];
    }
    return result;
}

int main()
{
    color(3, 0);
    std::cout << R"(
$$$$$$\                     $$\   $$\                                $$$$$$\                      
\_$$  _|                    \__|  $$ |                              $$  __$$\                     
  $$ |  $$$$$$$\ $$\    $$\ $$\ $$$$$$\    $$$$$$\   $$$$$$$\       $$ /  \__| $$$$$$\  $$$$$$$\  
  $$ |  $$  __$$\\$$\  $$  |$$ |\_$$  _|  $$  __$$\ $$  _____|      $$ |$$$$\ $$  __$$\ $$  __$$\ 
  $$ |  $$ |  $$ |\$$\$$  / $$ |  $$ |    $$$$$$$$ |\$$$$$$\        $$ |\_$$ |$$$$$$$$ |$$ |  $$ |
  $$ |  $$ |  $$ | \$$$  /  $$ |  $$ |$$\ $$   ____| \____$$\       $$ |  $$ |$$   ____|$$ |  $$ |
$$$$$$\ $$ |  $$ |  \$  /   $$ |  \$$$$  |\$$$$$$$\ $$$$$$$  |      \$$$$$$  |\$$$$$$$\ $$ |  $$ |
\______|\__|  \__|   \_/    \__|   \____/  \_______|\_______/        \______/  \_______|\__|  \__|
)" << std::endl;

    color(12, 0);
    std::cout << "How many invites you want(0 = infinite number): ";
    int choice;
    color(2, 0);
    std::cin >> choice;
    std::ofstream MyWriteFile("invites.txt");
    color(3, 0);
    if (choice != 0) {

        for (int i = 1; i <= choice; ++i)
        {
            std::string a = "https://discord.gg/" + rdmstr();
            std::cout << a << std::endl;
            MyWriteFile << a << std::endl;
        }
        MyWriteFile.close();
    } else {
        while (true) {
            std::string a = "https://discord.gg/" + rdmstr();
            std::cout << a << std::endl;
            MyWriteFile << a << std::endl;
        }
    }
    system("pause");
    return 0;
}