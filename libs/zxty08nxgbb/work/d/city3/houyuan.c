// Room: /d/shaolin/hanshui1.c
// bye mei
inherit ROOM;
void create()
{
        set("short", "后院");
        set("long", @LONG
这里是假日客店的后院，这里有辆马车，专门负责迎
送住店的客人。
LONG);

        set("no_fight", 1);
        set("exits" , ([
             "south": __DIR__"kedian",
             "enter" : __DIR__"chexiang",
           ]));


        setup();
}
int valid_leave(object me, string exit)
{
      if (exit=="enter"){
        delete("exits/enter");
        message_vision("$N战战兢兢地钻进马车里。\n");
        message("vision","马夫一甩鞭子，马车随着阵阵马蹄转眼间跑得无影无踪。\n", this_object());
      } 
      return 1;
}

