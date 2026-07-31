//  Room:  /d/city/road3.c

inherit  ROOM;

void  create  ()
{
	set("short",  "大官道");
	set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向函
谷关，往西北则直达长安城。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northwest" :  __DIR__"road4",
		"east"      :  __DIR__"zhongnan",
		"west"      :  "/d/quanzhen/guandao1",
	]));
	set("objects", ([
                "quest/skills2/wunon/dalie/dalie" : 2,
	])); 

	set("outdoors",  1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}






