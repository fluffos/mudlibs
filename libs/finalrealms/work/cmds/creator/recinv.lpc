// Randor, 25-mar-98
// recinv - recursive inventory
#pragma strict_types
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

string result;

void setup(){
  position = 1;
}

protected void format_inv(object targ, int level) {
  object *inv;
  string s;

  if(!sizeof(inv=all_inventory(targ))) return;
  foreach (object ob in inv) {
    s=desc_object(ob);
    result += sprintf("%*s%s (%O)\n", level*3, "", s, ob);
    format_inv(ob, level+1);
  }
}

protected int cmd(string str, object me) {
  object targ;
  object *tmp;

  if (this_player(1) != me) return 0;

  notify_fail("Usage: recinv <object>\n");
  if (!str) return 0;
  if(!sizeof(tmp = wiz_present(str, me)))
    return 0;
  targ=tmp[0];
  result="Recursive inventory of "+desc_object(targ)+":\n";
  format_inv(targ, 0);
  return this_player()->more_string(result);
}
