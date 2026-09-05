// room: /d/quanzhou/huanggu.c
// Eric 96.9.26

inherit ROOM;

void create()
{
        set("short", "荒谷");
        set("long", @LONG
这里是荒谷的东面，一栋草房孤孤单单地座落在荒谷的尽头，北
面遥望是一个小山坡，下雨的时候可以听到山洪的声音，隐隐有紫光
射来，有着说不出的神秘，东面是黑沉沉的山谷。
LONG
        );
        set("exits", ([ 
	"east": "/d/taohuadao/jinjiting",
      "west" : __DIR__"wuminggudi",
        ]));
        set("objects", ([ 
//            __DIR__"npc/wentong" : 1,
            __DIR__"npc/xiuwen" : 1,
            __DIR__"npc/dunru" : 1,
         ]) );

        set("outdoors", "quanzhou");

        setup();
        replace_program(ROOM);
}

