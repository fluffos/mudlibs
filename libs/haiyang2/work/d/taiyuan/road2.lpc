// /d/taiyuan/road2.c
// Room in 太原
// modify by yang

#include <room.h>
inherit ROOM;
void create()	
{
	set("short", "天宁寺");
	set("long", @LONG
天宁寺依山而建,周围是层峦迭嶂的山峰,环境幽静.寺内建筑多为明清时所建，
层次分明，错落有致。主要建筑有千佛阁、虚堂、大佛殿等，其中千佛阁内有元代
铸佛像三尊，高6米，每尊旁各有六尊铁铸弟子像；虚堂右侧有一座明朝时铸就的
大钟，钟声可达数里；大佛殿位居寺院正中，殿内供奉释迦牟尼像，登上殿后的毗
卢阁，远山近水一览无余。进入山门，左右两侧的长廊内有历代书法名家的碑文，
笔力不俗。
LONG
        );
set("outdoors", "taiyuan");
set("exits", ([
                "east":__DIR__"road1", 
                "southwest":__DIR__"road3", 
                
	]));
       setup();
       replace_program(ROOM);
}


