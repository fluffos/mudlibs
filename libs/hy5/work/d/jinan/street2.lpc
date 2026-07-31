 // street2.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","观川亭");
  set("long",@LONG
济南大街上这个富丽堂皇的亭子，据说是当年丐帮老帮主任慈出资修葺而
成，以便来往路人遮风挡雨。立于此亭，看着远方汩汩流动的江河，文人雅客
突发奇想，名此亭为“望川亭”，以此追怀孔夫子那至理名哲：子在川上曰，
逝者如斯夫！西面，几幢格调清雅的别墅便是丐帮在济南城修建的总堂。
LONG
  );
  set("exits",([
         "north":__DIR__"street1",
         "southup":__DIR__"street3",
         "west":__DIR__"shungeng",
         "east":__DIR__"lake"
               ]));
    set("outdoors", "jinan");
        set("coor/x",30);
        set("coor/y",1950);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}        
