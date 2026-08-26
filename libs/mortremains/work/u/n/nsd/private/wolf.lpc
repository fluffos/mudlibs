/*
** File: wolf.c
** Author: Lady Nsd
** Other comments: This wolf was created out of Chronos's stud.
**          I only changed it to wolf, and added some emotes :)
*/
#include <mudlib.h>

inherit MONSTER ;

object hero ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1) ;
    set("author", "nsd");
    set("short", "Fear");
    set ("long", @ENDLONG
A well kept big gray wolf with aqua green eyes that stare
at you fiercely and angrily. Beware!
ENDLONG
    );                                
    set ("id", ({"fear", "Fear", "wolf"}) );
    set_name("fear");
    set ("gender", "male") ;
    set ("race", "canine");
    enable_commands() ;
    set ("stat/constitution", 15);
    set ("stat/strength", 18);
    set ("base_ac", 2);
    set ("armor_class", 1);
    set ("damage", ({ 20, 50 }) ) ;
    set ("weapon_name", "fists");
    set ("CLASS", "warrior");
    set_verbs( ({ "bite", "swing at", "attack" }) ) ;
    set_size(6);
    set_level(15) ;
    set("no_attack", 1);
    if (!hero) hero=find_player("nsd");
}

void init() {
    add_action("pet", "pet");
    add_action("fuck", "dest");
    add_action("fuck", "zap");
    add_action("hug", "hug");
    add_action("bad_emote", "kick");
    add_action("bad_emote", "bop");
    add_action("bad_emote", "boot");
    add_action("bad_emote", "sodomize");
    add_action("bad_emote", "smack");
    add_action("bad_emote", "slap");
    add_action("bad_emote", "bite");
    add_action("bad_emote", "bump");
    add_action("bad_emote", "buttkick");
    add_action("bad_emote", "mount");
    add_action("bad_emote", "strip");
    if (!hero) hero=find_player("nsd");
    add_action("duh", "quit") ;
}
int pet (string str) {
    if (str != "fear") return 0;
    if (TP->query("gender")!="female" && !adminp(TP)) {
	say(TPN+" pets Fear...\n");
	say("Fear bites "+TPN+"'s hand viciously!!!\n");
	write("You pet Fear...\n");
	write("Fear bites your hand viciously!!!\n");
	return 1;
    }
    say(TPN+" pets Fear, he wiggles his tail and licks "+TPN+".\n");
    write("You pet Fear, he wiggles his tail and licks you.\n");
    return 1;
}
int duh() {
    if (TPN=="Nsd") TO->move("/u/n/nsd/workroom") ;
    return 0 ;
}

void heart_beat() {
    if (hero)  {
	if (environment() != environment(hero)) {
	    tell_object(environment(),  
	      "Fear enters following his master, Nsd.\n") ;
	    TO->move(environment(hero)) ;
	    tell_object(hero, "Fear follows you wherever you go..\n");
	    message("whore", "Fear follows his master, Nsd.\n",
	      environment(hero), ({ hero }) ) ;
	}
    }
    heal_up();
    ::heart_beat() ;
} 
int fuck (string str) {
    if (str != "fear") return 0;
    if ("dest" && "zap") {
	if (TP->query("name") != "nsd") {
	    say("Fear jumps to "+TPN+" and rips off some flesh!!\n");
	    write("Fear jumps to you and rips off some flesh!!!\n");
	    return 1;
	}
    }
}
int hug (string str) {
    if (str != "fear") return 0;
    if (TP->query("gender")!="female" && !adminp(TP)) {
	write("You try to hug Fear, but he growls at you fiercely...\n");
	say(TPN+" tries to hug Fear, but he growls at "+TPN+" fiercely...\n");
	return 1;
    }
    write("You hug Fear... He pants and slurps your face!\n");
    say(TPN+" hugs Fear... He pants and slurps "+TPN+"'s face!\n");
    return 1;
}
int bad_emote (string str) {
    if((str != "fear") && (str != "nsd")) return 0;
    if("kick" && "bop" && "boot" && "sodomize" && "smack" && "slap"
      && "bite" && "bump" && "buttkick" && "mount" && "strip") {
	write("Fear jumps to you and rips off some flesh!\n");
	say("Fear jumps to "+TPN+" and rips off some flesh!\n");
	return 1;
    }
}
