// Last edited by deforce on 03-31-2010
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
#include <playerflags.h>

inherit "/std/buff";

void create(int duration)
{
   buff::create();

   set_buff_duration(duration);
}

void apply_buff(object target)
{
   tell(target, "%^BOLD%^%^RED%^You can no longer feel the Force.%^RESET%^\n");
}

void remove_buff(object target)
{
   tell(target, "%^BOLD%^You can feel the Force around you once again.%^RESET%^\n");
}