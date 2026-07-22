// Room: /u/legato/workroom.c
inherit ROOM;

void create()
{
  set ("short", "工作室");
  set ("long", @LONG
这里是巫师的工作室，里面乱七八糟的放了一些东西
LONG);
            set("objects",([
         "/u/legato/obj/hua_wuque":1,
       ]));

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yushi",
 "west" : "/d/wiz/meeting",
 "yd" :"/d/yandang/luoyan6",
"lingjiu" : "/d/lingjiu/dating",
 "down" : "/d/zhongzhou/shizhongxin"

]));
  set("light_up", 1);
 set("outdoor","lingjian");
  setup();
  replace_program(ROOM);
}
