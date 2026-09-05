//mingyuelou.c -- 明月楼
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"明月楼"NOR);
  set("long", @LONG
这里是一座三层高的小楼，飞檐斗拱，雕梁画栋，小楼所有的门、窗
、柱、梁，都涂以红漆，在周围绿树的掩映下，那一抹红色，煞是好看。
每个月的初一、十五，王府的家宴一般都是摆在这里的，每逢王爷、王妃
的寿辰，这里还要搭台唱戏。但平常时候，不是王爷至亲至信的人，轻易
不能到此。

LONG
  );

  set("exits", ([     
      "southwest" : __DIR__"jingtang",   
      "east" : __DIR__"houhuayuan",
  ]));

//  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
