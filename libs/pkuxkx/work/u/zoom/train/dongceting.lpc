//dongceting.c
//by zoom
//2004.3.29

inherit ROOM;

void create()
{
    set("short", "东侧厅");
    set("long", @LONG
这里是新手学堂的东侧厅。是大家喝茶闲聊的地方。
茶房自古便是谈天说地，传播小道消息的地方。这里人们
东一群，西一伙地闲聊。或是吐沫横飞，讲得天花乱坠；
或是指手划脚，争得面红耳赤。手提铜壶的茶博士正高声
吆喝着来回穿梭。
LONG
    );

    set("exits", ([
                "north" : __DIR__"dongxiang",
                "west" : __DIR__"zhengting",
    ]));

    set("objects", ([ 
		__DIR__ + "npc/xianren" : 1,
    ])); 
  
    set("indoors", "train");
    setup();

}
