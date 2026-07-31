
#include <room.h>
#include <ansi.h>


inherit ROOM;
void create()
{
        set("short", "树顶");
        set("long", @LONG
这是大树的顶部，这里有一个鹰剿。从这里看到四周草原的景色。
只听一声声的清啸从远处传来，看来护巢的老鹰要回来了，还是赶紧下
去的好。
LONG);
        set("exits", ([
            "down" : __DIR__"caoyuan1",                        
        ]));
        set("objects",([
          __DIR__"xiaoying":3,
          ]));
        set("outdoors", "caoyuan");
        setup();
        
}

void reset()
{
   object *ob;
   int i;
   
   ob=all_inventory(this_object());
   
   for(i=0;i<sizeof(ob);i++){
     if(userp(ob[i])){
     	tell_object(ob[i],"你听到老鹰回来了，赶紧下树了！\n");
     	ob[i]->move(__DIR__"caoyuan1");
     }
   }
   ::reset();
}
    