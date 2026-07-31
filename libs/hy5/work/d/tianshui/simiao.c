// /u/xiaozhen/simiao.c

inherit ROOM;

void create()
{
        set("short", "乾圣寺正殿");
        set("long",@LONG
大殿的房屋已经有些破旧了，但前面正中的佛像却通体金光
耀眼，座下香烟缭绕。正中是一个香炉，里面插满了善男信女进
献的香，可见乾圣寺规模不大却香火旺盛。两旁是寺院的侧殿。
LONG
        );

	
        set("exits", ([
                "east" : __DIR__"wroad2",
		  "south" : __DIR__"simiao2",
        ]));
        set("objects",([
                __DIR__"obj/xianglu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
