#include <mudlib.h>
#include <magic.h>

inherit ARMOR;
	void create(){
	set("author", "sebastian");
	set("id", ({ "Seb's ring", "ring", "Sebastian's ring"}));
	set("short", "hematite ring");
	set("long", @EndText
A plain hematite ring, with glowing runes upon the surface.
EndText
);
	set_armor_type("ring");
	set("size", -1);
	set("magic_defense", 2);
	set("prevent_drop", 1);
	set("prevent_get", 1);
	set("equip_func", "equip_func");
}

int equip_func(){
TP->resistance("cold", 0);
return 1;
}
int query_auto_load(){return 1;}
