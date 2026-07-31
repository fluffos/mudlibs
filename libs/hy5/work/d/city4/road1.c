//  Room:  /d/city/road1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "关洛道");
	set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向洛阳城，
往西则直达长安城。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  "/d/luoyang/westgate",
		"west"  :  __DIR__"hanguguan",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/mingjiao/yuan/zhaomin" : 1,
		"/d/mingjiao/yuan/zhao1" : 1,
		"/d/mingjiao/yuan/qian2" : 1,
		"/d/mingjiao/yuan/sun3" : 1,
		"/d/mingjiao/yuan/li4" : 1,
			"/d/mingjiao/yuan/lu" : 1,
				"/d/mingjiao/yuan/he" : 1,
/*
		"/d/mingjiao/yuan/zhou5" : 1,
		"/d/mingjiao/yuan/wu6" : 1,
		"/d/mingjiao/yuan/zheng7" : 1,
		"/d/mingjiao/yuan/wang8" : 1,
*/
	]));
	set("outdoors",  1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}






