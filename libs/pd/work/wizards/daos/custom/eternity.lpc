#include <std.h>

inherit ARMOUR;

void create() {    
    ::create();
    set_properties( (["no steal" : 1 ]) );
    set_name("ring");
    set("id", ({"ring", "ring of eternity"}) );
    set_short("%^BOLD%^Ring of%^RESET%^ %^RED%^Eternity%^RESET%^");
    set_long("%^BOLD%^BLACK%^As you look into the stone, you see the past "
      "of many white paladins fighting hordes of demons to keep this world "
      "safe.  As you watch the vision that the ring shows, you notice it "
      "focuses on a particular paladin.  You look closer for a better look, and "
      "you notice who it was.  It was the greatest paladin who brought down the "
      "demon king.  And the paladin's name is... Shizim.");
    set_type("ring");
    set_limbs( ({"right hand", "left hand"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "shizim")
	return 1;
}
