// Room: /u/zqb/shaolin/qdian.c
// by zqb

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "前殿");
        set("long", @LONG
这里是天王殿前的一处前殿。规模很小，殿内亦无很多摆设。只有几个
小沙祢在接待着来往的香客。透过洞开的大门，可以看到前面规模雄伟的天
王殿。
LONG
        );

        set("exits", ([
                "south" : __DIR__"gchang-1",
                "north" : __DIR__"twdian",
        ]));

        set("objects",([
                CLASS_D("shaolin") + "/qing-shan" : 1,
                __DIR__"npc/xiang-ke" : 1, 
        ]));

        set("coor/x",50);
  set("coor/y",230);
   set("coor/z",110);
   setup();
}

void init()
{
        object me = this_player();
        
	if (userp(me) && me->query("jingli") < 50) {
                message_vision(HIY"只见$N脚下一滑，仰面摔了个大马趴，原来$N踩了个香蕉皮。\n"NOR,me);
                me->start_busy(2);
        }
}
