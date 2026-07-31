// shield.c ≈£∆§∂‹
#include <ansi.h>   
#include <armor.h>
 
inherit SHIELD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"ªﬁπ‚÷Æ∂‹"NOR, ({ "shield16"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "√Ê");
		set("value", 2500);
	set("armor_prop/armor", 81);
	set("armor_prop/defense", 20);
set("armor_prop/strength",8);
	}
	setup();
}
