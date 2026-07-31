
#include <ansi.h>  
#include <armor.h>

inherit NECK;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"∂¨√∑œÓ¡¥"NOR, ({ "necklace8"}));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¥Æ");
		set("value", 3000);
		set("material", "gold");
	set("armor_prop/armor", 60);
set("armor_prop/constitution",14);
set("armor_prop/karay",15);
	}
	setup();
}	
