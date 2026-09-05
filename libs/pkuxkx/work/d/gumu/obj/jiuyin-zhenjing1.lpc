// jiuyin-zhenjing1.c
#include <ansi.h>
inherit ITEM;
int do_zuanyan(string arj);

void create()
{
     set_name(MAG "九阴真经" NOR, ({ "jiuyin zhenjing", "zhenjing" }));
        set_weight(200);
        set("unit", "本");
        set("long", "这是道家武学之总纲「九阴真经」的上册，最后一篇好象文理不通，不知值不值的钻研(zuanyan).\n");
        set("value", 0);
//        set("no_drop",1);
//         set("no_give",1);
         set("no_steal",1);
//        set("no_get",1);
	set("material", "paper");
        set("skill", ([
                        "name": "jiuyin-shengong",      	// name of the skill
                        "exp_required": 100000,  	// minimum combat experience required
                        "jing_cost": 40+random(10),	// jing cost every time study this skill
                        "difficulty":   30,     	// the base int to learn this skill
                        "max_skill":    100      // the maximum level you can learn
        ]) );
setup();
}

void init()
{
	add_action("do_zuanyan","zuanyan");
}

int do_zuanyan(string arg)
{
        object me;
        mapping fam;
        string book;
        int times,realtimes,max_level;
        
	me = this_player();
        if(!arg || (sscanf(arg, "%s %d",book,times) < 1 ) || book != "zhenjing")
             return notify_fail("指令格式：zuanyan zhenjing [次数]\n");
        if (times < 1)
        	return notify_fail("你至少要读一次！\n");
	if( (int)me->query_skill("fanwen",1)<100)
    	{
            write("你看了半天，还是看不出头绪，只隐隐觉的好象自己梵文水平不够。\n");
            return 1;
	}
	if ( (int)me->query_skill("literate", 1) < 100)
        {
                write("你看了半天，还是看不出头绪，只隐隐觉的好象自己读书写字水平不够。\n");
                return 1;
        }
	if ( (int)me->query_skill("daoxue-xinfa", 1) < 100)
        {
                write("你觉的上面蕴含着深奥的道家真理，很难理会其中含义。\n");
                return 1;
        }

	realtimes = times;
        if ((me->query("jing")-120)/100 < times)
                realtimes = (me->query("jing")-120)/100;

        me->add("jing",-100*realtimes);
	if ( (int)me->query_skill("jiuyin-shengong", 1) < 100)
	{
	      write ("你的九阴神功的级别太低了，领悟不了上面的文字. \n");
	      return 1;
	}
	if ( (int)me->query_skill("jiuyin-shengong", 1) < ((int)me->query("int")+10)*5)
	{
		me->improve_skill("jiuyin-shengong", (int)(((int)me->query_skill("fanwen", 1)+(int)me->query_skill("literate")+(int)me->query_skill("daoxue-xinfa"))/30+(int)me->query("int")/7)*realtimes);
		write("你对九阴真经的最后一篇研读了一会,似乎有些心得, \n");
	}
	else	return notify_fail("你左看右看，始终看不懂最后一章的一些地方，看来以你的智力水平也就学到这个程度了。\n");
	if (realtimes < times)
		write("你现在有些疲倦，无法专心下来研读新知. \n");
	return 1;
}

