#define SERVER "220.133.201.41 9994"

#include <socket.h>
#include <socket_err.h>
#include <ansi.h>

nosave int my_socket, x;

void create()
{

    my_socket = socket_create( MUD, "read_callback", "close_callback" );

    if( my_socket < 0 ) return ;
    
	x = socket_connect( my_socket, SERVER , "read_Callback", "write_Callback");

	if( x != EESUCCESS ) 
	{
		socket_close(my_socket);
		return;
	}
}

void write_callback( int fd )
{
	return;
}

void read_callback( int fd, mixed msg )
{
	if( stringp(msg) || msg == "~ok~" )
		socket_close(fd);
		
    return;
}

void close_callback( int fd )
{
    return;
}
