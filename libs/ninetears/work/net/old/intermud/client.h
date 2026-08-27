#ifndef __CLIENT_H__
#define __CLIENT_H__

class client {
    int Descriptor;
    int Blocking;
    mixed *Buffer;
}

int eventCreateSocket(string host, int port);
nosave void eventAbortCallback(int fd);
nosave void eventReadCallback(int fd, mixed val);
nosave void eventRead(mixed val);
nosave void eventWriteCallback(int fd);
void eventWrite(mixed val);
nosave void eventClose(class client sock);
nosave void eventSocketClose();
int eventDestruct();
nosave void eventSocketError(string str, int x);
function SetRead(function f);
int SetSocketType(int x);
int SetDestructOnClose(int x);

#endif /* __CLIENT_H__ */
