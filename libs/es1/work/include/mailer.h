#ifndef __MAILER_H
#define __MAILER_H
 
#define OWNERDELETED          1
#define MAIL_READ             2
 
#ifndef NETMAIL_D
#include "net/daemons.h"
#endif

#define MAILER2 "/d/eastland/easta/post_office"
#define MAILER "/adm/obj/mailer"
#define BOARD "/std/board/bboard"
#define POST_OFFICE "/d/noden/farwind/post_office"
#define CMD_FROM "/cmds/wiz/_from"
#define CMD_MAIL "/cmds/wiz/_mail"

#define TRUSTED_MAILERS ({ MAILER, BOARD, NETMAIL_D, POST_OFFICE, \
	CMD_FROM, CMD_MAIL, MAILER2 })
 
#define MAILDIR "/data/mail/"

#define NETMAIL_DIR "/data/mail/net/"
#define MAILER_SHORT "/doc/mudlib/mailer_short"
#define MAILER_LONG "/doc/mudlib/mailer_long"
#define MAIL_BOUNCE_FILE "/adm/etc/bounced_mail"
 
#define MAILMESG_D "/adm/daemons/mailmesg"
#define MAILBOX_D "/adm/daemons/mailbox"
#define MBOXDIR "/data/mail/mbox/"
#define MESGDIR "/data/mail/mesg/"

#define user_mbox_file(x) (MBOXDIR+(x[0..0])+"/"+(x))
#define mail_mesg_file(x) (MESGDIR+"mesg."+x)

#endif //__MAILER_H
