// Room: /u/poq/sdxl/dongkou.c 洞口
// by poq@jyqx 97/7
// alter dubei
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "洞口"NOR);
    set("long", 
"四下长草齐膝，一片寂静。你面前是一个大山洞。东南方是幽暗的深谷。"
);

    set("exits", ([
        "southeast" : __DIR__"xiaolu3",
        "enter" : __DIR__"shandong",
    ]));

    set("outdoors", "xiangyang");

    set("item_desc", ([
        "dong" : "山洞里面黑黝黝的，你看不到任何东西。\n",
	]));

    setup();
    (CLASS_D("ultra") + "/dugu")->come_here();  
}

 
string long()
{
        object ob;   
        string msg;   

        msg = query("long"); 
        if (! objectp(ob = present("dugu qiubai", this_object())))   
                msg += "\n";
        else if (! ob->is_fighting())   
                msg += "只见一人坐在地上，手中抱着一柄竹剑，翻了复"  
                       "去的看，也不知道在研究什么。\n";   
        else   
                msg += "只见一人正在与" +   
                       (ob->is_fighting(this_player()) ? "你" : "人") +   
                       "激战，竹剑施展开来竟然有诺大的威力，真是匪夷所思。\n";   
           return sort_string(msg, 64, 4);   
}
