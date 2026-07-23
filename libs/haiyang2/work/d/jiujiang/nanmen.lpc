
inherit ROOM;


void create ()
{
  set ("short","南门");
  set ("long", @LONG
这里是九江的南门。这里的行人很多。虽是战乱年代，但九江还是
很繁华。不时有行人在这里出出进进，几个官兵耀武扬威地站在这里，
检查着来往的行人。
LONG);

  set("exits", ([ 

 "north":__DIR__"nandajie2",
 "south":__DIR__"shanlu1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

