// huwan.c »¤Íó

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name( (order[random(13)])+"ÐÇÁú»¤Íó"NOR, ({ "wrists9"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ë«");
		
		set("value", 2100);
		set("material", "cloth");
	set("armor_prop/armor", 33);
set("armor_prop/strength",8);
set("armor_prop/damage", 7);
	}
	setup();
}
