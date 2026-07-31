//zhifang.c 芝房
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
void init();
void create()
{
          set("short",HIG"芝房"NOR);
	  set("long",@LONG
鼻中闻到一股浓浓的泥土清香，这便是芝房，只见房内到处种植着奇花异
草，房间中央种着一枝灵芝，看上去与普通的灵芝有些不一样，一名绿衫少女
正守护着它。
LONG
           );

	 set("exits",([
               "north": __DIR__"lang5",
         ]));

         set("objects",([
             __DIR__"npc/gslve":1,
         ]));    
         setup();
         replace_program(ROOM);
}
