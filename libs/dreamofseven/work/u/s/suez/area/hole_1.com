#include <room.h>
inherit ROOM;

void create()
{
 set("short","洞中小室");
        set("long",@LONG
一盞昏暗的油燈和一張破舊的木桌，搖曳的燈光偶而掃到你的臉上，
不知從哪兒跑進來的雨蛙在靠牆的書架上嘓嘓的叫，兩三張小凳凌亂的擺
著，順著這裡的擺設看下去，赫然發現你的腳下竟有一個大石門﹗門上的
兩個大鐵環靜靜閃耀著赤紅的光輝，好像訴說著門下的神秘及危機，突然
一陣寒風吹入，讓你不禁毛骨悚然。
LONG
        );

         set("exits", ([
         "south": __DIR__"hole_out",
       "down":__DIR__"hole_2",
         ]));
        create_door("down","石門","up",DOOR_CLOSED);

        set("objects",([
              __DIR__"npc/pan-en" : 1,
          ]) );
        set("light", 1);
        setup();
        replace_program(ROOM);

 }