/*
** File:        _wield.c
** Purpose:     Command to wield weaponry.
** Author:      Cyanide@Nightfall's Keep
** Changes:
**  15 Apr 97  Cyanide@Nightfall's Keep write the file to replace the
**               one originally written by Mobydick@TMI-2 on 9/11/92.
**  11 Jun 97  Cyanide added support for variable levels of skill with
**               the wielded weapon.
**  25 Jun 97  Cyanide fixed an oversight concerning two-handed weapons.
**  24 Aug 99  Cyanide made a change to "wield_func"
*/

#include <mudlib.h>

#define SUBJECTIVE subjective(this_player()->query("gender"))
#define OBJECTIVE objective(this_player()->query("gender"))
#define POSS possessive(this_player()->query("gender"))

inherit DAEMON;

int help() ;

int cmd_wield (string str, int silent) {
    object obj, weaponpri, weaponsec, shield ;
    string namm, adjective, adjective2;
    string pstring, sstring;
    int to_hit, to_hit_s, hand;
    int sizep, sizesec, size, sizeob;
    int damage;

    to_hit = 0; to_hit_s = 0;
    damage = 0;
    adjective = "";  adjective2 = "";

    if (!str) {
	return help();
    }

    // Silent equipping for monsters from the create() function.
    // (04-06-98) Chronos.
    if (TP->query("npc") && sscanf(str, "%s SILENT", str)==1) silent = 1;
if (!environment(TP)) silent = 1;
    obj = present (str, this_player() );
    if (!obj) {
	notify_fail ("You don't possess a "+str+".\n");
	return 0;
    }

    if (!obj->query("weapon") ) {
	notify_fail ("That isn't a weapon.\n");
	return 0;
    }

    if (TP->query("summoned")) {
	object summoner;

	if (!obj->query("native_object")) {
	    summoner = TP->query("summoner");

	    if (summoner)
		tell_object(summoner, TP->query("cap_name") + 
		  " refuses to wield that.\n");
	    return 1;
	}
    }

    hand = (int)this_player()->query("handedness");
    if ((!hand) || (hand==0)) {
	this_player()->set("handedness", 1);
	hand = 1;
    }

    if (hand==1) {
	weaponpri = this_player()->query("weapon1");
	weaponsec = this_player()->query("weapon2");
	pstring = "right"; sstring = "left";
    } else {
	weaponpri = this_player()->query("weapon2");
	weaponsec = this_player()->query("weapon1");
	pstring = "left"; sstring = "right";
    }

    if (weaponpri)  sizep = (int)weaponpri->query("size");
    if (weaponsec)  sizesec = (int)weaponsec->query("size");
    sizeob = obj->query("size");
    size = (int)this_player()->query("size");

    //If the object has no size value, set it to 3.  This avoids the annoying 
    //"too small" messages to object that haven't been defined yet.

    if ((!sizeob) || (sizeob==0)) {
	obj->set("size", 3);
	sizeob = 3;
	if (wizardp(this_player()))
	    write("(Wield) Size of "+obj->query("short")+
	      " undefined or 0.  Assigned default of 3.\n");
    }

    if (obj==weaponpri || obj==weaponsec) {
	//He's already wielding it. Tell him so.
	notify_fail ("You are already wielding it!\n");
	return 0;
    }

    /*
      if ((size/6) >= ((int)obj->query("size"))) {
	notify_fail ("That weapon is way too small for you to wield.\n");
	  return 0;
      } else {
      }
      */
    if ((size+2) < ((int)(obj->query("size")))) {
	notify_fail ("That weapon is way too large for you to wield.\n");
	return 0;
    }

    if (this_player()->query("armor/shield")) {
	if (obj->query("nosecond")) {
	    write("You cannot use a two-handed wepon and a shield!\n");
	    return 1;
	} else {
	    if (weaponpri) {
		write("You cannot use two weapons and a shield.\n");
		return 1;
	    }
	}
    }

    // If a weapon has a wield_func, and it returns 0, that player
    // cannot wield that weapon.
    if (!obj->wield_func()) {
	write("You cannot wield that.\n");
	return 1;
    }

    switch (this_player()->query_skill(obj->query("weapon_type"))) {
    case 0 :  //Nonproficiency...
	switch ((string)this_player()->query_class()) {
	case "wizard" : to_hit -= 4; break;
	case "priest" : to_hit -= 2; break;
	case "rogue" : to_hit -= 2; break;
	case "warrior" : to_hit -= 1; break;
	case "psionicist" : to_hit -= 3; break;
	default : to_hit -= 3; break;
	}
	adjective = " cluelessly ";
	break;
    case 1 :
	//proficient
	break;
    case 2 : //specialization, expertise...
	if (this_player()->query("CLASS") == "warrior") {
	    to_hit += 1;  damage += 2;
	}
	adjective = " skillfully ";
	break;
    case 3 : // Mastery...
	to_hit += 3; damage += 3;
	adjective = " masterfully ";
	break;
    case 4 : // High Mastery...
	to_hit += 4; damage += 5;
	adjective = " become one with your weapon as you ";
	adjective2 = " becomes one with "+POSS+" weapon as "+
	SUBJECTIVE+" ";
	break;
    case 5 :    //Grand mastery...
	to_hit += 4; damage += 6;
	adjective = " grin evilly as you ";
	adjective2 = " grins evilly as "+SUBJECTIVE+" ";
	break;
    }


    // Ilzarion adds support for two-hand style:
    if ((TP->query_skill("Two Handed Style") > 1) && 
      obj->query("nosecond") )
	damage +=2;

    if ((!adjective) || (adjective=="")) adjective = " ";
    if ((!adjective2) || (adjective2==""))
	adjective2 = adjective;

    if (weaponpri) {
	if (weaponpri->query("nosecond") || obj->query("nosecond") ) {
	    write("You don't have enough hands free to wield that.\n");
	    return 1;
	} 
	if (!weaponsec) {       //He has a primary but no secondary...
	    to_hit = -2; to_hit_s = -4;
	    if ((int) this_player()->query_skill("Ambidexterity")==1) {
		to_hit_s += 2;
	    } else {
		if (sizeob>2) {
		    write("Your secondary weapon must be smaller.\n");
		    return 1;
		}
	    }
	    switch((int)TP->query_skill("Two Weapon Style")) {
	    case 0 : write(wrap("In order to wield two weapons, "+
		    "you must first learn the 'Two Weapon Style' skill.") );
		return 1;
		break;
	    case 1 : break; //Fighters and thieves automatically get this skill.
	    case 2 : to_hit += 2; to_hit_s += 2;
		break;
	    }
	    switch (hand) {
	    case 1 : this_player()->set("weapon2", obj);
		obj->set("wielded", 2);
		break;
	    case 2 : this_player()->set("weapon1", obj);
		obj->set("wielded", 1);
		break;
	    default : write ("(Wield) Error in handedness: "+
		  "Notify Cyanide.\n");
		break;
	    }

	    obj->set("temp_to_hit", to_hit_s);
	    weaponpri->set("temp_to_hit", to_hit);
	    obj->set("temp_dam_adj", damage);
	    if (!silent) {
		write(wrap("You"+adjective+"wield "+obj->query("short")+
		    " in your "+sstring+" hand."));
		say(wrap(TPN+adjective2+"wields "+obj->query("short")+" in "+
		    POSS+" "+sstring+" hand."));
	    }
	    return 1;
	} else {   
	    //If we get here, he has a primary AND a secondary...
	    write ("You already have two weapons wielded.\n");
	    return 1;
	} //end if no second weapon.
    } else {  
	if (!weaponsec) {  //Has no weapons wielded whatsoever...

	    obj->set("temp_to_hit", to_hit);
	    obj->set("temp_dam_adj", damage);

	    if (obj->query("nosecond")) {
		str = obj->query("wield_func") ;
		if (str) call_other(obj,str) ;
		if (!silent) {
		    write(wrap("You"+adjective+"wield "+
			obj->query("short")+" in both hands."));
		    say(wrap(TPN+adjective2+"wields "+obj->query("short")
			+" in both hands."));
		}
		obj->set("wielded", 3);

		if (hand==1) {
		    this_player()->set("weapon1", obj);             
		} else { 
		    this_player()->set("weapon2", obj);
		}
		return 1;
	    } else {
		str = obj->query("wield_func") ;
		if (str) call_other(obj,str) ;
		if (!silent) {
		    write(wrap("You"+adjective+"wield "+obj->query("short")+" in your "+
			pstring+" hand."));
		    say(wrap(this_player()->query("cap_name")+adjective2+"wields "+
			obj->query("short") +" in "+ possessive(TP->query("gender"))+
			" "+pstring+" hand."));
		}
		obj->set("wielded", hand);
		obj->set("temp_to_hit", to_hit);
		obj->set("temp_dam_adj", damage);
		this_player()->set("weapon"+hand, obj); 
		return 1;
	    }
	} else {
	    // He has a secondary, but no primary...
	    if (weaponsec->query("nosecond") || obj->query("nosecond") ) {
		write("You don't have enough hands free to wield that.\n");
		return 1;
	    } 

	    if ((int) this_player()->query_skill("Ambidexterity")==1) 
		to_hit_s += 2;
	    switch((int)this_player()->query_skill("Two Weapon Style")) {
	    case 0 : write ("Your class cannot wield two weapons at once.\n"+
		  "Now tell Cyanide how you got a weapon in your "+
		  sstring+" hand...\n");
		return 1;
		break;
	    case 1 : break; //Fighters and thieves automatically get this skill.
	    case 2 : to_hit += 2; to_hit_s += 2;
		break;
	    }
	    str = obj->query("wield_func") ;
	    if (str) call_other(obj, str);
	    if (!silent) {
		write(wrap("You"+adjective+"wield "+obj->query("short")+" in your "+
		    pstring+" hand."));
		say(wrap(this_player()->query("cap_name")+adjective2+"wields "+
		    obj->query("short") +" in "+possessive(TP->query("gender"))+
		    " "+pstring+" hand."));
	    }
	    obj->set("wielded", hand);
	    this_player()->set("weapon"+hand, obj);
	    obj->set("temp_to_hit", to_hit);
	    weaponsec->set("temp_to_hit", to_hit_s);
	    return 1;
	} //end if secondwep
    } //end if primarywep

    // This is a quick hack to gove monsters more xp.
    if (!userp(TP)) TP->calc_xpv();
} // end cmd_wield()


int help() {
    write (@EndHelp
Usage: wield <weapon namm>

The wield command allows you to wield weapons.  Typing "wield sword" lets you 
use a sword if you have one. You can wield up to two weapons at one if you are
a rogue or fighter class, usually (though with penalties if you lack the skills
"ambidexterity" and/or "two weapon style"). However, the weapon in your 
off-hand must be smaller than your primary weapon. Most of your attacks, but
not all, will be made using your primary weapon.
EndHelp
    );
    return 1;
}   //end help()

