/*
** GUILD_D - The guild daemon.
** Drives all the guild stuff, and does all permisison checks.
** Credits: 
**  10 Aug 97  Cyanide created the file.
**  14 May 98  Cyanide added support for dual-classing
**  20 Jun 99  Cyanide made so guest can't join a class.
*/

#include <daemons.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <move.h>
#include <priv.h>
#include <driver/origin.h>

// This is only needed for consistency_check.
#include <channels.h>
#include <domains.h>

#include <logs.h>
#include <guilds.h>

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)
#define SORRY "Sorry - this guild is not yet registered.\n"

inherit DAEMON;

// This func checks if the filename of the calling guild is within
// the "registered guilds" #define.

int check_registry(object ob) {
    string name;

    name = base_name(ob);

    if (member_array(name, REGISTERED_GUILDS)==-1) {
	tell_room(ob, SORRY);
	return 0;
    }

    return 1;
}

// This func is called by the add_action "join" in the std guild
// object. "Dual" calls d_dual().

int d_join(object player) {
    object guild, link;
    string gstring;

    guild = previous_object();
    gstring = file_name(guild);

    if (!check_registry(guild)) return 0;
    if (!player) return 0;

    if (player->query("name")=="guest") {
	tell_object(player, "Sorry - the guest may not join a class.\n");
	return 0;
    }

    link = player->query_link();

    if ((string)keys(link->query("Class"))[0] != "none" ) {
	tell_object(player, "You already have a class. To join anyway,"+
	  " type \"dual\".\n");
	return 0;
    }

    link = player->query_link();
    link->set("level", 1);
    link->set("Class", ([
      guild->query("group") : guild->query("class")
    ]) );

this_player()->save_me();
link->save_data() ;
return 1;
}


// Cyanide finally added this on 14 May, 1998.
// About fucking time, too!

int d_dual(object player) {
    object guild, link;
    string gstring;
    mapping class_old;

    guild = previous_object();
    gstring = file_name(guild);

    if (!check_registry(guild)) return 0;
    if (!player) return 0;

    link = player->query_link();
    class_old = link->query("Class");

    if ((string)keys(class_old)[0] == "none" ) {
	tell_object(player, "You need a primary class first!\n");
	return 0;
    }

    if (link->query("level_old")) {
	tell_object(player, "You have already dual-classed.\n");
	return 0;
    }

    if ((string)keys(class_old)[0]==(string)guild->query("group")) {
	tell_object(player, "You are already a "+
	  guild->query("group")+" class!\n");
	return 0;
    }

    return 1;
}

// Cyanide realized he needed this, 24 Nov 98.

int d_dual2(object player) {
    int lvl;
    mapping class_old;
    object link, guild;

    guild = previous_object();

    if (!check_registry(guild)) return 0;
    if (!player) return 0;

    link = player->query_link();
    class_old = link->query("Class");
    lvl = link->query("level");

    player->set("experience", 0);
    link->set("Class_old", class_old);
    link->set("level_old", lvl);

    link->set("level", 1);
    link->set("Class", ([
      guild->query("group") : guild->query("class")
    ]) );

player->save_me();
link->save_data() ;

return 1;
}

object get_guild_path (object player) {
    object guild;

    guild = previous_object();
    return guild;
}


int d_advance(object ob, int xp) {
    int lvl;
    object link;

    if (!check_registry(previous_object())) return 0;

    if ((int)ob->query("experience") < xp) {
	tell_object (ob, "You do not yet have enough experience "+
	  "to advance in level.\n");
	tell_object (ob, "You need "+
	  ( xp - ((int)ob->query("experience") ) )+
	  " more experience to advance.\n");
	return 0;
    }

    link = ob->query_link();
    /*
       if(!(this_player()->query("hero"))){
	  if ((int)link->query("level")>=30 ) {
	     tell_object(ob, "You are as skilled in your"+
	      " profession as possible.\n"+
	      "You can advance no further.\n");
	     return 0;
	  }
       }
      */

    link->set("level", (int)link->query("level") + 1);
    link->save_data();
    link->save_data_conn();
    this_player()->save_me();
    return 1;
}


int do_title (object ob, string title) {
    if (check_registry(previous_object())) {
	ob->setenv("TITLE", title);
	return 1;
    }

    return 0;
}


int set_sp(object ob, int sp) {
    if (!check_registry(previous_object())) return 0;

    ob->set("max_sp", sp);
    tell_object(ob, "You now have "+sp+" spell points.\n");
    return 1;
}


int set_tp(object ob, int tp) {
    if (!check_registry(previous_object())) return 0;

    ob->set("max_tp", tp);
    tell_object(ob, "You now have "+tp+" theurgy points.\n");
    return 1;
}


int add_hp(object ob, int hp) {
    if (!check_registry(previous_object())) return 0;

    ob->add("max_hp", hp);
    tell_object(ob, "You have gained "+hp+" hit points.\n");
    return 1;
}


/*  Who did this?  Big ugly security hole!
    I don't care if something doesn't work anymore, because
    anything that uses it shouldn't work anyway.
      Cyanide, 18 Feb 98

int add_hp_num(object ob, int hp) {

  ob->set("max_hp", hp + ob->query("max_hp"));
  tell_object(ob, "You have gained "+hp+" hit points.\n");
  return 1;
}
*/


int check (object ob) {
    object link;
    string klass, groop;
    int lvl;

    link = ob->query_link();

    lvl = link->query("level");
    klass = (string)keys(link->query("Class"))[0];
    groop = (string)values(link->query("Class"))[0]; 

    tell_object(ob, "Class :"+klass+"\n"+
      "Group: "+groop+"\n"+
      "Level: "+lvl+"\n");

    return 1;
}

// I'm guessing Ilzarion added this?

int adv_stat(object ob, string statname, int val){
    // Cy added security precautions, 18 Feb 98
    if (!check_registry(previous_object())) return 0;

    switch(statname){
    case "strength" : ob->set("base_stat/strength", val);
	break;
    case "constitution" : ob->set("base_stat/constitution", val);
	break;
    case "wisdom" : ob->set("base_stat/wisdom", val);
	break;
    case "intelligence" : ob->set("base_stat/intelligence", val);
	break;
    case "charisma" : ob->set("base_stat/charisma", val);
	break;
    case "dexterity" : ob->set("base_stat/dexterity", val);
	break;
    }

    return 1;
}

// Cyanide added this for some anti-Kyako security.
// 13 May 98

int add_experience(object ob, int xpv) {
    object Pob = previous_object(1);
    string xp_log, name;

    if (!userp(ob)) return 0;

    if ((living(Pob) && userp(Pob)) ||
      !living(Pob) ||
      (xpv > 40000) ) {
	if (previous_object(2))
	    name = previous_object(2)->query("cap_name");
	else
	    name = "*SOMETHING*";

	xp_log = (living(Pob) ? Pob->query("short")+" " : 
	  name )+ " ("+ file_name(Pob)+") called "+
	"add_experience(" + xpv+") in "+
	ob->query("cap_name")+".";

	xp_log += " [" + extract(ctime(time()), 4, 15) + "]";
	log_file(ADD_XP, iwrap(xp_log));
    }

    ob->set("experience", (int)ob->query("experience") + 
      xpv, MASTER_ONLY);

    return xpv;
}

// Added by Cyanide,  1 Dec 98.
// Just for dragons, baby.
int set_player_size(object ob, int size) {
    ob->set("size", size);
    ob->set("SIZE", size);

    return size;
}

/* EOF */
