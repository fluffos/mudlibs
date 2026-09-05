// D:\xkx\d\liuxiu-shanzhuang\cangshuge.c藏书阁
// labaz  2012/10/23
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

int do_get(string);

void create()
{
    set("short", "藏书阁");
    set("long", 
    "这里是山庄保存重要书册典籍的地方，如果未经庄主允许是不能进入
这里的。在此你可以了解到江湖上的典故、秘闻甚至是不少门派的武功。
这里排列着好几排的书架"+HIY"(shujia)"NOR+"。\n"
);

    set("indoors","liuxiu-shanzhuang");

    set("item_desc", ([
        "shujia":"在书架的醒目位置你一眼就看到了你要找的那本"+HIY"《江湖掌故》"NOR+"，\n你可以把它从书架上取下来"+HBBLU+WHT"(get book from shujia)"NOR+"读一下"+HBBLU+WHT"(read book for 1)"NOR+"。\n",
        ]));

    
    set("exits", ([
        "south" : __DIR__"shangwutang",
        ])
     );

    setup();
}

void init()
{
	add_action("show_quest", "quest");
    add_action("do_get","get");
}

int do_get(string arg)
{
    string book,shujia;
    object who,zhanggu;
    who=this_player();
    
    if (sscanf(arg, "%s from %s", book, shujia)==2)
    {
        if (strcmp(shujia,"shujia")!=0) return 0;
        if ((strcmp(book,"jianghu zhanggu")!=0 && strcmp(book,"book")!=0)) 
        {
            tell_object(who,"书架里没有这样东西。\n");
            return 1;
        }
        if (1==who->query("newbie_village/jianghuzhanggu"))
        {
            tell_object(who,"你已经读过这本书了，不需要再拿了。\n");
            return 1;
        }
        if (present("jianghu zhanggu",who))
        {
            tell_object(who,"你已经有这本书了，不需要再拿了。\n");
            return 1;
        }
        zhanggu=new(__DIR__"obj/jianghuzhanggu");
        message_vision("$N从书架上拿下了一本《江湖掌故》。\n",who);
        zhanggu->move(who);
        return 1;
    }
    return 0;
}
