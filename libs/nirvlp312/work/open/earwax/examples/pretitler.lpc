#include "../defs.h"

void
reset(status arg)
{
  if (arg)
    return;

  return;
}

string query_my_name() { return "pretitler"; }
string query_cost() { return "1500"; }
string query_desc() { return "Sets a colored pretitle for the user."; }

status id(string arg) { return (arg == "pretitler" || arg == "wand"); }

string short() {
  return HIG+"Earwax's "+HIM+"C"+HIY+"o"+HIC+"l"+HIR+"o"+HIB+"r"+HIG+" Pretitler"+NORM+NORM;
}

string long() {
  write(short()+".\n");
  write("This is a long, slender wand.\n\Use: 'help xtitle' to see help on color codes,\n"+HIW+"pretitle_me <pretitle>"+NORM+NORM+" to use.\n\n"+HIR+"Note: This item is only usable one-time.\n"+NORM+NORM);
}

status get() { return 1; }

status
pretitle_me(string arg)
{
  if (!arg) 
  {
    notify_fail("Syntax: pretitle_me <pretitle to set>.\nSee 'help xtitle' for help on color codes.\n");
    return 0;
  }

  arg = (string)PARSER->parse_pcodes(arg);
  this_player()->set_pretitle(arg);
  write("Your pretitle has been set to: "+arg+"\n");
  write("Your pretitler wand crumbles into dust.\n");
  transfer(this_object(), "/room/void");
  destruct();
  return 1;
}

void
init()
{
  add_action("pretitle_me", "pretitle_me");
}
