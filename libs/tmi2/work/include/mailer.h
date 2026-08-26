#ifndef __MAILER_H
#define __MAILER_H
 
#define OWNERDELETED          1
#define MAIL_READ             2
 
#ifndef NETMAIL_D
#include "net/daemons.h"
#endif

#define MAILER "/adm/obj/mailer"

#define TRUSTED_MAILERS ({ MAILER, BOARD, NETMAIL_D })
 
#define MAILDIR "/data/mail/"
#define NETMAIL_DIR "/data/mail/net/"
#define MAILER_SHORT "/doc/mudlib/mailer_short"
#define MAILER_LONG "/doc/mudlib/mailer_long"
#define MAIL_BOUNCE_FILE "/adm/etc/bounced_mail"
 
#define MAILMESG_D "/adm/daemons/mailmesg"
#define MAILBOX_D "/adm/daemons/mailbox"
#define MBOXDIR "/data/mail/mbox/"
#define MESGDIR "/data/mail/mesg/"
#endif //__MAILER_H
