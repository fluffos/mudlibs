//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","上天梯");
	set("long",@LONG
这里是唐贞年间，有位仁果禅师在崆峒山开山辟路，凿通的通向最高峰的唯
一通道“上天梯”，山势奇险，每逢雷雨，则风喉雷鸣，震撼山谷，此响彼应，
如山崩地裂，令人心惊胆战。崖壁上密密麻麻镌满了摩崖题刻，中有“上天梯”
三个斗大金字，传说为汉武帝御笔。
LONG);
	set("exits",
	([
          "eastdown" : __DIR__"shijie2",
          "northup" : __DIR__"shijie3",
	]));
        set("outdoors","kongdong");
	set("objects", ([
		__DIR__"npc/youke" : 2,
		]) );
        setup();
        //place_program(ROOM);
}
