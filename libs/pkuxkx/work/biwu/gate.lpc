inherit ROOM;

void create()
{
	set("short","武门");
	set("long",@LONG
    一路走来，景致平平，突然一座大门突兀而起，气势巍峨。门上有匾，抬眼望去，两个朱红的大字：武门。
这里就是天下武林门派比武较技的所在，请按照你的门派属性选择入口。
LONG);
	set("exits",
		([
			"south":"/d/luoyang/ximen",
		]));
		    	
    set("outdoors", "luoyang");        
	set("no_reset",1);
	set("no_clean_up",1);
	set("no_die",1);
	set("no_fight",1);
	setup();	
}

void init()
{
    //for no_reset room, objects can not be created automatically.
    //so we add a npc here.
    object master;
    if(!objectp(present("jason npc")))
    {
        master = new(__DIR__"master");
        master->move(this_object());
    }
}

int valid_leave(object me,string dir)
{
	object target;
    object* inv;    
    int i;
    int count = 0;
    object kickob;
    
	if(query("exits/"+dir))
	{
		target = load_object(query("exits/"+dir));
		if(objectp(target) && !target->query("family_name"))
		{
			return ::valid_leave(me,dir);
		}

		if(objectp(target) && target->query("family_name") == me->query("family/family_name") && BIWU_D->taskstarted() != 1)
		{
			if(target->query("expstage") > 0 && (target->query("expstage")) < me->query("combat_exp") / 1000000)
			{
				return notify_fail("现在是"+chinese_number(target->query("expstage"))+"M以下的小辈们在比武，你德高望重，不好插手。\n");
			}
			if(me->query("score") < 1000)
			{
				return notify_fail("你对师门的贡献不够，没有资格代表师门参战。\n");
			}
			if (me->query("exp/biwu") > (me->query("combat_exp")/10)&& me->query("combat_exp")<30000000)
			{
				return notify_fail("你整天来蹭比武，巫师都看不下去了，想进去，门也没有！\n");
			}
            inv = deep_inventory(me);
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if(userp(inv[i]))
                {
                    me->add_busy(5);
                    return notify_fail("比武者必须光明磊落，你带别人进去是什么意思？\n");
                }
            }
			if(me->is_realuser())
            {
                inv = all_inventory(target);   
                for(i=sizeof(inv)-1; i>=0; i--)            
                {
                    if(userp(inv[i]) && interactive(inv[i]))
                    {
                        count++;
                        if(!inv[i]->is_realuser())
                        {
                            kickob = inv[i];
                        }
                    }
                    
                }
                
                if(count >= target->query("max_user") && objectp(kickob))
                {
                    //实名用户顶替非实名用户
                    tell_object(kickob,"由于名额有限，你被实名用户"+me->name()+"顶替了。\n想成为实名用户吗，请访问pkuxkx.com申请。\n");
                    write("你顶替了非实名用户"+kickob->name()+"的名额参加比武。\n");
                    kickob->move(this_object());                    
                }
            }
            else
            {                
                //检查不能有同ip的人，转发ip也不行,实名用户不判断这个。
                for(i=sizeof(inv)-1; i>=0; i--)
                {
                    if(userp(inv[i]) && interactive(inv[i]) && stringp(query_ip_number(inv[i])) && strcmp(query_ip_number(inv[i]),query_ip_number(me)) == 0)
                    {
                        me->add_busy(5);
                        return notify_fail("对不起不允许一个玩家派两个ID比武。如果你使用的是转发IP，抱歉。\n");
                    }
                }						
            }
			if(me->query("antirobot/deactivity")  > 2)
			{
				write("你的活跃度已经一段时间没有更新了，比武的奖励可能会受到影响。请help fullme。\n");
			}
			if (!me->query("biography/jobs/biwu"))
			{
				me->set("biography/jobs/biwu",time());//个人传记记录第一次完成任务时间ZINE
			}
			return ::valid_leave(me,dir);
		}
	}
	return notify_fail("你不能去那里，那里是比武的门派在比武准备期间才能进去的。\n");
}
