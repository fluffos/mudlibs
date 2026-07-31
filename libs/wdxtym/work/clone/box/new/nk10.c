
#include <ansi.h>  
#include <armor.h>

inherit NECK;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"ÓðÈªÏîÁ´"NOR, ({ "necklace10"}));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "´®");
		set("value", 3200);
		set("material", "gold");
	set("armor_prop/armor", 62);
set("armor_prop/constitution",15);
set("armor_prop/karay",16);
	}
	setup();
}	
