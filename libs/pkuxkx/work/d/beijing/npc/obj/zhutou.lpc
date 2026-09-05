
//iszt@pkuxkx, 2006-09-13
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"猪头"NOR, ({"zhu tou", "zhutou", "tou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个"HIR"猪头"NOR"，不知道吃下去会有什么效果。\n");
                set("value", 1000);
        }

        setup();
}

int do_eat(string arg)
{
        int i;
        object *all;
        object me = this_player();
        object room = environment(me);
        string msg;

        if (!id(arg))
                return notify_fail("你要吃什么？\n");

        message_vision(HIG"$N狼吞虎咽的吃下一个"HIR"猪头"HIG"，不禁有些洋洋自得，似乎领悟了什么。\n"NOR, me);
        me->add_temp("zhutou_count", 1);
        all = all_inventory(environment(me));
        for (i=0; i<sizeof(all); i++)
        {
                if(!living(all[i]))
                        continue;
                if(!userp(all[i]))
                {
                        msg = HIC"【闲聊】" + all[i]->query("name") + HIG"(" + capitalize(all[i]->query("id")) + ")";
                        break;
                }
                if(me != all[i])
                        msg = HIC"【闲聊】" + all[i]->query("name") + HIG"(" + capitalize(all[i]->query("id")) + ")";
        }
        if(!msg)
        {
                msg = HIC"【闲聊】" + me->query("name") + HIG"(" + capitalize(me->query("id")) + ")"HIC"：啊～～～～我怎么变成这个样子了？？！！\n"NOR;
                if(random(2) && me->query_temp("zhutou_count") < 10)
                        message("channel:rumor", HIM"【谣言】某人：听说" + me->query("name") + HIM"在" + room->query("short") + HIM"变成了一个"HIR"猪头"HIM"！\n"NOR, users());
        }
        else
                msg += HIC"：啊～～～～快来" + room->query("short") + HIC"看，" + me->query("name") + HIC"变成"HIR"猪头"HIC"了！！\n"NOR;
        if(random(2) && me->query_temp("zhutou_count") < 10)
                message("channel:chat", msg, users());
        me->set_temp("apply/short", HIR"猪头 "NOR + me->query("name") + "(" + capitalize(me->query("id")) + ")");
        if(random(3) == 0)
                me->improve_skill("huyou-wiz", 2);
        else if(random(2) == 0)
                me->improve_skill("chatting", 2);
        else
                me->improve_skill("rumoring", 2);
        me->start_busy(2);
        
        destruct(this_object());
        return 1;
}
