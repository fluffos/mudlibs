// Room: /d/snow/weapon_storage.c
inherit ROOM;

void create()
{
        set("short", "比武场");
        set("long", @LONG
这是一个高耸的比武台,几面大旗迎风招展，发出唰唰的响声,
 令你有一种挑战的冲动.在每根旗杆的下面，都站立着淳风武馆的
 武士.............
此时你情不自尽的摸摸身上的武器，也想象别人一样，大显威风!
LONG);
        set("exits", ([
                "south" : __DIR__"weapon_storage",
        ]));
	set("no_dead",1);
        setup();
      //  call_other( "/obj/board/biwuchang", "???" );
}
