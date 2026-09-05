#include "/bin/wiz/cmd_defs.h"

int cmd_I(string str) {
  object *ob, targ;
  int h, s;

  if (!str) {
    write("Usage: 'I <player>'\n");
    return 1;
  }

  if (str == "me")
    targ = this_player();
  else
    targ = find_player(str);

  if (!targ) {
    write("Target not in play.\n");
    return 1;
  }
  s = sizeof(ob = all_inventory(targ));
  write(CAP(str) + "'s inventory.\nROOM: " +
        object_name(ENV(targ)) + "\n");
  for (h = 0, s = sizeof(ob); h < s; h++) {
    write((string)TO->print_obj_info(h, ob[h])+"\n");
  }
  write("Done.\n");
  return 1;
}

string print_obj_info(int i, object ob) {
  string sh, nm;

  if (!ob)
    return "";
  return i + "\t" + object_name(ob) + " " +
         ((sh = (string)ob->short()) ? sh
                                     : ((nm = (string)ob->QN) ? nm
                                                              : "INVIS"));
}
