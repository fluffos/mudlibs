
#include <job_mul.h>
#include <ansi.h>
inherit ROOM;

int do_pi(string arg);

void create()
{
	set("short", "粥室");
	set("long", @LONG
一间不大的小屋，正中摆着一口大铁锅，正冒着腾腾的热气，一股粥香弥
漫在室内。几个火工正在忙着加柴，煽火，全寺弟子做完早课都要喝粥。一位
侍粥僧挥舞着沉重的大铁勺，正在吃力的搅动着粥汤。
LONG
       );
	set("no_fight",1);
	set("exits", ([
		"south"  : __DIR__"zhaitang",
	]));
	set("objects", ([
        	"d/shaolin/npc/szseng" : 1,
      	]));
	setup();
}

void init()
{
        add_action("do_ao", "ao");
        add_action("do_ao", "熬");
}

int do_ao(string arg)
{
        object me;
        int costj, costq,times;
        int exp,pot;
        me = this_player();

        if(me->query_temp("job_name")!="熬粥") 
          	return notify_fail("厨房可不是闹着玩的地方，你还是走开吧! \n");

        if (me->is_busy())
         	return notify_fail("你现在正忙着呢!\n");

        if (me->is_fighting())
         	return notify_fail("你正在战斗中,无法专心干活!\n");

        if ( !arg || arg != "粥" )
        	return notify_fail("你要做什么？\n");

        costj = (int)me->query("con")/2;
        costq = (int)me->query("str")/2;

        times = 15+random(6);

        if ((int)me->query("jingli") < costj
         || (int)me->query("qi") < costq){
        	message_vision("$N手一松，掉进锅里\n",me);
        	me->unconcious();
        	return 1;
        }
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       
        if ((int)me->query_temp("mark/做")>times 
         &&(present("shizhou seng", environment(me)))){
         	
         	me->add("job_time/少林",1);
         	
         	exp = (int)(me->query_skill("buddhism",1)/5)+60;
         	
         	exp = me->add_exp_combat(exp,"侍饭僧","少林熬粥");
         	//me->add("job_time/少林熬粥",1);
         	//GIFT_D->check_count(me,"侍饭僧","少林熬粥");
         	//me->add("combat_exp",exp);
         	         	         	
         	pot = 20+random(5);
		me->add("potential",pot);
                if(me->query("potential") > me->query("max_pot"))
                	me->set("potential", me->query("max_pot"));
             	
             	me->delete_temp("job_name");
             	me->delete_temp("mark");
            	return notify_fail(CYN"侍饭僧说道：多谢你来帮我的忙，还是快回去吧!!!\n"NOR);
        }
        message_vision("$N身形一抖，双脚勾住房梁，倒悬在空中，接过铁勺用力搅拌粥锅。\n", me);
        me->add_temp("mark/做",1);
        me->add_busy(1);
        
	if ((int)me->query_skill("hand", 1) < 20
         && random(10) > 6 ){
        	write(HIM"你在挥舞铁勺中，对手上功夫有些领悟!\n"NOR);
                me->improve_skill("hand", (int)(me->query_skill("buddhism",1) / 5));
                me->improve_skill("finger", (int)(me->query_skill("buddhism",1) / 5));
	}
      	return 1;
}
