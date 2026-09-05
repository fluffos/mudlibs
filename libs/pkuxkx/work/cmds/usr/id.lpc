// id.c
// modified by whuan,20008-3-19,去重
inherit F_CLEAN_UP;
inherit F_MORE;

int main(object me, string arg)
{
	int i, j;
	int *count;
	object obj, *inv ,*inv1;
	string *id;
	string str;


        if(!wizardp(me) && time()-me->query_temp("scan_time") < 3)
                return notify_fail("等等，系统喘气中......\n");
        me->set_temp("scan_time",time());
        str = "";
	if( !arg ) 
	{
		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("你身上没有任何东西。\n");
        write( "你(你)身上携带物品的别称如下(右方) :\n");
         for (i = 0; i < sizeof(inv); i++) 
        {
        	if (!arrayp(inv1))
        {inv1=({inv[i]});
         count=({1});}
        else
        {
        	for (j = 0; j < sizeof(inv1); j++)
             if ((base_name(inv[i]) == base_name(inv1[j])) && (inv[i]->short() == inv1[j]->short()))
             break;
        if (j == sizeof(inv1))
         {
             inv1+=({inv[i]});
             count+=({1});
         }
        else
             count[j]+=1;
         }      
        }
    for(i=0; i<sizeof(inv1); i++) 
    {
      if( !me->visible(inv1[i]) ) continue;
			str = str + sprintf("%-20s = %s\n", inv1[i]->name(),
				implode(inv1[i]->parse_command_id_list(), ", ") );
    }
		start_more(str);
		return 1;
	}

	if( arg=="here" ) {
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("这里没有任何东西。\n");
        write( "在这个房间中, 生物及物品的(英文)名称如下 :\n");
    for (i = 0; i < sizeof(inv); i++) 
        {
        	if (!arrayp(inv1))
        {inv1=({inv[i]});
         count=({1});}
        else
        {
        	for (j = 0; j < sizeof(inv1); j++)
             if ((base_name(inv[i]) == base_name(inv1[j])) && (inv[i]->short() == inv1[j]->short()))
             break;
        if (j == sizeof(inv1))
         {
             inv1+=({inv[i]});
             count+=({1});
         }
        else
             count[j]+=1;
         }      
        }        
		for(i=0; i<sizeof(inv1); i++) {
			if( !me->visible(inv1[i]) ) continue;
       if( inv1[i]->query("no_show") ) continue;
			str = str + sprintf("%-20s = %s\n", inv1[i]->name(),
				implode(inv1[i]->parse_command_id_list(), ", ") );
		}
		start_more(str);
		return 1;
	}
}
int help(object me)
{
write(@HELP
指令格式 : id [here]
 
这个指令可以让你知道物品的英文名称及名字. 只打 id 会显示
你身上所携带物品的名称. 'id here' 则显示所有跟你在同一个
环境里的物件名称.
 
HELP
    );
    return 1;
}
 

