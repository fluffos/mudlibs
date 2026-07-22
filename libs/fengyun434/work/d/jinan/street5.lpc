 // street5.c
#include <room.h>
inherit ROOM;
void create()
{
   set("short","趵突桥");
  set("long",@LONG
济南号称泉城，据说有泉水七十二处，趵突泉群是其中比较大的一个泉水群
落。地下泉水汇成河流，因泉成路，形成曲水流觞的秀丽地貌。趵突泉至此汇集
成河，当地人修造了这座趵突桥。远处山色空朦灵动，近处水光粼粼，称得上齐
鲁江南。桥南是新修建的官邸衙门，东南方则是关押囚犯之地。
LONG
  );
    set("exits",([
        "north":__DIR__"street4",
        "south":__DIR__"govern",
        "southeast" : __DIR__"dayu",
    ]));
        set("objects", ([
        __DIR__"npc/yayi3" : 2,
        ]) );
    set("outdoors", "jinan");
        set("coor/x",30);
        set("coor/y",1890);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}   
