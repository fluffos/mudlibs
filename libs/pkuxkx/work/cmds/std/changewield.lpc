// changewield.c

inherit F_CLEAN_UP;

int main(object me)
{
        object weapon1, weapon2;
		int dmg1,dmg2,dmg;
        if( me->is_busy() ) 
                return notify_fail("你已经够忙的了！\n");
        if(!wizardp(me) && time()-me->query_temp("changewield_time") < 3)
                return notify_fail("你刚换过一次，也不嫌累得慌！\n");
        if ( wizardp(me) )
        {
        	me->changewield();
        	return 1;
        }
        else if((weapon1=me->query_temp("weapon")) && (weapon2=me->query_temp("secondary_weapon")))
        {
				if (me->query_temp("yinyang-daoluan/daoluan") || me->query_temp("kuihua.guiming"))
				{
					return notify_fail("你现在的武功状态无法交换武器。\n");
				}
				else
				{
					me->changewield();
					if (me->is_fighting())
					{
							if (random(me->query_kar()) < 3)
							{
									message_vision("$N试图交换左右手的兵器，无奈对手攻势太急，反把自己弄得手忙脚乱。\n",me);
									me->start_busy(3);
							} 
					}
					message_vision("$N两手一交叉，将右手的" + weapon1->name() + "换到左手，左手的" + weapon2->name() + "换到右手。\n", me);
					me->set_temp("changewield_time",time());

					return 1;
				}
        }
        else if (!me->query_temp("weapon") && !me->query_temp("secondary_weapon"))
                return notify_fail("你手上没有武器，换什么换？\n");
        else 
                return notify_fail("你手上只有一件武器，没有必要换来换去。\n");
}

int help(object me)
{
        write(@HELP
指令格式：changewield

这个指令让你互换左右手武器。

HELP
    );
    return 1;
}
