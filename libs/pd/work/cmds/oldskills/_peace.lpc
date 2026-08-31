// _peace.c
//      Monk and cleric ability
//      created by Descartes 14 November 1992
// a dungeonware.net edit to make it work ewith belief skill...
#include <std.h>
inherit DAEMON;
int spell();
int cmd_peace(string str) {
    object *inv;
    int faith, belief, i, def;
    if (!spell() && !wizardp(this_player())) {
        write("What?\n");
        return 1;
    }
    if((int)this_player()->query_mp() < 10) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if (this_player()->query_disable() && !wizardp(this_player()))
        return notify_fail("You are busy.\n");
    if(!alignment_ok(this_player()) && !wizardp(this_player())) {
        notify_fail("You have betrayed the source of your power.\n");
        return 0;
    }
    faith = (int)this_player()->query_skill("faith");
    belief = (int)this_player()->query_skill("belief");
    this_player()->add_mp(-random(51));
    if (!wizardp(this_player())) {
        if (this_player()->query_subclass() == "cleric") {
            if (belief < 10) def = 2; else
            if (belief < 55) def = 3; else
            if (belief < 110) def = 4; else
            if (belief < 165) def = 5; else
            if (belief < 220) def = 6; else
            if (belief >= 220) def = 7;
            this_player()->add_mp(belief/2-random(belief/4));
            if(random(def)<2) {
                notify_fail("Your belief does not bring peace, this time.\n");
                return 0;
            }
        }
        else {
            if (faith < 10) def = 2; else
            if (faith < 55) def = 3; else
            if (faith < 110) def = 4; else
            if (faith < 165) def = 5; else
            if (faith < 220) def = 6; else
            if (faith >= 220) def = 7;
            this_player()->add_mp(faith/2-random(faith/4));
            if(random(def)<2) {
                notify_fail("Your faith does not bring peace, this time.\n");
                return 0;
            }
        }
    }
    write("You bring peace to the area.\n");
    say(this_player()->query_cap_name()+" raises "+this_player()->query_possessive()+" hands to the sky and brings peace to the area.\n", this_player());
    if ((this_player()->query_class("cleric"))) {
        this_player()->add_skill_points("belief", 1);
    }
    if ((this_player()->query_class("monk"))) {
        this_player()->add_skill_points("faith", 1);
    }
    this_player()->add_alignment(5);
    this_player()->set_magic_round(2);
    this_player()->set_disable(2);
    inv = all_inventory(environment(this_player()));
    for(i=0; i<sizeof(inv); i++) {
        if(!living(inv[i])) continue;
        inv[i]->cease_all_attacks();
    }
    return 1;
}
void help() {
    write("Syntax: <peace>\n\n"+
      "This prayer brings full peace to all beings in an area.\n");
}
int spell() {
    object j;
    j = this_player();
    if (!j) return 0;
    if (wizardp(this_player())) return 1;
    if (j->query_subclass() != "cleric" && j->query_subclass() != "monk" && j->query_subclass() != "white") return 0;
    if (j->query_level() < 5) return 0;
    return 1;
}
