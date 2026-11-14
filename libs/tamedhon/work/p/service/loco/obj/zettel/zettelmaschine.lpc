// SilberLand MUDlib
//
// /p/service/obj/zettel/zettelmaschine.c -- Anfaengerzettelmaschine
//
// $Date: 1997/09/25 15:19:49 $
/* $Revision: 1.4 $
 * $Log: zettelmaschine.c,v $
 * Revision 1.4  1997/09/25 15:19:49  Woody
 * Material Papier
 *
 * Revision 1.3  1997/09/15 14:05:33  Woody
 * Ueberarbeitet, mitloggen von Nehmern
 *
 * Revision 1.2  1997/03/16 18:39:10  Woody
 * move() retourniert bei M_GET auf jeden Fall ME_CANT_BE_TAKEN
 * mit P_NOGET=="", ein work-around fuer das 'nimm alles' Problem :)
 *
 * Revision 1.1  1997/03/16 18:37:49  Woody
 * prepared for revision control
 *
 */

// /p/service/mupfel/zettel/zettelmaschine.c Eine Zettelmaschine
// Entstanden aus /p/service/loco/obj/buchautomat.c
// 23-04-95  - Mupfel@AnderLand -

inherit "/std/thing";

#include <properties.h>
#include <moving.h>

#define ZETTEL "/p/service/loco/obj/zettel/zettel"

int get(mixed targ);

void create()
{
  if(!clonep(this_object())) return;
  ::create();
  SetProp(P_SHORT, "Ein Zettel mit Hinweisen");
  SetProp(P_LONG, "Ein Zettel mit Hinweisen.\n");
  SetProp(P_NAME, "Hinweiszettel");
  AddId(({"zettel", "hinweiszettel", "obj$zettel$maschine"}));
  SetProp(P_GENDER, MALE);
  SetProp(P_ARTICLE, 1);
  SetProp(P_NOGET, "");
  SetProp(P_MATERIAL,MAT_PAPER);
}

varargs int move(mixed target,mixed method,mixed mess)
{
  if ((method & M_GET) && living(target))
    return get(target), ME_CANT_BE_TAKEN;
  else
    return ::move(target,method,mess);
}

int get(mixed targ)
{
  if (!targ || !interactive(targ) || targ != this_player())
    return 0;
  if (present("obj$zettel",this_player()))
  {
    write("Du benötigst nur einen Hinweiszettel.\n");
    return ME_CANT_BE_TAKEN;
  }
  clone_object(ZETTEL)->move(targ,M_GET);
  write("Du nimmst einen Zettel. "
      "Sofort erscheint auf unerklärliche Weise ein neuer.\n");
  say(targ->Name(WER,1) + " nimmt einen Zettel.\n", targ);
  log_file("zettel",
      dtime(time())+" : "+targ->Name()+" nimmt einen Zettel.\n");
  return 1;
}

