// toukui.c 头盔
#include <ansi.h>  
#include <armor.h>
 
inherit HEAD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"饕餮头盔"NOR, ({ "helmet12" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "顶");
		set("long", "这是一顶饕餮头盔，用以保护头部。\n");
		set("value", 2600);
set("armor_prop/intelligence",17);
set("armor_prop/armor", 76);
set("armor_prop/defense", 9);
	}
	setup();
}