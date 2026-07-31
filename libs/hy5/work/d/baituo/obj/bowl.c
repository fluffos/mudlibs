//海口大碗

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("海口大碗", ({"bowl","wan" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只可盛水的粗瓷大碗。\n");
		set("value", 0);
		set("max_liquid", 6);
        }
        set("liquid", ([
            "name" : "清水",
            "remaining" : 8,
                "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}
