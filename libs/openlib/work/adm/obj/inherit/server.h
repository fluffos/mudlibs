#ifndef __SERVER_H__
#define __SERVER_H__

class server {
    int Descriptor;
    int Blocking;
    int Closing;
    mixed *Buffer;
}

int eventListenSocket(int port, int type);
int eventCreateSocket(string host, int port, int SocketType);
nosave void eventServerListenCallback(int fd);
nosave void eventServerAbortCallback(int fd);
nosave void eventServerReadCallback(int fd, mixed val);
nosave void eventRead(int fd, mixed val);
nosave void eventServerWriteCallback(int fd);
varargs void eventWrite(int fd, mixed val, int close);
nosave void eventClose(class server sock);
nosave void eventSocketClosed(int fd);
int eventDestruct();
nosave void eventNewConnection(int fd);
nosave void eventWriteError(int fd);
nosave void eventSocketError(string str, int x);

function SetRead(function f);
function SetSocketClosed(function f);
int SetDestructOnClose(int x);

#endif /* __SERVER_H__ */
