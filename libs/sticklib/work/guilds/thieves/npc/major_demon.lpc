#include <group_npc.h>
#include <guild.h>

void
create_monster()
{
    set_group("thief_guard");
    set_name("major demon");
    set_id(({ "demon", "major", "thief_guard", "thief_demon" }));
    set_short("Major Demon");
    set_long(
      "This gloomy fellow is a typical major demon, with cloven hooves, barbed \
tail, wings, horns, hands with long, red claws, scaly black skin and \
the usual glowing red eyes. He can kill you with a wink of his eye!");
    set_level(80);
    set_ac(200);
    set_hp(10000);
    set_ep(500000);
    set_alignment(AL_EVIL);
    set_breath_attack(300, 10,
      "The demon breathes fire on you!",
      "A terrible fire breath almost scorches your flesh!", DT_FIRE);
}

int
extra_aggressive(object ob)
{
    object att;

    if (!ob) return 0;
    if ((string)ob->query_guild() == GN_THIEF) return 0;
    if (!(att = (object)ob->query_attack())) return 0;

    // Is it attacking a thief or guard?
    if ((string)att->query_guild() == GN_THIEF) return 1;
    if (att->id("thief_guard")) return 1;

    return 0;
}
