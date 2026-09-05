// Room: /shenlongjiao/qianlongtang.c
// kiden 06/08/25
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", HIC"潜龙堂"NOR);
        set("long", @LONG
那后厅便在大厅之后，厅堂不大，居中两张竹椅，显然是教主及夫人的座位。
下面设了五张矮凳，看起来应该是五龙使的座位。
LONG
        );
//        set("outdoors", "shenlongdao");
    set("no_fight", 1);
        set("exits", ([
                "north" : __DIR__"xiangtang",     
                "south" : __DIR__"xianfuju",     
                "west" : __DIR__"xixiangfang",     
                "east" : __DIR__"dongxiangfang",     
        ]));

   set("objects", ([
//         __DIR__"npc/dizi":1,
                "/kungfu/class/shenlong/hong" : 1,
                "/kungfu/class/shenlong/su" : 1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
}

void init()
{
    add_action("do_none", "perform");
    add_action("do_none", "fight");
    add_action("do_none", "killall");
    add_action("do_none", "kill");
    add_action("do_none", "attack");
    add_action("do_none", "hit");
}
int do_none()
{
    tell_object(this_player(),"在神龙教主前动武，你真是活得不耐烦了！\n");
    return 1;
}
