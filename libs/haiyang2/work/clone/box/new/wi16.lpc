// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"须弥腰带"NOR, ({ "waist16"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		
		set("value", 2900);
		set("material", "leather");
		set("armor_prop/armor", 18);
set("armor_prop/constitution",8);
set("armor_prop/dodge", 9);
	}
	setup();
}
