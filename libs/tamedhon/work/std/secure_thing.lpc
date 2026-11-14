// SilberLand MUDlib
//
// std/secure_thing.c -- thing.c fuer sicherheitsrelevante Objekte
//
// $Date: 1997/04/10 18:49:31 $
/* $Revision: 1.2 $
 * $Log: secure_thing.c,v $
 * Revision 1.2  1997/04/10 18:49:31  Woody
 * aktualisiert und noch sicherer gemacht :)
 *
 * Revision 1.1  1997/03/13 03:12:53  Woody
 * prepared for revision control
 *
 */

// thing.c fuer Objekte, die sicherheitsrelevant sind.
// Sollte von Dingen aus /secure oder Magiertools auf jeden
// Fall inherited werden!
// 14.06.93 Rumata

inherit "std/thing";
#include <properties.h>

mixed lies(string str)
{
  if (!str || !id(str)) return 0;
  if (this_player()->CannotSee()) return 1;
  if (QueryProp(P_READ_MSG))
    return write(funcall(QueryProp(P_READ_MSG))), 1;
  return 0;
}

int read(string str)
{
  return lies(str);
}

varargs string long()
{
  return funcall(QueryProp(P_LONG));
}

string short()
{
  if (QueryProp(P_INVIS)) return 0;
  if (QueryProp(P_SHORT))
    return funcall(QueryProp(P_SHORT))+".\n";
  return 0;
}
