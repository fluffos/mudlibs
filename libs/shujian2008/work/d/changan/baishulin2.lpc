// Write By Yanyang@SJ 2001.10.3
// Room: /d/changan/baishulin2.c

inherit ROOM;
#include <room.h>

void create()
{
        set("short", "柏树林");
        set("long", @LONG
这是一片郁郁葱葱的柏树林。浓密宽厚的树叶遮蔽了日月星辰，使人分不
出昼夜。四下如死一般的寂静，只有风吹过树梢的沙沙之声。走到这里，你努
力的辨认着四周的方向，寻找出去的路。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"baishulin2",
                "west"   : __DIR__"baishulin2",
              "northwest": __DIR__"baishulin2",
              "northeast": __DIR__"baishulin2",
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        me->add_temp("ca_bsl",1);
  
        if( dir =="east") {
        if( me->query_temp("ca_bsl") > 20 + random(10) ) {
                me->move(__DIR__"wenquan");
                me->delete_temp("ca_bsl");
                return notify_fail("你转来转去，眼前终于看不到柏树了。\n");
                }
        }
        if( dir =="west") {
        if( me->query_temp("ca_bsl") > 20 + random(10) ) {
                me->move(__DIR__"changjie2");
                me->delete_temp("ca_bsl");
                return notify_fail("你转来转去，眼前终于看不到柏树了。\n");
                }
        }
        if( dir =="northwest") {
        if( me->query_temp("ca_bsl") > 20 + random(10) ) {
                me->move(__DIR__"baishulin1");
                me->delete_temp("ca_bsl");
                return notify_fail("你转来转去，发现眼前依然是一片密密麻麻柏树。\n");
                }
        }
        if( dir =="northeast") {
        if( me->query_temp("ca_bsl") > 20 + random(10) ) {
                me->move(__DIR__"shihuangling");
                me->delete_temp("ca_bsl");
                return notify_fail("你转来转去，眼前终于看不到柏树了。\n");
                }
        }
        return ::valid_leave(me,dir);
}