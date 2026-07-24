//      shanmen.c 雪山寺山門
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","雪山寺山門");
        set("long",@LONG
這里就是著名的雪山寺。寺廟依山而建，顯得格外壯觀。方圓數
百里內的香客都來此朝拜。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "north" : __DIR__"guangchang",
                "southdown" : __DIR__"shanlu2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

