#include <std.h>
inherit DAEMON;
int abil();
string type() { return "deception"; }
int cmd_mystify(string str) {
    object ob;
    int healing, mag, dam, def, time;
    if (!abil()) {
        return notify_fail("What?\n");
    }
    if(environment(this_player())->query_property("no attack") &&
      !wizardp(this_player())) {
        notify_fail("A magic force prevents you from doing that.\n");
        return 0;
    }
    if(!str) ob = (object)this_player()->query_current_attacker();
    else ob = present(lower_case(str), environment(this_player()));
    if(!ob && str) ob = parse_objects(environment(this_player()), lower_case(str));
    if(!ob) {
        notify_fail("Mystify whom?\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail("Ok, the "+str+" is mystified.\n");
        return 0;
    }
    if(this_player()->query_ghost()) {
        notify_fail("Hmm..... yup, looks like you're dead.\n");
        return 0;
    }
    if(!this_player()->ok_to_kill(ob)) {
        notify_fail("You cannot attack them.\n");
        return 0;
    }
    if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
    if(this_player()->query_casting()) {
        notify_fail("You find it difficult to focus.\n");
        return 0;
    }
    dam = (int)this_player()->query_skill("entertainment")/2 - (int)ob->query_skill("dexterity")/2;
    
    if (dam < 10) def = 2; else
    if (dam < 55) def = 3; else
    if (dam < 110) def = 4; else
    if (dam < 165) def = 5; else
    if (dam < 220) def = 6; else
    if (dam >= 220) def = 7;
    time = 2+random(def);
    if (def = 0) {
        write("You fail to mystify even yourself.");
        return 1;
    }
    if((int)this_player()->query_sp() < dam/4) {
        notify_fail("You are too tired to do that.\n");
        return 0;
    }
    if(ob->query_paralyzed()) {
        write("You mystify yourself!");
        this_player()->set_paralyzed(time / 2);
        return 1; 
    }
    this_player()->add_sp(-(dam/6+random(30)));
    this_player()->set_disable();
    if(random(time)>2) {
      ob->set_paralyzed(time);
      this_player()->add_skill_points("entertainment", dam/25);
      write("You jump around in an elaborate pattern!\n");
      say(this_player()->query_cap_name()+" jumps around "+ob->query_cap_name()+" in an elaborate pattern!\n", ob);
      tell_object(ob, this_player()->query_cap_name()+" mystifies you with dance!\n");
    }
    else {
      write("You fail to mystify anyone.");
    }
    return 1;
}
void help() {
    write("Syntax: <mystify [enemy]>\n\n"
      "An ability that allows you to jump around your opponent,\n"
      "and amaze them with your talents.\n"
    );
}
int abil() {
    object j;
    j = this_player();
    if
(!j) return 0;
    if (j->is_monster()) return 1;
    if (j->query_subclass() != "jester") return 0;
    if (j->query_level() < 15) return 0;
    if (j->query_skill("entertainment") < 50) return 0;
    return 1;
}
