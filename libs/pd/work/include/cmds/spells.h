#ifndef __SPELLS__
#define __SPELLS__

int spell_check(object ob)
{
 if (this_player()->query_ghost())
   return notify_fail("You are a ghost!\n");
if (ob->query_ghost())
   return notify_fail("You cannot attack ghostly things.\n");
 if (!ob->is_living())
   return notify_fail("You can only attack living things.\n");
 if (environment(this_player())->query_property("no attack"))
   return notify_fail("You cannot attack in such a peaceful place.\n");
 if (environment(this_player())->query_property("no magic"))
   return notify_fail("Your magic cannot be casted here.\n");
 if (this_player()->query_disable())
   return notify_fail("You are busy doing something else.\n");
 return 1;
}

#endif
