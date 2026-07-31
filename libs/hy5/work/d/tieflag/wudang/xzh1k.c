 inherit ROOM;
void create()
{
        set("short", "厨房");
        set("long", @LONG
穿过一扇挂著蓝布帘的小门，是一间小得不能再小的厨房。左面
靠墙放著一个大水缸和几只酒坛。右面则是一个大炉子，火烧得正旺。
一个老妇人挤在中间正在做饭。 
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"xzhouse1",
        ]));
        set("objects", ([
                __DIR__"npc/oldwoman" : 1,
        ]) );
        set("coor/x",120);
        set("coor/y",-50);
        set("coor/z",0);
        setup();
replace_program(ROOM); 
}
