// toukui.c 头盔
#include <ansi.h>  
#include <armor.h>
 
inherit HEAD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"血斩头盔"NOR, ({ "helmet15" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "顶");
		set("long", "这是一顶血斩头盔，用以保护头部。\n");
		set("value", 2900);
set("armor_prop/intelligence",18);
set("armor_prop/armor", 89);
set("armor_prop/defense", 21);
	}
	setup();
}