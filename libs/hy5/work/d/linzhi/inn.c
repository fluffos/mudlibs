// Room: /d/linzhi/inn.c

inherit ROOM;

void create()
{
	set("short", "巴依客店大院");
	set("long", @LONG
这里是八一镇唯一的一家客店，也是巴依老爷的财产。大院
四周用石砖围起，院北侧摆着几个盛水用的石缸(fill)，东侧横
放着一个躺椅。西边是个牲口圈。一个伙计看见你走进来，热情
的你向打招呼。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by04",
  "north" : __DIR__"inn01",
  "west" : __DIR__"inn02",
]));
        set("outdoors", "linzhi");
        set("resource/water", 1); 
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
