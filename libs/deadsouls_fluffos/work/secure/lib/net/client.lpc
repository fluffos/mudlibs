/*    /secure/lib/client.c
 *    From the Dead Souls Mud Library
 *    a TCP client object
 *    Created by Descartes of Borg 950428
 *    Version: @(#) client.c 1.3@(#)
 *    Last modified: 96/12/21
 */

#include <lib.h>
#include NETWORK_H

inherit LIB_DAEMON;

class client {
    int Descriptor;
    int Blocking;
    mixed *Buffer;
}

private nosave int DestructOnClose, SocketType = -1;
private nosave string LogFile;
private nosave function Read;
private nosave class client Socket;

protected void eventClose(class client sock);
protected void eventRead(mixed val);
protected void eventSocketClose();
protected void eventSocketError(string str, int x);

function SetRead(function f) { return (Read = f); }

int SetSocketType(int type) { return (SocketType = type); }

int SetDestructOnClose(int x) { return (DestructOnClose = x); }

int eventCreateSocket(string host, int port) {
    int x, ret;

    Socket = new(class client);
    Socket->Blocking = 1;
    if( SocketType == -1 ) SocketType = MUD;
    x = socket_create(SocketType, "eventReadCallback", "eventAbortCallback");
    if( x < 0 ) {
        eventSocketError("Error in socket_create().", x);
        return x;
    }
    ret = x;
    Socket->Descriptor = x;
    x = socket_bind(Socket->Descriptor, 0);
    if( x != EESUCCESS ) {
        eventClose(Socket);
        eventSocketError("Error in socket_bind().", x);
        return x;
    }
    x = socket_connect(Socket->Descriptor, host + " " + port,
            "eventReadCallback", "eventWriteCallback");
    if( x != EESUCCESS ) {
        eventClose(Socket);
        eventSocketError("Error in socket_connect().", x);
        return x;
    }
    return ret;
}

protected void eventAbortCallback(int fd) {
    if( !Socket ) return;
    if( fd != Socket->Descriptor ) return;
    eventClose(Socket);
}

protected void eventReadCallback(int fd, mixed val) {
    if( functionp(Read) ) evaluate(Read, val);
    else eventRead(val);
}

protected void eventRead(mixed val) { }

protected void eventWriteCallback(int fd) {
    int x;
    if( !Socket ) return;
    Socket->Blocking = 0;
    x = EESUCCESS;
    while( Socket->Buffer && x == EESUCCESS ) {
        switch( x = socket_write(Socket->Descriptor, Socket->Buffer[0]) ) {
            case EESUCCESS:
                break;
            case EECALLBACK:
                Socket->Blocking = 1;
                break;
            case EEWOULDBLOCK:
                call_out( (: eventWriteCallback($(fd)) :), 0);
                return;
            case EEALREADY:
                Socket->Blocking = 1;
                return;
            default:
                eventClose(Socket);
                eventSocketError("Error in socket_write().", x);
                return;
        }
        if( sizeof(Socket->Buffer) == 1 ) {
            Socket->Buffer = 0;
        }
        else {
            Socket->Buffer = Socket->Buffer[1..];
        }
    }
}

protected void eventWrite(mixed val) {
    if( !Socket ) return;
    if( Socket->Buffer ) Socket->Buffer += ({ val });
    else Socket->Buffer = ({ val });
    if( Socket->Blocking ) {
        return;
    }
    else {
        eventWriteCallback(Socket->Descriptor);
    }
}

protected void eventClose(mixed arg) {
    class client sock;
    if(!arg) return;
    if(classp(arg)) sock = arg;
    if(!classp(arg)){
        trr("arg: "+identify(arg),"yellow");
        trr("prevs: "+identify(previous_object(-1)),"yellow");
        trr("i am: "+identify(this_object()),"yellow");
        if(mapp(arg)) socket_close(arg["Descriptor"]);
        if(objectp(arg)) socket_close(arg->GetDescriptor());
        return;
    }
    //else trr("Yes, I am a class.");
    socket_close(sock->Descriptor);
    sock = 0;
    eventSocketClose();
    if( DestructOnClose ) Destruct();
}

protected void eventSocketClose() { }

int eventDestruct() {
    eventClose(Socket);
    return daemon::eventDestruct();
}

protected void eventSocketError(string str, int x) {
    if( LogFile )
        log_file(LogFile, ctime(time()) + "\n" + socket_error(x) + "\n");
}
