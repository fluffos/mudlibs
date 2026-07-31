//ROM dating

inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long",
             "这是『白驼山庄』的大厅，内部摆设极尽豪华，当中一张黑色檀木\n"
         "条案，上面陈放着精美的花瓶和一些珍贵的瓷器，四壁挂满名家的字画。\n"
        );
	set("valid_startroom",1);

        set("exits", ([
                "north" : __DIR__"liangong",
                "southdown" : __DIR__"yuanzi",
//                "east" : "quest/menpai/btshan/zhubanzi",
        ]));
 set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects",([
		CLASS_D("btshan") + "/ouyangfeng" : 1,
                __DIR__"npc/yahuan" : 2,
                "/d/biwu/champion_bt":1,
                "quest/menpai/btshan/shi":1,
        ]));
//        set("no_clean_up", 0);
        setup();

        "/clone/board/baituo_b"->foo();

        replace_program(ROOM);
}

