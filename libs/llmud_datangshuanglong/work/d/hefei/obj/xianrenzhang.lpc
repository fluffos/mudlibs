
inherit ITEM;

void create()
{
        set_name("仙人掌", ({ "xianren zhang","zhang" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
				set("long","这是一个仙人掌，可以用它来炼制。\n");
                set("value", 200);
				set("heal",([
					"heals":15,
					]));
                
        }

      
        setup();
}
