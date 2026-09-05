// File         : tangtou.c
// Created By   : iszt@pkuxkx, 2007-05-03

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("汤头歌诀", ({"tangtou gejue", "tangtou", "gejue", "jue", "book"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一本汤头歌诀，记载了大量基本知识。\n"NOR);
                set("unit", "本");
                set("value", 20000);
        }
        setup();
}

void init()
{
        add_action("do_look", ({"look", "scan"}));
        add_action("do_study", ({"study", "read"}));
}

int do_look(string arg)
{
        string msg;

        if(!id(arg))
                return 0;
        if(!(msg=read_file(__DIR__"tangtou.txt")))
                return notify_fail("你翻开一看，这是一本无字天书！……");
        this_player()->start_more(msg);
        return 1;
}

string* line;

int do_study(string arg)
{
        int times;
        int point;
        string msg;
        object me = this_player();

        if(!arg || (sscanf(arg, "%s %d", arg, times) != 2 && !id(arg)))
                return notify_fail("指令格式：study|read <id> <次数>\n");
        if(!id(arg))
                return 0;
        if(!times)
                times = 1;
        if(times > 50)
                return notify_fail("学习次数不能超过五十次。\n");
        if(me->is_busy())
                return notify_fail("你正忙着呢。\n");
        if(!me->query_skill("literate", 1))
                return notify_fail("你读了半天，一个字也不认识。\n");
        if(me->query("jing") < 10 * times)
                return notify_fail("你的精神不够，无法研读。\n");
        if(!line)
        {
                msg = read_file(__DIR__"tangtou.txt");
                line=explode(msg,"\n");
        }
        if(!line)
                return notify_fail("你翻开一看，这是一本无字天书！……");

        write(YEL"你仔细研读着汤头歌诀，道是：「"+line[random(sizeof(line))]+"」\n"NOR);
        if(random(2))
                message("vision",
                        me->name() + "拿着一本书仔细研读着。\n",
                        environment(me), ({me}) );
        me->receive_damage("jing", 10 * times);
        if(me->query_skill("medical-skill", 1) < 100)
        {
                point = to_int(pow(to_float(me->query_skill("literate", 1)), 0.5) + 1);
                point *= 2 * times;
                me->improve_skill("medical-skill", point);
        }
        else
                write("不过这本书上记述的内容非常基本，对你并没有什么作用。\n");
        return 1;
}
