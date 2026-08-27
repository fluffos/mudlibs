#ifndef __CLIENT_H__
#define __CLIENT_H__

class client {
    int Descriptor;
    int Blocking;
    mixed *Buffer;
}

int eventCreateSocket(string host, int port);
void eventAbortCallback(int fd);
void eventReadCallback(int fd, mixed val);
void eventRead(mixed val);
void eventWriteCallback(int fd);
void eventWrite(mixed val);
void eventClose(class client sock);
void eventSocketClose();
int eventDestruct();
void eventSocketError(string str, int x);
function SetRead(function f);
int SetSocketType(int x);
int SetDestructOnClose(int x);

#endif /* __CLIENT_H__ */
