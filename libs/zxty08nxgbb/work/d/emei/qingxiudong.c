// /d/emei/qingxiudong.c 清修洞
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "清修洞");
	set("long", @LONG
这是一间依山而建的石洞，洞内十分的宽阔，但略有一些昏暗。在正中
有一方行石坛，在石坛上摆放了一张木案，上面有一些书籍和一个小香炉，
从香炉中不断的飘出屡屡清烟。只见在书案旁坐了一位师太，眼眉低垂，白
发萧萧。正在那里低头沉思。
LONG
	);
	set("exits", ([ 
                "north" : __DIR__"zoulang5", 
		]));
	set("objects", ([ 
               CLASS_D("emei") + "/miejue" : 1,
     ]));

        setup();
	replace_program(ROOM);
}
