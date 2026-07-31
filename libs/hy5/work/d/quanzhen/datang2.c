// datang2.c 大堂二进
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大堂二进");
        set("long", @LONG
这里是大堂的第二重，是全真教弟子做功课的所在。现在还不到
功课时间，大堂里空荡荡的，只有全真教掌管上下杂事的掌理道长带
领着几个小道童在整理桌椅，预备餐饭。
LONG
        );
        set("exits", ([
                "east" : __DIR__"datang3",
                "west" : __DIR__"datang1",
                "north" : __DIR__"cetang",
                "south" : __DIR__"piandian",
        ]));
        set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects",([
                __DIR__"npc/zhangli" : 1,
                __DIR__"npc/daotong1" : 2,
                __DIR__"npc/daotong" : 2,
           "quest/menpai/quanzhen/shi" : 1,

        ]));
        setup();
        replace_program(ROOM);
}
