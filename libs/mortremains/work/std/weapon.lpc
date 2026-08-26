// Inheritable weapon object. For now.
// Mobydick@@TMI-2, 9-11-92
// 10 Jun 97  Cyanide added set_weapon_type().   It rocks.
// 18 Jun 97  Cyanide changed old set_weapon() to set_bonus() on the
//            grounds that it is easier to remember.
// 07 Jun 99  Cyanide daemonized weapon and armor.

#include <daemons.h>
#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

string *vb, *vb2 ;

void unwield(int silent);
varargs void set_weapon (int, int, int);
varargs void set_bonus (int, int, int);

#define set_value(x) set("value", x) 


int move (mixed dest) {

    object fellow ;

    fellow = environment(this_object()) ;
    if (fellow) {
	if (query("wielded")) {
// Chronos tries this..
    unwield(0) ;
	}
    }
    return ::move(dest) ;
}


int remove() {

    object fellow ;

    fellow = environment(this_object()) ;
    if (fellow) {
	if ((object)fellow->query("weapon1")==this_object() ||
	  (object)fellow->query("weapon2")==this_object()) {
	    unwield(0);
	}
    }
    return ::remove() ;
}


void unwield(int silent) {

    object firstwep, secondwep, obj ;
    string str ;
    object fellow, wep ;
    string name ;
    int Class ;

    fellow = environment(this_object()) ;
    if (fellow) {
	firstwep = fellow->query("weapon1") ;
	secondwep = fellow->query("weapon2") ;
	obj = this_object() ;
	obj->set("wielded",0) ;

	if(!silent)
	    tell_object (fellow,"You stop wielding "
	      +obj->query("short")+".\n") ;
	if(fellow && environment(fellow) && !silent)
	    tell_room (environment(fellow),fellow->query("cap_name")+
	      " stops wielding "+obj->query("short")+".\n",fellow) ;

	if (obj==firstwep) {
	    if (secondwep) {
		//fellow->set("weapon1",secondwep) ;
		//fellow->set("weapon2",0) ;
		fellow->set("weapon1", 0);  //Cyanide Apr 27
		Class = secondwep->query("weapon") ;
		//fellow->set("attack_strength",Class) ;
	    } else {
		fellow->set("weapon1",0) ;
		//fellow->set("attack_strength",0) ;
	    }
	} else {
	    fellow->set("weapon2",0) ;
	    //		     Class = firstwep->query("weapon") ;    
	    //fellow->set("attack_strength",Class) ;
	}
    }

    delete("tmp_enchantment");
    str = obj->query("unwield_func") ;
    if (str) call_other(obj,str) ;

}


void set_verbs(string *verbs) {
    int i ;
    string w1, w2 ;

    vb = verbs ;
    vb2 = allocate(sizeof(vb)) ;
    for (i=0;i<sizeof(verbs);i++) {
	if (sscanf(verbs[i],"%s %s",w1,w2)==2) {
	    vb2[i]=w1+"s "+w2 ;
	} else {
	    vb2[i]=verbs[i]+"s" ;
	}
    }
}


void set_verbs2 (string *verbs) {
    vb2 = verbs ;
}


string *get_verb() {

    int i ;

    i = random(sizeof(vb)) ;
    return ({ vb[i], vb2[i] }) ;
}

int has_verbs() { return sizeof(vb); }


// set_weapon is obsolete, but its here for compatibility.
// Please use set_bonus() instead.
varargs void set_weapon (int magic, int to_hit, int dam) {
    if (!magic) magic = 0;
    if (!to_hit) to_hit = 0;
    if (!dam) dam = 0;

    set_bonus(magic, to_hit, dam);
}


varargs void set_bonus (int magic, int to_hit, int dam) {
    seteuid(getuid());
    WEAPARM_D->weap_set_bonus(TO, magic, to_hit, dam);
}


void set_weapon_type (string weap) {
    WEAPARM_D->set_weapon_type(TO, weap);
} // end set_weapon_type()


void set_material_type (string stuff) {
    WEAPARM_D->set_material_type(TO, stuff);
} //end set_material_type()     (weapon version)

int wield_func() { return 1; }

// All damage filters through the 'hit_func', function. This is
// only a placeholder, but weapons can be made to do some
// cool stuff with this.

int hit_func (object attacker, int damage) {
    return damage;
}
