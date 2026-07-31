
inherit ROOM;

void create()
{
        set("short", "八角街");
        set("long", @LONG
大招寺外，围绕着寺院的八角街是布达拉宫里最繁华热闹的地方。所有
最大的客栈和商号都在这条街上。远处钟声不时的齐鸣。一声声梵唱随风飘
来。宝塔的尖顶在太阳下闪着金光，充满了神圣庄严肃穆的景象。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"dazhaotemple",
  "east" : __DIR__"citygate",
  "north" : __DIR__"octo16",
  "south" : __DIR__"octo1",
]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/lama" : 3,
                __DIR__"npc/traveller": 4,
        ]) );
        setup();
}

