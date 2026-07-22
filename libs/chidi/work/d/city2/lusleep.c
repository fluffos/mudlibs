// 制作人 jzad
// Email jzad@sy163.net
// 01-8-6
 
#include <ansi.h>
inherit ROOM;

void create ()
  {
  set("short", HIR"鹿鼎公府客房"NOR);
set("long", @LONG
 这里鹿鼎公爵府的客房，是专为远来的朝廷官员预备的
      休息的地方，外面是一个大花园，环境真不错！   
       
LONG);

   set("exits",([ /* sizeof() == 1 */
                "west":__DIR__"luzt",
                ])); 
  setup(); 
}
