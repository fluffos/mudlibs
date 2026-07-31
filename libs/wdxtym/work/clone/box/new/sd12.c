// shield.c ≈£∆§∂‹
#include <ansi.h>   
#include <armor.h>
 
inherit SHIELD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"√Õª¢÷Æ∂‹"NOR, ({ "shield12"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "√Ê");
		set("value", 2100);
	set("armor_prop/armor", 88);
	set("armor_prop/defense", 29);
set("armor_prop/strength",5);
	}
	setup();
}
