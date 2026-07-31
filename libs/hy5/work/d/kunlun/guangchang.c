#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "广场");
		  set("long",@long
这里是一个平平开阔的大广场，广场上有昆仑派的弟子在习武，前面不远处是
个巨大的石屏风，后面就是昆仑派的前厅了，西面和东面仍然是广场。
long);
		 set("exits",([
"north" : __DIR__"shanlu04",
"south" : __DIR__"pingfeng",
"west" : __DIR__"guangchangw",
"east" : __DIR__"guangchange",
]));
set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
set("objects",([
        "/kungfu/class/kunlun/gaozecheng" :  1,
		__DIR__"npc/kl-dizi2" :  4,
		"/d/biwu/champion_kl":1,
           "quest/menpai/kunlun/shi" : 1,
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
