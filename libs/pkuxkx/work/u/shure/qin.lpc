// npc/obj/qin.c 七弦琴
// by Shure 2001-9-1.  

#include <dbase.h>
inherit MUSIC;

void create() 
{
    	set_name("七弦琴", ({"qixian qin", "qin" }) );  
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else 
   	{
       		set("long", "这是一张仲尼式的玄漆素琴。\n褐色的绦子略显旧色，琴颈之上镌刻着[[36m五陵柏斫[2;37;0m]四字。\n"); 
        	set("unit", "张");
        	set("material", "wood"); 
        	set("type", "heptachord");	
        	set("value", 20000);
    	}
	setup();  
}