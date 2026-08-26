// channels.h
#ifndef __CHANNELS_H
#define __CHANNELS_H

#define ADD 1
#define KIL 2
#define CRE 3
#define DEL 4

#define CHANNELS_CONFIG "/adm/etc/channels"
#define CHANNELS_LOG "CHANNELS"
#define CHANNELS_D	"/adm/daemons/channels"

#define CHANNELS_INFO ({ "", "plural", "priv", "object" })

#define TCH (find_player("foobar"))
#define TELL(x) if( TCH ) tell_object( TCH, x + "\n" )

#define NO_NEW_CHANNELS

#endif /* __CHANNELS_H */
