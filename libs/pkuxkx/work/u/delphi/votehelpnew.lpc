//helpnew  delphi

inherit F_CLEAN_UP;
#define HELPNEW_LST "/log/doc/helpnew_lst"

void main(object me, string victim_name)
{
        object victim;
        string msg;
        string *line;
        int allow_number;
        string lines, my_id, ip_list, victim_id, cname;
        int i;
        
        allow_number = 0;
        if ((int)me->query("combatd_exp")>500000)             
        {
           return notify_fail("你已经不是新手，需要自立更生了。\n");
        }
        if (!victim_name )
        {
           return notify_fail("你要投谁的票？\n");
        }
        if (victim_name == (string)me->query("id"))
        {
           return notify_fail("你要投自己的票，这怎么能行？\n");
        }

//对方不在线不能投票
        victim = LOGIN_D->find_body(victim_name);
        if (!victim) return notify_fail("你要投谁的票？\n");
        
//开始读取文件，看是否已经投票或IP地址重复，防止bug
        lines = read_file(HELPNEW_LST);
        if(lines)
        {
           line = explode(lines, "\n");
           for(i=0;i<sizeof(line);i++)
           {
              sscanf(line[i],"%s,%s,%s,%s", my_id, ip_list, victim_id, cname);

//限制已经投票者和同一ip投票              
              if(my_id == me->query("id") || ip_list == query_ip_name(me)) 
                   {
                        allow_number =1;
                        break;
                   }
           }
        }
                
        if (allow_number==1) return notify_fail("对不起，你的投票无效！\n");
        else 
        {
           msg = me->query("id") + "," + query_ip_name(me) + "," 
                 + victim->query("id") + "," + victim->query("name") + "\n";
           write_file(HELPNEW_LST, msg);   
           CHANNEL_D->do_channel(this_object(),"chat",me->query("name")+
                "("+me->query("id")+")由于" + victim->query("name") + "("
                + victim->query("id") + ")乐于帮助新手，决定投其一票！\n");                  
           return notify_fail("投票成功！\n");
        }            
}





int help(object me)
{
write(@HELP
指令格式 : votehelpnew  <某人> 

对乐于帮助新手的玩家投票。wiz会给予这个玩家一定
奖励。

HELP
    );
    return 1;
}
