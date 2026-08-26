#ifndef __SMTP_H__
#define __SMTP_H__

#define SMTP_HOST "127.0.0.1"
#define SMTP_PORT 25
#define MUD_IP_NAME "snafu.net.au"

#undef DEBUG

#ifdef DEBUG
#define TPC(s) tell_object(find_player("shaydz"), s)
#else
#define TPC(s)
#endif

#endif /* __SMTP_H__ */
