/* New guard for the priests's guild */
#include <group_npc.h>
#include <macros.h>
#include "../priest.h"
#include <guild.h>
#include <servers.h>

inherit NAME_SERVER;


//Prototypes
status ring();
status fire();
status ice();

#define RING_DMG 45
#define ICE_DMG 65
#define FIRE_DMG 80

void
create_monster(){
    string name;

    name = random_name();
    set_name(name);
    set_short(capitalize(name) + " the Templar of the Holy Order");
    set_id(({"templar","guard"}));
    set_long(
      "The Templar of the Order stands here to make sure that no \
harm comes to the Cathedral or any member of the Order here. \
He looks well versed in spells... you have been warned.");
    set_gender(G_MALE);
    set_guild(GN_PRIEST);

    /* Bah! These templars basically suck! Added hp, ac and wc. */

    set_level(30); // Was 20
    set_ep(1000000);
    /* Well, thief guards have 10k - 12k hps, even 14k */
    set_hp(3000); // Was 1500 // Was 2000.. Sucky
    set_ac(45); // Was 37
    set_wc(32); // Was 28
    set_group("cathedral_templars");
    set_group_message("ask_help_msg",
      "Templar yells: Someone help me within this heathen.");
    set_group_message("cant_help_msg",
      "Templar shouts: Sorry Brother, my hands are full here.");
    set_group_message("can_help_msg",
      "Templar bellows: For the Glory of the Church and Boccob!");
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
    att->tell_me("You are hit by the Templar's Ring of Fire!");
    ENV->tell_here(":%<me.capname>% has hit %<him.name>% with a \
ring of fire!", 0, 0, ({TOBJ, att}), TOBJ, att, 0);
    att->hit_player(RING_DMG, DT_FIRE, 0, TOBJ);
    return 1;
}

status
ice() {
    object att;

    if (!(att = query_attack())) return 0;
    att->tell_me("You are hit by the Templar's Bolt of Ice!");
    ENV->tell_here(":%<me.capname>% has hit %<him.name>% with a \
Bolt of Ice!", 0,0, ({TOBJ, att}), TOBJ, att, 0);
    att->hit_player(ICE_DMG, DT_COLD, 0, this_object());
    return 1;
}

status
fire() {
    object att;

    if (!(att = query_attack())) return 0;
    att->tell_me("You are hit by the Templar's Huge Fireball!");
    ENV->tell_here(":%<me.capname>% has hit %<him.name>% with a \
Huge Fireball!", 0,0, ({TOBJ, att}), TOBJ, att, 0);
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
	SERVER->inform(sprintf("Templar reports the heathen \
%s is in %s.", ob->query_name(), environment(ob)->query_short()));
	return 1;
    }
    return 0;
}

status
query_ctrl() { return 1; }

