//      /bin/user/_roar.c
//      Dragon's small paralyze
//      depends on breath skill
//      Nightshade
//      a dungeonware.net mod by: Stormbringer 1:23 PM 9/6/2002
#include <std.h>
inherit DAEMON;
int abil();
string type() { return "defense"; }
int cmd_roar(string str) {
    object ob;
    int breath, dam, para, time;
    if (!abil()) {
        return notify_fail("What?\n");
    }
    if(environment(this_player())->query_property("no attack")) {
        notify_fail("You dare not disturb such a peaceful place.\n");
        return 0;
    }
    if(!str) ob = (object)this_player()->query_current_attacker();
    else ob = present(lower_case(str), environment(this_player()));
    if(!ob && str) ob = parse_objects(environment(this_player()),lower_case(str));
    if(!ob) {
        notify_fail("Roar at whom?\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail("Inanimate objects cannot be scared.\n");
        return 0;
    }
    if(this_player()->query_ghost()) {
        notify_fail("Your voice is silent.\n");
        return 0;
    }
    if(this_player()->query_disable()) {
        notify_fail("You are too busy with something else.\n");
        return 0;
    }
    if(this_player()->query_sp() < 20) {
        notify_fail("Your voice is too hoarse.\n");
        return 0;
    }
    breath = ((int)this_player()->query_skill("breath")/3-((int)ob->query_skill("perception")/3));
    breath += (int)this_player()->query_stats("strength")/2;
    dam = (breath);
    if (dam < 10) para = 0; else
    if (dam < 50) para = 2; else
    if (dam < 100) para = 3; else
    if (dam < 150) para = 4; else
    if (dam < 200) para = 5; else
    if (dam >= 200) para = 6;
    time = 2+random(para);
    if (para = 0) {
        write("You fail to frighten anyone.");
        return 1;
    }
    if(ob->query_paralyzed()) {
        write("You over exert yourself roaring and need to recover.");
        this_player()->set_paralyzed(time);
        return 1; 
    }
    this_player()->add_sp(-(dam + random(30)));
    ob->set_paralyzed(time, "You are too frightened by the roar of "+this_player()->query_cap_name()+"!");
    this_player()->set_disable();
    this_player()->add_skill_points("breath", dam+random(5));
    write("You roar, instilling %^CYAN%^fear%^RESET%^ in your opponent.\n");
    say(this_player()->query_cap_name()+" %^CYAN%^roars%^RESET%^ at "+ob->query_cap_name()+", paralyzing them with fear.\n", ob);
    tell_object(ob, this_player()->query_cap_name()+" %^CYAN%^roars%^RESET%^, terrifying you!\n");
    return 1;
}
void help() {
    write("Syntax: <roar [enemy]>\n\n"
      "Dragons are able to roar at their enemy, causing them to\n"
      "freeze due to the force of the dragon's voice.\n"
    );
}
int abil() {
    object j;
    j = this_player();
    if (!j) return 0;
    if (j->query_race() != "dragon") return 0;
    if (j->query_level() < 4) return 0;
    return 1;
}
