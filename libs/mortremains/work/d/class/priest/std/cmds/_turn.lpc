//Turn undead command

int cmd_turn(string str){
    int undead, num, bonus;
    object priestob, target;

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();         
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write("Turn what?\n");
	return 1;
    }

    priestob = present("#CLASS_OBJECT#", TP);
    bonus = priestob->query("turning");
    undead = target->query("undead");

    if (!bonus){
	write("Your god does not grant you the ability to turn undead.\n");
	return 1;
    }
    if (!undead){
	write(target->query("cap_name")+" ignores you feeble attempts to call upon your god.\n");
	return 1;
    }

    num = random(20)+(this_player()->query_level("priest"))+bonus;

    num = num - (undead * 2);

    if ((num > 23) && (undead < 9)){
	write(target->query("cap_name")+" crumbles to dust!\n");
	say(target->query("cap_name")+" succumbs to the forces of faith and is destroyed!\n");
	target->remove();
	return 1;
    }
    if (num > 10){
	if (undead > 15){
	    write(target->query("cap_name")+" ignores you feeble attempts to call upon your god.\n");
	    target->add("undead", 1);
	    target->kill_ob(this_player());
	    return 1;
	}
	write(target->query("cap_name")+" is turned!\n");
	say(target->query("cap_name")+" succumbs to the forces of faith and flees!\n");
	target->add("undead", 1);
	target->kill_ob(this_player());
	target->run_away();
	return 1;
    }
    write(target->query("cap_name")+" ignores you feeble attempts to call upon your god.\n");
    target->add("undead", 1);
    target->kill_ob(this_player());
    return 1;
}
