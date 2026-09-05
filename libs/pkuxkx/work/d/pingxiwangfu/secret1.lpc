#include <combat.h>
inherit ROOM;
void create()
{
        set("short", "秘室");
        set("long", @LONG
秘室里摆放着四盏灯,南边一盏写着朱雀,北边是玄武,东边是苍龙,西边是白虎,
古人以北为尊,以东为贵,你可以试着点燃他们.但须小心在意.

LONG
        );
        set("exits", ([ 
"up" : __DIR__"shu_fang",
  ]));
       set("objects", ([
        __DIR__"obj/lampn" : 1,
         __DIR__"obj/lamps" : 1,
 __DIR__"obj/lampe" : 1,
 __DIR__"obj/lampw" : 1,
                ]) );

set("no_newbie_task",1);
        setup();
}
void init()
{
     add_action("do_light","light");
} 
int do_light(string arg)
{ object me;int mount;
   me=this_player();mount=me->query("light");
if (!arg || arg != "lamp" && arg != "lampn" && arg != "lamps" && arg!="lampe" && arg!="lampw")
 {write("当心，看准再点!\n");return 1;}

if ((arg=="lamp" || arg=="lampn")&&!(mount)) 
{write("你点燃一盏灯，屋里明亮了一些.\n");
me->set("light",1);
mount=me->query("light");
}
else if ((arg=="lamps")&&(mount==1)) {write("你点燃一盏灯，屋里又明亮了一些.\n");
me->set("light",2);
mount=me->query("light");
}
else if ((arg=="lampe")&&(mount==2)) {write("你点燃一盏灯，屋里又明亮了一些．\n");
me->set("light",3);
mount=me->query("light");
}
else if ((arg=="lampw")&&(mount==3)) 
  {me->set("light",0);
      set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"secret2",
"up" : __DIR__"shu_fang",
  ]));
  message_vision("$N点燃了所有的灯，明亮中看见了一个出口．\n", this_player());
    remove_call_out("close");
    call_out("close",8,this_object());
return 1;

}
else
{message_vision("冷不防飞出一只冷箭，向$N射来．\n",me);
if (random(me->query("dodge",1))<80)
{message_vision("$N被射中，疼痛钻心。\n",me);
   me->add("qi", -90);
}
 else
{message_vision("$N轻轻闪过，毫不在意.\n",me);}
}

return 1;
}


void close(object room)
{
    message("vision","突然间灯光变暗，你无法看清入口的位置!\n",room);
    room->delete("exits/down");
}
