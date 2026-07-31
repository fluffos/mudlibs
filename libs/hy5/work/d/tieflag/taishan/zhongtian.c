 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","扇子崖");
  set("long",@LONG
胜寨西有一峰，高耸峻削，丹壁奇特，名扇子崖，明代杨博为其题词“仙人掌”
。扇子崖峰极险峻，唯借助绳索自西南隅方可攀巅。赤眉军曾就顶设望哨，明代
举人王无欲筑室崖巅，后又结茅其下，名“西山别业”。峰崖交接处为山口，前有
扇子崖庙，殿西有地母宫，再西为太阳庙。   
LONG
  );
  set("exits",([
        "down" : __DIR__"butian",
        "up" : __DIR__"buyun",
               ]));
        set("objects", ([
        "/d/tieflag/fy/npc/beggar" : 2,
        __DIR__"npc/honglianhua" : 1,
                        ]) ); 
        set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2380);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
}     
