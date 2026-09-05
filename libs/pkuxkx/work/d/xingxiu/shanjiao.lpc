// tianshan: /d/xingxiu/shanjiao.c
// Jay 3/17/96

inherit ROOM;
#include "/d/xingxiu/flower.h"
void create()
{
        set("short", "小山坡");
        set("long", @LONG
这里是一处小山坡，西面是被黄河冲积而成的大片肥沃土地，自古有
“黄河百害，唯富一套”的说法。地上有个沙丘(shaqiu)，有点古怪。西
北面是一个还算繁盛的小镇子，东南方向是六盘山了。
LONG
        );
        set("exits", ([
            "westup" : __DIR__"tianroad1",
            "northwest" : __DIR__"beijiang",
            "southwest" : __DIR__"nanjiang",
            "north" : "d/huijiang/shanlu1",
            "southeast" : __DIR__"xxroad3",
]));
        set("item_desc", ([
                "shaqiu" : "这个沙丘明显和周围环境不符，你可以推(push)开试试。\n",
                "沙丘" : "这个沙丘明显和周围环境不符，你可以推(push)开试试。\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai" );
        set("objects", ([
            __DIR__"npc/trader" : 1,
             flower:random(2),]));

        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_push", "push");
        add_action("do_push", "tui");
}
int do_push(string arg)
{
        object me;
        mapping fam;

        me = this_player();

        if( !arg || arg=="" ) return notify_fail("你要推什么？\n");

        if( arg=="shaqiu" || arg=="沙丘")
        {
                if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
                {
                        message_vision("$N推开沙丘，只见泥沙纷纷跌落，地面上露出一个小洞。\n", me);
                        message("vision",
                                me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/underxx");
                        message("vision",
                                me->name() + "从洞里走了进来。\n",
                                environment(me), ({me}) );
                        return 1;
                }
                else 
                        return notify_fail("这么小的洞，你钻得进去吗？\n");
        }
}       



int valid_leave(object me, string dir)
{
    int current_water;
    if (dir == "southwest") {

        if (!userp(me)) return 0;
        current_water = me->query("water");
        if (current_water==0) {
        }

        if (current_water>0 && current_water<20) {
            me->set("water",0);
        }

        if (current_water>20) {
            me->set("water",current_water-20);
        }
        return ::valid_leave(me, dir);
    }
        return ::valid_leave(me, dir);

}
