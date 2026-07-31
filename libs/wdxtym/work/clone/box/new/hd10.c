// toukui.c 头盔
#include <ansi.h>  
#include <armor.h>
 
inherit HEAD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"螭吻头盔"NOR, ({ "helmet10" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "顶");
		set("long", "这是一顶螭吻头盔，用以保护头部。\n");
		set("value", 2400);
set("armor_prop/intelligence",16);
set("armor_prop/armor", 74);
set("armor_prop/defense", 8);
	}
	setup();
}