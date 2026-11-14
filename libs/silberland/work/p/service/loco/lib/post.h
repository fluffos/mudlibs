#define MAILER "/mail/mailer"
#define STDPOST "/p/service/loco/std/post"
#define TESTMAILER "/mail/testmailer"
#define MAILCABIN "/p/service/loco/std/mailcabin"
#define NEDIT "/mail/nedit"
#define NRCABINS 2
#define SAVEFILENAME ("/open/"+geteuid(this_player())+".mail")
#define LONGHELP "/p/service/loco/doc/post"
#define MAILDEMON "/secure/mailer"
#define ALIASFILE(name) ("/players/"+name+"/.mailrc")
#define SYSALIAS "/mail/system.mailrc"

// Paketpost
#define PARCEL "/p/service/loco/obj/parcel"
#define STAMPSERV "/p/service/loco/lib/stampserv"
#define STAMP "/p/service/loco/obj/marke"
#define PARCELSERVER "/p/service/loco/lib/parcelserver"
#define STAMPSAVEPATH "/p/service/loco/save/stamps/"
#define COUNTER "/p/service/loco/std/schalter"

// Versendeerlaubnis
#define P_POST             "Post"
#define PP_FORBIDDEN       -2     // verboten
#define PP_NO_EXPRESS      -1     // Nicht als Kurierpaket
#define PP_DEFAULT          0     
#define PP_NORMAL_ALLOWED   1     // postlagernd erlaubt, Kurierp. nach Default
#define PP_ALLOWED          2     // Auf jeden Fall erlaubt
