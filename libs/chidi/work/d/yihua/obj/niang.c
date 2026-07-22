inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("百花酿", ({ "baihua niang","niang" }));
        set_weight(1000);
        if( clonep() )
          set_default_object(__FILE__);
        else {
        set("long",
            "这是一碗宫主用百花经过十年时间酿出的百花酿。!\n");
        set("unit", "碗");
        set("value", 0);
        set("food_supply", 60);
        set("max_liquid", 20);
        }
        set("liquid", ([
            "name" : "百花酿",
            "remaining" : 50,
       	    "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}