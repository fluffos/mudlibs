// yugan.c  破渔竿
//Jay 4/8/96

#include <ansi.h>

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_get", "get");
}

void create()
{
        set_name("破渔竿", ({"poyu gan", "gan"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一根当年鹿鼎公韦爵爷落难此岛时，曾经使用过的钓鱼竿。\n");
                set("unit", "根");
                set("material", "cloth");
        }
        setup();
}

int do_get(string arg)
{
        object xian;
        object me = this_player();
       if (!id(arg) || arg=="all")
                 return 1;
//        if (this_player()->query("passwd") ) {
//                if (!present("kuihua baodian",me)){
		tell_object(me, HIY 
"你轻轻地拿起渔竿，经过长期的日晒雨淋，渔竿已经腐朽，在你手中断为几节......
你只得到了鱼线及鱼钩。\n"NOR);
                xian = new(__DIR__"yuxian");
                xian->move(me);
	        destruct(this_object());
                return 1;
}
