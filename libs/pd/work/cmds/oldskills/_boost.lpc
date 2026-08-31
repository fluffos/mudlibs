#include <std.h>
inherit DAEMON;
int spell();
int cmd_boost(string str) {
    string clas;
    int amount, cost, healing, wisdom, numba;
    object ob;
    string thing, what;
    if (!spell()) {
        notify_fail("What?\n");
        return 0;
    }
    if(!str) {
        notify_fail("Boost whom?\n");
        return 0;
    }
    if(this_player()->query_casting() || this_player()->query_magic_round() || this_player()->query_disable())
    {
        notify_fail("You are busy!\n");
        return 0;
    }
    if(!alignment_ok(this_player())) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
    if (this_player()->query_ghost()) {
        notify_fail("You cannot do that.\n");
        return 0;
    }
    healing = (int)this_player()->query_skill("healing");
    wisdom = (int)this_player()->query_stats("wisdom");
    if((string)this_player()->query_class() == "mage")
        clas = "mage";
    else
        clas = (string)this_player()->query_subclass();

    if(sscanf(str,"%s %d", str, numba) == 2)
        for(int i=1;i<=numba;i++)
            cost += random(9);
    if(str == "me" || str == "myself") ob = this_player();
    else ob = present(str, environment(this_player()));
    if(!ob) {
        notify_fail("Boost whom?\n");
        return 0;
    }
    if((int)this_player()->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    this_player()->set_magic_round(1);
    numba--;
        amount = random(wisdom/3 + 5) + healing/10;
    if(numba > 0)
    while(numba--)
        amount += random(wisdom/3 + 5) + healing/10;
    if(clas == "paladin"){
      amount = amount*2/3;
    }
    cost = amount/4;
    this_player()->add_mp(-cost);
    if(this_player() == ob) this_player()->add_skill_points("healing", amount/20);
    else this_player()->add_skill_points("healing", amount/10);
    ob->add_sp(amount / 2);
    if(clas == "antipaladin" || clas == "paladin" || clas == "cleric") {
        thing = "prayer";
        what = "a prayer of healing";
    }
    else if(clas == "mage" || clas == "kataan" || clas == "blue") {
        thing = "magic";
        what = "a spell of healing";
    }
    else {
        thing = "nonsense";
        what = "nonsense";
    }
    if(this_player() == ob) {
        tell_object(this_player(), "You boost your own power through "+thing+".");
        tell_room(environment(this_player()), this_player()->query_cap_name() + " mutters "+what+".", ({this_player()}));
    }
    else {
        tell_object(this_player(), "You boost "+ob->query_cap_name()+"'s power through "+thing+".");
        tell_object(ob, this_player()->query_cap_name()+" boosts your power through "+thing+".");
        tell_room(environment(this_player()), this_player()->query_cap_name()+" mutters "+what+".", ({this_player(), ob}));
        this_player()->add_alignment(amount/10);
   }
    this_player()->set_disable();
    return 1;
}
void help() {
    write("Syntax: <boost [friend]>\n\n"
      "Allows you to boost the power of those feeling kinda weak.\n"
    );
}
int spell() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (!alignment_ok(tp)) return 0;
    if (tp->query_subclass() != "paladin" && tp->query_subclass() != "cleric" &&
      tp->query_subclass() != "antipaladin" && tp->query_class() != "mage" && 
      tp->query_subclass() != "kataan" && tp->query_subclass() != "blue")
        return 0;
    if (tp->query_level() < 5) return 0;
    return 1;
}
