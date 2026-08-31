#include <std.h>
#include <illuminati.h>

inherit "/wizards/nulvect/seals/seal";

void create() {
 ::create();
   set_name("seal");
   set_short("Seal of the Illuminati");
   set_long("A stone seal depicting the Tower of Light.");
   set_weight(1);
   set_curr_value("gold", 150);
   set_id(({ "seal", "illuminati seal" }));
  set_guild("illuminati");
  set_marked(1);
  set_seal_max(10);
  set_marked_label("illuminati");
  set_marked_filename(ILROOM"newhall");
  set_marked_short(query_short());
  set_marked_long(query_long(""));
  set_marked_id(query_id());
  set_mark_msg("This seal cannot be marked.");
  set_meld_msg("The stone seal of the Illuminati cracks and falls apart.");
  set_break_msg("%^YELLOW%^Mystical energies engulf you!\n");
  set_break_room_msg("%^YELLOW%^Mystical energies engulf $N!\n");
  set_finish_msg("\n%^YELLOW%^You appear in the Illuminati Hall!\n");
  set_finish_room_msg("%^YELLOW%^$N vanishes from sight$R!");
}
