inherit COMMAND_BASE;

int cmd() {
  if(!clonep(ENV(TP)) || sizeof(ENV(TP)->query_exits()) > 1) {
    tell_object(TP, "You do not seem to need rescuing as you are "
      "not in a terrain room with no exits.  If this is incorrect, please "
      "contact a creator.\n");
    return 1;
  }
  TP->move_with_look("/d/calarien/slum/pub/pub", "$N pops out of thin air, "
    "looking bemused.");
  return 1;
}
