// Room: /d/putian/fzshi.c 方丈室
// Lklv 2001.9.12

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"方丈室"NOR);
        set("long", @LONG
这里是方丈室，室内摆有一方桌，桌子旁边有几把藤椅，靠窗的位置有一
张茶几，茶几前摆一个蒲团，南面放有一张竹床，看起来很简单。西首墙上写
有一段金刚经的经文，
LONG
        );

        set("exits", ([
                "east" : __DIR__"changlang2",
        ]));

        set("objects",([
                __DIR__"npc/shami" : 1,
        ]));

        setup();
}
