// /d/taiyuan/beidajie1.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "北大街");
	set("long", @LONG
青石铺成的大道有二丈宛宽，来往的国马虽然多，但无感到拥挤，
再向北走就要到太原北门了，东面是太原有名的晋祠，西面是一家鸟笼
店。
LONG);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"beimen", 
                "south" : __DIR__"beidajie2", 
                "east" : __DIR__"jinci", 
                "west" : __DIR__"niaolongdian",       
	]));
	set("objects",([
	__DIR__"npc/girl":1,
	]));
       setup();
	replace_program(ROOM);
}	
