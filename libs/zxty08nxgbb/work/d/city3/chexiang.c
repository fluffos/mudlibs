//bye mei
#include <ansi.h>
inherit ROOM;
void create()
{
     set ("short", "车厢内");
     set ("long", @LONG
你正躺在马车车厢内，车厢里的陈设极为豪华，波斯地毯，
上好的座椅，最妙的是有瓶五粮液在那里放着，你忍不住想喝
他几口。
LONG
    );
    set("exits",([
          "out": __DIR__"houyuan",
      ]));
    set("objects",([
          __DIR__"obj/wuliangye" : 1,
     ]));

    setup();
}
void init()
{
      if (userp(this_player())){
         delete("exits");
         remove_call_out("yangzhou");
         call_out("yangzhou",5,this_player(),1);
      }
}
void close()
{
       message("vision","车夫把车门关上了！\n",this_object());
}
void yangzhou(object me,int i)
{
    object room;
    if (!me || environment(me)!=this_object())
    {
        if (room=find_object(__DIR__"houyuan"))
            room=load_object(__DIR__"houyuan");
        room->set("exits/enter",base_name(this_object()));
           return;
    }
    if (i<15){
       i++;
      switch(i){
        case 5:
       message("vision","马车在山路不断颠簸......\n",this_object());
        break;
      default:
       message("vision","风声、马蹄声不断地从车外传来......\n",this_object());
     }
       remove_call_out("yangzhou");
       call_out("yangzhou",5,this_player(),i);
       return;
    }
    if (!room=find_object("/d/city/postoffice"))
       room=load_object("/d/city/postoffice");
    me->move(room);
    tell_object(this_player(),HIR "车夫说道：喝啥子喝，到了。\n" NOR,me);
    message_vision("$N从车厢中走了出去，回到了扬州。\n",me);
        if (room=find_object(__DIR__"houyuan"))
            room=load_object(__DIR__"houyuan");
        room->set("exits/enter",base_name(this_object()));

}

