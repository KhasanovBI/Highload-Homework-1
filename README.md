# Neutrino 
![Neutrino logo](https://raw.githubusercontent.com/KhasanovBI/Highload-Homework-1/master/image/Neutrino.png)

##### Запуск сервера
Для запуска сервера необходимо вызвать команду make в директории сервера. После вызова данной команды будет сгенерирован бинарный файл httpd. <br>

##### Конфигурационный файл settings.cfg

| Ключ                  | Значение                                | Тип     |
|-----------------------|-----------------------------------------|---------|
| buffer_size           | Размера буфера                          | Integer |
| connections_max_count | Максимальное число соединений           | Integer |
| CPU_cores_count       | Количество используемых ядер процессора | Integer |
| debug_messages        | Вывод отладочных сообщений в STDIN      | Boolean |
| default_page          | Имя индекса директории                  | String  |
| port                  | Порт                                    | Integer |
| root_directory        | Путь к корневой директории              | String  |

##### Поддерживаемые ключи

| Ключ | Описание                                | Тип     |
|------|-----------------------------------------|---------|
| -с   | Количество используемых ядер процессора | Integer |
| -r   | Путь к корневой директории              | String  |
