//  bite

#define REG   0
#define PRE   1
#define DIE   2
#define UDIE  3
#define UNK   4

int cmd_bite(string s) {
    int x, hp;
    float hpp;
    object o, t;
    if(!s || s == "") return notify_fail("Bite what?\n");
    if(!o=present(s, environment(this_player()))) return
	notify_fail("You do not notice that here.\n");
    t=this_player();
    if(o->is_player()) {
	if(o->query_race() == "vampire") return
	    notify_fail("You may not drink of your own kind.\n");
	if(member_array("vampire", o->query_quests()) == -1) return
	    notify_fail("That person is not marked.\n");
	write("Transform person.");
	return 1;
    }
    hpp=percent(o->query_hp(), o->query_max_bp());
    if(hpp > 25) return notify_fail("Your prey is not yet weak enough.\n");
    write("You bite "+o->query_cap_name()+"'s neck and begin to "
      "draw %^BOLD%^%^RED%^blood%^RESET%^.");
    message("", t->query_cap_name()+" bites your neck!  You feel warm "
      "blood begin to trickle down your neck!", o);
    message("", t->query_cap_name()+" ", environment(t), ({ t, o }));
    t->set_paralyzed(100, "You are drinking the blood of another.\n", 
      "You release "+o->query_cap_name()+" from your grasp.\n");
    o->set_paralyzed(100, t->query_cap_name()+" is biting your neck "
      "and you are immobilized.\n", t->query_cap_name()+" releases you from "
      +possessive(t)+" grasp.\n");
    call_out("continue_bite", 2, t, o, 1);
    return 1;
}

int abil() {
    if(this_player()->query_class() == "vampire") return 1;
    return 0;
}

int finish_bite(object t, object o, int type) {
    t->set_paralyzed(0);
    o->set_paralyzed(0);
    switch(type) {
    case REG:
	write("You release your victim while "+objective(o)+" has barely "
	  "any life in "+nominative(o));
	message("", "You are released while you still have a little life in your body.", o);
	message("", t->query_cap_name()+" releases "+o->query_cap_name()+
	  " from "+possessive(t)+" grasp.\n", environment(t), ({t,o}));
    case PRE:
	write(o->query_cap_name()+" breaks out of your grasp!");
	message("", "You break out of "+t->query_cap_name()+"'s grasp!", o);
	message("", o->query_cap_name()+" breaks out of "+o->query_cap_name()+
	  "'s grasp.\n", environment(t), ({t,o}));
	break;
    case DIE:
	write(o->query_cap_name()+" dies in your arms!");
	message("", "You die from the lack of blood.", o);
	t->kill_ob(o);
	o->die();
	break;
    default:
	break;     
    }
    return 1;
}

varargs int continue_bite(object t, object o, int bypass) {
    int b, x;
    b=random(o->query_level()/2);
    b += random(o->query_stats("strength")) + random(o->query_stats("intelligence"));
    x=random(t->query_level()/2+t->query_level()/3);
    x += random(t->query_skill("nature")) + random(t->query_skill("illusion"));
    write("Displaying system stats... \nx: "+x+" B: "+b);
    if(!bypass && x < b) 
	return finish_bite(t, o, PRE);
    if(!present(o, environment(t))) 
	return finish_bite(t, o, UNK);
    if(o->query_bp()<1) 
     return finish_bite(t, o, DIE);

    finish_bite(t, o, REG);
}

