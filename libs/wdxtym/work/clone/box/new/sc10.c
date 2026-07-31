// necklace.c 肚带
#include <ansi.h>   
#include <armor.h>
 
inherit SURCOAT;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"深渊肚带"NOR, ({ "surcoat10"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "条");
		set("long", "这是一件皮质的深渊肚带，用以保护腹部。\n");
		set("value", 2100);
	set("armor_prop/dodge", 15);
set("armor_prop/intelligence",15);
set("armor_prop/armor", 32);
	}
	setup();
}
