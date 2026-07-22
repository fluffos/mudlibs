#include <room.h>
inherit ROOM;

void create()
{
      set("short","忘忧园");
      set("long",@LONG
这里是山庄正中的一个大花园，只见这里鸣莺啼柳，草碧花浓，春意盎然。
左边是一个荷塘，里面开满了荷花。荷塘中心的假山云雾笼罩，不知尽处。
中有开口流泉悬瀑，弹珠溅玉，飞漱而下，入鼻回香，掬手可饮。   水鸟
飞蜓，倒影湖面。右边是一片茶树，虽然还不是开花的时节，但是那些生
机勃勃的茶树，不禁让你感到心神清爽。草丛里有些小虫子正唧喁唧喁地
叫得正欢。
LONG);
           set("exits",([ /* sizeof() == 1 */
          "east"  : __DIR__"liangongfang",
          "west"  : __DIR__"path2",
          "north" : __DIR__"path1",
          "south" : __DIR__"path",
      ]));
      setup();
}


