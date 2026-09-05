// by bugbug & alading @ 缥缈水云间, 2003-4-5
// cmd.c
// written by mon 3/8/98

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string str;
	object *list;
	int i, j, threshold;

        if (time()-me->query_temp("scan_time") < 15 && !wizardp(me) )
		return notify_fail("等等，系统喘气中......\n");
    me->set_temp("scan_time",time());


   if( !arg || !sscanf(arg, "%d", threshold) )
	  threshold=0;


   list = users();

   i=sizeof(list);
printf("ID         attack  defense   dodge   damage   magic\n");

   for(j=0;j<i;j++)
   {
   	if(wizardp(list[j])) continue;
    if(list[j]->query("old_guy")) continue;
    if(list[j]->query("combat_exp") < 200000) continue;
		if(list[j]->query_temp("apply/damage") > threshold 
	   	|| list[j]->query_temp("apply/attack") > threshold 
		  || list[j]->query_temp("apply/defense") > threshold 
      || list[j]->query_temp("apply/dodge") > threshold 
      || list[j]->query_temp("apply/magic") > threshold 
		)
		    printf(
        "%10s  %5d  %5d  %5d   %5d   %5d\n",getuid(list[j]),
			to_int(list[j]->query_temp("apply/attack")),
			to_int(list[j]->query_temp("apply/defense")),
      to_int(list[j]->query_temp("apply/dodge")) ,
			to_int(list[j]->query_temp("apply/damage")),
			to_int(list[j]->query_temp("apply/magic"))
			);
	}
	return 1;
}
int help(object me)
{
write(@HELP
指令格式 : status_all [threshold]
	查询玩家apply/damage,apply/defense,apply/attack,apply/dodge,apply/magic的大小。
	显示>threshhold的玩家。
HELP
    );
    return 1;
}


