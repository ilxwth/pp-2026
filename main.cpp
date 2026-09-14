#include <cstdio>  
#include <exception>
#include <print>    
#include <string>   
#include <thread>  
#include <vector>
#include <clocale>

#ifdef _WIN32
#include <windows.h>
#endif

void Worker(int index)
{
    std::println("Поток {} выполняет свою работу", index);
}

int main(int argc, char* argv[])
{
    std::setlocale(LC_ALL, "Russian");
    if (argc < 2)
    {
        std::println(stderr, "Ошибка: не указано количество потоков.");
        std::println(stderr, "Использование: {} <количество_потоков>", argv[0]);
        return 1;
    }

    int threadCount = 0;

    try
    {
        size_t charsRead = 0;

        threadCount = std::stoi(argv[1], &charsRead);

        if (argv[1][charsRead] != '\0' || threadCount <= 0)
        {
            std::println(stderr, "Ошибка: аргумент должен быть целым положительным числом.");
            return 1;
        }
    }
    catch (const std::exception&)
    {
        std::println(stderr, "Ошибка: передан некорректный аргумент.");
        return 1;
    }

    std::vector<std::jthread> threads;
    threads.reserve(threadCount);

    for (int i = 1; i <= threadCount; ++i)
    {
        threads.emplace_back(Worker, i);
    }

    return 0;
}