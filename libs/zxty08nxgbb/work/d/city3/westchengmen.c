// Room: /chengdu/westchengmen.c
// oooc: 1998/06/20 

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "西城门");
	set("long", @LONG
这里是成都城的西门，高大的城墙上有两个红色的大字“成
都”，下面是两个小字“西门”。城门口两边站着一队官兵，端
的是衣甲鲜明，精神拌擞，门口来来往往的行人和商贾很多，偶
而走过几个面生的江湖豪杰。城门口贴着告示(gaoshi)，再向西
便是出城的路，向东就是热闹的西大街了。
LONG
	);
	set("exits", ([
                "west" : __DIR__"guandao1",
                "east" : __DIR__"xijie",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("item_desc",([
             "gaoshi" : "捉拿采花大盗田伯光，活人赏金一百两，死尸赏金五十两。\n\n\n成都巡抚　　阮耀\n",
        ]));


        set("outdoors", "chengdu");
	setup();
}

