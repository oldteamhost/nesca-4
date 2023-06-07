![alt text](https://i.imgur.com/fb5pG53.png)

![alt text](https://i.imgur.com/iiwGfJq.png)

# COMPILE
#### Debian 11:
```
    sudo apt-get install libcurl4-openssl-dev
    sudo apt install g++ make git cmake
    git clone https://github.com/oldteamhost/nesca4
    cd nesca4
    cmake .
    make
```
#### Arch linux:
```
    sudo pacman -S curl cmake
    git clone https://github.com/oldteamhost/nesca4
    cd nesca4
    cmake .
    make
```

# Крос?
К сожалению с недавнего обновления уже нет, компиляция возможна только на linux.
Если кто-то сможет расставить предпроцессор для сокетов, то сюда ![telegram](https://t.me/Lomasterrr).

# Error
```
On start using:
    export LD_LIBRARY_PATH=lib/platform/linux
```


# UPDATE
+ Добавлена многопоточность для сканирования портов.
+ Добавлены оригинальные цвета с nesca3.
+ Настроен вывод.
+ Исправлена случайная остановка во время сканирования.
+ Добавлены цвета для DNS сканирования.
+ Добавлен аргумент -no-color.
+ Оптимизированы цвета.
+ Добавлены цвета в help menu.
+ Добавлено сохранение в txt для сканирования портов.
+ Настроен debug для сканирования портов.
+ Добавлен брутфорс FTP.
+ Добавлены filter ports в debug.
+ Добавлен обход фаервола сканирования.
+ Добавлены аргументы ftp-brute-log и ftp-brute-verbose.
+ Добавлена поддержка импорта и сканирования ip диапазонов.
+ Добавлены новые аргументы: -host-test -tcp-ping -response-code -gen-count -gen-ipv4 -gen-ipv6.
+ Добавлены новые разделы testing и generation.
+ Добавлен брутфорс ssh AKA sftp.
+ Добавлен аргумент -sftp-brute-known-hosts для проверки доверенных ключей.
+ Добавлен брутфорс RTSP.
+ Убраны ненужные брутфорс аргументы, добавлены более автономные.
+ Исправлено segmentation error при откючение RTSP.
+ Добавлены потоки для брутфорса FTP, SSH, RTSP.
+ Добавлен новый аргумент, -brute-timeout.
+ Исправлена максимальная задержка брутфорса в 25секунд.
+ Программа разделена по файлам, до этого весь код был в одном).
+ Добавлен аргумент -on-get-dns.
+ Добавлена два метода парсинга для абсолютных.
+ Добавлено распозвование и парсинг абсолютных путей.
+ Исправлены ошибки парсинга путей, и пердусмотрены любые моменты.
+ Добавлен новый аргумент -no-get-path>
+ Исправлен парсинг путей, переписаны все функции парсинга на regex.
+ Добавлен парсинг из content, content location, и window.location.href в js.
+ Добавлены 2 аргумента, -fix-get-path и -get-path-log
+ Добавлено сохранение redirect в txt и немного изменён дизайн вывода.
+ Весь вывод перенесён в отдельный класс.
+ Исправлены кривые цвета.
+ Добавлена возможность использывать кастомные цвета из конфига.
+ Добавлен аргумент -import-color для парсинга конфига.
+ Добавлена одна color scheme в стиле "retrowave".
+ Добавлена поточность дял брутфорсов.
+ Добавлен брутфорс axis камер aka http basic auth.
+ Добавлено распознование http брутфорса.
+ Добвлены http title для брутфорса.
+ Переписан вывод полностью, убран говнокод.
+ Добавлено определение описание ftp сервера.
+ Добавлены новые шаблоны портов http,https,sftp,ftp
+ Убран брутфорс RTSP, он был не рабочий, и сделать его я пока не знаю как.
+ Кое как сделан брутфорс RTSP на сколько рабочий не знаю.
+ Добавлен брутфорс hikvision камер.
+ Сделан чёткий make файл.
+ Убрано ненужное сообщение при брутфорсе hikvision.
+ Исправлен вывод http title.
+ Исправлена утечка памяти.
+ Теперь для главных потоков используеться future вместо threads.
+ Добавлено отключение получения описания ftp после 15 секунд неудачного подключения.
+ Наконец исправлена ошибка с segmentation error при получение путей.
+ Добавлен новый аргумент в тестрирование -redirect.
+ Добавлен новый аргумент в тестрирование -http-request.
+ Добавлена возможность указывать диапазон портов, типа 0-65535.
+ Убран говнокод из main файла.
+ Переписана функция по сканированию портов.
+ Проект перешёл на cmake.
+ Наконец то написано syn сканирования вместо tcp.
+ За счёт syn сканирования, теперь есть обход фаерволов.
+ Увеличена аннонимность, за счёт неполного подлкючения.
+ Увеличена скорость.
+ Настроена кроссплотформленность.
+ Исправлено syn сканирования повышена точность.
+ Добавлены новые аргументы -sss-timeout, -ssr-timeout
+ Добавлен debug для syn сканирования -syn-db, syn-debug.
+ Добавлен icmp ping.
+ Добавлены новые аргументы для icmp ping.
+ Улучшен icmp ping.
+ Переписан вывод.
+ Сохранение в txt вновь рабочее.
+ Улучшем код в main файле, и его читабельность.
+ Добавлено куча всего, слишком много измененей.

### 20230528
- FTP, SSH буртфорс переписан без libcurl + скорость.
- Исправлен бутфорс HTTP.
- Немного изменения по коду.

### 20230530
- Исправлены все функции.
- Улучшен код везде.

### 20230531
- Испралена большая часть багов.
- Добавлено сканирование XMAS,FIN,NULL.
- Добавлено Ping сканирование.
    - 3 метода IMCP пинга.
    - Пинг TCP.
- Обновление дизайна.
- Почти готова к релизу.
- Добавлен брутфорс SMTP.

### 20230608 GLOBAL
- Сканирование полностью переписано.
- Пинг сканирование тоже.
- Улучшено всё.
- Улучшен дизайн.
- Но пока нету потоков.

# Документация
Читайте do_not_read.txt

## Потоки при брутфорсе
Для брутфорса выделяються отдельные потоки, на каждую комбинацию логина и пароля, свой поток. За счёт этого максимальная задержка подбора, которую
я смог поймать равна `25 секунд`.

### Таймаут при брутфорсе
За этот таймаут отвечает отдельный аргумент `-brute-timeout`, которые аналогично принимает количество милисекунд.
По стандарту стоят `10 милисекунд`. Тут слишком много ставить не нужно.

## DNS сканирование
`DNS` сканирование в `nesca4` заключаеться в генерации рандомного домена, и проверки его доступности.
Для генерации используеться функция `generate_random_str`, для проверки доступности `measure_ping_time`.

Для `DNS` сканирования в `nesca4` есть 3 аргумента, давайте их тоже разберём:

- `-dns-scan` - Включает `DNS` сканирование, и в качестве параметра принимает домен
первого уровня, например: `-dns-scan .com` или `-dns-scan .net`.

- `dns-length` - В качестве параметра принимает длинну генерируемого домена. Стандартно стоит `5` символов.

- `dns-dict` - В качестве параметра принимает словарь символов, из которых будет генерироваться домен. Стандартно стоит
`0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`.

## Брутфорс 
В `nesca4` есть 8 аргументов для работы с брутфорсам, давайте их разберём:

- `-brute-login` - Этот аргумент позволяет указать путь к файлу с логинами для конкретного протокола при брутфорсе.
В качестве параметра принимает протокол и путь, через запятую без пробела. Например: `-brute-login ftp,login.txt`.

- `-brute-pass` - Аналогичен преведущему, но принимает файл не с логинами а с паролями.

Для следующих аргументов действует ключевое слово `all`, которое указывает что нужно приминить операцию сразу ко всем протоколам.
Для использывания этого слова, нужно просто указать его в параметр заместо протокола.

- `-brute-only` - Этот аргумент ставит ограничение на вывод, за счёт этого выводяться только те результаты которые были успешно забрутфорсины.
В качестве параметра принимает протокол к которому нужно это приминить. Также можно указать несоклько протокол,
через запятую без пробела. Например: `-brute-only ftp,sftp`.

- `-no-brute` - Этот аргумент повзоляет отключить брутфорс для указанного протокола. Протокол указываеться в параметре. Также как и в преведущем
аргументе можно указать сразу несолько. Через запятую без пробела. Наример: `-no-brute ftp,sftp`, это команда отключит брутфорс для `FTP` и `SFTP`.

- `-brute-verbose` - Этот аргумент позволяет, включить `verbose` для конкретного протокола. В качестве параметра передаёться сам протокол. Можно также
указать несколько. Через запятую без пробела. Наример: `-brute-verbose ftp,sftp`, такая комбинация влкючить `verbose` для `FTP` и `SFTP` брутфорса.

- `-brute-log` - Этот аргумент включает вывод лога для конкретного протокола, в логе показываються все комбинации которые он пробует при брутфорсе.
В качестве параметра выступает сам протокол, можно также указать несолько через запятую без пробела. Наример: `-brute-log ftp,sftp`. Эта запись
включит лог для брутфорса `FTP` и `SFTP`.

- `-sftp-brute-known-hosts` - Этот аргумент позволяет включить определение, и подключение через файл доверенностей, `known_host`.
Параметр у него отсутствует.

## Тестирование
В `nesca4` для тестирование хостов, есть три аргумента:

- `-host-test` - Этот аргумент включает тестирование, и устанавливает хост для него. В качестве параметра указывается хост. Также
есть возможность указать несколько хостов для тестирования. Для этого просто укажите их через запятую без пробела.

- `-responce-code` - Этот аргумент, включает получения кода ответа, действует для всех указанных хостов. Использует функцию `get_response_code`.

- `-tcp-ping` - Этот аргумент позволяет получить время ответа, и узнать доступность хоста. В качестве параметра принимает
режим работы. Первый это `(default)` второй это `(live)`. Первый работает со всеми указанными хостами второй только с одним.
Так как второй запускает бесконечный цикл, в котором выводиться время ответа. Использует функцию `measure_ping_time`.

## Генерация
В `nesca4` для генерации есть три аргумента:

- `-gen-count` - Этот аргумент позволяет изменить количество генерируемых целей.
- `-gen-ipv4` - Этот аргумент указывает в качестве цели для генерации айпи версии 4. Параметров не принимает. Использует функцию `generate_ipv4`.
- `-gen-ipv6` - Этот аргумент указывает в качестве цели для генерации айпи версии 6. В параметр принимает количество окетов айпи. Использует функцию `generate_ipv6`.


