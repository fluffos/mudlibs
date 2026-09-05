// lover-rose.c 情人玫瑰
// Created by iszt@pkuxkx, 2007-02-14

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"情人玫瑰"NOR, ({"lover rose", "rose"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "束");
                set("long", HIM"这是一束鲜艳的玫瑰花，在这情人的节日传递着浓浓爱意。你不禁想闻闻(smell)它。\n"NOR);
                set("value", 500);
                set("no_store", 1);
                set("no_sell", 1);
                set("no_pawn", 1);
        }
        setup();
}

void init()
{
        add_action("do_smell", "smell");
}

int do_smell(string arg)
{
        object me = this_player();
        mapping skills = me->query_skills();
        string* sname = keys(skills);
        int i, level;

        if (!id(arg))
                return notify_fail("你要闻什么？\n");
        if(me->query("gift/20070214"))
                return notify_fail(HIM"你深深的闻了闻这束玫瑰，好香啊！\n"NOR);
        if(!me->query("couple"))
                return notify_fail("你尚未婚配，何来情人？莫非……有私情？\n");
        if(!sizeof(skills))
                return notify_fail("先去学点功夫再来吧！\n");

        me->set("gift/20070214", 1);

        i = random(sizeof(skills));
        level = 1 + random(4);
        me->set_skill(sname[i], skills[sname[i]] + level);

        message_vision(HIM"$N深深的闻了闻这束玫瑰，好香啊！\n"
                BNK+HIR"突然，花中射出一支暗器，直射$N的心窝，$N却神奇的毫发无损！\n"NOR, me);
        tell_object(me, HIC"你发觉你的「"+CHINESE_D->chinese(sname[i])+"」进步了！\n"NOR);

        CHANNEL_D->do_channel(this_object(), "sys",
                me->query("name") + "获得「" + CHINESE_D->chinese(sname[i]) +
                "」(" + sname[i] + ")" + chinese_number(level) + "级！");

        if(!random(3))
                CHANNEL_D->do_channel(this_object(), "rumor", "听说" +
                        me->query("name") + "的「" + CHINESE_D->chinese(sname[i]) +
                        "」进步了" + chinese_number(level+random(41)) + "级！");

        return 1;
}
