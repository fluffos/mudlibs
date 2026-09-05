// item: yaofang.c
// Jay 3/18/96
//write by lysh
inherit ITEM;

void setup()
{}


void create()
{
        set_name("九花玉露丸药方", ({"yao fang", "fang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这是一张九花玉露丸的药方。通天草，紫檀花，蛤蟆肉，雪莲。\n");
                set("value", 10);
        }
        setup();
}

