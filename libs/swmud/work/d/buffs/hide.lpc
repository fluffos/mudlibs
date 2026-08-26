// Last edited by deforce on 10-24-2009
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
#include <flags.h>

inherit "/std/buff";

void assign_flag(int which, int state);
void clear_flag(int which);

void create(int duration)
{
   buff::create();

   set_buff_duration(duration);
}

void apply_buff(object target)
{
   target->assign_flag(F_HIDDEN, 1);

   tell(target, "You hide in the shadows.\n");
}

void remove_buff(object target)
{
   target->clear_flag(F_HIDDEN);

   tell(target, "%^BOLD%^You are no longer hidden.%^RESET%^\n");
}