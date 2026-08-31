/* Do not remove the headers from this file! see /USAGE for more info. */

// Tsath, 2023

#define CHEST_GONE_IN 60

inherit CHEST;
inherit M_GRAMMAR;

object loot_for;
object env;
int dest_step = 0;
private
string *msgs = ({"The chest starts to disappear, becoming a bit translucent.", "The chest will be gone soon.",
                 "The chest has disappered."});

void destroy_loot_chest()
{
   if (dest_step < (sizeof(msgs) - 1))
   {
      // Is there player next to me
      if (env && present(loot_for, env))
         tell(loot_for, msgs[dest_step] + "\n");
      call_out("destroy_loot_chest", (CHEST_GONE_IN / (1 + sizeof(msgs))));
   }
   else
   {
      if (present(loot_for, env))
         tell(loot_for, msgs[dest_step] + "\n");
      remove();
   }

   dest_step++;
}

void setup(object player)
{
   if (player)
   {
      set_in_room_desc(genetive(player) + " loot chest is standing here");
      env = environment(player);
      loot_for = player;
   }
   else
      set_in_room_desc("A loot chest is standing here");

   set_attached(0);
   add_relation("in", VERY_LARGE);
   add_relation("on", VERY_LARGE);
   set_default_relation("in");
   call_out("destroy_loot_chest", (CHEST_GONE_IN / (1 + sizeof(msgs))));
}

mixed direct_open_obj()
{
   if (this_body() == loot_for)
      return 1;
   return "Not your loot chest, sorry.";
}

mixed indirect_get_obs_from_obj()
{
   if (this_body() == loot_for)
      return 1;
   return "Not your loot chest, sorry.";
}

mixed indirect_get_obj_from_obj()
{
   if (this_body() == loot_for)
      return 1;
   return "Not your loot chest, sorry.";
}

mixed indirect_put_obj_wrd_obj(object ob)
{
   return "You can only take from loot chests.";
}

mixed indirect_put_obs_wrd_obj()
{
   return "You can only take from loot chests.";
}