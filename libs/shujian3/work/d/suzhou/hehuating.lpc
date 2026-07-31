#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",MAG"荷花厅"NOR);
	set("long", @LONG
荷花厅的主建筑面阔三间，宽敝高爽，厅名取朱熹：“一水方涵碧，千
林以变红”之诗意。厅前宽广的平台依临荷池，为夏日赏荷纳凉胜处，故称
“荷花厅”。厅后有花台庭院，叠石种树，自成一景。
LONG	);
      
        set("exits", ([ 
     "west" : __DIR__"gumujiaohe",
	"east" : __DIR__"liuyuan",
	]));
	set("outdoors", "suzhou" );
	set("no_clean_up", 0);
	set("coor/x",90);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}
