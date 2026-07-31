
#include <ansi.h>  
#include <armor.h>

inherit NECK;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"ÇåË®ÏîÁ´"NOR, ({ "necklace16"}));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "´®");
		set("value", 3800);
		set("material", "gold");
	set("armor_prop/armor", 68);
set("armor_prop/constitution",18);
set("armor_prop/karay",19);
	}
	setup();
}	
