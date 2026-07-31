// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"Ò¹ÔÆÑü´ø"NOR, ({ "waist2"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ìõ");
		
		set("value", 1600);
		set("material", "leather");
	set("armor_prop/armor", 6);
set("armor_prop/constitution",1);
set("armor_prop/dodge", 3);
	}
	setup();
}
