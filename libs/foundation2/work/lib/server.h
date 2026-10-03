#ifndef __SERVER_H__
#define __SERVER_H__

class server {
    int Descriptor;
    int Blocking;
    int Closing;
    string *Buffer;
}

int eventCreateSocket(int port);
protected void eventServerListenCallback(int fd);
protected void eventServerAbortCallback(int fd);
protected void eventServerReadCallback(int fd, string str);
protected void eventRead(int fd, string str);
protected void eventServerWriteCallback(int fd);
varargs void eventWrite(int fd, string str, int close);
void eventClose(class server sock);
protected void eventSocketClosed(int fd);
int eventDestruct();
protected void eventNewConnection(int fd);
protected void eventSocketError(string str, int x);
function SetRead(function f);
int SetDestructOnClose(int x);

#endif /* __SERVER_H__ */
