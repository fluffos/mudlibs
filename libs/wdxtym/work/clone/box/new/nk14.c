
#include <ansi.h>  
#include <armor.h>

inherit NECK;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"Ω≠∫”œÓ¡¥"NOR, ({ "necklace14"}));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¥Æ");
		set("value", 3600);
		set("material", "gold");
	set("armor_prop/armor", 66);
set("armor_prop/constitution",17);
set("armor_prop/karay",18);
	}
	setup();
}	
