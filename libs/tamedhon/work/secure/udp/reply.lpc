/* SilberLand MUDlib
 *
 * /secure/udp/reply.c -- UDP reply
 *
 * $Date: 1997/03/16 00:16:08 $
 * $Revision: 1.1 $
 * $Log: reply.c,v $
 * Revision 1.1  1997/03/16 00:16:08  Woody
 * prepared for revision control
 *
 */

#include <udp.h>

#ifdef ZEBEDEE
#include <defs.h>
#endif

#ifndef DATE
#define DATE	ctime(time())[4..15]
#endif

#define DEBUG(x) if (find_player("debugger")) tell_object(find_player("debugger"),x)
#undef DEBUG
#define DEBUG(x)

void udp_reply(mapping data) {
    string err;
    object ob;

    DEBUG(sprintf("reply: %O\n",data));

    if (data[SYSTEM]) {
        switch(data[SYSTEM]) {
            case TIME_OUT:
                if (data[SENDER]) {
                    if (stringp(data[SENDER]) && (ob = find_player(data[SENDER])))
                        tell_object(ob, "\ninetd: " + capitalize(data[REQUEST]) +
                                " request to " + (data[RECIPIENT] ?
                                    capitalize(data[RECIPIENT]) + "@" + data[NAME] :
                                    data[NAME]) + " timed out.\n");
                    else if (objectp(ob = data[SENDER]) ||
                            (ob = find_object(data[SENDER])))
                        ob->udp_reply(data);
                }
                return;
        }
    }
    if (data[RECIPIENT]) {
        /* If recipient is a player name, pass the message to them. */
        if (stringp(data[RECIPIENT]) && (ob = find_player(data[RECIPIENT])))
            tell_object(ob, "\n" + data[DATA] + "\n");
        /* Otherwise send it to udp_reply() in the recipient. */
        else if (objectp(ob) || (ob = find_object(data[RECIPIENT])))
        {
            DEBUG(sprintf(" --- SENDING TO %O %O %d\n",ob,data,objectp(ob)));
            ob->udp_reply(data);
            DEBUG("DONE");
        }
        return;
    }
    switch(data[REQUEST]) {
        case "ping":
            /* Ignore system ping replies. */
            return;

        case "query":
            switch(data["QUERY"])
            {
                case "encoding":
                    /* a host tells us its preferred encoding */
                    INETD->update_host_encoding(data[NAME],data[DATA]);
                    return;
                case "mud_port":
                    INETD->update_host_mud_port(data[NAME], data[DATA]);
                    return;
                case "list":
                    INETD->update_host_queries(data[NAME], data[DATA]);
                    return;
            }
            return;

        default:
            /* Log replies to the system. (ie. No RECIPIENT) */
            if (data[DATA])
                log_file(INETD_LOG_FILE, DATE + ": Reply from " + data[NAME] +
                        "\n" + data[DATA] + "\n");
            return;
    }
}

