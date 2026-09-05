// Room: /u/cuer/emei/dcmen.c

inherit ROOM;

void create()
{
	set("short", "东侧门");
	set("long", @LONG
这里是千佛庵的东侧门了，这是一个月亮门，不时有
峨嵋弟子们来来往往。出东侧门后一条石阶展现在你眼前
，沿石阶往上走就到了归云阁。				
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dlang3",
  "eastup" : __DIR__"guiyun",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
