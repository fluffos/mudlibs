// Room:/d/changan/road4.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大官道");
	set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向函
谷关，往西则直达长安城。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" :  __DIR__"dong-chengmen",
		"east" :  __DIR__"road3",
	]));
	set("outdoors", "changan");
	setup();
}
