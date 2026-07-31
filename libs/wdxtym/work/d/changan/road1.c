inherit  ROOM;

void  create  ()
{
	set("short",  "关洛道");
	set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向脂
粉之都的扬州，往西则直达长安城。
LONG);
	set("exits",  ([
		"east"  :  "/d/city/ximenroad",
		"west"  :  __DIR__"hanguguan",
	]));

	set("outdoors", "changan");
	setup();
}

