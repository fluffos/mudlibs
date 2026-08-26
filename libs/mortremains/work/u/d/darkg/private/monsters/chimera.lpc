
#include <mudlib.h>

inherit MONSTER;

void create () {
    seteuid(getuid());
    ::create();
    set ("special", 15);
    set ("short", "Chimera") ;
    set ("long", @CHIMERA
The chimeraa has a body of a lion, and goat with wings of a dragon
but the most noticable and dealdly part is the three heads.
A lion, dragon, and goat heads stare menacingly at you.
CHIMERA
    );
    set ("id", ({ "chimera", "it" }) ) ;
    set ("capacity", 0);
    set("gender", "male");
    set_size(6);

    //  set ("volume", 0);
    //  set ("mass", 8000) ;     Don't ever 
    //  set ("bulk", 2500) ;     set these.
    set("armor_class", 5);
   set ("natt" , 6);
    set("race", "chimera");
    set("damage_type", "slashing");
  set ("damage", ({1, 4}));
    set ("weapon_name", "claws") ;
    set_verbs( ({ "slash", "rend", "crush" }) ) ;
    set_verbs2( ({ "slashes", "rends", "crushes" }) ) ;
    set_name("chimera") ;
    set_living_name("chimera");
    enable_commands() ;
    set_level(9);
}

void init() {
    ::init();
    command("say Roar, Baaa, Growl!");
}

void special_attack() {
    //this is the breathe or bite function for raw excessive damage
    object ob = this_object()->query_current_attacker();
    int sv;   

    if (!ob) return;

    if (random(3) == 0) {
	say( "the chimera's dragon head breathes a gout of flame on "
	  + ob->query("cap_name")+" !\n", ob);
	tell_object(ob, "The chimeras dragon head breathes a gout "+
	  "of flame on you!\n");
	sv = (ob->save_throw());
	if (sv == 1){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob,"You dodge the breath weapon!\n");
	    }else{
     ob->receive_damage(((random(3) +22)/2), "fire");
	    }
	} else {
    ob->receive_damage((random(3)+22), "fire");
	}

    }else{
	if(this_object()->query_hit(ob)){
	    say("The chimeras dragon head chomps on "+ ob->query("cap_name") +" !\n", ob);
	    tell_object(ob, "The chimeras dragon head chomps you mightily!\n");
   ob->receive_damage((random(2)+10), "slashing", this_object(), 1);
	}else{
	    say( "The chimeras dragon head misses "+ ob->query("cap_name") +" !\n");
	    tell_object(ob, "The chimeras dragon head Misses!\n");
	}
    }


    if(this_object()->query_hit(ob)){
	say( "The chimeras lion head chomps on "+ ob->query("cap_name") +" !\n");
	tell_object(ob, "The chimeras lion head chomps you mightily!\n");
    ob->receive_damage((random(1)+7), "slashing", this_object(), 1);
    }else{
	say( "The chimeras lion head misses "+ ob->query("cap_name") +" !\n");
	tell_object(ob, "The chimeras lion head Misses!\n");
    }

    if(this_object()->query_hit(ob)){
	say( "The chimeras goat head butts "+ ob->query("cap_name") +" !\n", ob);
	tell_object(ob, "The chimeras goat head butts you mightily!\n");
   ob->receive_damage((random(1)+4), "slashing", this_object(), 1);
    }else{
	say( "The chimeras goat head misses "+ ob->query("cap_name") +" !\n");
	tell_object(ob, "The chimeras goat head Misses!\n");
    }

}
