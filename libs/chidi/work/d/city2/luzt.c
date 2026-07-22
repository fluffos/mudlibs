// 制作人 jzad
// Email jzad@sy163.net
// 01-8-6
 
#include <ansi.h>
inherit ROOM;

void create ()
  {
  set("short", HIR"鹿鼎公府正厅"NOR);
set("long", @LONG
      这里便是大名鼎鼎的韦小宝韦爵爷的鹿鼎公爵府正厅了，
      韦爵爷取了七个老婆，不想再脚踏两条船，就回到朝里安心
      的当起了他的大官了，不过最近皇上叫他负责捉拿天地会的
      反贼，着实让他头痛了好几天，  

LONG);

   set("exits",([ /* sizeof() == 1 */
                "out":__DIR__"ludamen",
                
                "east":__DIR__"lusleep" ])); 
   set("objects", ([
            "/quest/weijob/wei" : 1,
       ]));
setup(); 
}

