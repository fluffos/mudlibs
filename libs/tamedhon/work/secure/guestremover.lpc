/* SilberLand MUDlib
 *
 * /secure/guestremover.c -- guest remover object
 *
 * $Date: 1997/04/10 18:25:34 $
 * $Revision: 1.2 $
 * $Log: guestremover.c,v $
 * Revision 1.2  1997/04/10 18:25:34  Woody
 * inherit secure_thing instead of thing
 *
 * Revision 1.1  1997/03/15 23:04:30  Woody
 * prepared for revision control
 *
 * 1996/11/19  Woody
 * Remove per callout, um doppelten "...hat verlassen" Text zu vermeiden
 *
 * 1996/10/12  Woody
 * Initial Revision
 */

/*
 * Sorgt dafuer, dass Gaeste beim netztot-werden destructed werden.
 */

inherit "/std/secure_thing";
#include <properties.h>
#include <moving.h>

void create()
{
  ::create();
  SetProp(P_WEIGHT, 0);
}

void RemoveEnv()
{
  catch(environment()->remove());
  if (objectp(environment())) destruct(environment());
  destruct(this_object());
}

void BecomesNetDead()
{
  call_out ("RemoveEnv", 1);
}

string short()
{
  return "";
}

varargs int move(mixed dest)
{
  if (explode(object_name(previous_object()), "#")[0]=="/secure/login")
    move_object(this_object(), dest);
  else
    return ME_CANT_BE_DROPPED;
  return 1;
}

