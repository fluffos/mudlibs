inherit  ROOM;
void  create  ()
{
    set  ("short",  "终南山口");
    set  ("long",  @LONG
终南山又称太乙山，距长安城八十多里，素有“锦秀巨屏拱长
安”之说。据传老子曾在山中讲经。这条大官道穿越终南山口，两
面秀峰入云，这里却没有一条路可以上山。西面是往长安的大道，
东面前往中原。
LONG);
    set("exits",  ([
//        "east"  :  __DIR__"road2",
//        "west"  :  __DIR__"road3",
    ]));
    set("outdoors", "changan");

    setup();
}

