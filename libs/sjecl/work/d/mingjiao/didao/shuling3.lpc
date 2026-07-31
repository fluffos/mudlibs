// /d/mingjiao/shuling3.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",GRN"树林"NOR);
       set("long", @LONG
这是一片乱树林。几十丈高的树木簇在一块，密实的枝叶象一蓬蓬巨伞般
伸向天空，把阳光遮得丝毫也无。你一走进这这觉得阴阴森林的，你的感觉告
诉你，得赶快离开。
LONG);    
       set("exits", ([
                "east" : __DIR__"shuling1",                     
                "west" : __DIR__"shenchu1",
                "south" : __FILE__,
                "north" : __DIR__"shuling4",
       ]));             
       set("outdoors", "明教光明顶");
       set("coor/x",-310);
  set("coor/y",190);
   set("coor/z",100);
   setup();
}

void init()
{
      string a,b,c,d;
      a =query("exits/west");
      b =query("exits/north");
      c =query("exits/south");
      d =query("exits/east");

       set("exits/north", a);
       set("exits/south", b);
       set("exits/west", c);
       set("exits/east", d);
}
