inherit ROOM;
void create()
{
        set("short", "太白居");
        set("long", @LONG
这里是太白先生居所，窗明几净，一尘不染。在他的两侧坐满了求学的学生。
一张古意盎然的书案放在太白先生的前面，案上摆着几本翻开了的线装书籍。太白
先生的身后是一个书架(shujia)讲堂内多历代楹联石刻，正上方还有个牌匾（pai)
。  
LONG
        );
        set("exits", ([
                "north" : __DIR__"shuyuan2",
                "northeast" : __DIR__"dongmen",
        ]));
        set("item_desc", ([
                   "pai" : "\n昔在长安醉花柳，五侯七貴同杯酒。"
                           "\n氣岸遥临豪士前，风流肯落他人后。"
                           "\n夫子红颜我少年，章台走马著金鞭。"
                           "\n文章献纳麒麟殿，歌舞淹留玳瑁筵。\n\n",
        "shujia":"书架上一尘不染，放满了太白先生历年来写著的诗篇。\n",
        ]));
        
        set("objects", ([
                __DIR__"npc/libai": 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && (userp(me) && !wizardp(me)))
                return notify_fail("那是太白先生的私人寝室！\n");
        return 1;
}

