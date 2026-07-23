
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","九江广场");
  set ("long", @LONG
这里是九江最繁华的地带了。这里汇集了五湖四海的商人、游客。
熙熙攘攘，好不热闹。虽然近来动乱不住，但是这里仍然热闹非凡。据
说任少名不久前在这里被刺杀，更是让寇仲和徐子陵两人名震江湖。
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie1",
  "north":__DIR__"beidajie2",
  "east":__DIR__"dongdajie1",
  "west":__DIR__"xidajie1",
         ]));
  set("objects",([
  __DIR__"npc/feiyan":1,
  ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

