/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : _ident_usr.c
 * Author : Clode@RevivalWorld
 * Date   : 2001-3-2
 * Note   : Ident
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#include <socket.h>
#include <message.h>

nosave int remote_port;

nomask int get_ident()
{
	string socket, address;
	int port, socket_port;

	if( !(socket = socket_address(this_object())) ) return 0;
	if( sscanf(socket, "%s %d", address, port) != 2 ) return 0;
	
	remote_port = port;

	socket_port = socket_create(STREAM, "ident_create_read_callback", "ident_create_close_callback");
	
	if( socket_port < 0)
	{
		tell(this_player(), socket_error(socket_port) + "\n", ERRMSG);
		return 0;
	}
	
	if( socket_connect(socket_port, address + " 113", "ident_read_callback", "ident_write_callback") < 0 ) 
	{
		socket_close(socket_port);
		return 0;
	}
	return 1;
}

void ident_write_callback(int socket_port)
{    
	if( socket_write(socket_port, remote_port + "," + query_ip_port(this_object()) + "\n") < 0 ) 
		socket_close(socket_port);
}

void ident_read_callback(int socket_port, mixed info) 
{
	string tmp, machine, name;

	if( !info || sscanf(info,"%s : USERID : %s :%s\r\n", tmp, machine, name) != 3 )
	    	set("ident", info);
	else
		set("ident", machine+"-"+name);

	set("remote_port", remote_port);
	socket_close(socket_port);
}

void ident_create_read_callback(int fd, mixed message)
{
}

void ident_create_close_callback(int fd)
{
	socket_close(fd);
}
