// Room: hnme.c
// Date: Sep.6 1997

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
      set("short", "听月阁");
      set("long",
"这里是‘听月阁’，是江湖奇人净南的家。屋内布置古朴典雅，\n"
"不带一丝俗气。房内家具虽然不多，但都显得恰到好处，最引人注目\n"
"的是右首一个古色古香的红木书柜，里面放满了各门派的武功密籍。\n"
"左首是一张大床，床边茶几上还有一套别致的茶具，里面的茶正冒着\n"
"热气，使整个房间弥漫着淡淡的茶香。墙上贴着一幅主人手书的狂草：\n"
BLU"        闲看庭前花开花落\n"
"        漫随天外云卷云舒\n"NOR
);
      set("exits", ([ /* sizeof() == 1 */
          "south" : __DIR__"jiaowai7",
      ]));
      set("valid_startroom","1");

      set("no_fight", 1);
      set("no_clean_up", 0);
      set("sleep_room", 1);
      setup();
      create_door("south", "雕花小门", "north", DOOR_CLOSED);
}


