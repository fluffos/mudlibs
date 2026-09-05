//Cracked by Roath
//ROOM: dadao_yongan_s.c

inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
你走在一条青石大道上，四周静悄悄的。北面是京城的永安门，
东南面是往天津方向的大路。
LONG
        );
        set("outdoors", "beijing");
        set("exits", ([
                "southwest" : "/d/beijing/yidao2",
                "north" : "/d/beijing/yonganmen",
                "southeast" : "/d/beijing/tanggu",
        ]));
        set("cost", 2);

        setup();
        replace_program(ROOM);
}
