// a dungeonware.net production
// coded by stormbringer for primal darkness
// 20-Oct-00


#include <std.h>
inherit DAEMON;
int spell();

private object *blinded;

int cmd_dazzle(string str) {
    object ob;
    int which, tmp, i, skip;
    string what;
    object *inv;

    if(!str) {
        ob = (object)this_player()->query_current_attacker();
        if(!ob) {
            notify_fail("Dazzle what?\n");
            return 0;
        }
    }
    else {
        ob = present(str, environment(this_player()));
        if(!ob) {
            sscanf(str, "%s %d", what, which);
            inv = all_inventory(environment(this_player()));
            for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
                if(inv[i]->id(what)) {
                    skip++;
                    if(skip == which) ob = inv[i];
                }
            }
            if(!ob) {
                notify_fail("No "+str+" here!\n");
                return 0;
            }
        }
    }
   if (!spell()) {
      write("There is no illusion here.");
      return 1;
   }
    if(environment(this_player())->query_property("no magic"))
      return notify_fail("A supernatural force prevents your magic.\n");
    if((int)this_player()->query_mp() < 100)
      return notify_fail("Too low on mana.\n");
    if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
    this_player()->set_magic_round();
    message("my_action", "You concentrate upon "+(string)ob->query_cap_name()+".", this_player());
    message("other_action", (string)this_player()->query_cap_name()+" begins to loose focus on reality.", environment(this_player()),({ this_player() }));
    tmp = (int)this_player()->query_stats("wisdom");
    tmp += (int)this_player()->query_skill("magic attack");
    tmp += (int)this_player()->query_skill("conjuring");
    tmp -= (tmp*1/2);
    if(random(20) > tmp/2) {
        message("my_action", "Your spell fails.",this_player());
        return 1;
    }
    if(!this_player()->kill_ob(ob, 0)) return 1;
    message("my_action", (string)ob->query_cap_name()+" flinches in pain!", this_player());
    message("environment", "A dazzling flash of light sears into your brain! You can't see!!!",
      ob);

    this_player()->add_mp(-tmp/4);
    this_player()->set_casting(tmp/2 + random(this_player()->query_level()));
    this_player()->set_disable();
    return 1;
}



void help() {
    message("help", "Syntax: <dazzle [player]>\n\n"
      "Illusionists make the target see a dazzling flash of light "
      "causing pain.", this_player()
    );
}

int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_class() != "mage") return 0;
   if (tp->query_subclass() != "illusionist") return 0;
   if (tp->query_level() < 2) return 0;
   return 1;
}

