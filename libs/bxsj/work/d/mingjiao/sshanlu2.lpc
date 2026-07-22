//sshanlu2.c 山路
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", YEL"山路"NOR);
	set("long",@LONG
这是一条一窄又陡的山路，山路两旁长着又高又杂的乱草杂树，几没人头，
偶尔会有几枝荆棘挡住你的去路，一不小心则会被其刺伤。
LONG);
	set("exits",([
        	"northdown" : __DIR__"sshanlu1",
        	"westup"  : __DIR__"sshanlu3",
    	]));
        set("objects",([
               __DIR__"npc/you" : 2,
        ]));
        set("outdoors", "明教光明顶");
    	set("coor/x",-330);
  set("coor/y",90);
   set("coor/z",20);
   set("coor/x",-330);
 set("coor/y",90);
   set("coor/z",20);
   setup();
}
