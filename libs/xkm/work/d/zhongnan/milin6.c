//Cracked by Roath
// road: /zhongnan/milin6.c

inherit ROOM;

void create()
{
        set("short","树林");

        set("long",@LONG
走在林中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花香，自密
林深处传出。一群乳白色的蜜蜂在你身旁飞来飞去。往北是一座古墓。其
它方向尽是茂密的树林。
LONG);

        set("exits",([ "west" : __DIR__"milin9",
                        "east" : __DIR__"milin4",
			"north" : __DIR__"gumu",
                        "south" : __DIR__"guolin",
                      ])
           );

	set("objects",([
		  "/d/zhongnan/npc/maque" : 3,
	 ]));

	  set("cost",2);
	  set("outdoors", "zhongnan");
          setup();
       // replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        object *inv;
        int i;

        inv = all_inventory(me);
        
          if ( dir == "west" || dir == "north" ||dir == "east" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其麻雀离开树林。\n");
                }
        }

        return ::valid_leave(me, dir);
}

