//      _lore.c
//      Mage ability
//      created by Bohemund 14 January 1994
//      based upon Descartes' _sense.c

#include <std.h>
inherit DAEMON;

string query_output(object tp, object ob);
string query_examine(object tp, object tgt);

int spell();

string type() { return "conjuring"; }

int cmd_lore(string str) {
    object ob;
    object *inv;
    int i, skip, which, conjure;
    string what, clas;
    mixed *arr;

   if (!spell()) {
      return 0;
   }
    if(!str) {
        notify_fail("Gather lore about what?\n");
        return 0;
    }
    clas = (string)this_player()->query_class();
    if(clas != "mage") {
        notify_fail("Your mind boggles in confusion.\n");
        return 0;
    }
    ob = present(str, this_player());
    if(!ob) {
        inv = all_inventory(this_player());
        if(sscanf(str, "%s %d", what, which) != 2) {
            notify_fail("You don't have that!\n");
            return 0;
        }
        for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
            if(inv[i]->id(what)) {
                skip ++;
                if(skip == which) ob = inv[i];
            }
        }
        if(!ob) {
            notify_fail("You don't have that!\n");
            return 0;
        }
    }
    conjure = (int)this_player()->query_skill("conjuring");
    if((int)this_player()->query_mp() < 13) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    say(this_player()->query_cap_name()+" mutters quietly as "+
        this_player()->query_subjective()+" focuses on the "+
        (string)ob->query_name()+".", this_player());

  this_player()->set_magic_round();
  this_player()->add_mp(-13);
  this_player()->add_skill_points("conjuring", random(13));

  write(query_output(this_player(), ob));
  return 1;
}

void help() {
    write("Syntax: <lore [item]>\n\n"
        "Allows a mage to discern any magic powers inherent in an object. "
        "There is no way to tell the difference between a failure to discern "
        "magic in the object and the lack of magic in an object.\n");
}

int spell() {
   if (this_player()->query_class() != "mage") return 0;
   if (this_player()->query_skill("conjuring") < 13) return 0;
  if (this_player()->query_level() < 3) return 0;
   return 1;
}

string query_examine(object tp, object tgt) {
  tp->add_mp(-13);
  tp->add_skill_points("conjuring", 13);
  return query_output(tp, tgt);
}

string query_output(object tp, object ob) {
  string *magic = ob->query_property("magic item");
  if (tp->query_skill("conjuring") > random(101) && sizeof(magic)) {
    return "You discern a magical force emanating from it...\n"
           "You sense the word \"%^BOLD%^"+magic[random(sizeof(magic))]+"%^RESET%^\".";
  }
  return "You fail to discern anything special about it.";
}
