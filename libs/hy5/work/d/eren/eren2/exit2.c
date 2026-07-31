 inherit ROOM;
void create()
{
        set("short", "泥道");
        set("long", @LONG
泥道越往上越陡，奇怪的是，地面并没有干燥起来，反而越来越泥泞，
到处都是青苔，厚厚的足有寸许。风更大了，水气也更浓了。已经没有了
烛火，但远远地似乎有些亮光，也许出口就要到了？
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"exit1",
                "northup" : __DIR__"exit3",
                        ]));
        set("objects", ([
                __DIR__"npc/guardb" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
