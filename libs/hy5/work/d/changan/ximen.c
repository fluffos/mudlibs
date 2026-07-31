inherit  ROOM;
void  create  ()
{
        set  ("short",  "长安城西北门");
        set  ("long",  @LONG
这里是长安城的西北门。东面就到了城中，远望人山人海，往来
行人车流不绝。西面一条大路通向远方。城门下有一些执勤的兵士。
时下虽已天下太平，但一干兵将还是英姿勃勃，警惕的盯着往来人
士。
LONG);
        set("exits",  ([
            "up"  :  __DIR__"ca29",
            "east"  :  __DIR__"ca18",
]));
        set("objects",  ([
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  1,
]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
        setup();
        replace_program(ROOM);
}

