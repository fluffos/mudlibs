// ROOM:mudao2.c
// Created by Numa 19990912
// Revised by Darken

inherit ROOM;

void create()
{
        set("short","墓道");
        set("long",@LONG
这是一条通往墓室的通道，两旁尽是古玩珍宝。
通道四面八方的伸展，高低不平，你看得头昏脑胀。
LONG);
        set("exits",([
                "up" : __DIR__"mudao1",
                "south" : __DIR__"mudao2",
                "north" : __DIR__"mudao2",
                "east" : __DIR__"mudao2",
                "west" : __DIR__"mudao2",
                "northeast" : __DIR__"mudao2",
                "northwest" : __DIR__"mudao2",
                "southeast" : __DIR__"mudao2",
                "southwest" : __DIR__"mudao2",
                "southup" : __DIR__"mudao2",
                "southdown" : __DIR__"mudao2",
                "northup" : __DIR__"mudao2",
                "northdown" : __DIR__"mudao2",
        ]));

        setup();
}

void init()
{
      mixed *local;
      int h;
      local = localtime(time()*60);
      h = local[2];
      if (h>12)
          h = h - 12;
      if(this_player()->query_temp("thd/step")) {
          this_player()->move("/d/thd/mudao1");
            this_player()->delete_temp("thd/step");
          message_vision("$N不知道不觉的走回出口，抓了抓头。\n", this_player()); }
      else
      this_player()->set_temp("thd/step",1);
      set("exits/northup", __DIR__"mudao2");
      set("exits/northdown", __DIR__"mudao2");
      set("exits/north", __DIR__"mudao2");
      set("exits/northeast", __DIR__"mudao2");
      set("exits/northwest", __DIR__"mudao2");
      set("exits/east", __DIR__"mudao2");
      set("exits/west", __DIR__"mudao2");
      set("exits/southup", __DIR__"mudao2");
      set("exits/southdown", __DIR__"mudao2");
      set("exits/south", __DIR__"mudao2");
      set("exits/southeast", __DIR__"mudao2");
      set("exits/southwest", __DIR__"mudao2");
      switch(h){
            case 1:
      set("exits/northup", __DIR__"mudao3");
      break;
            case 2:
      set("exits/north", __DIR__"mudao3");
      break;
            case 3:
      set("exits/northdown", __DIR__"mudao3");
      break;
            case 4:
      set("exits/northeast", __DIR__"mudao3");
      break;      
            case 5:
      set("exits/east", __DIR__"mudao3");
      break;
            case 6:
      set("exits/southeast", __DIR__"mudao3");
      break;
            case 7:
      set("exits/southup", __DIR__"mudao3");
      break;
            case 8:
      set("exits/south", __DIR__"mudao3");
      break;
            case 9:
      set("exits/southdown", __DIR__"mudao3");
      break;
            case 10:
      set("exits/southwest", __DIR__"mudao3");
      break;
            case 11:
      set("exits/west", __DIR__"mudao3");
      break;
            case 12:
      set("exits/northwest", __DIR__"mudao3");
      break;
      }
}

