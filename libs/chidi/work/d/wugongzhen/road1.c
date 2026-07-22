//road1.c

inherit  ROOM;

void  create  ()
{
        set("short",  "关洛道");
        set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向脂粉之
都的扬州，往西则直达长安城。
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"  :  "/d/quanzhen/zhuangjiadi2",
                "west"  :  __DIR__"hanguguan",
        ]));

        set("outdoors",  1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


