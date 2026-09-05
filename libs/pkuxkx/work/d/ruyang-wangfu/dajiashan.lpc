//dajiashan.c -- 大假山
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"大假山"NOR);
  set("long", @LONG
这里是由各色不同的奇石堆砌而成的一座大假山，看起来，可比一般
大户人家的假山高多了。王爷命人专门在此打井，把水引到假山上，并在
假山上开凿渠道，是使水可以流到后花园，以方便灌溉。
LONG
  );

  set("exits", ([     
      "southeast" : __DIR__"liushuiting",   
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
