//  Created by Whit for Primal Darkness
#include <std.h>
#include <keep.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("gardener");
    set_short("a gardener, busy at work");
    set_long("The gardener runs around all day tending to the "
      "gardens of the keep.  Watering plants, trimming hedges, "
      "sweeping sidewalks.");
    set_id(({ "gardener" }));
    new(WEP+"trimmers")->move(this_object());
    force_me("wield trimmers");
}
