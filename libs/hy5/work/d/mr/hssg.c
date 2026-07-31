// /u/beyond/mr/hssg.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",MAG"还施水阁"NOR);
         set("long",
"这就是举世闻名的姑苏慕容的还施水阁，这里据说有很多武林人事向\n"
"往以久的武功。只见墙上有一个书架子(shujia)，上面摆满了各种武籍。\n"
);
         set("exits",([
             "south" : __DIR__"jiabi",
]));
         set("item_desc", ([
             "shujia" : "书架上各个门派的武功秘籍(miji)，你忍不住想拿起一本就翻看起来。\n",
]));
}

int init()
{
        add_action("do_kan","kan");  
        add_action("do_kan","du");
        add_action("do_kan","yandu");
        add_action("do_kan","lingwu");
        add_action("do_kan","study");
}

int do_kan(string arg)
{         object me;
        me = this_player();
 if ( !living(this_player()) || arg != "miji" )
                 return 0;
        if (me->query("family/master_name")!="慕容复")
        if (me->query("family/master_name")!="慕容博")
        return 0;
        if ( (int)me->query_skill("literate", 1) < 1)
                 return notify_fail("你是个文盲，先学点文化(literate)再领悟斗转星移吧。\n");
	if ( (int)me->query_skill("literate", 1) < 165)
		 return notify_fail("你的读书写字级别不够，无法领悟出斗转星移的绝妙之处。\n");
        if ( (int)me->query_skill("parry", 1) < 160 )
                 return notify_fail("凭你现在的招架功夫，无法领悟斗转星移这么高深的武功。\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 170)
        return notify_fail("你看了半天书架上的武功秘籍，结果对你来说太深奥了！\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) > 200)
        return notify_fail("恭喜恭喜！你已经融会贯通了斗转星移的绝妙之处！\n");
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("你太累了，已经没有力气来领悟斗转星移了！\n");              
        return 1;}
	if( (int)me->query("potential", 1) < 2 ) {
		write("你已经没有潜能来领悟学习斗转星移了。\n");
		return 1; }
		  me->receive_damage("jing", random(50));
        message_vision("$N正在低头沉思有关斗转星移的种种疑难。\n", me);  
        write("你静静地钻研各家门派的武功秘籍，冥冥之中你的斗转星移又进了一步。\n");
               me->improve_skill("douzhuan-xingyi", me->query_skill("literate",1)/2);
		  me->add("potential", -2);       
         return 1;
}
