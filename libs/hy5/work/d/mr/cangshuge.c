// /u/beyond/mr/cangshuge.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"藏书阁"NOR);
         set ("long",@long
这里是曼陀罗山庄的藏书阁, 天下武功皆荟粹与此, 包罗万象,可与 "燕子
坞" 的藏书相辟敌。 屋子四周全是一排排高大的书架。
long);
set("no_fight", 1);
set("exits",([
"down" : __DIR__"yunjinlou",
]));
	setup();
	replace_program(ROOM);
}
