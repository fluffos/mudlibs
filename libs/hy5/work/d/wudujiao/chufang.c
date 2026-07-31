// by mayue


inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是五毒教的厨房，平常弟子们饿了可以到这里要(yao)些食物。
房中灶火正旺，一个大厨师正忙的满头大汗。屋角放着一个大水缸。  
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"bingqi",
		"south" : __DIR__"beiyuan",
//		"west" : __DIR__"damen",
//		"north" : __DIR__"chufang",
	]));
        set("objects", ([
                 __DIR__"obj/ganchai": 3,
                 __DIR__"obj/hulu": 1,
                 __DIR__"npc/tian": 1,
	]));
       set("resource", ([ /* sizeof() == 1 */
              "water" : 1,
       ]));   
	setup();
//	replace_program(ROOM);
}
int valid_leave(object who, string dir)
{
    object where=environment(who);
       if(present("baozi", who))
        {
              return notify_fail("吃完包子再走嘛！\n");
              who->move(where);
              return 1;
        }
       if(present("hulu", who))
        {
	       return notify_fail("你不能把葫芦带走！\n");
              who->move(where);
              return 1;    
         }
        else return ::valid_leave();
}
