// shield.c Å£Æ¤¶Ü
#include <ansi.h>   
#include <armor.h>
 
inherit SHIELD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"ÁúÍ·Ö®¶Ü"NOR, ({ "shield11"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "Ãæ");
		set("value", 2000);
	set("armor_prop/armor", 87);
	set("armor_prop/defense", 28);
set("armor_prop/strength",5);
	}
	setup();
}
