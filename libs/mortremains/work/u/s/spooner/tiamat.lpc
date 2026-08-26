//TIAMAT!!!
// Cleaned by Cyanide, 4 January 2000

inherit MONSTER;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("stat/constitution", 24);
    set ("stat/dexterity", 12);
    set ("stat/strength", 23);
    set("resist_type", ([  "fire" : 0, "electricity" : 0, "poison" : 0, "acid" : 0, "cold" : 0 ]) );
    set ("special", 100);
set ("short", "Lag-Monster") ;
    set("long", @EndLong
This is the Deadly Lag-Monster and he will Kick your ASS When you 
least expect it.  She is made up of lots of little Fucking things
that always seem to fuck with ya at the wrong time and kill ya
so if you thng you have a set of balls just try and kill this
BITCH!!!!
EndLong
    );
set ("id", ({ "dragon", "Lag-Monster" }) ) ;
    set("gender", "female");
    set_size(200);
    set("armor_class", -30);
    set("magic_resist",125);
    set ("natt" , 2);
    set("race", "dragon");
    enable_commands();
    set("damage_type", "slashing");
    set ("damage", ({30 , 56}));
    set ("weapon_name", "claws") ;
    set_verbs( ({ "slash", "rend", "crush" }) ) ;
    set_verbs2( ({ "slashes", "rends", "crushes" }) ) ;
    set_name("tiamat") ;
    set_living_name("tiamat");
    enable_commands() ;
    set("wealth", (this_object()->query("hit_points")));
    set("prevent_summon", 1);
    set_level(100);
}

/*
void init() {
    ::init();
    command("say Roar!");
}
*/

void special_attack() {
    //this is the breathe or bite function for raw excessive damage
    object ob;
    int sv;   
    ob = this_object()->query_current_attacker();

    if (random(3) == 0) {
	say( "Tiamat's Black head breathes corrosive acid on "+ ob->query("cap_name")+"!\n", ob);
	tell_object(ob, "Tiamat's Black head Breathes corrosive acid on you!\n");
	sv = (ob->save_throw(-6));
	if (sv == 1){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob,"You dodge the breath weapon!\n");
	    }else{
		ob->receive_damage(((random(103)+51)/2), "acid");
	    }
	}
	if (sv == 0){
	    ob->receive_damage((random(103)+51), "acid");
	}
    }else{
	if(this_object()->query_hit(ob)){
	    say( "Tiamat's Black head chomps on "+ ob->query("cap_name")+ "!\n", ob);
	    tell_object(ob, "Tiamat's Black head chomps you mightily!\n");
	    ob->receive_damage((random(26)+37), "slashing", this_object(), 1);
	}else{
	    say( "Tiamat's Black head misses "+ ob->query("cap_name") +" !\n");
	    tell_object(ob, "Tiamat's Black head Misses!\n");
	}
    }
    if (random(3) == 0) {
	say( "Tiamat's Blue head breathes Lightning on "+ ob->query("cap_name")+"!\n", ob); 
	tell_object(ob, "Tiamat's Blue head Breathes Lightning on you!\n");
	sv = (ob->save_throw(-6));
	if (sv == 1){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob,"You dodge the breath weapon!\n");
	    }else{
		ob->receive_damage(((random(239)+51)/2), "electricity");
	    }
	}
	if (sv == 0){
	    ob->receive_damage((random(239)+51), "electricity");
	}

    }else{
	if(this_object()->query_hit(ob)){
	    say( "Tiamat's Blue head chomps on "+ ob->query("cap_name") +" !\n", ob);
	    tell_object(ob, "Tiamat's Blue head chomps you mightily!\n");
	    ob->receive_damage((random(36)+37), "slashing", this_object(), 1);
	}else{
	    say( "Tiamat's Blue head misses "+ ob->query("cap_name") +" !\n");
	    tell_object(ob, "Tiamat's Blue head Misses!\n");
	}
    }
    if (random(3) == 0) {
	say( "Tiamat's Green head breathes poisonous gas on "+ ob->query("cap_name")+" !\n", ob);
	tell_object(ob, "Tiamat's Green head Breathes poisonous gas on you!\n");
	sv = (ob->save_throw(-6));
	if (sv == 1){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob,"You dodge the breath weapon!\n");
	    }else{
		ob->receive_damage(((random(171)+51)/2), "poison");
	    }
	}
	if (sv == 0){
	    ob->receive_damage((random(171)+51), "poison");
	}

    }else{
	if(this_object()->query_hit(ob)){
	    say( "Tiamat's Green head chomps on "+ ob->query("cap_name") +"!\n", ob);
	    tell_object(ob, "Tiamat's Green head chomps you mightily!\n");
	    ob->receive_damage((random(37)+33), "slashing", this_object(), 1);
	}else{
	    say( "Tiamat's Green head misses "+ ob->query("cap_name") +" !\n");
	    tell_object(ob, "Tiamat's Green head Misses!\n");
	}
    }	
    if (random(3) == 0) {
	say( "Tiamat's Red head breathes a gout of flame on "+ ob->query("cap_name")+" !\n", ob);
	tell_object(ob, "Tiamat's Red head Breathes a gout of flame on you!\n");
	sv = (ob->save_throw(-6));
	if (sv == 1){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob,"You dodge the breath weapon!\n");
	    }else{
		ob->receive_damage(((random(307)+51)/2), "fire");
	    }
	}
	if (sv == 0){
	    ob->receive_damage((random(307)+51), "fire");
	}

    }else{
	if(this_object()->query_hit(ob)){
	    say("Tiamat's Red head chomps on "+ ob->query("cap_name") +" !\n", ob);
	    tell_object(ob, "Tiamat's Red head chomps you mightily!\n");
	    ob->receive_damage((random(46)+37), "slashing", this_object(), 1);
	}else{
	    say( "Tiamat's Red head misses "+ ob->query("cap_name") +" !\n");
	    tell_object(ob, "Tiamat's Red head Misses!\n");
	}
    }

    if (random(3) == 0) {
	say( "Tiamat's White head breathes freezing cold on "+ ob->query("cap_name") +" !\n");
	tell_object(ob, "Tiamat's White head Breathes freezing cold on you!\n");
	sv = (ob->save_throw(-6));
	if (sv == 1){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob,"You dodge the breath weapon!\n");
	    }else{
		ob->receive_damage(((random(111)+39)/2), "cold");
	    }
	}
	if (sv == 0){
	    ob->receive_damage((random(111)+39), "cold");
	}

    }else{
	if(this_object()->query_hit(ob)){
	    say( "Tiamat's White head chomps on "+ ob->query("cap_name") +" !\n");
	    tell_object(ob, "Tiamat's White head chomps you mightily!\n");
	    ob->receive_damage((random(29)+33), "slashing", this_object(), 1);
	}else{
	    say( "Tiamat's White head misses "+ ob->query("cap_name") +" !\n");
	    tell_object(ob, "Tiamat's White head Misses!\n");
	}

    }
}
