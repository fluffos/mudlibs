/* Do not remove the headers from this file! */
/**
  * socket.c
  *
  * This object represents an open UDP/TCP socket using the MudOS
  * socket facilities.  Borrowed from The Lima Mudlib with permission
  * from Beek.
  *
  * 09-Feb-95. Deathblade. Created.
  * 05-Jan-96. Cowl. Added STREAM BINARY connect and listen styles
  * 12-Jul-96. Rust. Added write callback.
  * 02-Jun-98. Sebastian.  Ported to Dragon Mudlib
  */

#include <net/socket.h>

nosave private int      style;
nosave private int      fdOwned = -1;   /* no socket yet */
nosave private function read_func;
nosave private function close_func;
nosave private function write_func;
nosave private mixed *  write_queue = ({ });
nosave private int blocked;

/* For debug purposes only */
nosave private mixed addr;

void error(string str) {
    log_file("socket", str);
}

void set_write_callback(function f)
{
    write_func = f;
}

int stat_me()
{
    string stat;

    switch ( style )
    {
    case SKT_STYLE_LISTEN:
        stat = sprintf("%O: listening at %O\n", this_object(), addr);
        stat += sprintf("    read_func=%O  close_func=%O\n",
          read_func, close_func);
        break;

    case SKT_STYLE_CONNECT:
        stat = sprintf("%O: connected to %O\n", this_object(), addr);
        stat += sprintf("    read_func=%O  close_func=%O\n", read_func,
          close_func);
        break;

    case SKT_STYLE_UDP:
        stat = sprintf("%O: UDP at %O\n", this_object(), addr);
        stat += sprintf("    read_func=%O\n", read_func);
        break;

    case SKT_STYLE_LISTEN_M:
        stat = sprintf("%O: (mud) listening at %O\n", this_object(), addr);
        stat += sprintf("    read_func=%O  close_func=%O\n", read_func,
          close_func);
        break;

    case SKT_STYLE_CONNECT_M:
        stat = sprintf("%O: (mud) connected to %O\n", this_object(), addr);
        stat += sprintf("    read_func=%O  close_func=%O\n", read_func,
          close_func);
        break;

    case SKT_STYLE_INT_ACQUIRE:
        stat = sprintf("%O: accepted connection from %s\n", this_object(),
          socket_address(fdOwned));
        stat += sprintf("    read_func=%O  close_func=%O\n", read_func,
          close_func);
        break;
    }

    if ( sizeof(write_queue) )
        stat = sprintf("queue: %O\n", write_queue);

    CHANNEL_D->do_channel(this_object(),"sys",stat);
    return 1;
}

private nomask void read_callback(int fd, mixed message) {
    catch(evaluate(read_func, this_object(), message));
}

private nomask void read_udp_callback(int fd, mixed message, string address)
{
    catch(evaluate(read_func, this_object(), message, address));
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

private nomask void write_callback(int fd)
{
    mixed tmp;

    /*
    ** No longer blocked (can accept new data).
    */
    if ( !sizeof(write_queue) && write_func && blocked )
    {
        write_queue = ({ evaluate(write_func, this_object()) });
    }

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
            error("could not write: " + socket_error(err));
        }
        else if ( write_func )
        {
            tmp = evaluate(write_func, this_object());
            if ( sizeof(tmp) )
                write_queue += ({ tmp });
        }
    }
}

nosave void release_callback(int fdToAcquire)
{
    int err;

    fdOwned = fdToAcquire;
    err = socket_acquire(fdOwned,
      (: read_callback :),
      (: write_callback :),
      (: close_callback :));

    if ( err < 0 )
        error("could not release: " + socket_error(err));

    /*
    ** Deliver a 0 indicating a new connection (and providing self)
    */
    catch(evaluate(read_func, this_object(), 0));
}

private nomask void listen_callback(int fd)
{
    object      s;
    int         err;

    fd = socket_accept(fd, (: read_callback :), (: write_callback :));
    s = new(SOCKET, SKT_STYLE_INT_ACQUIRE, read_func, close_func);
    err = socket_release(fd, s, "release_callback");
    if ( err < 0 )
        error("could not release: " + socket_error(err));
}

varargs nomask void send(mixed message, string address)
{
    int err;

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
            if ( write_func )
            {
                message = evaluate(write_func, this_object());
            }
        }
    }

    if ( err < 0 )
        error("could not write: " + socket_error(err));
}

void remove(string euid)
{
    int err;

    if ( fdOwned >= 0 )
    {
        err = socket_close(fdOwned);
        if ( err < 0 )
            log_file("socket", "could not close: " + socket_error(err));
    }

    //destruct(this_object());
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

string channel_id() { return "SOCKET"; }

void create(int skt_style, mixed p1, mixed p2, mixed p3)
{
    int err;

    if ( !clonep() )
        return;

    style = skt_style;
    addr = p1;

    switch ( style )
    {
    case SKT_STYLE_LISTEN:
        read_func = p2;
        close_func = p3;
        fdOwned = socket_create(1 /* STREAM */,
          (: read_callback :),
          (: close_callback :));
        if ( fdOwned < 0 )
            error("could not create socket: " + socket_error(fdOwned));
        if ( (err = socket_bind(fdOwned, p1)) < 0 )
            error("could not bind socket: " + socket_error(err));
        if ( (err = socket_listen(fdOwned, "listen_callback")) < 0 )
            error("could not listen to socket: " + socket_error(err));
        break;

    case SKT_STYLE_CONNECT:
        read_func = p2;
        close_func = p3;
        fdOwned = socket_create(1 /* STREAM */,
          (: read_callback :),
          (: close_callback :));
        if ( fdOwned < 0 )
            error("could not create socket: " + socket_error(fdOwned));
        err = socket_connect(fdOwned, p1, "read_callback", "write_callback");
        if ( err < 0 )
            error("could not listen to socket: " + socket_error(err));
        break;

    case SKT_STYLE_LISTEN_B:
        read_func = p2;
        close_func = p3;
        fdOwned = socket_create(3 /* STREAM BINARY */,
          (: read_callback :),
          (: close_callback :));
        if ( fdOwned < 0 )
            error("could not create socket: " + socket_error(fdOwned));
        if ( (err = socket_bind(fdOwned, p1)) < 0 )
            error("could not bind socket: " + socket_error(err));
        if ( (err = socket_listen(fdOwned, "listen_callback")) < 0 )
            error("could not listen to socket: " + socket_error(err));
        break;

    case SKT_STYLE_CONNECT_B:
        read_func = p2;
        close_func = p3;
        fdOwned = socket_create(3 /* STREAM BINARY */,
          (: read_callback :),
          (: close_callback :));
        if ( fdOwned < 0 )
            error("could not create socket: " + socket_error(fdOwned));
        err = socket_connect(fdOwned, p1, "read_callback", "write_callback");
        if ( err < 0 )
            error("could not listen to socket: " + socket_error(err));
        break;

    case SKT_STYLE_UDP:
        read_func = p2;
        fdOwned = socket_create(2 /* DATAGRAM */, (: read_udp_callback :));
        if ( fdOwned < 0 )
            error("could not create socket: " + socket_error(fdOwned));
        if ( (err = socket_bind(fdOwned, p1)) < 0 )
            error("could not bind socket: " + socket_error(err));
        break;

    case SKT_STYLE_LISTEN_M:
        read_func = p2;
        close_func = p3;
        fdOwned = socket_create(0 /* MUD */,
          (: read_callback :),
          (: close_callback :));
        if ( fdOwned < 0 )
            error("could not create socket: " + socket_error(fdOwned));
        if ( (err = socket_bind(fdOwned, p1)) < 0 )
            error("could not bind socket: " + socket_error(err));
        if ( (err = socket_listen(fdOwned, "listen_callback")) < 0 )
            error("could not listen to socket: " + socket_error(err));
        break;

    case SKT_STYLE_CONNECT_M:
        read_func = p2;
        close_func = p3;
        fdOwned = socket_create(0 /* MUD */,
          (: read_callback :),
          (: close_callback :));
        if ( fdOwned < 0 )
            error("could not create socket: " + socket_error(fdOwned));
        err = socket_connect(fdOwned, p1, "read_callback", "write_callback");
        if ( err < 0 )
            error("could not listen to socket: " + socket_error(err));
        break;

    case SKT_STYLE_INT_ACQUIRE:
        read_func       = p1;
        close_func      = p2;
        break;
    }
}
