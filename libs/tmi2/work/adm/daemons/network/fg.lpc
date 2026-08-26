// Unix finger support for clients.
#include <mudlib.h>
#include <uid.h>
#include <net/socket.h>


#define WHO	find_player( "no_one" )
#define TELL(x)	 if( WHO ) tell_object( WHO, (x) );
#define MYPORT	4343

mapping sockets;
int listen_fd;

void create() {
  seteuid( ROOT_UID );
  sockets = allocate_mapping( 5 );
}

void write_callback( int fd, string msg ) {
   string txt;
   int err;

   if( sockets[fd]["pending"] ) {
      txt = sockets[fd]["outgoing"];
      err = socket_write( fd, txt );
      if( err < 0 ) {
         return;
      }
      TELL( sprintf( "socket_write( %d, %O )\n", fd, txt + "\n" ) );
      sockets[fd]["pending"] = 0;
      sockets[fd]["outgoing"] = "";
   }
}

void read_callback( int fd, string msg ) {
/*
   sockets[fd]["incoming"] += msg;
*/
   message( "info", msg, sockets[fd]["object"] );
}

void close_callback( int fd ) {
   string txt;

   if ( !sockets[fd] )  return;
   TELL( sprintf( "Closing socket %d\n", fd ) );
   if( strlen( txt = sockets[fd]["incoming"] ) ) 
      message( "info", txt, sockets[fd]["object"] );

   map_delete( sockets, fd );
   socket_close( fd );
}

int create_listen() {
  int err;

   listen_fd = socket_create( STREAM, "read_callback", "close_callback" );
   if( listen_fd < 0 ) {
     TELL( sprintf( "Error %d in socket_create()\n", listen_fd ) );
      return 0;
   }
  
   err = socket_bind( listen_fd, MYPORT );

   if( err < 0 ) {
      TELL( sprintf( "Error %d in socket_bind()\n", err ) );
      socket_close( listen_fd );
      return 0;
   }

   err = socket_listen( listen_fd, "close_callback" );
   if( err < 0 ) {
      TELL( sprintf( "Error %d in socket_listen()\n", err ) );
      socket_close( listen_fd );
      return 0;
   }
  return listen_fd;
}

varargs
int create_socket( string dest, object ob ) {
   int fd, err;

   fd = socket_create( STREAM, "read_callback", "close_callback" );
   if( fd < 0 ) {
      TELL("create_socket: socket_create: " + socket_error(fd) + "\n");
      return -1;
   }

   err = socket_connect( fd, dest, "read_callback", "write_callback" );
   if( err != EESUCCESS ) {
      socket_close( fd );
      TELL("create_socket: socket_connect: " + (err) + "\n");
      return -1;
   }  

   sockets[fd] = allocate_mapping( 5 );
   sockets[fd]["pending"] = 0;
   sockets[fd]["outgoing"] = "";
   sockets[fd]["incoming"] = "";
   if( !ob ) ob = this_player();
   sockets[fd]["object"] = ob;
   call_out( "close_callback", 30, fd );
   message( "info", "Socket: " + fd + " is ready for writes.\n",
		this_player() );
   return fd;
}

int write_socket( int fd, string msg ) {
   int err;

   if( !sockets[fd] ) return -1;
   if( sockets[fd]["pending"] ) {
      sockets[fd]["outgoing"] += msg;
   } else {
         err = socket_write( fd, msg + "\n" );
         if( err < 0 ) {
            TELL( sprintf( "socket_write() err %d\n", err ) );
            sockets[fd]["pending"] = 1;
            sockets[fd]["outgoing"] += msg;
            return 2;
         }
   }
   return 1;
}


void dump() {
  printf( "%O\n", sockets );
}


