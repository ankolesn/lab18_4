Реализовать LFU кэш фиксированного размера (количество записей задается в конструкторе) для адресов (адресом является строка, например, “AFFB”). 
Согласно алгоритму LFU после исчерпания размера кэша в начале удаляются записи, которые запрашивались реже всего. 
Удобной реализацией такого кэша является map<адрес, число запросов адреса>. 
При реализации использовать дополнительный multimap или priority_queue (т.е. всего 2 map) для быстрого поиска адреса, который встречался наименьшее число раз.

LfuCache(size_t size)
bool find_and_add(const std::string &address); //возвращает true, если адрес найден в кэше
operator<< для вывода на экран
