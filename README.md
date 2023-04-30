![alt text](https://i.imgur.com/fb5pG53.png)

## Половина функций ещё не рабочая!!
Консольная утилита для сканирования `портов` и `dns`, брутфорсер для `ftp`, `sftp`, `hikvision` и `rvi`.
Поддерживает многопоточность: До `500` потоков работает стабильно, дальше за ваш процессор не ручаюсь.
Использует `TCP` сканирования, но поддерживает полную настройку его. Разогнать можно очень сильно.
Полностью кроссплотформлена, для компиляции на `linux` используйте `gcc` для `windows` `MinGW`.

![alt text](https://i.imgur.com/xoJQ2N5.png)

# COMPILE
#### Debian 11:
```
    sudo apt install g++ make git
    sudo apt-get install libcurl4-openssl-dev
    git clone https://github.com/oldteamhost/nesca4
    cd nesca4
    make
```
#### Arch linux:
```
    sudo pacman -S curl git
    git clone https://github.com/oldteamhost/nesca4
    cd nesca4
    make
```
#### Windows:
```
    Скачать MinGW
    Подлинковать libcurl - https://curl.se/windows/
    Скачать архив с репозиторием - https://github.com/oldteamhost/nesca4/archive/refs/heads/main.zip
    Распокавать
    cd nesca4
    make
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
+ Добавлен аргумент -sftp-brute-known-hosts для прорки доверенных ключей.
+ Добавлен брутфорс RTSP.
+ Убраны ненужные брутфорс аргументы, добавлены более автономные.
+ Исправлено segmentation error при откючение RTSP.
+ Добавлены потоки для брутфорса FTP, SSH, RTSP.
+ Добавлен новый аргумент, -brute-timeout.
+ Исправлена максимальная задержка брутфорса в 25секунд.

# Все рабочие функции
```
d8b   db d88888b .d8888.  .o88b.  .d8b.         j88D  
888o  88 88'     88'  YP d8P  Y8 d8' `8b       j8~88  
88V8o 88 88ooooo `8bo.   8P      88ooo88      j8' 88  
88 V8o88 88~~~~~   `Y8b. 8b      88~~~88      V88888D 
88  V888 88.     db   8D Y8b  d8 88   88          88  
VP   V8P Y88888P `8888Y'  `Y88P' YP   YP          VP  

usage: ./nesca4 [flags]

arguments target:
  -ip <1,2,3>            Set ip target.
  -cidr <1,2,3>          Set cidr target.
  -range <1,2,3>         Set range target.
  -import-ip <path>      Set ips on target from file.
  -import-cidr <path>    Set cidr on target from file.
  -import-range <path>   Set range on target from file.
  -random-ip <count>     Set random ips target.

arguments ports:
  -ports, -p <1,2,3>     Set ports on scan.
     - example ports:    all, nesca, top100, top50

arguments speed:
  -threads, -T <count>   Set threads for scan.
  -timeout, -t <ms>      Set timeout for scan.

arguments bruteforce:
  -brute-login <ss,path> Set path for <ss> logins.
  -brute-pass <ss,path>  Set path for <ss> passwords.
  -brute-timeout <ms>    Edit brute timout.
  -brute-only <ss,2>     Display only success <ss> bruteforce.
  -no-brute <ss,2>       Disable <ss> bruteforce.

arguments other bruteforce:
  -brute-verbose <ss,2>  Display bruteforce <ss> all info.
  -brute-log <ss,2>      Display bruteforce <ss> info.
  -sftp-brute-known-hosts Reading known_host for connection.

arguments dns-scan:
  -dns-scan <.dns>       On dns-scan and set domain 1 level.
  -dns-length <count>    Edit length generating domain.
  -dns-dict <dict>       Edit dictionary for generation.

arguments output:
  -db, -debug            On debug mode, save and display not even working hosts.
  -er, -error            On display errors.
  -no-color              Disable colors.
  -log-set <count>       Change change the value of ips after which, will be displayed information about how much is left.
  -txt <path>            Save result to text document.

arguments testing:
  -host-test <1,2,3>     Set host for testing.
  -response-code         Get response code from host.
  -tcp-ping <mode>       Get response time from host, modes (live) or (default).

arguments generation:
  -gen-count <count>     Set count for generation.
  -gen-ipv6 <octets>     Generate ip version 6.
  -gen-ipv4              Generate ip version 4.
```

# Документация
Я решил написать документацию, потому что аргументов стало намного больше, сразу извеняюсь за ошибки в документации.
У меня их тут может быть очень много. Но мне главное донести информацию, а не сдать егэ. Пока не вся, но возможно скоро будет вся :).

## Потоки
Для указания количества потоков служит аргумент `-threads` и в параметр принимает количество потоков.
В `nesca4` потоки работают подругому чем в `nesca3`, тут каждый поток выделяеться под каждый айпи.
Сколько потоков, столько и просканированных айпи за указанный `timeout`. Также учитывайте что чем больше
потоков, тем больше должен быть `timeout`.

- По стандарту для сканирования `портов` и `DNS` стоят `20 потоков`.

## Потоки при брутфорсе
Для брутфорса выделяються отдельные потоки, на каждую комбинацию логина и пароля, свой поток. За счёт этого максимальная задержка подбора, которую
я смогу поймать равна `25 секунд`.

## Таймаут
Для указания задержки при работе любого процесса в `nesca4` служит аргумент `-timeout`, который принимает
количество милисекунд в параметр. При сканирование портов от него зависит точность, и нагрузка на процессор.
При других задачах, от него зависит только нагрузка на процессор.

- При сканирование портов по стандарту `timeout` стоит в `2 секунды` AKA `2000 милисекунд`.
- При сканирование `DNS` по стандарт стоит в `100 милисекунд`.
- При других других задачах, сохраняеться значение в `2 секунды` AKA `200 милисекунд`.

### Таймаут при брутфорсе
За этот таймаут отвечает отдельный аргумент `-brute-timeout`, которые аналогично принимает количество милисекунд.
По стандарту стоят `10 милисекунд`. Тут слишком много ставить не нужно.

## Цель
Для указания цели в `nesca4` есть 7 аргументов, давайте их разберём:

- Аргумент `-ip` принимает в качестве параметра обычный айпи версии 4, например `192.1.1.1`. Также есть возможность
узказать сразу несколько. Для этого просто напишите их в параметр через запятую, без пробела, например `-ip 192.1.1.1,192.2.2.2`.
Тут мы указали два айпи, `192.1.1.1` и `192.2.2.2`, они и будут просканированы.

- Аргумент `-cidr` принимает в качестве параметра `cidr` AKA `подсеть`, после получения `cidr-а`, разбирает его на айпи.
С помощью функции `cidr_to_ips`, а так аналогичен аргументу `-ip`, в него тоже можно указать несколько целей, абсолютно точно также.

- Аргумент `-range` принимает в качесте параметра `ip range` в переводе `IP диапазон`, после получения которого, также как и `-cidr`
разбирает его на айпи, с помощью функции `range_to_ips`. И точно также поддерживает несоклько целей, которые всё также указываються через,
запятую без пробела. Принимает `IP диапазоны` в таком формате: **31.17.49.0-31.17.49.255**.

- Аргумент `-import-ip` в качестве параметра принимает путь, до файла в котором лежат обычные айпи, версии 4, пример: `-import-ip node.txt`.

- Аргумент `-import-cidr` аналогичен преведущему, но вместо айпи принимает `cidr` АКА `подсети`.

- Аргумент `-import-range` также аналогичен, но вместо `cidr` принимает `IP диапазоны`.

- Аргумент `-random-ip` в качестве параметра принимает количество генерируемых айпи, для генерации использует
функцию `generate_ipv4`

## Порты
Для указания портов в `nesca4` есть аргумент `-p` или его длинная версия `-ports`.
Этот аргумент в качестве параметра принимает порт для сканирования. Их также можно указать несолько. Интересно как?)
Через запятую без пробела, например: `-p 80,21,22`.

Также можно использывать уже готовые паки портов, достаточно написать в параметр ключевые слова AKA шаблоны портов.
Вот какие имеються в наличии:

- `all` - все порты, начиная от **0** заканчивая **65535**.
- `nesca` - аналогично нажитию кнопки `default ports` в `nesca3`, вот все порты которые там содержаться: `80,81,88,8080,8081,60001,60002,8008,8888,554,9000,3536,21`
- `top100` - топ 100 самых популярных портов, наверное. Вот что там содержиться:
```
80, 443, 22, 21, 25, 3389, 110, 143, 53, 445, 139, 3306, 8080, 
1723, 111, 995, 993, 5900, 1025, 587, 8888, 199, 1720, 465, 548, 113, 81,
6001, 10000, 514, 5060, 179, 1026, 23, 8443, 8000, 444, 1433, 1900, 2001,
1027, 49152, 2049, 1028, 1029, 5901, 32768, 1434, 3283, 5800, 389, 53, 17988,
106, 5666, 1725, 465, 995, 548, 7, 123, 389, 113, 37, 427, 8001, 427, 1726,
49153, 2002, 515, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039,
1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052,
1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065,
1066, 1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077
```
- `top50` - топ 50 самых популярных портов, наверное. Вот что там содержиться:
```
80, 443, 22, 21, 25, 3389, 110, 143, 53, 445, 139, 3306, 8080, 
1723, 111, 995, 993, 5900, 1025, 587, 8888, 199, 1720, 465, 548, 113, 81,
6001, 10000, 514, 5060, 179, 1026, 23, 8443, 8000, 444, 1433, 1900, 2001,
1027, 49152, 2049, 1028, 1029, 5901, 32768, 1434, 3283, 5800, 389, 53, 17988,
106, 5666, 1725, 465, 995, 548, 7, 123, 389, 113, 37, 427, 8001, 427, 1726,
49153, 2002, 515, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039,
1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052,
1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1065,
1066, 1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077
```

## DNS сканирование
`DNS` сканирование в `nesca4` заключаеться в генерации рандомного домена, и проверки его доступности.
Для генерации используеться функция `generate_random_str`, для проверки доступности `measure_ping_time`.

Для `DNS` сканирования в `nesca4` есть 3 аргумента, давайте их тоже разберём:

- `-dns-scan` - Включает `DNS` сканирование, и в качестве параметра принимает домен
первого уровня, например: `-dns-scan .com` или `-dns-scan .net`.

- `dns-length` - В качестве параметра принимает длинну генерируемого домена. Стандартно стоит `5` символов.

- `dns-dict` - В качестве параметра принимает словарь символов, из которых будет генерироваться домен. Стандартно стоит
`0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`.

## Вывод
Не вывод что документация не достаточно элегантная, а консольный вывод в `nesca4`.
Объяснять как тут выводиться что то на экран, я конечно не буду. Но покажу аргументы которые, могут
менять этот вывод.

- `-db, -debug` - этот аргумент влючает `debug`, при котором на экан будут выводиться даже не удачные результаты.
Но они будут не только выводиться, они ещё и будут сохраняться, если у вас включен аргумент для сохранение.

- `-er, -error` - этот аргумент, влючает вывод ошибок, но в отличии от `-db, -debug` он просто их выводит.
Без сохранения, даже если у вас включен аргумент для которого.

- `-no-color` - этот аргумент, отключает все цвета для вывода. Программа становиться чёрно белой. Как оно работает?
Дело в том что все цвета в `nesca4` задаються через `ANSI` коды. И коды для установки цветов, храняться в 8 переменнах в
самом начале файла. После установки этого аргумента, или в случае если ваш терминал не поддерживает цвета, в этих переменных все
коды цветов, заменяються на пустую строку. Вот такие дела).

- `-log-set` - Этото аргумент позволяет изменить значение просканированных айпи после каторого, будет выводиться информация о 
том сколько осталось. Стандартно стоит `200` айпи.

## Сохранение
Пока `nesca4` поддерживает только сохранение в текстовый документ, с помощью аргумента:

- `-txt` - Этот аргумент включает сохранение результатов в текстовый документ. В качестве параметра этот аргумент принимает имя файла, куда будут сохраняться результаты.
Подвластен `debug-у`.

## FTP брутфорс 
Для брутфорса в `nesca4` используеться фунция, `brute_ftp`. Сам её вызов происходит если у цели был найден открытый порт `20` либо `21`.
Для настройки брутфорса `FTP` серверов используйте эти аргументы:

- `-no-ftp-brute` - Этот аргумент, позволяет отключить брутфорс `FTP` при сканирование.
- `-ftp-login` - Этот аргумент позволяет изменить путь к файлу в котором храняться логины для брутфорса `FTP`. Стандартно стоит `passwd/ftp_logins.txt`
- `-ftp-pass` - Этот аргумент позволяет изменить путь к файлу в котором храняться пароли для брутфорса `FTP`. Стандартно стоит `passwd/ftp_passwords.txt`
- `ftp-brute-log` - Этот аргумент включает вывод лога при брутфорсе `FTP`. В этом логе, показываеться какую комбинацию логина и пароля он щас пробует.
- `ftp-brute-verbose` - Этот аргумент включает опцию `curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L)`, которая показывает всю информациию работы функции.

