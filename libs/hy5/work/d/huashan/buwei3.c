// buwei3.c

inherit ROOM;

void create()
{
        set("short", "偏厅");
	set("long", @LONG
偏厅里供奉着华山历代祖师的神位。正中神案的墙上是华山派开山祖
师风祖师的画象。画象神情清隽，非常传神。神案上香炉里插着三柱清香，
香烟袅袅上升，散发着一股檀香味。西面有扇门通往外面的正厅。
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"buwei1",
	]));
	set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
         set("objects", ([
           "quest/menpai/huashan/shi" : 1,
                "/d/huashan/npc/nvdizi" :2,
                "/d/huashan/npc/nandizi" :2,
                "/d/biwu/champion_hs" :1,
        ]));set("no_clean_up", 0);
        set("valid_startroom","1");

        setup();
        "/clone/board/huashan_b"->foo();
        replace_program(ROOM);
}
