// mishi.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",BLU"密室"NOR);
        set("long",@long
你眼前突然出现个地下密室，密室里很小，但摆放着一些石桌石椅，石几
石床，边上堆放着一些石制的器皿，都堆满了灰，看来似乎已经很久没人来过
了。正对你的一堵墙壁(wall)上好象刻着些什么。
long);

        set("item_desc", ([
            "wall" : "一整块墙上东划西划画了不少奇怪的符号（fuhao）。\n",
            "fuhao" : "奇奇怪怪的符号，好象可以（lingwu）。\n",
        ]));
 
	set("exits" ,([
            "out" : __DIR__"jiashan1",
	]));

        setup();
}

void init()
{  
        add_action("do_study", "study");
        add_action("do_study", "lingwu");
}

int do_study(string arg)
{
        object me;

        me = this_player();
        if ( !arg || arg != "fuhao" )
                 return notify_fail ("你想研读什么？\n");
        if (me->is_busy() || me->is_fighting()){
           write("你正忙着哪！\n");
           return 1;
           }
        if ((int)me->query_skill("literate", 1) < 1) {
            write("你是个文盲，先学点文化(literate)吧。\n");
            return 1;
            }
        if(me->query("potential", 1) < 1 ) {
            write ("你的潜能没了，不能再进一步领悟了。\n");
            return 1;
            }
        if ((int)me->query("jing") < 20) {
            me->receive_damage("jing", 10);
            write("你太累了，已经没有力气来研读墙壁上「奇异符号」的了！\n");
            return 1;
            }
            me->receive_damage("jing", 10 + random(5));
            tell_room(this_object(), me->name() + "正专心研究墙面上的「奇异符号」。\n", ({ me }));         
        if ( (int)me->query_skill("shenzhao-jing", 1) < 15 && (int)me->query_skill("force",1) > 5 ) {
            me->improve_skill("shenzhao-jing", me->query("int")/3+1);
            me->add("potential",-1);	     
            write("你对着墙面上的「奇异符号」琢磨了一会儿，似乎对「神照经」略有心得。\n");
            return 1;
            } 
        if ((int)me->query_skill("force", 1) <= 5) {
            write("你的基本内功太低，看了半天就是不能理解符号的含义。\n");
            return 1;
	    }
        write("你已经把符号研究透彻，再也不能从上面学到什么东西了。\n");
        return 1;
}
 
