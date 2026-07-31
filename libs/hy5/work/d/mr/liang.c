// /u/beyond/mr/liang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short",HIW"梁上"NOR);
       set("long",@long
这是碧水亭上的房梁，上面画满了希奇古怪的字符。
long
        );                                           
        set("item_desc",([
  "zihua" : "上面画满了各种奇怪的字符。\n"
        ]));
        setup();
}
void init()
{
add_action("do_study","lingwu");                           
add_action("do_study","kan");                            
add_action("do_study","study");
add_action("do_jump","jump");
}

int do_study(string arg)
{         object me;
	me = this_player();
        if (arg != "zihua" )
                 return 0;
    if (me->query("family/master_name")!="慕容复" && me->query("family/master_name")!="慕容博")
         return 0;
 
        if ( (int)me->query_skill("literate", 1) < 1)
                 return notify_fail("你是个文盲，先学点文化(literate)再领悟斗转星移吧。\n");
        if ( (int)me->query_skill("parry", 1) < 120 )
		 return notify_fail("凭你现在的招架功夫，无法领悟斗转星移这么高深的武功。\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 130)
        return notify_fail("你对着字画看了半天，结果对你来说太深奥了，什么都没有学到！\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) > 170)
        return notify_fail("你对着字画看了半天，结果对你来说已经太浅了，什么都没有学到！\n");
if(me->query_skill("douzhuan-xingyi",1)>(me->query_skill("shenyuan-gong",1)+30)){
write("由于你的神元功火侯不够，不能再进行更高一层的提高。\n");
return 1;
}
if(me->query_skill("douzhuan-xingyi",1)>(me->query_skill("literate",1)+30)){
write("由于你的读书写字火侯不够，不能再进行更高一层的提高。\n");
return 1;
}
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("你太累了，已经没有力气来领悟斗转星移了！\n");              
        return 1;
}
        me->receive_damage("jing", random(45));
        message_vision("$N正在低头沉思有关斗转星移的种种疑难。\n", me);  
        write("你对着字画看了半天，冥冥之中你的斗转星移又进了一步。\n");
                  me->improve_skill("douzhuan-xingyi", me->query("int"));       
         return 1;
}

int do_jump(string arg)
{
                         object me;
                    me = this_player();
                     if (arg !="down") 
                 return notify_fail("你要到那去？\n");
                     if( arg=="down")
           {
            
                    write("你纵身跳下了房梁。\n");
                    message("vision",
                             me->name() + "一纵身跳下了房梁。\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"bishuiting");
                    message("vision",
                             me->name() + "走了过来。\n",
                             environment(me), ({me}) );
                }
                return 1;
            }
