// By River@sj 99.5.24
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
      set("short", YEL"洞口"NOR);
      set("long", @LONG
这是一条崎岖的山路，路面上夹杂着一些泥沙，两边长着一些野草，开出
来的野花飘着阵阵花香。四下长草齐膝，一片寂静。你在山石草丛之中行走良
久，来到一个大山洞前。
LONG
    );

     set("exits", ([
        "southeast" : __DIR__"xiaolu3",
        "enter" : __DIR__"shandong",
     ]));

     set("objects",([
           "/d/gumu/npc/diao" : 1,
     ]));

     set("outdoors", "襄阳");

     setup();
}

int valid_leave(object me, string dir)
{
        if ( ! me->query("ygpass")
         && dir == "enter"
         && objectp(present("shen diao", environment(me))))
           return notify_fail("神雕伸出翅膀拦住你的去路，神情藐视的看着你。\n");
           return ::valid_leave(me, dir);
}
