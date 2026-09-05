
// room
#include <ansi.h>
inherit ROOM;

void leave_here(object me);

void create ()
{
  set ("short", BLU"大海"NOR);
  set ("long", @LONG

    冰山在海上无休止地漂流，眼望西天，血红的夕阳仍未落入
海面。此处已地近北极，天时大变，这些地方半年中白日不尽，
另外半年却是长夜漫漫，但觉种种怪异，宛若到了世界的尽头。

LONG);

  set("exits", ([
        "east"      : __DIR__"migong2",
        "west"      : __DIR__"migong2",
        "south"     : __DIR__"migong2",
        "north"     : __DIR__"migong2",
        "northwest" : __DIR__"migong2",
        "southwest" : __DIR__"migong2",
      ]));
  setup();
}

int valid_leave (object me, string dir)
{
  object icedew;
  int i;
  if (i = me->query_temp("out_of_migong"))
  {
    i++;
    me->set_temp("out_of_migong",i);
    if (i > 5)
    {
      me->set_temp("lost_in_migong",0);
      me->set_temp("out_of_migong",0);
      
      call_out("leave_here",1,me);

      return 1;
    }
  }
  else if (! me->query_temp("lost_in_migong"))
  {
    me->set_temp("lost_in_migong",1);
    call_out("found_outlet",100+random(100),me);
  }
  return 1;
}
void leave_here(object me)
{
      me->move(__DIR__"haitan");
      
}

void found_outlet(object me)
{
  if(!me) return;
  me->set_temp("lost_in_migong",0);
  me->set_temp("out_of_migong",1);
}


