// File         : zhiqian.c
// Created By   : iszt@pkuxkx, 2007-05-01

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("纸钱", ({"zhi qian", "zhiqian", "qian"}));
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一叠纸钱，可以烧给地下的亲友，也可以撒向空中。\n"NOR);
                set("unit", "叠");
                set("value", 200);
        }
        setup();
}

void init()
{
        add_action("do_shao", ({"shao", "burn"}));
        add_action("do_sa", ({"sa", "throw"}));
}

int do_shao(string arg)
{
        object me = this_player();

        if(!id(arg))
                return 0;
        if(!present("fire", me))
        {
                write("没有火折，用什么点火？\n");
                return 1;
        }
        message_vision(HIW"$N点起火折，默默烧了一叠$n，火舌跳动着……\n"NOR, me, this_object());
        destruct(this_object());
        return 1;
}

int do_sa(string arg)
{
        object me = this_player();
        object where = environment(me);
        string* desc;
        int size, len, pos;
        string extra = "遍地撒满了纸钱。";

        if(!id(arg))
                return notify_fail("你要撒什么？\n");
        if(!where->query("outdoors"))
        {
                write("只能在屋外撒纸钱。\n");
                return 1;
        }
        if(!stringp(where->query("long")) || strwidth(where->query("long")) <= 20)
        {
                write("这里什么也看不清，还是别撒了。\n");
                return 1;
        }
        if(where->query("zhi qian"))
        {
                message_vision(HIW"$N一言不发，掏出一叠$n，撒向空中，任$n随风飘散……\n"NOR, me, this_object());
                destruct(this_object());
                return 1;
        }
        where->set("zhi qian", 1);

        desc = explode(where->query("long"), "\n");
        size = sizeof(desc);
        if(strwidth(desc[size-1]) == COLOR_D->color_len(desc[size-1]))
                size --;
        len = 70 - strwidth(desc[size-1]);
        pos = strwidth(where->query("long")) - 2 - COLOR_D->color_len(desc[sizeof(desc)-1]);
        if(len>strwidth(extra))
                where->set("long", where->query("long")[0..pos]+extra
                        +where->query("long")[pos+1..strwidth(where->query("long"))]);
        else
                where->set("long", where->query("long")[0..pos]
                        +extra[0..len-1]+"\n"+extra[len..strwidth(extra)-1]
                        +where->query("long")[pos+1..strwidth(where->query("long"))]);
        message_vision(HIW"$N一言不发，掏出一叠$n，撒向空中，任$n随风飘散……\n"NOR, me, this_object());
        destruct(this_object());
        return 1;
}
