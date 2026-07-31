// shield.c ≈£∆§∂‹
#include <ansi.h>   
#include <armor.h>
 
inherit SHIELD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"—„Ù·÷Æ∂‹"NOR, ({ "shield2"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "√Ê");
		set("value", 1200);
	set("armor_prop/armor", 69);
	set("armor_prop/defense", 14);
set("armor_prop/strength",1);
	}
	setup();
}
