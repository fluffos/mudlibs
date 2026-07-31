 inherit ROOM;
void create()
{
        set("short", "大厅");
        set("long", @LONG
门后面，是一间厅。地道已是如此华丽，厅堂自然更堂皇；在地下竟
会有如此堂皇的厅堂，更是件令人想不到的事。除了没有窗子，这里简直
和地上富户的花厅没什么两样，陈设得雅致大方，还尤有过之。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace4",
                "south" : __DIR__"palace2",
                "west" : __DIR__"sideroom",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
