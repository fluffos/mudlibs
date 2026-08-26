// Inheritable weapon object. For now.
// Mobydick@TMI-2, 9-11-92

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

string *vb, *vb2 ;

void unwield(int silent);


int move (mixed dest) {

	object fellow ;

	fellow = environment(this_object()) ;
	if (fellow) {
		if (query("wielded")) {
			unwield(0);
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
		tell_object (fellow,"You stop wielding "+obj->query("short")+".\n") ;
		
		if(fellow && environment(fellow) && !silent)
		tell_room (environment(fellow),fellow->query("cap_name")+" stops wielding "+obj->query("short")+".\n",fellow) ;
                if (obj==firstwep) {
			if (secondwep) {
				fellow->set("weapon1",secondwep) ;
				fellow->set("weapon2",0) ;
                                Class = secondwep->query("weapon") ;
                                fellow->set("attack_strength",Class) ;
			} else {
				fellow->set("weapon1",0) ;
				fellow->set("attack_strength",0) ;
			}
                } else {
                        fellow->set("weapon2",0) ;
                        Class = firstwep->query("weapon") ;
                         fellow->set("attack_strength",Class) ;
                }
	}
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
