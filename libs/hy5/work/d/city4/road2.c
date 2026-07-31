//  Room:  /d/city/road2.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大官道");
	set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向函
谷关，往西则直达长安城。北边有一条小路通往山里。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  "/d/village/hsroad1",
		"east"   :  __DIR__"hanguguan",
		"west"   :  __DIR__"zhongnan",
//"eastdown"  :  "/d/luoyang/guandaow4",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/mingjiao/yuan/zhou5" : 1,
		"/d/mingjiao/yuan/wu6" : 1,
		"/d/mingjiao/yuan/zheng7" : 1,
		"/d/mingjiao/yuan/wang8" : 1,
	]));
	set("outdoors",  1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}






