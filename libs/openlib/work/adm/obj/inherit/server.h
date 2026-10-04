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
protected void eventServerListenCallback(int fd);
protected void eventServerAbortCallback(int fd);
protected void eventServerReadCallback(int fd, mixed val);
protected void eventRead(int fd, mixed val);
protected void eventServerWriteCallback(int fd);
varargs void eventWrite(int fd, mixed val, int close);
protected void eventClose(class server sock);
protected void eventSocketClosed(int fd);
int eventDestruct();
protected void eventNewConnection(int fd);
protected void eventWriteError(int fd);
protected void eventSocketError(string str, int x);

function SetRead(function f);
function SetSocketClosed(function f);
int SetDestructOnClose(int x);

#endif /* __SERVER_H__ */
