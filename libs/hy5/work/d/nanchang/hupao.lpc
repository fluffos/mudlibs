
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","水观音亭");
  set ("long", @LONG
水观音亭水观音亭位于南湖湖心，始建于唐代。明正德年
间，曾为宁王朱宸濠之妻娄妃的“梳妆台”；万历年间，一度
为相国张位别墅，称“杏花楼”。汤显祖在此曾有吟咏。清朝
时为祭祀娄妃，募捐修建，始名“因是庵”。乾隆五十三年（
1788年）重修时改称“观音亭”，又称“水观音亭”。
LONG);

  set("exits", ([ 
  "north":__DIR__"hupan",
  "southwest":__DIR__"nanan2",
  "northeast":__DIR__"yhs",
        ]));
   set("objects",([
       __DIR__"npc/daoke":1,
       ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

