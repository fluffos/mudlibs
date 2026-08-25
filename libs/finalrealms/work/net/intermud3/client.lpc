/*    /secure/lib/client.c
 *    from the Nightmare IVr1 Object Library
 *    a TCP client object
 *    created by Descartes of Borg 950428
 *    modified for the Discworld mudlib by Turrican 25-10-95
 */

#include <network.h>
#include "client.h"
#include "intermud_cfg.h"

private nosave int DestructOnClose, SocketType = -1;
private nosave function Read;
private nosave class client Socket;

void create() {
  seteuid(getuid());
}

int eventCreateSocket(string host, int port) {
    int x;

    Socket = new(class client);
    Socket->Blocking = 1;
    if( SocketType == -1 ) SocketType = STREAM;
    x = socket_create(SocketType, "eventReadCallback", "eventAbortCallback");
    if( x < 0 ) {
	eventSocketError("Error in socket_create().", x);
	return x;
    }
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
}

protected void eventAbortCallback(int fd) {
    if( !Socket ) return;
    if( fd != Socket->Descriptor ) return;
    eventClose(Socket);
}

protected void eventReadCallback(int fd, mixed val) {
    if( functionp(Read) ) evaluate(Read, val);
      else eventRead(val); // Taniwha, in an attempt to shut the damn thing up
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
	if( sizeof(Socket->Buffer) == 1 ) Socket->Buffer = 0;
	else Socket->Buffer = Socket->Buffer[1..];
    }
}

void eventWrite(mixed val) {
    int x;

    if( !Socket ) return;
    if( Socket->Buffer ) Socket->Buffer += ({ val });
    else Socket->Buffer = ({ val });
    if( Socket->Blocking ) return;
    else eventWriteCallback(Socket->Descriptor);
}

protected void eventClose(class client sock) {
    if( !sock ) return;
    socket_close(sock->Descriptor);
    sock = 0;
    eventSocketClose();
    if( DestructOnClose ) destruct(this_object());
}

protected void eventSocketClose() { }

int dest_me() {
    eventClose(Socket);
}

protected void eventSocketError(string str, int x) { 
    if( LOGFILE ) 
      log_file(LOGFILE, ctime(time()) + socket_error(x) + "\n");
}

function SetRead(function f) { return (Read = f); }

int SetSocketType(int type) { return (SocketType = type); }

int SetDestructOnClose(int x) { return (DestructOnClose = x); }
