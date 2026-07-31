// huwan.c »¤Íó

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name( (order[random(13)])+"¶ÉÐÄ»¤Íó"NOR, ({ "wrists3"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ë«");
		
		set("value", 1500);
		set("material", "cloth");
	set("armor_prop/armor", 37);
set("armor_prop/strength",10);
set("armor_prop/damage", 4);
	}
	setup();
}
