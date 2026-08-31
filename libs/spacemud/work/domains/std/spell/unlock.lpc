/* Do not remove the headers from this file! see /USAGE for more info. */

#include <spells.h>

inherit SPELL;

void setup()
{
   set_name("unlock");
   set_category("transmutation");
   set_level(1);
   set_description("This spell has a chance of unlocking a non-magical lock. The chance of success is based on the "
                   "caster's skills, and the difficulty of the lock.");
   set_targets(TARGET_ITEM);
}

void cast_spell(object ob, object reagent, int success)
{
   mixed result = ob->magic_unlock();

   if (stringp(result))
   {
      this_body()->simple_action("$N $vcast a spell on $o...", ob);
      write(result);
   }
   else if (!result)
   {
      this_body()->simple_action("$N $vtry to unlock $o with a spell, but fails.", ob);
   }
   else
   {
      this_body()->simple_action("$N $vunlock $o with a spell.", ob);
   }
}

mixed valid_target(object ob)
{
   /* the target must be lockable() */
   return ob && ob->is_lockable();
}

mixed valid_reagent(object ob)
{
   return !ob || "That wouldn't help the spell any.\n";
}

mixed valid_circumstances(mixed target, mixed reagent)
{
   if (!target)
      return "You need to cast the spell on something.\n";
   if (reagent)
      return "That won't help your unlock spell.\n";
   return 1;
}
