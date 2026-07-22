// sshanlu6.c 山路
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"山路"NOR);
    set("long",@LONG
这是一条一窄又陡的山路，这里已见白雪，白雪盖着山路两旁又高又杂的
乱草杂树，极是美丽。你感到阵阵的寒恿上心头。南边是半山腰。
LONG);
    set("exits",([
        "eastdown"  :     __DIR__"shanting",
        "southup"   :     __DIR__"shanyao",
    ]));
    set("coor/x",-320);
  set("coor/y",120);
   set("coor/z",70);
   set("coor/x",-320);
 set("coor/y",120);
   set("coor/z",70);
   setup();
    set("outdoors", "明教光明顶");
}

int valid_leave(object me, string dir)
{
     if ( dir == "southup" && userp(me)) {
       me->receive_damage("jing", 10);
       me->receive_damage("qi", 10);
       }
       return ::valid_leave(me, dir);
}

void init()
{
	object me=this_player();
	if (me->query("jing")<20 || me->query("qi") < 20){
	write("你看起来已经很累了，休息一下再赶路吧。\n"NOR);
        me->start_busy(2);
        }
}
