// Room : /d/huashan/siguoyahoudong.c
//by www

inherit ROOM;

void create()
{
        set("short", "思过崖后洞");
        set("long", @LONG
这里是华山派思过崖旁的山洞。洞里黑乎乎的，没有一个人影。
你往洞壁上一看，似乎刻满了很多扑击格斗的画面。地上躺着很多骷
髅，使你打了一个寒颤。你敲了一下洞壁，发现好象有回音。你仔细
一看似乎南面还是个小洞。
LONG
        );

        set("exits", ([
                   "out" : __DIR__"siguoya",
        ]));
        set("no_hsnewbiejob",1);
        setup();
        set("no_task",1);
        set("no_clean_up", 0);
        setup();


}
int valid_leave(object me, string dir)
{
        if( this_player()->query_temp("marks/风1") ) {
                this_player()->set_temp("marks/风1", 0);
        }
        return 1;
}

void init()
{
        this_player()->set_temp("marks/study",0);
        add_action("do_study", "study");
        add_action("do_south", "south");

}


int do_study(string arg)
{
        object me;

        me = this_player();
        if (me->query_temp("marks/study") == 4) return 0;

        if ( (int)me->query_skill("literate", 1) < 1)
	{
                write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}

        me->add("jing", -40);
        me->add("qi",-20);
        me->set_temp("marks/study",me->query_temp("marks/study")+1);
        message_vision("$N正专心研读洞壁上的格斗场面。\n", me);

	if((int)me->query_skill("sword",1)*(int)me->query_skill("sword",1)*(int)me->query_skill("sword",1)/10 > me->query("combat_exp"))
	{
		write("也许是缺乏实战经验，你对墙上画中的内容总是无法领会。\n");
		return 1;
	}

        if ( (int)me->query_skill("sword", 1) < 100)
        {
                me->improve_skill("sword", me->query("int"));
                write("你对着洞壁琢磨了一回儿，似乎对基本剑法有点心得。\n");
                me->set_temp("wall_learned",1);
        }


        if ( !me->query_temp("wall_learned") )
        {
                write("你对着洞壁琢磨了一回儿，发现上面所画的太过浅显，对你来说已毫无意义了。\n");
        }
        return 1;
}

int do_south()
{
        object me;
        mapping nowtime;
        me = this_player();
	if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() > 40) 
        {
		write("你身上背的东西太多，洞口又太小，你钻不进。\n");
                return 1;
	}
	nowtime=CHINESE_D->chinese_time();
/*	先去掉这个限制
	if(nowtime["hour"]!="子"&&nowtime["hour"]!="午"&&nowtime["hour"]!="卯"&&nowtime["hour"]!="酉") {
		message("vision","你看看四周，觉得现在来并不合适。\n",me);	

		return 1;
		}
*/
        if( (int)me->query_condition("findfeng")==0 || me->query("family/master_id")=="feng qingyang" )
	{
//降低难度  if (random (100) > 98 || me->query("family/master_id")=="feng qingyang")

                if (random (50) > 46 || me->query("family/master_id")=="feng qingyang")

        	{
                	message("vision",me->name() + "向南边的洞里钻了进去。\n",
	                environment(me), ({me}) );
        	        me->move("/d/huashan/feng");
                	message("vision",me->name() + "钻进南边的洞里。\n",
	                environment(me), ({me}) );
               		this_player()->set_temp("marks/风1", 0);
        	        return 1;
	        }
        	else
	        {
        	        message("vision",me->name() + "向南边的洞里钻了进去。\n",
                	environment(me), ({me}) );
	                me->move("/d/huashan/feng1");
                        me->apply_condition("findfeng", 60);
        	        message("vision",me->name() + "钻进南边的洞里。\n",
                	environment(me), ({me}) );
	                this_player()->set_temp("marks/风1", 0);
	                return 1;
        	}
	}
	else 
	{
                 write("你今天已经进去过了，怎么还要进去。\n");
		return 1;
	}
       
}
