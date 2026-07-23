// baopi.c 雪豹皮
// by iceland
#include <ansi.h> 
#include <armor.h> 
 
inherit CLOTH; 

void create() 
{ 
	set_name( WHT "雪豹皮" NOR, ({ "bao pi", "baopi","pi" }) ); 
	set_weight(2500);
	if( clonep() ) 
		set_default_object(__FILE__); 
	else { 
		set("unit", "张");
		set("long", "这是一件上好的毛皮，摸上去温暖柔软，只有雪山中的雪豹才有这种皮毛。\n"); 
		set("value", 50000);
		set("material", "fur");
		set("armor_prop/armor", 20);
	} 
	setup(); 
} 
