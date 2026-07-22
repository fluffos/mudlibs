
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是南大街。北边是九江的繁华地带了。东边有一家酒楼。这里
听到酒楼中喝酒叫笑的声音，一阵阵不时传来酒菜的香气。酒楼的店小
二正在门口热情地招呼着来往的客人。只听马嘶鸣叫声中，又一个江湖
豪客停在酒楼门前。
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie2",
  "north":__DIR__"center",
  "east":__DIR__"fengyilou",
         ]));
  set("objects",([
    __DIR__"npc/huxiaoxian":1,
    ]));
  
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

