// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"鬼雨腰带"NOR, ({ "waist10"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		
		set("value", 2500);
		set("material", "leather");
		set("armor_prop/armor", 43);
set("armor_prop/constitution",15);
set("armor_prop/dodge", 7);
	}
	setup();
}
