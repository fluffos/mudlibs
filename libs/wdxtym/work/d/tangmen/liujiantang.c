// Room: /dream/liujiantang.c
// HEM 1998/11/5
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "留剑堂");
	set("long", @LONG
	“留剑堂”，顾名思义，凡是来唐门的访客，过这儿都要解下兵器，否则不允
许再深入唐门。
LONG
	);
        set("exits", ([
		"south" : __DIR__ "tianjing",
		"northwest" : __DIR__ "zhaobi",
                "northeast" : __DIR__ "zhaobi",
		"west" : __DIR__ "huayuan1",
		"east" : __DIR__ "huayuan6",
	]));
          set("valid_startroom", 1);
	set("objects", ([
                "quest/menpai/tangmen/shi" : 1,
                "d/biwu/champion_tm" : 1,
                "/quest/menpaijob/tangmen/tang_wuhuo" : 1,
                __DIR__"npc/dizi" : 2,
        ]));

	setup();
//	replace_program(ROOM);
	"/clone/board/tangmen_b"->foo();

}
int valid_leave(object me, string dir)
{
    object *inv;
    mapping myfam;
    int i;
myfam = (mapping)me->query("family");
               

    if ((!myfam || myfam["family_name"] != "唐门" ) && dir == "west"  ) {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("tang wuhuo", environment(me))))
                    return notify_fail("唐无火拦住你喝道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。再进去就是"
                        "唐门内堂，外客\n不得持兵刃如内！\n");
                
    }
    if ((!myfam || myfam["family_name"] != "唐门" ) && dir == "east"  ) {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("tang wuhuo", environment(me))))
                    return notify_fail("唐无火拦住你喝道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。再进去就是"
                        "唐门内堂，外客\n不得持兵刃如内！\n");
                
    }
    if ((!myfam || myfam["family_name"] != "唐门" ) && dir == "south"  ) {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("tang wuhuo", environment(me))))
                    return notify_fail("唐无火拦住你喝道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。再进去就是"
                        "唐门内堂，外客\n不得持兵刃如内！\n");
                
    }
    return ::valid_leave(me, dir);
}



