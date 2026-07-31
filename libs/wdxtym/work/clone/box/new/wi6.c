// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"Ïþ´äÑü´ø"NOR, ({ "waist6"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ìõ");
		
		set("value", 2000);
		set("material", "leather");
	set("armor_prop/armor", 50);
set("armor_prop/constitution",14);
set("armor_prop/dodge", 4);
	}
	setup();
}
