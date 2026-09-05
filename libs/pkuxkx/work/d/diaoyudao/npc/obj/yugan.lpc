// yugan.c
//Jay 4/8/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_get", "get");
}

void create()
{
        set_name("破渔竿", ({"yu gan", "gan"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一根当年鹿鼎公韦爵爷落难此岛时，曾经使用过的钓鱼竿。\n");
                set("unit", "根");
                set("material", "cloth");
//                set("no_get", "这样东西不能离开那儿。\n");

        }
        setup();
}

int do_get(string arg)
{
        object xian;
        object me = this_player();
        if (!id(arg))
                return 0;
//        if (this_player()->query("passwd") ) {
//                if (!present("kuihua baodian",me)){
                message_vision(
"$N轻轻地拿起渔竿，经过长期的日晒雨淋，渔竿已经腐朽，在$N手中断为几节......
$N只得到了鱼线及鱼钩。\n", this_player());
                xian = new(__DIR__"yuxian");
                xian->move(me);
		me->unconcious();
	        destruct(this_object());

                return 1;
//                }
/*
                message_vision(
"$N轻轻地挪动袈裟，抖起一些尘土，呛得$N直打喷嚏。\n", this_player());
                return 1;
        }
        else {
                message_vision(
"$N轻轻地挪动袈裟，突然从袈裟的窟窿中冒出一股毒气，钻进$N的鼻子中。\n", this_player());
                me->die();
                return 1;
        }
*/
}
