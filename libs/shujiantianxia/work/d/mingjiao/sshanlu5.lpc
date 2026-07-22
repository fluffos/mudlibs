// sshanlu5.c 山路
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
        "westdown"  :     __DIR__"xuanya3",
        "southup"   :     __DIR__"shanting",
    ]));
    set("objects",([
         __DIR__"npc/guiren"  :    2,
    ]));	
    set("coor/x",-310);
  set("coor/y",130);
   set("coor/z",50);
   set("coor/x",-310);
 set("coor/y",130);
   set("coor/z",50);
   setup();
    set("outdoors", "明教光明顶");
}

int valid_leave(object me, string dir)
{
       if (dir == "southup" && userp(me)){
           me->receive_damage("jing", 10);
           me->receive_damage("qi", 10);
       }
       return ::valid_leave(me, dir);
}

void init()
{
	object me=this_player();
	if (me->query("jing")<20 || me->query("qi")<20 ){
	  write("你看起来已经很累了，休息一下再赶路吧。\n"NOR);
          me->start_busy(2);
        }
}
