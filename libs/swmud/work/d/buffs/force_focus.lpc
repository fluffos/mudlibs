// Last edited by deforce on 10-10-2009
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

function my_hook;
int bonus_amount;

void create(int bonus, int duration)
{
   buff::create();

   bonus_amount = bonus;

   set_buff_duration(duration);
}

int query_bonus_amount()
{
   return bonus_amount;
}

void apply_buff(object target)
{
   my_hook = (: query_bonus_amount :);
   target->add_hook("force_focus", my_hook);

   tell(target, "You are now focusing on the Light side of the Force.\n");
}

void remove_buff(object target)
{
   target->remove_hook("force_focus", my_hook);

   tell(target, "%^BOLD%^You are no longer focusing on the Light side of the Force.%^RESET%^\n");
}