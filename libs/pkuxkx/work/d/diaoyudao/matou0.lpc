// Room: /d/diaoyudao/matou0.c
// Date: cgbii 96/10/2
// modify by hongdou 98.9.15

//航海路线：e,e,s,e,e,n,e,e,e,e,s,s,s可到达钓鱼岛。

inherit ROOM;

void create()
{
    set("short", "泉州码头");
    set("long", @LONG
只见码头上挤满了许多等待出海的客商，各种各样的人在来
来往往的穿梭不停，热闹极了。面前是一望无无际，波浪汹涌的
大海(dahai) ，岸边泊满了不同种类的船只，船工水手们在船上
船下来来回回不停的搬运货物，由此可见泉州港是何等的繁忙。
LONG
    );
         set("outdoors","diaoyudao");

    set("exits", ([
        "westup" : "/d/quanzhou2/haigang",
	"north"  : __DIR__"matou2",
	"south" : __DIR__"matou1",	
    ]));

    set("item_desc", ([
        "dahai" : "你望着眼前波涛汹涌的大海，你感到自己是如此的渺小，然而\n"
                  "你肩负着的国家民族大业是如此的沉重，不禁大有一番感慨！\n",
            ]));
        set("objects", ([
//         __DIR__"npc/mtlangren" : 2,          
//                __DIR__"npc/langren_t":1,
       ]));
    setup();
}


/*
void init()
{
    add_action("do_enter", "enter");
}

int do_enter(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

  if (arg=="chuan" || arg=="boat") arg = "船";
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
    this_player()->move(__DIR__"c_chuan");
    return 1;
}
*/
