 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "芭蕉小屋");
        set("long", @LONG
一条略略有些干涸的小溪边是间很简陋的小屋，用些蔓藤树枝作架，棕榈芭蕉
的叶子作屋顶，不过还不算太难看，倒也别有风味。一些柔软的草铺在地上权做是
床，一个笑眯眯的弥陀佛像舒舒服服的躺在上面。茅草边是些坚韧的岩石块和两片
木块。穿过小屋，竟然是个青青的山谷。
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"shangu",
       "south" : __DIR__"shatan",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("indoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}   
