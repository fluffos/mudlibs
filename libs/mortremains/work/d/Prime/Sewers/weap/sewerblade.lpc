// By Cattt
// Cyanide cleaned up and fixed a bit, 26 Aug 99

#include <mudlib.h> 

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "cattt");
    set("name", "SewerBlade");
    set("id", ({ "blade", "SewerBlade", "sewerblade", "sword" }) );
    set("short", "The Legendary SewerBlade");
    set("long", wrap("The long mithril blade assures you that this must "+
	"be the Legendary SewerBlade.  Ancient engravings of dragons "+ 
	"and warriors grace the blade. It looks as deadly as the battle "+
	"portrayed on it."));

    // Note, you don't ever have to actually set 
    // damage_type or damage to a weapon. If you do, please
    // take note of what the damage is before you reset it,
    // and not make it TOO fifferent.
    set_bonus(0,1,3);
    set_material_type("metal/mithril");
    set_weapon_type("sword/long");
    set("nosecond", 0);
    set("value", 5000);
    set("light",1);
    set_verbs( ({ "cut", "slash", "strike" }) );
    set_verbs2( ({ "cuts", "slashes", "strikes" }) );

}
