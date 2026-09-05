// Room: /d/quanzhou/dangpu.c
// Date: by jason(残叶) Tue May  1 18:40:08 2001
inherit F_HOCKSHOP;


void create()
{
	set("short", "泉州当铺");
	set("long", @LONG
泉州是个繁忙的海港，来来往往的人常常为了
换现来这里当东西。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		  "south" : __DIR__"haigang",
		]));
    set("objects",([
    __DIR__"npc/wangfugui":1,
     ]));
	set("no_clean_up", 0);
	setup();
	unique_id=5;
	setup_shop();

}
