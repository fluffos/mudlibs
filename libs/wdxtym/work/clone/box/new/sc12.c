// necklace.c 肚带
#include <ansi.h>   
#include <armor.h>
 
inherit SURCOAT;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"大川肚带"NOR, ({ "surcoat12"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "条");
		set("long", "这是一件皮质的大川肚带，用以保护腹部。\n");
		set("value", 2300);
	set("armor_prop/dodge", 16);
set("armor_prop/intelligence",16);
set("armor_prop/armor", 34);
	}
	setup();
}
