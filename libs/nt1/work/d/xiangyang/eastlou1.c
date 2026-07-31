inherit ROOM;

void create()
{
        set("short", "城东箭楼");
        set("long", @LONG
这是东城头的箭楼，里面布满了一排的垛口，一排大宋的箭手们正警
惕地监视着城外的一举一动，随时准备给前来偷袭的蒙古兵以迎头痛击。
LONG );
        set("indoors", "xiangyang");
        set("no_clean_up", 0);
        set("site", "east_out");
        set("no_fly",1);     
        set("exits", ([
                "east" : __DIR__"east_out1",
                "down" : __DIR__"eastgate1",
                "up"   : __DIR__"eastlou2",  
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "east")
                return notify_fail("冲出去做什么，送死啊？\n");

        return ::valid_leave(me,dir);
}

void init()
{
        object me = this_player();

        if (me->query_temp("guo_jianlou/mark_jianlou") == 2
        &&  ! me->query_temp("guo_shoucheng/start_job")
        &&  ! me->query_temp("guo_shoucheng/job_over")
        &&  ! me->query("guo_shoucheng/failed"))
        {
                me->set_temp("guo_shoucheng/start_job", 1);
                me->apply_condition("jobjianlou_limit", 40 + random(10));
        }
}

