/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** drop.c
**
*/

#include <move.h>
#include <mudlib.h>

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``throw <something>``
//  |  ``throw <something> at <something>``
//
//  Throw a grenade, throw it at something. Then run.
//
// .. TAGS: RST

varargs private nomask void throw_one(object ob, object target)
{
   mixed tmp;

   tmp = ob->do_throw(target);

   if (!tmp)
      tmp = target ? "That doesn't make a good weapon.\n" : "Someone else might pick it up...\n";

   if (stringp(tmp))
   {
      write(tmp);
      return tmp;
   }
}

void do_throw_obj(object ob)
{
   if (!try_to_acquire(ob))
      return;
   throw_one(ob);
}

void do_throw_obj_at_obj(object to_throw, object target)
{
   if (!try_to_acquire(to_throw))
      return;
   throw_one(to_throw, target);
}

void create()
{
   add_rules(({"OBJ:v", "OBS:v", "OBJ:v at OBJ"}));
}
