#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([
	"outdoors": 1,
	"lightning": 1,
	"light" : 1,
      ]));
}

void init() {
    ::init();
    if (this_player()->is_player()) {
	write("%^BOLD%^%^BLACK%^A %^YELLOW%^rogue %^RESET%^%^MAGENTA%^li%^BOLD%^%^WHITE%^gh%^YELLOW%^tn%^BLACK%^in%^RESET%^%^RED%^g b%^BOLD%^%^RED%^ol%^BLACK%^t strikes from under the %^WHITE%^clouds%^BLACK%^, hitting your body so %^RED%^hard %^BLACK%^you begin to sm%^WHITE%^o%^BLACK%^ke.%^RESET%^");
	this_player()->add_hp(200+random(50));
	this_player()->add_sp(-50+random(50));
	this_player()->add_mp(-50+random(50));
	remove_call_out("take_damage");
	call_out("take_damage", 120, this_player());
    }
}

int take_damage(object tp) {
    if (present(tp)) {
	tell_object(tp, "%^BOLD%^%^BLACK%^A %^YELLOW%^rogue %^RESET%^%^MAGENTA%^li%^BOLD%^%^WHITE%^gh%^YELLOW%^tn%^BLACK%^in%^RESET%^%^RED%^g b%^BOLD%^%^RED%^ol%^BLACK%^t strikes from under the %^WHITE%^clouds%^BLACK%^, hitting your body so %^RED%^hard %^BLACK%^you begin to sm%^WHITE%^o%^BLACK%^ke.%^RESET%^");
	tp->add_hp(-200+random(50));
	tp->add_sp(-50+random(50));
	tp->add_mp(-50+random(50));
	remove_call_out("take_damage");
	call_out("take_damage", 120, tp);
	return 1;
    }
}
