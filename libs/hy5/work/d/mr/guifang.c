// /u/beyond/mr/guifang.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIY"闺房"NOR);
         set("long",@long
这里是山庄庄主女儿的闺房，里面透着一股醉人的少女芳香，令你陶醉。
在闺房的一角摆放着一张梳妆台，台上摆着一些女人用的胭脂粉和用来涂抹
嘴唇的香粉，以及一瓶玉露。房屋的另一角摆放着一张闺床，一缕青纱低垂
下来。墙上有一个窗户，一扇窗子(window)大敞着。
long);
         set("no_fight",1); 
set("item_desc",([
"window" : "窗台上有一个小巧的脚印(sign)。\n",
"sign" : "几只可爱的小脚印，看上去向一种美妙的步法，你不住想踏上去。\n",
]));
         set("exits",([
              "west" : __DIR__"cl4-4",
]));
         setup();
//       replace_program(ROOM);
}
                                                           
int init()
{
	add_action("do_ta","ta");
	add_action("do_jump","jump");
}

int do_ta(string arg)
{         object me;
	me = this_player();
 if ( !living(this_player()) || arg != "sign" )
                 return 0;
        if ((int)me->query_skill("dodge", 1) > 31)
        return notify_fail("你踏上可爱的小脚印，但是已经无法提高你的基本轻功了。\n");
        if ( (int)me->query("jing")<30) {
                 me->receive_damage("jing", 10);
                 write("你太累了，已经抬不起脚了！\n");              
        return 1;
}
        me->receive_damage("jing", random(25));
        message_vision("$N正在踏着窗台上的小脚印。\n", me);  
        write("你踏着小脚印，使你的基本轻功又进了一步。\n");
                  me->improve_skill("dodge", me->query("int"));       
         return 1;
} 

int do_jump(string arg)
{       object me;
        me = this_player();
        if (arg !="window") 
        return notify_fail("你要干什么？\n");
        if( arg=="window")
        {          
             write("你一纵身，从窗户跳了下去。\n");
                    message("vision",
             me->name() + "从窗户跳了下去。\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"ytyuan1");
                    message("vision",
                  me->name() + "从墙上的窗户中跳了下来。\n",
                             environment(me), ({me}) );
                }
                return 1;
            }

        
