// huwan.c 护腕

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name( (order[random(13)])+"天羽护腕"NOR, ({ "wrists1"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		
		set("value", 1300);
		set("material", "cloth");
		set("armor_prop/armor", 55);
set("armor_prop/strength",11);
set("armor_prop/damage", 3);
	}
	setup();
}
