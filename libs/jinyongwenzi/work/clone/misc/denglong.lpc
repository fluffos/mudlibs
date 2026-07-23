// item: denglong.c
// by snowman@SJ , 01/05/1999.

inherit FIRE_ITEM;
void create()
{
        set_name("灯笼", ({"deng long", "deng", "light"}));
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盏纸敷的灯笼，到了黑暗的地方就用(light)得着了。\n");
                set("unit", "盏");
                set("value", 100);
                set("light/time", 180);
        }
        setup();
}


