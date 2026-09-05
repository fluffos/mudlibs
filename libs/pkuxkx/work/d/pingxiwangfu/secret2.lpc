inherit ROOM;
void create()
{
        set("short", "秘室");
        set("long", @LONG
秘室里立着一些巨木，长年未使用．秘室前有一扇精制
石门(door)，不用点内力是震(break)不开了．
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"secret1",
  ]));
      set("no_newbie_task",1);
        setup();
}
void init()
{
     add_action("do_break","break");
} 
int do_break(string arg)
{ object me;int mount;
   me=this_player();mount=me->query("neili");
if (!(arg) && (arg != "door")) 
{
    write("你要打开什么?\n");
    return 1;
    }
if (mount<300) {write("你用力一推，但门纹似不动!\n");me->set("neili",0);}
else 
  {me->add("neili",-300);
      set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"secret3",
"up" : __DIR__"secret1",
  ]));
  message_vision("$N震开大门，发现了一个入口．\n", this_player());
    remove_call_out("close");
    call_out("close",6,this_object());

}

return 1;
}


void close(object room)
{
    message("vision","只听咣荡一声，石门重新封闭。\n",room);
    room->delete("exits/down");
}
