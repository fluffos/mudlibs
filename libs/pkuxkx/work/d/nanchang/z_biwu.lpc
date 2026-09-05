
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "比武场");
	set("long", @LONG
这里是壮族山寨的比武场，很多壮族青年在这里比试，交换打猎心得。
LONG
	);
	set("exits", ([ 		
        "east" : __DIR__"z_guangchang",
        
		
    ]));
    set("no_die", 1);
	set("no_task",1);
    set("objects", ([
		__DIR__"npc/zhuang_man": 2+random(3),
        
        ]));
    set("outdoors", "nanchang");
	setup();
	
}

void init()
{
        add_action("do_none",({"study","learn","tuna","exercise","dz","apprentice","research","practice",}));
        add_action("do_quit",({"quit","suicide"}));
}
int do_none()
{
        write("这里不准练功。\n");
        return 1;
}
int do_quit()
{
        this_player()->move("/adm/room/quitroom");
        return 1;
}

