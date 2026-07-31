// /u/beyond/ningbo/majiu.c 马厩
// Beyond make 1996.6.8
inherit ROOM;
void create()
{
set("short", "马厩");
set("long",@long
这是北大街边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客人
要住店，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干
乾净净。一直伺候到客人离店上路。马厩中堆放著几堆草料，正中有一口泔
槽。
long);
        set("outdoors", "ningbo");
	set("exits", ([
		"northeast" : __DIR__"ningbocheng",
		"east" : __DIR__"kedian",

	]));

/*	set("objects", ([
		__DIR__"npc/mafu" : 1,
                __DIR__"obj/ma" : 3,
	]));
*/
	setup();
}

