// Zagyg does now carry the key to guild storages, so I made him a bit
// harder to kill. - Chopin
#include <conditions.h>
#include <npc_defs.h>
#include "../priest.h"
inherit PRIEST_MON_DIR "humble_mon";

#define FIRE_BALL_DAMAGE 100

void
create_monster() {
    real_short = "Pater Zagyg the Holy Priest";
    attend_short = "Pater Zagyg is conductiong Mass here";
    start_location = PRIEST_ROOM_DIR "library";
    dest_location = PRIEST_ROOM_DIR "guild_room";
    to_path = ({"north", "down", "south"});
    from_path = ({"north", "up", "south"});

    set_name("Pater Zagyg");
    set_id( ({"pater", "zagyg", "father", "priest"}) );
    set_short(real_short);
    set_long(
      "Pater Zagyg is the Holy Priest and conductor of Masses for the Church. \
All good followers of Boccob should respect and revere him.");
    set_level(40);
    set_ac(60);
    set_hp(6000);
    set_gender(G_MALE);
    set_spell_chance(40);
    set_spell_dam(FIRE_BALL_DAMAGE, DT_FIRE);
    set_spell_mess1(":%<me.capname>% points at %<him.name>%, and a ball of \
fire leaps from %<me.possessive>% fingertips to hit %<him.name>%.");
    // let's add some resistances to make him harder to kill!
    set_condition(RESISTANCE(C_STUNNED),-1);
    set_resistance(DT_MAGICAL, 500);
    set_resistance(DT_FIRE, 500);
    set_resistance(DT_LIGHT, 500);
    if(UNIQUE_D->create_unique("priest_store_key", 1)) {
	move_object(clone_object(PRIEST_OBJ_DIR "shop_key"), this_object());
    }
    ::create_monster();
}

status query_prevent_steal() { return 1; }
