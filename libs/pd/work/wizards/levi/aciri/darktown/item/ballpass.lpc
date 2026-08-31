#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_id(({"ballpass", "invitation", "card" }));
   set_name("ballpass");
   set_short("%^BOLD%^A Silver Invitation Card%^RESET%^");
   set_long("%^BOLD%^Whoever made this card went through a lot of trouble.  The card itself is "
       "composed of silver plates with a couple of hinges linking them "
       "together.  Onyx letters have been stamped onto it's surface and read: "
       "%^BLACK%^You hereby have been invited to attend the ball of Cain." );
   
}

int query_auto_load() { if (this_player()->query_level() >=1) return 1; 
}
