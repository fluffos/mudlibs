// huwan.c ª§ÕÛ

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name( (order[random(13)])+"Œ‰“Ìª§ÕÛ"NOR, ({ "wrists16"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "À´");
		
		set("value", 3100);
		set("material", "cloth");
	set("armor_prop/armor", 60);
set("armor_prop/strength",18);
set("armor_prop/damage", 20);
	}
	setup();
}
