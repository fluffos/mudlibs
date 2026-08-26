// Last edited by deforce on 10-07-2008
#include <playerflags.h>

inherit "/std/buff";

void clear_flag(int);
void assign_flag(int, int);

function my_hook;
int reduction;

void create(int amount, int duration)
{
   buff::create();

   reduction = amount;

   set_buff_duration(duration);
}

int query_reduction()
{
   return reduction;
}

void apply_buff(object target)
{
   my_hook = (: query_reduction :);
   target->add_hook("force_reflect", my_hook);
   target->set_flag(F_FORCE_REFLECT);

   target->simple_action("$N $vsurround $r with a reflective shield of the Force.\n");
}

void remove_buff(object target)
{
   target->remove_hook("force_reflect", my_hook);
   target->clear_flag(F_FORCE_REFLECT);

   target->other_action("The reflective Force shield surrounding $N dissipates.\n");
   tell(target, "%^BOLD%^Your reflective Force shield dissipates.%^RESET%^\n");
}