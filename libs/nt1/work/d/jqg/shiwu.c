// shiwu.c 大石屋
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIW"大石屋"NOR);
            set("long",@LONG
一座极大的石屋出现在眼前，只见两名绿衫僮儿手执拂尘，站在石屋门前。
石屋二边是绝壁峭崖，几株长在绝壁上松树长得很茂盛，把石屋遮得严严实实
的，远远看来，几乎看不出在这深谷中还有座石屋。
LONG
       );
            set("exits",([
              "south": __DIR__"qsroad",
              "enter": __DIR__"dating",
            ]));

            set("outdoor","绝情谷");
            set("objects",([
               __DIR__"npc/fan": 1,
               __DIR__"npc/tonger2": 2,
            ]));
	    setup();
}

int valid_leave(object me, string dir)
{
        if ( present("fan yiweng", environment(me)) 
           && dir =="enter")
         return notify_fail("樊一翁拦住你的去路，抱拳道：绝情谷中禁止外派弟子进入。\n");
         return ::valid_leave(me, dir);
}
