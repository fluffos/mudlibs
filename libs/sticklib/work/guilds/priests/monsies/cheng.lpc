/* New guard for the priests's guild, paid by the guild.. */

#include <group_npc.h>
#include <macros.h>
#include "../priest.h"
#include <guild.h>

//Prototypes
status ring();
status fire();
status ice();

#define RING_DMG 45
#define ICE_DMG 65
#define FIRE_DMG 80

void
create_monster()
{
    set_name("Cheng");
    set_short("Cheng, the High Priest of Boccob");
    set_id(({ "cheng","priest","high priest" }));

    set_long("High Priest Cheng Stands before you a very intimidating "+ 
      "figure. His upper body is covered with thick muscles as if he "+ 
      "had been doing physical labor all of his life. You notice he "+
      "wears only sandals and very loose trousers which you would "+ 
      "guess put little restriction on his movement.");

    set_gender(G_MALE);
    set_guild(GN_PRIEST);

    set_level(32);
    set_ep(1000000);
    set_hp(4000);
    set_ac(48);
    set_wc(38); 
    set_group("cathedral_templars");
    set_group_message("ask_help_msg",
      "Cheng yells: Templars! Help me with this heathen!");
    set_group_message("cant_help_msg",
      "Cheng shouts: Forgive me brothes, but my hands are full!");
    set_group_message("can_help_msg",
      "Cheng bellows: For the Glory of the Church and Boccob!");
    set_dead_ob(this_object());
}

// Returns true if there's still a fight!
status
attack(){
    if (!::attack()) return 0;
    switch(random(6)) {
    case 0: return ring();
    case 1: return ice();
    case 2: return fire();
    }
}

/*## SPELL FUNCTIONS ............................................. */

status
ring() {
    object att;

    if (!(att = query_attack())) return 0;
    att->tell_me("You are hit by the Cheng's Ring of Fire!");
    ENV->tell_here(":%<me.capname>% hits %<him.name>% with a \
ring of fire!", 0, 0, ({TOBJ, att}), TOBJ, att, 0);
    att->hit_player(RING_DMG, DT_FIRE, 0, TOBJ);
    return 1;
}

status
ice() {
    object att;

    if (!(att = query_attack())) return 0;
    att->tell_me("You are hit by the Cheng's Bolt of Ice!");
    ENV->tell_here(":%<me.capname>% hurls an Bolt of Ice "+
      "at %<him.name>%!", 0,0, ({TOBJ, att}), TOBJ, att, 0);
    att->hit_player(ICE_DMG, DT_COLD, 0, this_object());
    return 1;
}

status
fire() {
    object att;

    if (!(att = query_attack())) return 0;
    att->tell_me("You are hit by the Cheng's fiery Flamestrike!");
    ENV->tell_here(":%<me.capname>% casts a fiery Flamestrike "+
      "at %<him.name>%!", 0,0, ({TOBJ, att}), TOBJ, att, 0);
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

int
extra_aggressive(object ob){
    if (ob && interactive(ob) && !ob->query_coder_level()
      && ((string)ob->query_guild() != GN_PRIEST)
      && !(GUEST_D->query_guest(ob->query_real_name()))) {
	SERVER->inform(sprintf("Cheng reports the heathen \
%s is in %s.", ob->query_name(), environment(ob)->query_short()));
	return 1;
    }
    return 0;
}

status
query_ctrl() { return 1; }

