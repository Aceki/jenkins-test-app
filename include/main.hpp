/**
 * @file main.hpp
 * @brief Специальные функции.
 * @author Nikita Brekhuntsov <n.brekhuntsov@prosoftsystems.ru>
 */

#include <iostream>

/**
 * Выводит строку в стрим `os`.
 * @param os Выходной стрим.
 */
void helloworld(std::ostream& os)
{
    os << "Hello, World!";
}
