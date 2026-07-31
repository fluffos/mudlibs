// Room: /d/dali/duan2.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：20时44分1秒。

inherit ROOM;

void create()
{
	set("short", "镇南王府大门");
	set("long", @LONG
来到府前，只见朱红的大门之前左右旗杆高耸，两头威武狰狞
的玉石狮子盘坐门旁，一排白玉阶石直通到前厅，势派豪雄之极。
门口站满了亲兵卫士，戒备森严。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"duan1",
  "eastup" : __DIR__"duan3",
]));

                 set("objects", ([
                __DIR__"npc/qingbing" : 2,
        ]));

         
	setup();
}

