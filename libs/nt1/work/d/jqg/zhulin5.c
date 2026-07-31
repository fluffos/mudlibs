// zhulin5.c 竹林
// By River 99.5.24
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
          set("short",GRN"竹林"NOR);
	  set("long",@LONG
行出数里路，忽见对面绿油油的好大一片竹林，北方很少见长得这般茂密
的竹林，更别提数量之大，确实罕见，林中栖息着各种鸟儿，啼声婉转，多少
添了点喜气，林子中有一条小路通往后山。
LONG
);

          set("outdoors","绝情谷"); 
	  set("exits",([
                "east" :  __DIR__"zhulin"+(random(6)+1),
                "south" : __DIR__"zhulin"+(random(6)+1),
                "north" :  __DIR__"zhulin"+(random(6)+1),
                "west" : __DIR__"zhulin6",
          ]));

          setup();
          replace_program(ROOM);
}
