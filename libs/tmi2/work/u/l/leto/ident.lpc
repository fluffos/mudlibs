/*
 * A simple client interface to Identification Protocol servers
 *   (was Authentication Service Protocol, RFC931 (obsolete))
 *
 * See RFC1413 (supercedes RFC931) for a full understanding of the protocol.
 * Some quotes from section 6 on "Security Considerations":
 *
 * ``The information returned by this protocol is at most as trustworthy
 *   as the host providing it OR the organization operating the host.''
 *
 * ``The Identification Protocol is not intended as an authorization or
 *   access control protocol.  At best, it provides some additional
 *   auditing information with respect to TCP connections.''
 *
 * ``The use of the information returned by this protocol for other than
 *   auditing is strongly discouraged.''
 *
 * Note: this client is not fully conformant (robust) with the
 *   specification, for example: it expects US-ASCII character set, and
 *   does not process octet strings
 *
 * ident.c by Robocoder 95.03.15 - another tool for evil admin logging >=)
 */

#include <config.h>

#define __tmi__
#ifdef __tmi__

/* assume TMI */

#  include <mudlib.h>
#  include <uid.h>
#  include <net/socket.h>
#  include <logs.h>
#  include <driver/socket_err.h>
#  include <driver/runtime_config.h>
#  include <driver/origin.h>

inherit DAEMON;

#endif

#ifdef __nightmare__

#  include <std.h>
#  include <dirs.h>
#  include <daemons.h>
#  include <network.h>
#  include <security.h>

inherit DAEMON;

#define LOG_DIR DIR_LOGS "/"

#endif


#ifndef NET_IDENT_H
#define NET_IDENT_H

#ifndef IDENT_LOG
#define IDENT_LOG "IDENT"
#define IDENT_ERR_LOG "IDENT.err"
#endif

#define MAX_USER_ID_LEN         128
#define TIMEOUT_AUTH_INTERVAL   (60)
#define TIMEOUT_AUTH_CHECK      (5 * 60)

#endif /* NET_IDENT_H */

#define AUTH_PORT       113

#define IDENT_GAVE_UP   1
#define IDENT_TIMED_OUT 2

mapping noident;
mapping sockinfo;

#define LOCAL_ID(f) sockinfo[(f)][0]
#define ID_OWNER(f) sockinfo[(f)][1]
#define CALLBACK(f) sockinfo[(f)][2]
#define TREQUEST(f) sockinfo[(f)][3]
#define SOCKADDR(f) sockinfo[(f)][4]

/*
 * some prototypes for local functions
 */
void write_cb(int fd, string str);
void close_cb(int fd);

/*
 * initialization
 */
void create() {

#ifdef __tmi__
    seteuid(ROOT_UID);
#endif

#ifdef __nightmare__
    daemon::create();
    set_no_clean(1);
#endif

    sockinfo = ([ ]);
    noident = ([ ]);
    call_out("check_connections", TIMEOUT_AUTH_CHECK);
}

/*
 * initiate an Ident lookup with the remote server
 *
 * Inputs:
 *   id - name of user, if ob_or_fd is the player object
 *      - name of daemon requesting the service, if ob_or_fd is a socket
 *   ob_or_fd - an object or a socket descriptor (see above)
 *   myport - the local endpoint of the socket connection;
 *            usually the mud login port
 *   callback - an optional callback function of the form:
 *
 *      void mycallback(mixed ob_or_fd, string user_id);
 *
 *            - where ob_or_fd is a copy of what ident was given
 *              and user_id is the response from a successful query
 *            - note: the callback is _only_ called when an ident query
 *              was successful
 */
void ident_user(string id, mixed ob_or_fd, int myport, mixed callback) {
    string addr;
    int myfd, ret, i;

    if (!id)
        return;

    if (!myport)
        myport = __PORT__;

    if (stringp(callback))

// Leto
        callback = (: previous_object(), $(callback) :);

    if (callback && !functionp(callback))
        return;

    if ((addr = socket_address(ob_or_fd)) == "0.0.0.0 0")
        return;

    if ((myfd = socket_create(STREAM, "read_cb", "close_cb")) < 0)
        return;

    /*
     * socket_connect() usually always succeeds since inetd super server
     * handles initial connection before launching the ident server
     */
    if (socket_connect(myfd,
          sprintf("%s%d", addr[0..i = strsrch(addr, ' ')], AUTH_PORT),
          "read_cb", "write_cb") != EESUCCESS) {
        socket_close(myfd);

        /* log error */
        write_file(LOG_DIR IDENT_LOG,
              sprintf("[%s] %s@%s CONNECT REFUSED\n", ctime(time())[4..15],
                    LOCAL_ID(myfd), SOCKADDR(myfd)));
        return;
    }

    sockinfo[myfd] = ({ id, ob_or_fd, callback, time(), addr[0..i-1] });

    write_cb(myfd, sprintf("%s, %d\r\n", addr[i+1..<1], myport));
}

/*
 * receive ident response
 *
 * format of response (string):
 *     their_port, our_port : USERID : operating_system : user_id
 *     their_port, our_port : USERID : OTHER : user_id_octet_string
 *     their_port, our_port : ERROR : INVALID-PORT
 *     their_port, our_port : ERROR : NO-USER
 *     their_port, our_port : ERROR : HIDDEN-USER
 *     their_port, our_port : ERROR : UNKNOWN-ERROR
 *
 * NB: we don't log errors...
 */
void read_cb(int fd, string str) {
    int i;
    string user_id;

    if (undefinedp(sockinfo[fd]) || origin() != ORIGIN_DRIVER)
        return;

    if ((i = strsrch(str, "USERID")) != -1) {
        /* get the user_id portion of the response */
        i = strsrch(str, ':', i);
        user_id = str[i..<3]; /* skip trailing "\r\n" */
        if (strlen(user_id) > MAX_USER_ID_LEN)
            user_id = user_id[0..MAX_USER_ID_LEN-1];

        /* log ident */
        write_file(LOG_DIR IDENT_LOG,
              sprintf("[%s] %s@s%s\n", ctime(time())[4..15],
                    LOCAL_ID(fd), SOCKADDR(fd), user_id));

        /* perform callback (if possible) */
        if (CALLBACK(fd) && ID_OWNER(fd))
              (*CALLBACK(fd))(ID_OWNER(fd), user_id);
    } else if ((i = strsrch(str, "ERROR")) != -1) {
        i = strsrch(str, ':', i);

        /* log error */
        write_file(LOG_DIR IDENT_LOG,
              sprintf("[%s] %s@%s error%s\n", ctime(time())[4..15],
                    LOCAL_ID(fd), SOCKADDR(fd), str[i..<3]));
    }
    close_cb(fd);
}

/*
 * send ident request to remote server
 */
void write_cb(int fd, string str) {
    int ret;

    if (undefinedp(sockinfo[fd]) ||
//          !(origin() & (ORIGIN_DRIVER | ORIGIN_LOCAL)))
	 ( (origin() != ORIGIN_DRIVER) && (origin()!=ORIGIN_LOCAL) ) )
        return;

    if ((ret = socket_write(fd, str)) == EESUCCESS ||
          ret == EECALLBACK)
        /* wait for the reply */
        ;
 else if (ret == EEWOULDBLOCK || ret == EEALREADY)
        /* can't service request at this time...try again later */
        call_out("write_cb", 15, str);
    else {
        /*
         * can't service request at all...just give up;
         * log it only if we haven't logged it before
         */
        if (undefinedp(noident[SOCKADDR(fd)])) {
            write_file(LOG_DIR IDENT_ERR_LOG,
                  sprintf("[%s] %s@%s: GAVE UP", ctime(time())[4..15],
                        LOCAL_ID(fd), SOCKADDR(fd)));
            noident[SOCKADDR(fd)] = IDENT_GAVE_UP;
        }
        close_cb(fd);
    }
}

/*
 * close socket, and take care of internal accounting
 */
void close_cb(int fd) {
    if (undefinedp(sockinfo[fd]) ||
(  (origin()==ORIGIN_DRIVER)||(origin()==ORIGIN_LOCAL) ) )
        return;

    map_delete(sockinfo, fd);
    socket_close(fd);
}

/*
 * periodically scan sockinfo for timed-out ident requests
 * (ie response not received)
 */
void check_connections() {
    int *fds, s;

    if (fds = keys(sockinfo)) {
        s = sizeof(fds);
        while (s--)
            /* timed-out...remove */
            if ((TREQUEST(fds[s]) + TIMEOUT_AUTH_INTERVAL) > time()) {
                close_cb(fds[s]);

                /* log it only if we haven't logged it before */
                if (undefinedp(noident[SOCKADDR(fds[s])])) {
                    write_file(LOG_DIR IDENT_ERR_LOG,
                          sprintf("[%s] %s@%s: TIMED OUT",
                                ctime(time())[4..15], LOCAL_ID(fds[s]),
                                SOCKADDR(fds[s])));
                    noident[SOCKADDR(fds[s])] = IDENT_TIMED_OUT;
                }
            }
    }
    call_out("check_connections", TIMEOUT_AUTH_CHECK);
}

/* eof */
