// boots.c 皮靴
#include <ansi.h> 
#include <armor.h>

inherit BOOTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"狮枭之靴"NOR, ({ "boots8"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "双");
		set("long", "这是一双狮枭之靴。用以保护足部。并加快你的速度。\n");
		set("value", 1600);
set("armor_prop/armor", 60);
	set("armor_prop/dodge", 17);
set("armor_prop/dexterity",15);
	}
	setup();
}
