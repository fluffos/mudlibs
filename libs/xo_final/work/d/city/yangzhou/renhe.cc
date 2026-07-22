// dali_renhe.c

#include <ansi.h>

inherit ROOM;


void create()
{
    set("short", YEL "仁和车行扬州分号" NOR);
    set("long", @LONG
仁和车行在扬州开设车行还是不久以前的事情。扬州那是海内闻名的“销金
窝子”，从各地赶来做买卖的商贾络绎不绝，来寻欢作乐的高官阔老也不计
其数，所以仁和车行早就瞄准了这个城市，只是扬州的水运一向很发达，他
们难以插手。前一段扬州的水运船只出了些麻烦，仁和车行终于成功地开设
了扬州分号。现在，来租车的三教九流的人物挤满了车行那并不十分宽敞的
前厅。LONG
        );
    set("no_fight", 1);
    set("exits", ([
            "east" : __DIR__"tongsi_men",
            ]) );
    set("objects", ([
            __DIR__"npc/pangzi" : 1,
            ] ) );
    setup();
}

int valid_leave( object me, string dir )
{
    if ( me->query_temp_marks("booked_mache") )
        return notify_fail("你应该快上马车了，不要再随便跑开。\n");

    else if ( me->query_temp_marks("waiting_mache") )
        return notify_fail("你正在等马车呢，不要随便走开。\n");
    else
        return ::valid_leave( me, dir);
}

