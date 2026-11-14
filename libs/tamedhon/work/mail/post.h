// SilberLand MUDlib
//
// /mail/post.h -- mail system header file
//
// $Date: 1997/03/16 19:51:38 $
/* $Revision: 1.1 $
 * $Log: post.h,v $
 * Revision 1.1  1997/03/16 19:51:38  Woody
 * prepared for revision control
 *
 */

#ifndef __MAIL_POST_H__
#define __MAIL_POST_H__

// Files der Post

#define MAILER "/mail/mailer"
#define STDPOST "/p/service/loco/std/post"
#define TESTMAILER "/mail/testmailer"
#define MAILCABIN "/p/service/loco/std/mailcabin"
#define NEDIT "/mail/nedit"
#define SAVEFILENAME ("/open/"+geteuid(this_player())+".mail")
#define LONGHELP "/p/service/loco/doc/post"
#define MAILDEMON "/secure/mailer"
#define ALIASFILE(name) ("/players/"+name+"/.mailrc")
#define SYSALIAS "/mail/system.mailrc"
#define FWSERV "/p/service/loco/obj/fwserv"
#define FWSAVESERV "/p/service/loco/obj/fwsaveserv"
#define FWSAVEFILE(x) ("/p/service/loco/save/forwards/"+x)

// Konfiguration

#define NRCABINS 2                   // Anzahl Schreibkabinen pro Postamt
#define MAIL_SUPPORT_BCC             // bcc's in '-name'-Syntax (MG)
#define MAIL_QUERY_BCC               // bcc's abfragen (NF)

// Files fuer die Paketpost

#define PARCEL "/p/service/obj/parcel"
#define STAMPSERV "/p/service/lib/stampserv"
#define STAMP "/p/service/obj/marke"
#define PARCELSERVER "/p/service/lib/parcelserver"
#define STAMPSAVEPATH "/p/service/save/stamps/"
#define COUNTER "/p/service/std/schalter"

// Versendeerlaubnis
// Fuer Raeume: Darf hierher ein Kurierpaket geschickt werden?
// Fuer Objekte: Darf es in Paketen verschickt werden?
// Anwendung: SetProp(P_POST, wert);

#define P_POST             "Post"
#define PP_FORBIDDEN       -2     // verboten
#define PP_NO_EXPRESS      -1     // Kurierpaket verboten, postl. nach Default
#define PP_DEFAULT          0     
#define PP_NORMAL_ALLOWED   1     // postlagernd erlaubt, Kurierp. nach Default
#define PP_ALLOWED          2     // Auf jeden Fall erlaubt

#endif

