#include <std.h>
#include <vampq.h>
#include <mjungle.h>
#include <gcity.h>

inherit BAG;

void create() {
    object cloak;
	object message;
    ::create();
    set_name("coffin");
    set_id( ({ "coffin", "a coffin" }) );
    set_short("%^RESET%^%^ORANGE%^An old coffin%^RESET%^");
    set_long("With the lid pushed aside... %^RED%^Crimson red fabric%^RESET%^ has lined the entire coffin. A small headrest at the top end made from the same %^RED%^material%^RESET%^. It is certinaly a grand %^ORANGE%^coffin%^RESET%^ and whoever's it was indeed had the money to afford such craftsmanship.\n\n");
	set_possible_to_close(1);
    set_lock("locked");
    set_key("blood_key");
	set_lockable(1);
    set_mass(10);
    set_max_internal_encumbrance(10);
    set_value(0);
    set_prevent_get("How are you going to carry a bloody coffin?");
    cloak = new(VO "daywalker_cloak");
    cloak->move(this_object());
	message = new(VO"message");
	message->move(this_object());
    set_closed(1);
}

string query_long_closed() {
	if (query_closed()) return "%^RESET%^%^ORANGE%^The coffin is coverd in sand%^RESET%^\n\nAfter you wipe some of it off you notice the grand craftsmanship. Detailed images of what seems to be a story are carved right into the lid.\n\n%^BOLD%^%^RED%^Along the side a latch with a tiny lock hangs.%^RESET%^";
	else return "With the lid pushed aside... %^RED%^Crimson red fabric%^RESET%^ has lined the entire coffin. A small headrest at the top end made from the same %^RED%^material%^RESET%^. It is certinaly a grand %^ORANGE%^coffin%^RESET%^ and whoever's it was indeed had the money to afford such craftsmanship.\n\n";
	
}
