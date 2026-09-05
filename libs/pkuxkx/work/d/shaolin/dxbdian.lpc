// Room: /d/shaolin/dxbdian.c
// Date: YZC 96/01/19
// change by bibi
// 修改了提示信息及更新，去掉了磕头次数太多时晕倒得限制。
// notme
inherit ROOM;

void create()
{
    set("short", "大雄宝殿");
    set("long", @LONG
这里是少林寺的大雄宝殿。正中供奉着如来三宝，左右各是
文殊、普贤菩萨。一群青衣小和尚们正在佛像前的地上诵经。
缕缕香烟与梵唱交错在一起，仰视佛祖拈花浅笑的面容，令人顿
时生起几分脱俗之感。身边经常有一队队僧人鱼贯而入，看他们
手持戒刀，似乎是巡寺的僧人。
LONG
       );

    set("exits", ([
                "southdown" : __DIR__"guangchang2",
                ]));

    set("book_count",1);

    set("objects",([
                CLASS_D("shaolin") + "/dao-zheng" : 1,
                __DIR__"npc/xiang-ke" : 1,
                ]));
    setup();

}

void init()
{
    add_action("do_ketou", "ketou");
}

int do_ketou()
{
    object me, ob;

    me = this_player();

    if ((int)me->query("jing")<20)
        return notify_fail("你实在是太疲倦了，不能再磕头了！\n");

    if(me->query_skill("force", 1) > 100)
        return notify_fail("你的内功已经超高 100 级了，再磕头也没用！\n");
        
    message_vision("$N虔诚地跪下来，在如来佛祖面前磕头。\n", me);
    
    if(present("silk", me))
    {                              
        me->receive_damage("jing", 20);
        me->improve_skill("force", me->query("int"));
        if ( !random(5) )
            tell_object(me, "冥冥之中，你似乎觉得佛祖在点拨你在内功方面的疑难。\n");
        return 1;    
    }
        
    if(query_temp("been_get")) 
        return notify_fail("不用磕头了，内功心法已经被人拿走了。\n");
    if ( !random(100) )
    {
        set_temp("been_get",1);
        ob=new("d/shaolin/obj/book-silk");
        ob->move("/d/shaolin/dxbdian");
        tell_object(me, "突然你面前，啪地一声掉下一束羊皮线穿起来的薄绢！\n");
    }
    return 1;
}
void reset()
{
    ::reset();
    delete_temp("been_get");
}

