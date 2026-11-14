// SilberLand MUDlib
//
// /p/service/obj/fwsaveserv.c -- Mail Forward Load/Save Server
//
// $Date: 1997/03/16 21:03:37 $
/* $Revision: 1.1 $
 * $Log: fwsaveserv.c,v $
 * Revision 1.1  1997/03/16 21:03:37  Woody
 * prepared for revision control
 *
 */

/***************************************************************************

 Forward-Server: Lade-/Speicherserver.
  Dieser Teilserver hat die Aufgabe, einzelne Teile der forwardliste 
  auf Anfrage zu laden und 

 Teil des MG-Mailsystems
 (C) 1996 Loco@Morgengrauen

 Es gilt dasselbe Copyright wie fuer mailer.c, bitte dort nachlesen.

***************************************************************************/

#include "/mail/post.h"

mixed data;

void create() {
  seteuid(getuid());
}

mapping LoadData(string file) {
  if (!stringp(file)||strlen(file)>1||file>"z"||file<"a")
    return 0;
  restore_object(FWSAVEFILE(file));
  return data;
}

int SaveData(string file, mapping what) {
//  if (geteuid(previous_object())!=geteuid()) return 0;
  data=what;
  save_object(FWSAVEFILE(file));
  data=0;
  return 1;
}
