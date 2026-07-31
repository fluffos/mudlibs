// shanjiao.c 山脚下
// Modify By River@SJ 99.06
#include <ansi.h>
#include <wanted.h>
inherit ROOM;
void create()
{
    set("short", GRN"山脚下"NOR);
    set("long",@LONG
这里是昆仑山脚下，你从远处就可以看到绵绵无尽的昆仑山脉，厚雾绕山，
不能见顶，山中终年积雪，所见之处白茫茫的一大片，别说人难至那，就连那
飞鸟也恐怕难以飞越。光明顶的七巅十三崖，就座落在其中，但光凭肉眼所视，
哪能分辨出那里是圣火所在？东边好象有一条小路是通向上山之路。西边是通
往昆仑的山路。
LONG);
    set("exits",([
        "eastup" : __DIR__"sshanlu1",
        "westup" : "/d/kunlun/zhenyuanqiao",
        "south" : __DIR__"shejing",
    ]));
    set("objects",([
         __DIR__"npc/f-dizi" :   1,
         __DIR__"npc/m-dizi" :   1,
    ]));
    set("outdoors", "明教光明顶");
    set("coor/x",-340);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-340);
 set("coor/y",100);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "eastup" && is_wanted(me))
		return 0;
    if ( me->query("id") == "yin li" &&  dir != "westup" ) return 0;
    return ::valid_leave(me, dir);
}
