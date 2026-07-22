#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",HIR"心禅堂"NOR);
       set("long", @LONG
一座宽敞的禅室，并非用土木建成，而是依山而建，四壁如仞，都是石
壁。如此山间石室，若非浑然天成，定是有前辈高僧，以禅心智慧，绝大佛
力开山而致了。室内烛火通明，终年不息，正中供奉着我佛的法像，与大殿
不同的是做千手如来收万宝势。职事僧在殿内四处巡视，以备所需。一位老
僧瞑目跌坐，内视参禅。
LONG
     );
	set("exits", ([
                "south" : __DIR__"xcping",
                "west" : __DIR__"xclang",
              "north"  : __DIR__"duanya",
	]));

        set("objects",([
           "/kungfu/class/shaolin/fangsheng" : 1,
        ]));

        set("coor/x",60);
  set("coor/y",420);
   set("coor/z",130);
   setup();
}
