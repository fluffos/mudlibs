//daguandao2.c

inherit  ROOM;

void  create  ()
{
        set("short",  "大官道");
        set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向函谷关，
往西则直达长安城。
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"   :  __DIR__"hanguguan",
                "west"   :  __DIR__"daguandao",
        ]));

        set("outdoors",  1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}




