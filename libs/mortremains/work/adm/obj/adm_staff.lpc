/*
** File: adm_staff.c
** Purpose: Cool admin tool. Changes stats with root access,
**    and tells wielder about damage they receive.
** Credits:
**    11 July 97  Cyanide wrote the file.
**    10 Aug  97  Cyanide added logging for its own sake.
**    22 Jan  00  Cyanide included the Shadow Spy v1.0 to the staff. 
**    12 July 00  Cyanide added guild obj functionality of priests and mages.
*/

#define STAFF_PATH "/d/class/wizard/std/cmds:/d/class/wizard/general/cmds"+ \
      ":/d/class/priest/std/cmds"
#define STAFF_LOG "ADM_STAFF"

#include "/u/c/cyanide/debug.h"
#include <priest_spheres.h>
#include <daemons.h>
#include <move.h>
#include <mudlib.h>
#include <config.h>

inherit WEAPON;

void staff_log (string);
int show (string str, object u_obj) ;
int dest_shadows (string str) ;
object find_shadowed_player (string str) ;

void create() {
    seteuid(getuid());
    set("author", "cyanide");
    set_weapon_type("quarterstaff");
    set_material_type("stone");
    set_bonus(5);
    set("id", ({ "staff", "#CLASS_OBJECT#" }) );
    set("name", "black crystal staff");
    set("short", "a black crystal staff");
    set("long", @AdmLong
Commands:  glow [on|off]
    mutate <target> <stat> to <#>

Shadow Spy Commands:    
    sv             :  Show all shadows on all users logged in.
    sview <user>   :  See shadows on a specific user.
    sdest <user>   :  Destruct all shadows on a specific user.
    Sdest <user>   :  Silent sdest.
    rms <user> <#> :  Remove shadow <#> from specified user.
AdmLong
    );
    set_verbs ( ({ "smash", "beat" }) );  
    set("nosecond", 1);
    set("prevent_get", 1);
    set("prevent_drop", 1);
    set("prevent_clean", 1);

    // For "priest" class object

    set("major", ALLSPHERES);
}

void init() {
    object envir = environment(this_object());

    if (living(envir)) {
	if (!adminp(envir)) {
	    staff_log("("+TPN+") Staff autodest for nonadmin ownership.");
	    tell_room(environment(envir), envir->query("cap_name") +
	      "'s staff crumbles to dust!\n");
	    destruct(TO);
	}
    } else {
	remove();
    }

    add_action("mutater", "mutate");
    add_action("immunestaff", "immune");

    // This stuff is the 'shadow spy' stuff.
    add_action("view","sview");
    add_action("show_shadows","sv");
    add_action("dest_shadows","Sdest");
    add_action("alert_sdest","sdest");
    add_action("dest_spec_shadow","rms");

    // Class object stuff:
    add_action("cmd_hook", "", 1);
}


void staff_log(string log_me) {
    log_file(STAFF_LOG, wrap(log_me+" ["+
	extract(ctime(time()), 4, 15) + "]"));
}

// This is for the 'class object' portion.
int cmd_hook(string cmd) {
    string path, file, verb;
    int blah;

    path = STAFF_PATH;
    verb = query_verb();

    if (verb == "clean") return 0;
    file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
    if (file && (file!=""))
	blah = (int)call_other(file, "cmd_"+verb, cmd);

    return blah;
}            

void Class(string name, string str) {
    object targ, link;
    string str2, Class, Class_old;
    int level, level_old, tmp=0;

    targ = find_player(name);
    if (!targ) {
	write(capitalize(name)+" is not presently on the mud.\n");
	return;
    }

    sscanf("%s %s", str, str2);

    link = targ->query_link();

    switch(str) {
    case "exchange" :
	level = link->query("level");
	level_old = link->query("level_old");
	Class = link->query("Class");
	Class_old = link->query("Class_old");
	if (Class_old != "peasant") {
	    str2 = Class;
	    tmp = level;

	    link->set("Class", Class_old);
	    link->set("level", level_old);
	    link->set("Class_old", str2);
	    link->set("level_old", tmp);
	}

	if (tmp) write("Done.\n");
	else write("Could not complete operation.\n");

	break;
    default:
	write("Operation not understood.\n");
	break;
    }

    return;
}

int mutater (string str) {
    object targ;
    string stat, str2, tmp;
    int num, flag=1;

    if (!adminp(TP)) {
	write("NON_ADMIN!!\n");
	staff_log(TPN+" attempted to use staff.\n");
	return 1;
    }

    if (!str) {
	write("Usage: mutate <target> <stat|sp|cp|sp> to <#>\n");
	return 1;
    }

    tmp = str;
    if (sscanf(str, "%s %s %s", str, stat, str2) == 3)
	if (stat == "class") {
	    Class(str, str2);
	    return 1;
	}
	else
	    str = tmp;

    if (sscanf(str, "%s %s to %d", str, stat, num) != 3) {
	write("Usage: mutate <target> <stat|sp|cp|sp> to <#>\n");
	return 1;
    }

    targ = find_player(str);
    if (!targ) {
	write(capitalize(str)+" is not presently on the mud.\n");
	return 1;
    }

    stat = lower_case(stat);
    if (stat!="no_attack" && num<1) {
	write("All stats must be positive integers!\n");
	return 1;
    }

    /*
	if (num > 25) {
	    write("All stats have a maximum of 25.\n");
	    return 1;
	}
    */

    switch (stat) {
    case "con" : case "constitution" : stat="stat/constitution"; break;
    case "cha":case "charisma" : stat="stat/charisma"; break;
    case "dex":case "dexterity": stat = "stat/dexterity"; break;
    case "int":case "intelligence":stat="stat/intelligence"; break;
    case "str":case "strength": stat = "stat/strength"; break;
    case "wis":case "wisdom": stat = "stat/wisdom"; break;
    case "tp" : stat = "theurgy_points"; break;
    case "sp" : stat = "spell_points"; break;
    case "cp" : stat = "com_points"; break;
    case "hp" : stat = "hit_points"; break;
    case "no_attack" : stat = "no_attack"; break;
    case "snoopable" : stat = "snoopable"; break;
    default : flag = 0; break;
    }

    if (flag==0) {
	write(@EndFlag
Only the following are valid mutations: 
  Strength (Str)      Charisma (Cha)
  Constitution (Con)  Intelligence (Int)
  Dexterity (Dex)     Wisdom(Wis)

  Cp, hp, and sp.

  Class exchange

  Just added: no_attack!
EndFlag
	);
	return 1;
    }

    if (sscanf(stat, "%s_points", str) == 1) {
	str = "max_"+stat[0..0]+"p";
	targ->set(str, num);
    } else {
	targ->set("base_"+stat, num);
    }

    targ->set(stat, num);

    sscanf(stat, "stat_%s", stat);
    tell_object(targ, TPN+" just set your "+stat+" to "+num+".\n");
    write("You just set "+targ->query("cap_name")+"'s "+stat+
      " to "+num+".\n");

    staff_log("("+TPN+") Mutated "+targ->query("cap_name")+"'s "+
      stat+" to "+num+".");

    return 1;
}

// These are the shadow_spy funcs:

int show_shadows() {
    object *u;
    string name;
    int i;
    write("Shadow Spy (TM)  - by Tarod (To keep you guys in line.) :-)\n");
    u=users();
    i=0;
    while(i<sizeof(u)){
	name=u[i]->query("cap_name") ;
	if(!name)name="logon";
	show(name,u[i]);
	i+=1;
    }
    write("\n");
    return 1;
}

int show (string str, object u_obj) {
    object obj;

    string fn;
    write(capitalize(str)+":    \t");
    obj=shadow(u_obj,0);
    if (!obj) {write("Not Shadowed\n"); return 1;}
    fn = file_name(obj);
    write("Shadowed by:  "+fn+"\n");
    obj=shadow(obj,0);
    while (obj) {
	write("Muliple Shadows:   **  \t"+file_name(obj)+"\n");
	obj=shadow(obj,0);
    }
    return 1;
}

int view (string str) {
    object obj;
    string fn;
    if (find_shadowed_player(str)) {
	write(capitalize(str)+":     \t");
	obj=shadow(find_shadowed_player(str),0);
	if (!obj) {write("Not Shadowed\n"); return 1;}
	fn = file_name(obj);
	write("Shadowed by:  "+fn+"\n");
	obj=shadow(obj,0);
	while (obj) {
	    write("Multiple Shadows:   **  \t"+file_name(obj)+"\n");
	    obj=shadow(obj,0);
	}
	return 1;
    }
    write("Find shadows on who?\n");
    return 1;
}

int alert_sdest (string str) {
    object target;

    target=find_shadowed_player(str);
    if (!target) { write("sdest:  target not found\n"); return 1; }
    if (environment(target)==environment(this_player())) {
	write("You tear the shadows from "+
	  capitalize((string)target->query("cap_name"))+".\n");
	say(capitalize((string)this_player()->query("cap_name"))+
	  " tears the shadows from "+
	  capitalize((string)target->query("cap_name"))+".\n");
    }
    else {
	write("You tear the shadows from "+
	  capitalize((string)target->query("cap_name"))+".\n");
	tell_object(target,capitalize((string)this_player()->query("cap_name"))+
	  " tears your shadows from you.\n");
    }
    dest_shadows(str);
    return 1;
}

int dest_shadows (string str) {
    object obj, n_obj;
    string fn;
    if (find_shadowed_player(str)) {
	write(capitalize(str)+":\t");
	obj=shadow(find_shadowed_player(str),0);
	if (!obj) {write("Not Shadowed\n"); return 1;}
	fn = file_name(obj);
	write("Shadowed by:  "+fn);
	n_obj=obj;
	obj=shadow(obj,0);
	destruct(n_obj);
	write(" <- Destructed!\n");
	while (obj) {
	    write("Multiple Shadows:   **  \t"+file_name(obj));
	    n_obj=obj;
	    obj=shadow(obj,0);
	    destruct(n_obj);
	    write(" <- Destructed!\n");
	}
	return 1;
    }
    write("Dest shadows on who?\n");
    return 1;
}

object find_shadowed_player (string str) {
    object *u;
    int i;
    string name;
    if (!str || str == "") return 0;
    u=users();
    i=0;
    while(i<sizeof(u)){
	name=u[i]->query("cap_name") ;
	if(!name)name="logon";
	if (capitalize(name)==capitalize(str)) return u[i];
	i+=1;
    }
    return 0;
}

/* This function seems not to be doing anything... It's commented out.

dest_guild_shadows() {
object *u;
int i;
string name;
u=users();
    i=0;
	while(i<sizeof(u)){
	  name=u[i]->query("cap_name");
	  if(!name)name="logon";
	  clean_shadows(u[i]);
	     i+=1;
	     }
 return 1;
}

*/

int dest_spec_shadow (string str) {
    object obj, n_obj;
    string fn, who;
    int snum, count;
    if (sscanf(str,"%s %d",who,snum)!=2) {
	write("Shadow Spy:  Invalid Paramaters\n");
	return 1;
    }
    if (find_shadowed_player(who)) {
	write(capitalize(str)+":\t");
	obj=shadow(find_shadowed_player(who),0);
	if (!obj) { write("Not Shadowed\n"); return 1; }
	fn = file_name(obj);
	count=1;
	write("Shadowed by:  "+fn);
	n_obj=obj;
	obj=shadow(obj,0);
	if (count==snum) {
	    destruct(n_obj);
	    write(" <- Destructed!\n");
	}
	else write(" <- Ignored.\n");
	while (obj) {
	    write("Multiple Shadows:   **  \t"+file_name(obj));
	    n_obj=obj;
	    obj=shadow(obj,0);
	    count++;
	    if (count==snum) {
		destruct(n_obj);
		write(" <- Destructed!\n");
	    }
	    else write(" <- Ignored.\n");
	}
	return 1;
    }
    write("Dest shadow on who?\n");
    return 1;
}


int query_auto_load() { return 1; }
