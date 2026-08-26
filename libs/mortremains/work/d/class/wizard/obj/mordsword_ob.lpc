//ilz-2
// Nov 22, 1998 - Cyanide thinks.
// Changes:
//    14 Dec 98   Cyanide updated to the current spell standards.

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit WEAPON;
inherit SPELL;

void create() {
    seteuid(getuid());
    set("id", ({ "plane", "sword", "#MORDSWORD_SPELL#" }) );
    set("short", "Mordenkainen's Sword");
    set("name", "plane of force");
    set("long", wrap("A magical plane of force, about three "+
	"feet long, but with the weight and feel of a small "+
	"dagger. It seems to exist in only two dimensions, making "+
	"it infinitely sharp."));
    set_weapon_type("dagger");
    set_bonus(4, 4, 0);
    set("nosecond", 1);
    set("damage", ({ 5,20 }) );  
    set("prevent_drop", 1);
    set("prevent_sell", 1);
    set("dest_at_die", 1);
    set_verbs( ({ "slice at", "swipe at", "slash at" }) ) ; 
}

int begin_spell(object caster, int lvl) {
    set("level", lvl);
    set("enchantment", 4);
    set("schools", ({ "evocation" }) );
    write("Make sure you wield the sword if you want to use it!\n");
    call_out("remove", lvl * 20 );
    return 1;
}

/* EOF */
