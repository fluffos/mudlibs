
inherit ITEM;

void create()
{
        set_name("仙人掌", ({ "xianren zhang","zhang" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long","这是一个仙人掌，可以用它来炼制药物。\n");
                set("medicine_type",([
			    "gongxiao" :20+random(10),
                            "type" : "气血",
		]));
                
        }

      
        setup();
}
