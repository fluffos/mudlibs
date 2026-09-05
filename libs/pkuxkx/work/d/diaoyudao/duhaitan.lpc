// Room: /d/quanzhou/duhaitan.c
// Date: cgbii 96/10/3
//modify by hongdou 98.9.15
// enter 船 上船
//enter chuan后，e,n,n,w,w,w,w,s,w,w,n,w,w 可到达码头。
inherit ROOM;


//int do_enter();


void create()
{
    set("short", "钓鱼岛海滩");
    set("long", @LONG
这里就是钓鱼岛的岸滩，到处都残留着倭寇丢下的废物，而你的
船(chuan)就停泊在那里。
LONG
    );

    set("exits", ([
         "northeast" : __DIR__"haitan1",
        "southeast" : __DIR__"shatan1",
        "eastup" : __DIR__"dengta_0",
    ]));

    set("item_desc", ([
        "chuan" : "你的船就泊在那里，千万要看牢，给冲走了就回不了去啦。\n",
    ]));

    set("outdoors","diaoyudao");
    setup();
}



void init()
{
    add_action("do_enter", "enter");
}


int do_enter(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" || arg=="chuan" ) arg = "船";
    if( arg!="船")
    {return 1;}
    if( arg=="船")
    {
    if( (int)this_player()->query("dex") < 20 )
        message_vision("$N笨手笨脚的登上了船，弯低身往船舱钻了进去。\n",
            this_player());
        else
        message_vision("$N潇潇洒洒的纵身一越，就登上了船，往船舱钻了进去。\n",
            this_player());
        }
     this_player()->move(__DIR__"x_chuan2");
     this_player()->set_temp("航2",1);
     return 1;
}
