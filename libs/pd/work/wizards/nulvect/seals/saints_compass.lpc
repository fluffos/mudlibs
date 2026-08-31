#include <std.h>
#include <amun.h>
#include <locations.h>
inherit SEAL;
void create() {
    ::create();
    set_id(({"compass", "saints", "saints compass"}));
    set_name("Saints Compass");
    set_long("%^RESET%^%^ORANGE%^This Compass is a copper color except the middle, there is a %^BOLD%^%^WHITE%^clear misty center %^RESET%^%^ORANGE%^where it will flash the area it is marked for.%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^S%^WHITE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^t%^WHITE%^s %^RESET%^%^ORANGE%^C%^BOLD%^%^WHITE%^o%^RESET%^ORANGE%^m%^BOLD%^%^WHITE%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^s%^RESET%^");
    set_weight(1);
    set_curr_value("gold", 1000);
  set_guild("lastsaints");
  set_seal_max(20);
  set_mark_command("direct");
  set_break_command("crack");
  set_marked_short("a "+query_short()+" ($L)");
  set_marked_long(query_long("")[0..<11]+":\n\n$L\n");
  set_break_msg("%^BOLD%^%^WHITE%^You take the compass in both your hands and crack it.");
  set_break_room_msg("%^BOLD%^%^WHITE%^$N takes the compass in both their hands and cracks it.");
  set_finish_msg("\n%^BOLD%^%^YELLOW%^A bright light surrounds you!\n");
  set_finish_room_msg("%^BOLD%^%^YELLOW%^A bright light surrounds $N!");
}

int is_sphere() { return 1; }
