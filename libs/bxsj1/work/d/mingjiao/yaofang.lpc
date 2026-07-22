// yafang.c 药房
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIG"药房"NOR);
    set("long",@LONG
这里是明教的藏药室。各种灵丹秒药应有尽有，有各大门派感于张教主而
相赠的，加之张教主精通医术，练丹治病更是易为。这里灵丹飘香，一进来就
能令你精神一展。西面是一条通向聚义堂的走廊。
LONG);
    set("exits",([
           "west" :  __DIR__"wu1",
    ]));
	set("indoors", "明教");
    set("objects", ([
        __DIR__"npc/xtong" : 1,
        __DIR__"npc/yaoshi" : 1,
    ]));
    set("coor/x",-280);
  set("coor/y",200);
   set("coor/z",120);
   set("coor/x",-280);
 set("coor/y",200);
   set("coor/z",120);
   setup();

}
void init()
{
       	object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("yaofang"))
           me->set_temp("yaofang",1);
}
