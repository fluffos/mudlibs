//     Asmodeus

#include <std.h>
inherit DAEMON;
int abil();

int cmd_gore (string str) {

    int attack, total;
    object ob;
    if (!abil()) {
	write("What?\n");
	return 1;
    }
    if(!str)
	ob = (object)this_player()->query_current_attacker();
    else {
	ob = present(str, environment(this_player()));
	if(!ob) ob = parse_objects(environment(this_player()), str);
    }
    if(!ob || !living(ob)) {
	notify_fail("You do not see that here.\n");
	return 0;
    }
    if (ob==this_player())
	return notify_fail("You are an idiot.\n");
    if(this_player()->query_ghost()) {
	notify_fail("You are a ghost.");
	return 0;
    }
    if (this_player()->query_disable())
    {
	write("You are busy.");
	return 1;
    }
    if (this_player()->query_alignment() > -800) {
	notify_fail("You have betrayed your alignment.\n");
	return 0;
    }

    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    if(environment(this_player())->query_property("no attack")) {
	notify_fail("Greater powers prevent your malice.\n");
	return 0;
    }
    if((int)this_player()->query_sp() < 20) {
	notify_fail("You are too tired.\n");
	return 0;
    }
    this_player()->set_disable();
    if (ob->query_stats("dexterity")+ob->query_skill("defense")/3  > this_player()->query_stats("dexterity")+30+this_player()->query_skill("attack"))
    {
	write("You attempt to gore your opponent but fail.");
	tell_room(environment(this_player()), this_player()->query_cap_name()+ "misses with a gore!", ({ ob, this_player() }));
	return 1;
    }
    write("%^BOLD%^ORANGE%^You gore "+ob->query_cap_name()+" with your horns!\n");
    attack = this_player()->query_skill("attack")/2;
    attack += this_player()->query_stats("strength"); 
    attack += this_player()->query_skill("melee")*4/5;
    attack -= ob->query_stats("dexterity");
    attack -= ob->query_skill("defense")/2;
    attack *= 3/2;
    if (attack < 10) return notify_fail("You miss.\n");
    tell_room(environment(this_player()), this_player()->query_cap_name()+" gores "+(string)ob->query_cap_name() + "\n", ({ob, this_player()}));
    tell_object(ob, this_player()->query_cap_name()+" gores you!\n");
    total = random(this_player()->query_level()/2) + (attack);
    this_player()->add_skill_points("attack", total/40);
    this_player()->add_skill_points("melee", total/40);
    this_player()->add_sp(-total/7);
    if (ob->query_race()=="archangel" && this_player()->query_alignment()==-1500)
	ob->do_damage(total*3/2);
    else
	ob->damage(total);
    return 1;
}
void help() {
    write("%^RESET%^Syntax: <gore [(living)]>\n\n"
      "The demon uses its horns to puncture the flesh of its victim.");
}
int abil() {
    object r;
    r = this_player();
    if (!r) return 0;
    if (r->query_race() != "demon") return 0;
    if (r->query_level() < 25) return 0;
    return 1;
}
