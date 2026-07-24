
#include <ansi.h>  
#include <armor.h>

inherit NECK;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"夏雨项链"NOR, ({ "necklace2"}));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("value", 2500);
		set("material", "gold");
		set("armor_prop/armor", 64);
set("armor_prop/constitution",11);
set("armor_prop/karay",13);
	}
	setup();
}	
