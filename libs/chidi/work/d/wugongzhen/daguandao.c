//daguandao.c  大官道
inherit  ROOM;

void  create  ()
{
        set("short",  "大官道");
        set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向函谷关，
往西北则直达长安城，西面则是去终南山的必经之路武功镇。
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "east"      :  __DIR__"daguandao2",
                "west"      :  "/d/wugongzhen/guandao1",
        ]));
        set("outdoors",  1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

