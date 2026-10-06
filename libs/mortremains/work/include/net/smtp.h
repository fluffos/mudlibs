// smtp include, based on Truilkan's smtp include

#ifndef __SMTP_H
#define __SMTP_H

#define PORT_SMTP (__PORT__ - 4)

#define LOG_SMTP "smtp"
#define LOG_SMTP_ERR "smtp_errors"

#define SMTP_DEBUG(y) do { \
    if (find_player(DEBUGGER)) tell_object(find_player(DEBUGGER),y); \
} while (0)

void listen_callback(int fd);
void write_callback(int fd);
void read_callback(int fd, string str);
private void smtp_send(int fd, string code);
void close_connection(int fd);

#endif /* __SMTP_H */
