#include <std.h>
#include <locations.h>
inherit SEAL;

void create() {
   ::create();
     set_id(({"sphere", "glass", "glass sphere"}));
     set_name("glass sphere");
     set_long("A perfect sphere of glass. The inside is flawless and so clear as to be almost invisible.");
     set_short("%^BOLD%^WHITE%^a G%^RESET%^l%^BOLD%^a%^RESET%^s%^BOLD%^s %^RESET%^s%^BOLD%^p%^RESET%^h%^BOLD%^e%^RESET%^r%^BOLD%^e%^RESET%^");
     set_weight(1);
     set_curr_value("gold", 500);
  set_guild("illuminati");
  set_seal_max(20);
  set_break_command("smash");
  set_mark_msg("\n%^BOLD%^%^WHITE%^You focus on the sphere and it slowly fills with a light mist.\n");
  set_marked_short(query_short()+" %^BOLD%^($L)");
  set_marked_long("A perfect sphere of glass. The inside is filled with a white mist, it slowly coalesces into an image:\n\n$L\n");
  set_break_msg("%^BOLD%^%^WHITE%^You heft the sphere above your head, then smash it on the ground.\nA white mist begins to form.");
  set_break_room_msg("%^BOLD%^%^WHITE%^$N holds a glass sphere over his head, then abruptly smashes it on the ground.\nA white mist begins to form.");
  set_finish_msg("\n%^BOLD%^%^WHITE%^A white mist engulfs you!\n");
  set_finish_room_msg("%^BOLD%^%^WHITE%^A white mist engulfs $N!");
}

int is_sphere() { return 1; }
