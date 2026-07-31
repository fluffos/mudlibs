// Room: /u/jpei/thd/tomb.c
// Modified by Numa 19990906

#include <ansi.h>
inherit ROOM;

string* msg = ({
        "东",
        "西",
        "南",
        "北",
});

string* msg1 = ({
        "匆忙",
        "急忙",
        "赶忙",
        "急急忙忙",
        "匆匆忙忙",
});

void create()
{
        set("short", "石坟");
        set("long", @LONG
从幽暗的高台迷阵中走出来，只见绿草如荫，中间是一片白色花丛,
重重叠叠，宛如一座白花堆成的小湖。白花之中有一块东西高高隆
起，走近了才发现是一座石坟，坟前有一块墓碑(mubei)。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"taohua1",
                "west" : __DIR__"taohua1",
                "south" : __DIR__"taohua1",
                "north" : __DIR__"taohua1",
        ]) );
        set("item_desc",([
                "mubei" : RED"
                        
                       ┌─┐
                       │桃│
                       │花│
                       │岛│
                       │女│
                       │主│
                       │冯│
                       │氏│
                       │埋│
                       │香│
                       │之│
                       │冢│
                       └─┘\n
"NOR
        ]) );
        set("no_clean_up", 0);
        set("outdoors","桃花岛");

        setup();
}

void init()
{
        object me = this_player();
        
        if (me->query_temp("thd/job"))
                call_out("do_job",1,me);
                
        add_action("do_bai", "bai");
        add_action("do_bai", "guibai");
        add_action("do_bai", "gui");
        add_action("do_bai", "kneel");
        add_action("do_push","push");
        add_action("do_push","tui");
}

int do_bai(string arg)
{
        object me = this_player();

        if (arg != "mubei")
                return notify_fail("你要拜什么？\n");
        
        message_vision("$N在坟前跪倒，恭恭敬敬地拜了四拜。\n", me);
        me->set_temp("tomb/kneel", 1);
        return 1;
}

int do_push(string arg)
{
        string dir;
        object me = this_player();
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢！\n");

        if (!me->query_temp("tomb/kneel"))
                return notify_fail("突然,从墓中冲出一个守墓弟子,恶狠狠的瞪了你一眼.\n");
        if (!arg || arg=="")
                return notify_fail("什么?\n");
        if( arg=="mubei")
        {
                write("你要推向哪个方向？\n");
                return 1;
        }
        
        else if (sscanf(arg,"mubei %s",dir)==1)
        {
                if (dir=="left" || dir=="zuo")
                {
                        me->add_temp("tomb/p_left",1);
                        write("你把墓碑缓缓往左边推去，发出了「咯吱」的声音。\n");
                        return 1;
                }
        
                else if (dir=="right" || dir=="you")
                {
                        me->add_temp("tomb/p_right",1);
                        write("你把墓碑缓缓往右边推去，发出了「咯吱」的声音。\n");
                        if ((int)me->query_temp("tomb/p_left")==3
                        &&  (int)me->query_temp("tomb/p_right")==3)
                        {
                                write("墓碑缓缓移开，露出一条石砌的地道。你赶忙走了进去。\n");
                                message("vision", "墓碑向两边缓缓移开，" + me->name() + "快步走了进去，墓碑又合拢关上了。\n", this_object(), me);
                                me->delete_temp("tomb/p_left");
                                me->delete_temp("tomb/p_right");
                                me->move(__DIR__"mudao1");
                                message("vision", me->name() + "打开暗门，走了进来。\n", environment(me), me);
                        }
                        return 1;
                }
                else {write("你要推向哪个方向?\n");return 1;}
        }
        else {write("你要干什么?\n");return 1;}
}


int valid_leave(object me,string dir)
{        
       me->delete_temp("tomb/p_left");
       me->delete_temp("tomb/p_right");
       me->delete_temp("tomb/kneel");
       return ::valid_leave(me,dir);
}

void do_job(object me)
{
        object ob;
        string p_id;
        tell_object(me,"黄蓉说完，就" + msg1[random(sizeof(msg1))] +"的离开了。\n");
        tell_object(me,HIR"突然，从" + msg[random(sizeof(msg))] + "边的桃花阵中闯出一个盗墓贼，钻进石坟就不见了。\n"NOR);
        me->delete_temp("thd/job");
        me->set_temp("thd/dojob",1);
        p_id = me->query("id");
        ob = new(__DIR__"npc/zei");
        ob->set_temp("target",p_id);
        ob->move(__DIR__"mushi");
}