// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"Ã÷íøÑü´ø"NOR, ({ "waist8"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ìõ");
		
		set("value", 2400);
		set("material", "leather");
	set("armor_prop/armor", 52);
set("armor_prop/constitution",16);
set("armor_prop/dodge", 5);
	}
	setup();
}
