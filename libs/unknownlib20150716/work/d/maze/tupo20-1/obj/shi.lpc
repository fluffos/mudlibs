#include <ansi.h>
inherit COMBINED_ITEM;

void setup()
{}

void random_type(){ }	

void create()
{

	if( random(5)==0 )
	{
		set_name("石块",({"shi kuai","shi","stone",}));
		set("long","山中一颗普通的石块。\n");
	}
	else
	{	
        	set_name("灵石", ({"ling shi", "shi","stone"}));
        	set("long", "一颗山中石块，历经日月洗涤，稍微有了些灵气，不时的闪着霞光。\n");
        	random_type();
        }
        if(clonep())
		set_default_object(__FILE__);
        else 
        {
                set("unit", "些");
                set("base_unit", "颗");
                set("value", 0);
                set("base_weight",1);
	}
     	set_amount(1);
        setup();
}
