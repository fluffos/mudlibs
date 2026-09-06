// main part copied from old nightfall
// updated by Magictcs - 18 jun 1997

#include <moving.h>
#include <sykorath.h>

inherit "/std/thing";

//*******
// create
//*******
create() {
  ::create();
  SetShort("Go rules");
  SetLong("A list of the rules for playing Go.\n"
	  + "There are 5 rules.\n"
	  + "Do 'rule #', to read a rule number.\n");
  AddId(({"rules","rule"}));
  AddAdjective("go");
  SetHelpMsg("Use: rule <number>, to read rule number (1-5)\n");
  SetNoGet("The rules are attached to the floor!\n");
}

//********************
// add special command
//********************
init() {
  ::init();
  add_action("cmd_rule", "rule");
}

//**************
// show the rule
//**************
int cmd_rule(string str) {
  int n;
  if (!str) {
    notify_fail("Use: rule <number>, to read rule number (1-5)\n");
    return 0; }
  if (sscanf(str, "%d", n) != 1) return 0;
  if (n < 1 || n > 5) { write("Not that many rules.\n"); return 1; }
  show(NAME+ " reads rule " + n + "\n");
  write("You read rule "+n+":\n");
  cat("/d/sykorath/quests/go/rule" + n);
  return 1;
}

