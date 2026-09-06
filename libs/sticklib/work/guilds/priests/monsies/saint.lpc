/* New guard for the priests's guild */
#include <group_npc.h>
#include <macros.h>
#include "../priest.h"
#include <guild.h>


//Prototypes
status kick();
status fire();
status ice();

#define KICK_DMG 50
#define ICE_DMG 70
#define FIRE_DMG 80

#define REPORT_DELAY 30

int last_report;


void
create_monster(){
    string name;

    set_name("Guardian saint");
    set_short("Guardian saint of the Holy Order");
    set_id(({"guardian","saint","guardian saint", "priest_saint"}));

    set_long(
      "This is the Guardian saint of the Holy Order. He works with \
the Templars, and guards the Cathedral. He looks holy, and \
very skilled.");
    set_gender(G_MALE);
    set_guild(GN_PRIEST);

    set_level(35); 
    set_hp(7500); 
    set_ac(65);
    set_wc(60);
    set_group("cathedral_templars");
    set_group_message("ask_help_msg",
      "Guardian saint yells: Someone help me within this heathen.");
    set_group_message("cant_help_msg",
      "Guardian saint yells: My hands are full here.");
    set_group_message("can_help_msg",
      "Templar bellows: In the name of Boccob the Omnipotent!");
    set_dead_ob(this_object());
}

// Returns true if there's still a fight!
status
attack(){
    if (!::attack()) return 0;
    switch(random(6)) {
    case 0: return kick();
    case 1: return ice();
    case 2: return fire();
    }
}

/*## SPELL FUNCTIONS ............................................. */

status
kick() {
    object att;

    if (!(att = query_attack())) return 0;
    att->tell_me("Guardian saint kicks you crushing your knee! \
*CRACK*");
    ENV->tell_here(":%<me.capname>% kicks %<him.name>% hard, \
crushing the knee!", 0, 0, ({TOBJ, att}), TOBJ, att, 0);
    att->hit_player(KICK_DMG, DT_EARTH, 0, TOBJ);
    return 1;
}

status
ice() {
    object att;

    if (!(att = query_attack())) return 0;
    ENV->tell_here(":%<me.capname>% throws an Ice Bolt at %<him.name>%"
      , 0,0, TOBJ, TOBJ, att, 0);
    att->hit_player(ICE_DMG, DT_COLD, 0, this_object());
    return 1;
}

status
fire() {
    object att;

    if (!(att = query_attack())) return 0;
    att->tell_me("You are hit by the Saint's Flamestrike!");
    ENV->tell_here(":%<me.capname>% casts a Flamestrike at %<him.name>%,  \
who screams in pain!", 0,0, ({TOBJ, att}), TOBJ, att, 0);
    att->hit_player(FIRE_DMG, DT_FIRE, 0, TOBJ);
    return 1;
}

int
monster_died(object killer) {
    string n;

    killer = query_attack();
    if(!killer) n="Someone";
    if(killer) n=(string)killer->query_real_name();
    RAID_LOGGER->log_me(n);
    return 0;
}

status
extra_aggressive(object ob) {
    if(ob && interactive(ob) && EXCOM_D->excomed(ob->query_real_name()))
    {
	return 1;
    }

    return 0;
}


status
query_ctrl() { return 1; }

int
hit_player(int dam, int t, mixed hc, object enemy) {
    string str1,str2;

    if(enemy && (time() > (last_report + REPORT_DELAY))) {
	str1 = enemy->query_name();
	str2 = environment()->query_short();
	if(!stringp(str1)) str1 = "Someone";
	if(!stringp(str2)) str2 = "somewhere";
	SERVER->inform(sprintf("Guardian Saint reports the heathen \
%s is in %s.", str1, str2));
	enemy->tell_me("Guardian Saint yells: You filthy heathen! Begone!");
	last_report = time();
    }
    return ::hit_player(dam, t, hc, enemy);
}
