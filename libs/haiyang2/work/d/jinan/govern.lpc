 inherit ROOM;
void create()
{
        set("short", "济南衙门");
        set("long", @LONG
这里是朝廷所设，附近城里的纠纷都可以在这里上状请求处理。大厅南首一张卷
檐木案，案上有个小竹桶，里面插着几根有知府官印的竹签。木案后的太师椅上铺着
雪绒皮，椅后屏风上红日青云图。上悬金边匾：
                                明察秋毫

LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"street5",
        "south" : __DIR__"shufang",
        "west" : __DIR__"xiangfang",
    ]));
    set("objects", ([
        __DIR__"npc/yayi0" : 1,
        __DIR__"npc/yayi1" : 2,
        __DIR__"npc/yayi" : 2,
        __DIR__"npc/yayi2" : 2,
    ]) );
        set("coor/x",30);
        set("coor/y",1880);
        set("coor/z",0);
        setup(); 
} 

valid_leave(object me,string dir)
{
        object xing;
        
        if((dir =="south" || dir == "west") && me->query("class")!="official"
                &&xing=present("xing rui",this_object()))
                return notify_fail("邢锐对你喝道：“不得擅闯机要重地！！”\n");
        return 1;
}  
