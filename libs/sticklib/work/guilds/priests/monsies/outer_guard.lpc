/* New guard for the priests's guild */
#include <conditions.h>
#include <macros.h>
#include "../priest.h"

inherit PRIEST_MON_DIR "templar";

#define SP_COST 40

//Prototypes
status blind();
status healme();

void
create_monster(){ 
    ::create_monster();
    set_level(30);
    set_hp(3500); //Was 2500
}

//Returns true if there's still a fight!
status
attack(){
    if (!::attack()) return 0;
    switch(random(9)) {
    case 0: return ring();
    case 1: return ice();
    case 2: return fire();
    case 3: return blind();
    case 4:
    case 5: return healme();
    }
}

/*## SPELL FUNCTIONS ............................................. */

status blind() {
    object att;

    if(!(att = query_attack())) return 0;
    if(att->query_condition(C_BLIND)) return 1;
    att->tell_me("The Templar begins chanting. The chanting grows \
louder. You hear a bell ring three times. On the third chime, your vision \
begins to dim!");
    ENV->tell_here(":%<me.capname>% chants briefly, and points a finger at \
%<him.name>%.", 0,0, att, TOBJ, att, 0);
    att->set_condition(C_BLIND, 4 + random(8));
    return 1;
}

status healme() {
    if(query_hp() < query_max_hp() && query_sp() > SP_COST) {
	ENV->tell_here(":%<me.capname>% utters a short prayer,\
 %<me.possessive>% wounds heal!",0,0,0,TOBJ,0,0);
	add_hp(80+random(81));
	add_sp( - SP_COST );
    }
    return 1;
}

status
extra_aggressive(object ob) {
    if(ob && interactive(ob) && EXCOM_D->excomed(ob->query_real_name()))
    {
	SERVER->inform(sprintf("Templar reports the heathen \
%s is in %s.", ob->query_name(), environment(ob)->query_short()));
	return 1;
    }

    return 0;
}

