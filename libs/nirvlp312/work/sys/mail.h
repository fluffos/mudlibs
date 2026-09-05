#ifndef _sys_mail_h
#define _sys_mail_h

#define MAIL_PATH "/save/mail/"

#define POSTMASTER "obj/post_master"
#define IS_POSTMASTER(x) (object_name(x)==POSTMASTER)

#define MAILBOX "obj/mailbox"
#define IS_MAILBOX(x) (load_name(x)==MAILBOX)

#define POSTCLERK "obj/post_clerk"
#define IS_POSTCLERK(x) (load_name(x)==POSTCLERK)

#define INTERMUD_MAILER "etc/udp/mail"
#define IS_INTERMUD_MAILER(x) (object_name(x)==INTERMUD_MAILER)

#define MAILBOX_DUMMY "obj/mailbox_dummy"

#define MAILING_LISTS "room/mailing_lists"

#define MAIL_NEW "new"
#define MAIL_SENDER "sender"
#define MAIL_DATE "date"
#define MAIL_SUBJECT "subject"
#define MAIL_CC "cc"
#define MAIL_INFO "info"
#define MAIL_RECEIVERS "receivers"

#define INCOMING_FOLDER "INCOMING"
#define SENT_FOLDER "SENT"

#endif
