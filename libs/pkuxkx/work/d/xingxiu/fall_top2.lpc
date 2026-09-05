// 谷底
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
string look_fall();
void create()
{
	set("short", "巨石");
	set("long", @LONG
这里是一块巨石，正是观赏瀑布(fall)的好所在。你也可以游(swim)回去。
LONG
	);
    set("outdoors", "xingxiuhai");
    set("item_desc", ([ 
        "fall" : (:look_fall:),
    ])); 
    setup();
    ::create();
}

string look_fall()
{
    object me=this_player();
    string msg;
    string *colors=({HIW,WHT,HIC,CYN,HIG,HIB});
    string color=colors[random(sizeof(colors))];
    int n=random(100);
    if (time()-(int)me->query_temp("xx_valley_quest_watch_fall")<360)
    {
        msg=color+"瀑布虽美，老看也会累的。\n"+NOR;
        return msg;
    }
    me->set_temp("xx_valley_quest_watch_fall",time());
    if (n>74)
    {
        msg=color+"来到这里，你不禁想起李白的诗句“飞流直下三千尺，疑是银河落九天。”\n"+NOR;
    }
    else if (n>49)
    {
        msg=color+"白练似的瀑布直坠下去，底下的事物看着非常渺小，你不禁很有些一览众山小的感觉。\n"+NOR;
    }
    else if (n>24)
    {
        msg=color+"瀑布虽然壮阔，但天空更为广博。\n"+NOR;
    }
    else if (n>1)
    {
        msg=color+"如此美景，你不禁生出跳(jump)下去，埋骨此处的冲动。\n"+NOR;
    }
    else
    {
        msg=color+"此处瀑布，似乎很有些和武学相关的联系，你快回去找我踏月色而来讨教一下『武学』吧。\n"+NOR;
        me->set_temp("xx_valley_quest_ask_zine_skill",1);
    }
    return msg;
}
void init()
{
    add_action("do_jump","jump");
    add_action("do_swim","swim");
}

int do_jump(string arg)
{
    object rm,me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (arg!="down")
    {
        return 0;
    }
    if (!me->query_temp("xx_valley_quest_jump_fall_die"))
    {
        me->set_temp("xx_valley_quest_jump_fall_die",1);
        tell_object(me,"你真的要轻生吗？jump down下去可就没命了！\n");
        return 1;
    }
    rm=load_object(__DIR__"waterfall");
    message_vision(HIR"$N纵身跳下了瀑布。\n"NOR,me);
    tell_room(rm,"只见一个人影越来越大，飞坠下来。\n");
    me->move(rm);
    if (random(1000)>900)
    {
        me->unconcious();
    }
    else
    {
        me->receive_damage("qi", 0, "跳下瀑布摔");
        me->die();
    }
    return 1;
}

int do_swim()
{
    object rm,me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    rm=load_object(__DIR__"fall_top");
    message_vision(HIG"$N使出吃奶的劲，向"+rm->query("short")+HIG+"游了过去。\n"NOR,me);
    me->add_busy(3+random(3));
    tell_room(rm,me->name()+"十分艰难地游了过来。\n");
    me->move(rm);
    return 1;
}
