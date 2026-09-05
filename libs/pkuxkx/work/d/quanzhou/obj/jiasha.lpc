// jiasha.c
//Jay 4/8/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_move", "move");
}

void create()
{
        set_name("袈裟", ({"jia sha", "jia", "sha"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一件旧得已经看不出颜色的袈裟，上面有好多窟窿。\n");
                set("unit", "件");
                set("material", "cloth");
                        set("count",1);
                set("no_get", "这样东西不能离开那儿。\n");

        }
        setup();
}

int do_move(string arg)
{
        object book;
        object me = this_player();
        if (!id(arg))
                return 0;
        if (this_object()->query("count") == 0)
        {
                message_vision("$N挪动了一下袈裟，却发现上面已经有许多手印，显然已经被人动过了。\n",this_player());
                return 1;
        }
        if (this_player()->query("passwd") ) {
                if (!present("kuihua baodian",me)){
                message_vision(
"$N轻轻地挪动袈裟，抖起一些尘土...，突然从袈裟的窟窿中滚出一本书到$N怀中。\n", this_player());
                book = new(__DIR__"kuihua");
                book->move(me);
                        this_object()->set("count",0);
                return 1;
                }
                message_vision(
"$N轻轻地挪动袈裟，抖起一些尘土，呛得$N直打喷嚏。\n", this_player());
                return 1;
        }
        else {
                message_vision(
"$N轻轻地挪动袈裟，突然从袈裟的窟窿中冒出一股毒气，钻进$N的鼻子中。\n", this_player());
                me->receive_damage("qi", 0, "乱动袈裟被机关毒");
                me->die();
                return 1;
        }
}

