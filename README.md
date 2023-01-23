# Задание:

### Есть последовательность идентификаторов, строящаяся по следующим правилам:
1. Первый идентификатор последовательности имеет вид «A1», второй — «A2», третий - «A3» и так далее. За «A9» следует «B1». Следующий после «Z9» имеет вид «A1-A1», потом «A1-A2» и так далее. После «A1-Z9» следует «A2-A1».
2. Максимальная длина идентификатора - десять групп по два символа.
3. В идентификаторах никогда не должны присутствовать буквы «D», «F», «G», «J», «M», «Q», «V» и цифра «0».
   Необходимо реализовать класс, обеспечивающий работу с идентификатором по заданным правилам.
   Класс должен обладать следующим функционалом:
   • Метод, устанавливающий текущее значение идентификатора
   • Метод, инкрементирующий значение идентификатора и возвращающий новое значение
   Технические требования к решению:
1. Код должен быть потокобезопасным.
2. Код должен компилироваться.
3. Код должен быть кроссплатформенным (успешно собираться компиляторами msvc/gcc/clang).
4. Для решения задачи разрешается использовать только стандартную библиотеку С++(стандарт до C++17 включительно).


## Вопрос.
#### Существуют ли какие-то проблемы, общие для всех разработчиков, мешающие программистам работать с большей эффективностью? Какое решение этих проблем Вы видите? Существуют ли какие-то следующие шаги, которые возможно потребуется   предпринять, если Ваше решение указанных проблем будет реализовано на практике?

Мешать может: медленный интернет, ремонт у соседей, зубная боль, погода, настроение, цвет стен … и еще тысячи причин. Устраняешь одну проблему, появляется следующая. Единственный способ устранения проблем, устранить их в самом себе, свою реакцию на них. Следуем правилу: «нет у человека врага злее, чем он сам». Поэтому, устраняем технические неполадки и отключаемся от эмоций. Всё индивидуально.

## Вопрос:
#### Предложите оптимальную, на Ваш взгляд, программную архитектуру для бортового компьютера электромобиля. Обоснуйте свое решение.

Попробую, хотя вопрос сложный и требует специальной подготовки.

### Сервисный интерфейс (службы и сервисы).

Программное обеспечение для управления электронными блоками управления, таких как торможение, устойчивость, регулировка топлива, система впрыска, удаления газов, воды, ремни, генераторы, подушки безопасности, системы комфорта и так далее (сегодня это от 30 до 100 блоков в каждой машине). Это низкоуровневый блок, требующий максимальной точности программного решения, оптимизации, чипизации.

### Пользовательский интерфейс (кнопки на панелях и головное устройство).
1. Контроль систем автомобиля, таких как: давление в шинах, освещение снаружи и внутри, уровень жидкостей, уровень масла. Сервисное информирование
2. Пользовательские настройки: региональные, систем контроля, систем управления, датчиков, системы комфорта, bluetooth, wifi, местоположение и т.д..
3. Управление системой комфорта автомобиля: дистанционный запуск, система кондиционирования и обогрева, освещение, подсветка и т.д.
4. Система коммуникации: телефон, кнопка sos и прочее.
5. Развлекательная система: трансляция радио, медиа проигрыватель, bluetooth.
6. Система согласования с телефоном. (googleauto etc)
7. Навигационная система.

Все функции пользовательского интерфейса, кроме сервисных функций и настроек, практически полностью реализованы в смартфонах. В идеале, нужна полная трансляция экрана смартфона на головное устройство с функцией сенсорного управления. Такой интерфейс избавит производителя от «придумывания» функционала, реализовать нужно только сервисные функции:

1. Сервисное информирование и настройки.
2. Радио трансляцию в диапазонах AM, FM.
3. Трансляцию и управление смартфоном.

Уверен, что вопрос был о чем-то другом.