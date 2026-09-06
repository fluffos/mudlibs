#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Burial ground");
    set_long(
      "This place gives you the creeps. An eerie mist floats a feet above the ground.\
 There's a horrible stench that reminds you of rotten corpses, and yes, this\
 is where Death brings its victims. To the south you see the ruins of the Temple.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_OUTDOORS);
    set(IN_CITY);
    set(NO_PK);
    set_exits(([ "south" : AREA_TRISTEZA+"temple/temple_ruins" ]));
    add_object(AREA_TRISTEZA+"temple/grave_stone",0,1);
}

void
log_dead(string victim, string killer)
{
    object stone;
    if ( !stone = present("grave stone")) return;
    stone->log_dead(victim,killer);
}
