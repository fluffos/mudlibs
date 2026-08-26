/**
 * Donky's webster client, 20-7-95
 * @changed Galileo ported to new lib, 26-11-98
 * @changed Galileo ported to use TCP_CLIENT_M, 12-2-98
 * @changed Galileo adapted for new webster server, 27-2-99
 * @changed Ported to Divided Sky by Shaydz 3/21/02 2:10PM
 * @changed Changed the user member in the webster class from
 * object to string - Sandoz 11/09/02
 */

#include <network.h>
#include <webster.h>

inherit CLIENT;

class webster {
    string user;   // User initating the request
    string cmd;    // The request itself
    int call_out;  // Timeout specific to this request
}

mapping requests;

void create() {
    requests = ([ ]);
    client::create();
} /* setup() */

/** @ignore yes */
mapping query_requests() { return requests; }

/** @ignore yes */
int protocol( string cmd, object user ) {
    class webster request = new( class webster );
    int fd;

    if( !cmd )
        return 0;

    if( ( fd = eventCreateSocket( SITE_HOST, SITE_PORT ) ) < 0 ) {
        tell_object( user, PROTOCOL + ": " + socket_error(fd) + "\n");
        return 0;
    }

    request->user = user->query_name();
    request->cmd = cmd;
    request->call_out = call_out("timeout", TIMEOUT, fd );

    requests[fd] = request;
    eventWrite(fd, "");

    return 1;

} /* protocol() */

/** @ignore yes */
void timeout( int fd ) {
    object ob;

    if( ob = find_player( requests[fd]->user ) )
        tell_object( ob, PROTOCOL + ": Time out on request '"+
            requests[fd]->cmd+"'.\n");

    map_delete( requests, fd );
    eventSocketClose(fd);

} /* timeout() */

/** @ignore yes */
void dest_me() {
    map( requests, (: remove_call_out( $2->call_out ) :) );
    client::dest_me();
} /* dest_me() */

/** @ignore yes */
void eventRead( int fd, string reply ) {
    object ob;
    string ret;
    int close, code, index, i;

    i = 0;

    sscanf( reply, "%d", code );
    reply = replace_string( reply, "\r\n", "\n");

    if( ob = find_player( requests[fd]->user ) )
        switch( code ) {
          default:
            ret = reply+"\n";
          break;
          case 110:
          case 111:
          case 151:
          case 152:
            ret = reply[4..];
          break;
          case 150:
            if( ( i = strsrch( reply, "151") ) != -1 ) {
                eventRead( fd, reply[i..] );
                return;
            }
          case 220:
            ret = "";
          break;
          case 501:
            close = 1;
            ret = "Invalid syntax.\n";
          break;
          case 552:
            close = 1;
            ret = "No matches found.\n";
        }

    if( ( index = strsrch( ret, "250 ok") ) != -1 ) {
        close = 1;
        ret = ret[0..(index-1)]+"\n> ";
    }

    tell_object( ob, ret );

    if( close ) {
        remove_call_out( requests[fd]->call_out );
        map_delete( requests, fd );
        eventSocketClose(fd);
    }

} /* client_read_callback() */

/** @ignore yes */
void eventWrite( int fd, string notused ) {
    if( !requests[fd]->user )
        eventSocketClose(fd);

    ::eventWrite( fd, requests[fd]->cmd+"\r\n");

} /* client_write_callback() */
