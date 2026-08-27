
#ifndef __SERVER_H__
#define __SERVER_H__

int eventCreateSocket(int port);
nosave void eventServerListenCallback(int fd);
nosave void eventServerAbortCallback(int fd);
nosave void eventServerReadCallback(int fd, string str);
nosave void eventRead(int fd, string str);
nosave void eventServerWriteCallback(int fd);
varargs void eventWrite(int fd, string str, int close);
nosave void eventClose(mapping sock);
nosave void eventSocketClosed(int fd);
int dest_me();
nosave void eventNewConnection(int fd);
nosave void eventSocketError(string str, int x);
function SetRead(function f);
int SetDestructOnClose(int x);

#endif /* __SERVER_H__ */

