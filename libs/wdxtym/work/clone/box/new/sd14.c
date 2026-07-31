// shield.c Å£Æ¤¶Ü
#include <ansi.h>   
#include <armor.h>
 
inherit SHIELD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"ÆÃË®Ö®¶Ü"NOR, ({ "shield14"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "Ãæ");
		set("value", 2300);
	set("armor_prop/armor", 80);
	set("armor_prop/defense", 20);
set("armor_prop/strength",6);
	}
	setup();
}
