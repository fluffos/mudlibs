 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "大厅");
        set("long", @LONG
地道并不长，尽头处有一扇门，门上面也雕刻着一些人物花草，
看来，单只建这条地道，就不知花了多少人力物力，这里的主
人肯花这么大的人力物力在地下建造条走道，当真不知是个什
么样的怪物。门后面，是一间厅。地道已是如此华丽，厅堂自
然更堂皇；在地下竟会有如此堂皇的厅堂，更是件令人想不到
的事。除了没有窗子，这里简直和地上富户的花厅没什么两样，
陈设得雅致大方，还尤有过之。 
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace4",
                "south" : __DIR__"palace2",
                "west" : __DIR__"bedroom1",
                "east" : __DIR__"corridor1",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
