//      cedian1.c 侧殿
//      Designed by secret (秘密)
//      97/04/09

#include <room.h>
inherit ROOM;

void create()
{
        set("short","侧殿");
        set("long",@LONG
这里是雪山寺的东侧殿。殿内有神态各异的十八罗汉
塑像，金旒玉镶，很是庄严。
LONG );
        set("exits",([
                "up"   : __DIR__"zoulang1",
                "west" : __DIR__"dadian",
        ]));
        set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects",([
                CLASS_D("xueshan")+"/jiamu" : 1,
                __DIR__"npc/xiang-ke"       : 3,
                "quest/menpai/xueshan/shi" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=(mapping)me->query("family");
        if( (!myfam || myfam["family_name"] !="雪山寺") && dir=="up"
        && objectp(present ("jiamu huofo", environment(me))))
                return notify_fail("嘉木活佛说道: 你非雪山寺弟子, 不能入内。\n");
        return ::valid_leave(me,dir);
}


