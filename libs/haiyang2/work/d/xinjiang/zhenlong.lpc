 inherit ROOM;
void create()
{
        set("short", "镇龙塔");
        set("long", @LONG
此塔位于红山山顶，塔身高过十丈，塔顶铺满青蓝色瓦片，在阳光下
十分耀眼。塔的周围是红砖地，已经很旧了，布满了裂痕。这里很静，除
了一些武林中人在这里较武过招之外，似乎没有其他人来了。
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"hongshan",
  "east" : "/d/dingxiang/caoyuan3",	
])); 
        set("objects", ([
        "/clone/npc/man" : 2,
        ]) ); 
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
        set("coor/y",2130);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}      
