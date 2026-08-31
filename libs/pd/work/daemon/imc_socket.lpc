/* Do not remove the headers from this file! see /USAGE for more info. */
/*
** socket.c
**
** This object represents an open UDP/TCP socket using the MudOS
** socket facilities.
**
** 09-Feb-95. Deathblade. Created.
** 05-Jan-96. Cowl. Added STREAM BINARY connect and listen styles
** 12-Jul-96. Rust. Added write callback.
*/
// Above is the origional lima header
// Below is the header I got from the Darkemud lib
// There may be an issue here potentionaly, I'm working to figure it out
// Chances are the next release if it goes as plan will have a totally 
// rewritten socket wrapper, with the imc2 functionality built in
// So i can load different imc2 networks or maby even different clients (i2,i3?)
// as modules into some kind of controlling daemon
/*
**
** This object represents an open TCP socket using the MudOS
** socket facilities.
** 18-Feb-2003  Ported by Helios
** 06-Nov-2003  Redocumentation Started
** 15-Nov-2003  Madoc combined the .h and the .c, renamed it
**              and trimmed what im not using for distrobution 
**              with the taurus lpc imc2 client
*/

#define SKT_STYLE_CONNECT	2	/* connect to remote skt (text) */
#define SKT_STYLE_INT_ACQUIRE	100	/* internal */
#define EESUCCESS	  1		/* Call was successful */
#define EESOCKET	 -1		/* Problem creating socket */
#define EESETSOCKOPT	 -2		/* Problem with setsockopt */
#define	EENONBLOCK	 -3		/* Problem setting non-blocking mode */
#define EENOSOCKS	 -4		/* No more available efun sockets */
#define EEFDRANGE	 -5		/* Descriptor out of range */
#define EEBADF		 -6		/* Descriptor is invalid */
#define EESECURITY	 -7		/* Security violation attempted */
#define	EEISBOUND	 -8		/* Socket is already bound */
#define EEADDRINUSE	 -9		/* Address already in use */
#define EEBIND		-10		/* Problem with bind */
#define EEGETSOCKNAME	-11		/* Problem with getsockname */
#define EEMODENOTSUPP	-12		/* Socket mode not supported */
#define EENOADDR	-13		/* Socket not bound to an address */
#define EEISCONN	-14		/* Socket is already connected */
#define EELISTEN	-15		/* Problem with listen */
#define EENOTLISTN	-16		/* Socket not listening */
#define EEWOULDBLOCK	-17		/* Operation would block */
#define EEINTR		-18		/* Interrupted system call */
#define EEACCEPT	-19		/* Problem with accept */
#define	EEISLISTEN	-20		/* Socket is listening */
#define EEBADADDR	-21		/* Problem with address format */
#define EEALREADY	-22		/* Operation already in progress */
#define EECONNREFUSED	-23		/* Connection refused */
#define EECONNECT	-24		/* Problem with connect */
#define EENOTCONN	-25		/* Socket not connected */
#define EETYPENOTSUPP	-26		/* Object type not supported */
#define	EESENDTO	-27		/* Problem with sendto */
#define	EESEND		-28		/* Problem with send */
#define	EECALLBACK	-29		/* Wait for callback */
#define EESOCKRLSD	-30		/* Socket already released */
#define EESOCKNOTRLSD   -31		/* Socket not released */

#define	ERROR_STRINGS	 32		/* sizeof (error_strings) */

/*
** If this is defined, then the specified privilege is needed to create
** an outbound connection
*/
//#define REQUIRE_PRIV	"Mudlib:socket"

private int	style;
private int	fdOwned = -1;	/* no socket yet */
private function	read_func;
private function	close_func;

private mixed *	write_queue = ({ });
private int	blocked;


int stat_me() {
	printf("%O: connected to %O\n", this_object(), socket_address(fdOwned));
	printf("    read_func=%O  close_func=%O\n", read_func, close_func);
	if ( sizeof(write_queue) ) printf("queue: %O\n", write_queue);
    	return 1;
}


//### socket_connect() doesn't take funcptr yet...
/* private */ protected nomask void read_callback(int fd, mixed message)
{
    catch(evaluate(read_func, this_object(), message));
}


private nomask void close_callback(int fd)
{

    /* this descriptor is closed. don't try to close again. */
    fdOwned = -1;

    if ( close_func )
    {
	catch(evaluate(close_func, this_object()));
    }

    destruct(this_object());
}

//### socket_connect() doesn't take a funcptr yet
/* private */ protected nomask void write_callback(int fd){
    /*
    ** No longer blocked (can accept new data).
    */
    
    blocked = 0;

    while ( sizeof(write_queue) > 0 )
    {
	int err;

	err = socket_write(fd, write_queue[0]);

	if ( err == EEALREADY )
	{
            // write_callback will get called automatically.
            blocked = 1;
	    return;
	}
        if ( err == EEWOULDBLOCK )
        {
            // write_callback needs to get called manually.
            blocked = 1;
            call_out("write_callback",1,fd);
            return;
        }

	/*
	** Remove the item from the queue.  It has been written.
	*/
	write_queue = write_queue[1..];

	if ( err == EECALLBACK )
	{
	    /* done for now... wait for the next callback */
	    blocked = 1;
	    return;
	}
	if ( err < 0 )
	{
	    error("could not write: " + socket_error(err) + "\n");
	}	
    }
}

/* private */ nomask void release_callback(int fdToAcquire)
{
    int err;

    fdOwned = fdToAcquire;
    err = socket_acquire(fdOwned,
			 (: read_callback :),
			 (: write_callback :),
			 (: close_callback :));
    if ( err < 0 )
	error("could not release: " + socket_error(err) + "\n");

    /*
    ** Deliver a 0 indicating a new connection (and providing self)
    */
    catch(evaluate(read_func, this_object(), 0));
}


//### need a way to protect this from random writes
varargs nomask void send(mixed message, string address)
{
    int	err;

    if ( address )
	err = socket_write(fdOwned, message, address);
    else if ( blocked )
    {
	/*
	** If we are blocked, then the socket doesn't want us to send
	** any more.  Place it on our queue for sending later.
	*/
	write_queue += ({ message });
    }
    else
    {
	while ( sizeof(message) )
	{
	    err = socket_write(fdOwned, message);

	    if ( err == EEALREADY )
	    {
		// write_callback will get called automatically.
		blocked = 1;
		write_queue += ({ message });
		return;
	    }
	    if ( err == EEWOULDBLOCK )
	    {
		// write_callback needs to get called manually.
		blocked = 1;
		write_queue += ({ message });
		call_out("write_callback", 1, fdOwned);
		return;
	    }
	    if ( err == EECALLBACK )
	    {
		/*
		** Socket took the message but is blocked until it can
		** write it out.  Set a flag so that we don't write any
		** more until we get the callback.
		*/
		blocked = 1;
		return;
	    }

	    message = "";
	}
    }

    if ( err < 0 )
	error("could not write: " + socket_error(err) + "\n");
}

void remove()
{
    int err;

    if ( fdOwned >= 0 )
    {
	err = socket_close(fdOwned);
	//if ( err < 0 ) logging could go here
		
    }

    destruct(this_object());
}

nomask mixed *address()
{
    string tmp;
    string host;
    int port;

    tmp = socket_address(fdOwned);
    sscanf(tmp, "%s %d", host, port);
    return ({ host, port });
}

nomask int local_port()
{
  string address;
  int port;
  sscanf(socket_address(fdOwned), "%s %d", address, port);
  return port;
}

nomask string local_address() {
  string address;
  int port;
    sscanf(socket_address(fdOwned), "%s %d", address, port);
  return address;
}

void create(int typewhichisnotused,mixed addy, mixed readfcn , mixed closefcn) {
	int err;
#ifdef IMC_LIMA
	set_privilege(1);
#endif
    	if (!clonep()) return;
    	read_func  = readfcn;
    	close_func = closefcn;
   	fdOwned = socket_create(1 /* STREAM */,
		(: read_callback :),
		(: close_callback :));
	if ( fdOwned < 0 )
		error("could not create socket: " + socket_error(fdOwned) + "\n");
	err = socket_connect(fdOwned, addy, "read_callback", "write_callback");
	if ( err < 0 )
	    error("could not listen to socket: " + socket_error(err) + "\n");
}
