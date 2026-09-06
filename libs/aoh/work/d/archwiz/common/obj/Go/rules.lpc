#include <moving.h>
inherit "/std/thing";

create() {
  ::create();
  SetShort("Go rules");
  SetLong("A list of the rules for playing Go.\n"
	  + "There are 5 rules.\n"
	  + "Do 'rule #', to read a rule number.\n");
  AddId("rules");
  AddAdjective("go");
}

move(d,m,e) {
  if (M_GET == m) {
    write("The rules are attached to the floor!\n");
    return ME_NO_MOVE;
  }
  return ::move(d,m,e);
}

init() { ::init(); add_action("rule", "rule"); }

rule(string str) {
  int n;
  if (!str) return 0;   // Cadra
  if (sscanf(str, "%d", n) != 1) return 0;
  if (n < 1 || n > 5) { write("Not that many rules.\n"); return 1; }
  say(this_player()->QueryName() + " reads rule " + n + "\n");
  cat("/d/archwiz/common/obj/Go/rule" + n);
  /*if (n == 5) log_file("GO_RULES", this_player()->QueryName() + "\n");*/
  return 1;
}
