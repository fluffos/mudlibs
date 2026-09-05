//houhuayuan.c -- 后花园
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"后花园"NOR);
  set("long", @LONG
这里是王府的后花园。一年四季，都有应时的鲜花开放，在洛阳，这
也算比较难得的。一条人工开凿的小溪，由北到南贯穿整个花园。溪水不
停地流动着，淙淙的水声甚是悦耳。每到天气好的时候，王爷的姬妾们都
会带着丫鬟、仆人到花园逛逛，或采花、或嬉戏，或载歌载舞，整个花园
处处洋溢着清脆的笑声，更让人觉得春意浓浓。北面有片不大的草坪，似
乎有个小亭在那边。
LONG
  );

  set("exits", ([     
      "northup" : __DIR__"liushuiting", 
      "south" : __DIR__"xiaoshiqiao",   
      "east" : __DIR__"yanyitang",
      "west" : __DIR__"mingyuelou",
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
