
// by paladin
inherit ROOM;

void create()
{
        set("short", "琅缳福地");
        set("long", @LONG
这是个极大的石洞，比之外面的石室大了数倍，洞中一排排的列满木制书架，
可是架上却空洞洞地连一本书册也无。书架上贴满了签条，尽是“昆仑派”、
“少林派”、“四川青城派”、“山东蓬莱派”等等名称. 架上书册却已为人
搬走一空.
LONG
        );
       set("no_sleep_room",1);
       set("no_steal", "1");
//     set("no_fight", "1");

        set("exits", ([
                "north" : __DIR__"woshi",
                "west" : __DIR__"shishi",
        ]));

 set("objects",([
        __DIR__"npc/duanyu" : 1,
                 "/d/dalicheng/npc/wang" : 1,
//        __DIR__"npc/wang" : 1,
     ]));

        setup();

}
/*void init()
{
        add_action("do_fight", "perform");
        add_action("do_fight","yong");
        add_action("do_fight","yun");
        add_action("do_fight","exert");

}
int do_fight()
{
        write("这里是块福地，打打杀杀有煞风景呀。\n");
        return 1;
}*/



int valid_leave(object me,string dir)
{
     if(dir=="north"&&(string)me->query("family/family_name")!="天龙寺")
    return notify_fail("那是段誉的房间，外人不得入内!!\n");
    return ::valid_leave(me,dir);
}

