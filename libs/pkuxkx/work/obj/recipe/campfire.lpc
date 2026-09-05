inherit ITEM;

void create()
{
        set_name("篝火", ({"camp fire", "fire"}));
        set_weight(80000);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这是一堆篝火，利用它就可以来烹饪食物了。\n");
                set("unit", "堆");
                set("value", 1);
                set("no_get", 1);
        }
}

void init()
{
	call_out("ximie", 300, this_object());
}

void ximie(object ob)
{
    tell_room(environment(ob), "篝火的光芒跳动了几下，然后就熄灭了，霎时间，四周一片漆黑。\n");
    destruct(ob);
}