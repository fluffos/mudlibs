
//newsroom.c
//Date: 02/2/27 jhy

#include <ansi.h>
inherit ROOM;
#include <room.h>

void create()
{
         set("short",HIY"新闻中心"NOR);
      set("long",@LONG
这是巫师发布新闻的方地。
LONG);
      set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"wizard_room",
           ]));
      set("valid_startroom","1");
      call_other( "/clone/board/news_b", "???" );
      setup();
	}

