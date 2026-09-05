// Room: /d/emei/guiyun.c 峨嵋派 归云阁

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "归云阁");
        set("long", @LONG
这里是千佛庵的归云阁，也是峨嵋派的藏经阁，是峨
嵋派的重地，阁内按顺序摆满了书架，书架上放满了各式
各样的书籍，有佛经的和武功的，峨嵋派的弟子经过掌门
同意可以来此借阅。不过要记得归还。
LONG    );

        set("exits", ([
		"westdown" : __DIR__"dcmen",
               ])); 
        set("objects",([
               __DIR__"npc/obj/jing1" : 1,
               __DIR__"npc/obj/jing2" : 1,
             ]));  
        setup();
        replace_program(ROOM);
}
