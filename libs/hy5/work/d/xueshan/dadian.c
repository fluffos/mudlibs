//      dadian.c 大殿
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","大殿");
        set("long",@LONG
这里是雪山寺的大殿，中央供奉着佛祖塑像。僧人们
在念着经文。远来的香客们在这里虔诚地膜拜。大殿两侧
都是侧殿。
LONG );

set("roomif","$botten#讲经任务:ask banchan about job$#");

        set("exits",([
                "east"  : __DIR__"cedian1",
                "west"  : __DIR__"cedian2",
                "south" : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/lazhang" : 1,
		__DIR__"npc/xiang-ke" : 2,
		"/d/biwu/champion_xs":1,
		"/quest/menpaijob/xueshan/lj/banchan":1,
        ]));
        set("valid_startroom", 1);
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

        "/clone/board/xueshan_b"->foo();
}
