
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",YEL"竹林"NOR);
  set ("long", @LONG
这是一片竹林，约有几仗方圆大小。竹林还算茂盛，遮住了天上的
烈日，让人感到十分凉爽。这里气氛安静祥和，似乎会让人忘记所有的
烦恼。有几位上香的游人正在这里欣赏景色。
LONG);

  set("exits", ([ 
	  "northup":__DIR__"baishiguangchang",
	  "southeast":__DIR__"pudutang",
         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

