#include "Ident.h"

Ident::Ident() = default;

Ident::Ident(const std::string & identifier) {
    setCounter(identifier);
}

Ident::~Ident() {
    counter_mutex.lock();
    counter.clear();
    counter_mutex.unlock();
}

bool Ident::setCounter(const std::string & identifier) {
    // определяем количество пар символов в строке, если пар нет, выход без инициализации счетчика
    int pairs = ((int)identifier.size() + 1) / 3;
    if (pairs == 0) return false;
    // начинаем парсинг строки для инициализации счетчика, первая пара символом начинается с конца
    int i = (int) identifier.size() - 2;
    while (pairs-- > 0) {
        // проверяем первую пару и добавляем в счетчик если значение корректное, если нет обнуляем счетчик и выходим
        std::string s = identifier.substr(i,2);
        int bound = getBoundIndex(s);
        if (bound < 0) {
            counter_mutex.lock();
            counter.clear();
            counter_mutex.unlock();
            return false;
        }
        counter_mutex.lock();
        counter.push_back(bound);
        counter_mutex.unlock();
        // проверяем символ разделитель на корректность, если символ не корректен, обнуляем счетчик и выходим
        if (i-- > 2) {
            if (identifier[i] != SEPARATOR_CHAR) {
                counter_mutex.lock();
                counter.clear();
                counter_mutex.unlock();
                return false;
            }
        }
        i -= 2;
    }
    return true;
}

std::string Ident::getCurrentValue() {
    // если случайно счетчик пустой - выход с пустой строкой
    if (counter.empty()) return {};
    // выбираем самый старший разряд идентификатора, он находится в последнем элементе вектора
    int i = (int)counter.size() - 1;
    std::string number = getBoundValue(counter.at(i--));
    // если есть еще разряды, добавляем их с разделительным символом
    while (i >= 0) {
        number += SEPARATOR_CHAR;
        number += getBoundValue(counter.at(i--));
    }
    return number;
};

std::string Ident::counterInc() {
    // если счетчик пустой, инициализируем его и выходим
    if (counter.empty()) {
        counter_mutex.lock();
        counter.push_back(0);
        counter_mutex.unlock();
        return getCurrentValue();
    }
    // Проходим по каждому разряду идентификатора начиная с меньшего, если удается прибавить значение, тогда
    // прибавляем +1 и выходим из цикла, если нет, обнуляем текущий разряд и переходим к следующему разряду
    // идентификатора, пока не обойдем все. Если окажется что? вся разряды заполнены, создадим новый разряд
    // предыдущие разряды уже будут обнулены
    bool do_inc = false;
    for (auto & bound: counter) {
        if (bound < boundSize - 1) {
            counter_mutex.lock();
            bound++;
            counter_mutex.unlock();
            do_inc = true;
            break;
        } else {
            bound = 0;
        }
    }
    // если все разряды заполнены, добавляем новый разряд (все предыдущие уже обнулены выше)
    if (!do_inc) {
        counter_mutex.lock();
        counter.push_back(0);
        counter_mutex.unlock();
    }
    return getCurrentValue();
}

std::string Ident::getBoundValue(int index) {
    std::string s_value;
    if (index < boundSize) {
        int a = index / (int) numbers.size();
        int i = index % (int) numbers.size();
        s_value += letters[a];
        s_value += numbers[i];
    }
    return s_value;
}

int Ident::getBoundIndex(const std::string& value) {
    if (value.length() == 2) {
        int a = (int) letters.find(value[0]);
        int i = (int) numbers.find(value[1]);
        if (a != std::string::npos && i != std::string::npos) {
            return (a * (int) numbers.length() + i);
        }
    }
    return -1;
}

void Ident::displayBound() {
    for (int i = 0; i < boundSize; ++i) {
        std::cout << getBoundValue(i) << " ";
    }
}

int Ident::getBoundSize() const {
    return boundSize;
}



