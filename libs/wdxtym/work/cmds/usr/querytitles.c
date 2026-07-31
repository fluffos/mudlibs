// special

#include <ansi.h>
#define TITLE_D  "/adm/daemons/titled.c"
inherit F_CLEAN_UP;
int reach_player(object me,string title);
int main(object me, string arg)
{
	string  msg,fmsg;
	mapping ss;
	string  title;
	object ob;
	string pro,sname;
	int i;
       
	if (wizardp(me) && stringp(arg) &&
	    objectp(ob = find_player(arg)))
		// 查看其他玩家的特殊技能
		arg = 0;
	else
		ob = me;

	pro = (ob == me) ? "你" : ob->name(1);

	if (! ob->query("born"))
		return notify_fail(pro + "还没有出生呐，哪里有什么成就呢？\n");
		
           if (arg&&sscanf(arg, "%s==%s", msg, title) >= 2&&msg=="buy")
            {
			TITLE_D->buy_title(me,title);
			return 1;
			}

          if  (arg&&sscanf(arg, "%s==%s", msg, title) >= 2&&msg=="reach")
        {
        object player,*players;
        players = filter_array(users(),(: reach_player :),title);
        
       if (!sizeof(players))
        return notify_fail(title+"成就还没有任何玩家达成\n");
        
    msg= ZJOBLONG+HIR "◎"HIY "武动仙途成就系统" HIR "◎"NOR+ZJBR;
	msg+="目前在线玩家中:"+title+"成就已有"+sizeof(players)+"人达成\n";
	msg+=ZJOBACTS2+ZJMENUF(3,3,9,30); 
	
	foreach (player in players)
	msg += sprintf("名称：%s%s(%s):look %s%s",HIC+player->query("name")+NOR,ZJBR,HIG+player->query("id")+NOR,player->query("id"),ZJSEP);
	
	msg += HIY"返回界面"NOR":querytitles "+title;
	msg += "\n";
	write(msg);
			return 1;
			}
			
	if (! mapp(ss = TITLE_D->alltitles()) ||
	    ! sizeof(ss))
		return notify_fail(pro + "现在好像什么成就都没有哦，等待研发吧。\n");
	
	   if (!arg)
   {
	msg= ZJOBLONG+HIR "◎"HIY "武动仙途录成就系统" HIR "◎"NOR;
	msg+="目前已收录:"+sizeof(keys(ss))+"个称号\n";
	msg+=ZJOBACTS2+ZJMENUF(2,2,9,32); 
	
	    foreach (title in keys(ss))
     {		
		fmsg =HIC"〖"+title+"〗"NOR;
		fmsg+=me->query("titles/"+title)?HIM"(已拥有)":HIR"(未拥有)";
		msg+=fmsg+":querytitles "+title+ZJSEP;	
	 }	
		msg += "\n";	
      	write(msg);
     	return 1;
	}
	else
if (arg && (ob == me))
	{
		if (me->is_busy())
			return notify_fail("你现在忙着呢，不能改变称号。\n");
			title = arg;					
			if (!ss[title])	
					return notify_fail("你好像没有这个称号...\n");
					 msg=ZJOBLONG+TITLE_D->query_title(me,title);
					 msg = replace_string(msg,"\n",ZJBR)+"\n"; 
 msg+=ZJOBACTS2+ZJMENUF(2,2,9,30); 
 msg+= "佩戴称号:usetitles "+title+ZJSEP;
 msg+= "兑换称号:querytitles buy=="+title+ZJSEP;
 msg+= "达成人物:querytitles reach=="+title+ZJSEP;
 msg+= HIY"返回界面"NOR":querytitles";
 }  
msg += "\n";
	write(msg);
	return 1;
}

int reach_player(object me,string title)
{

if (me->query("titles/"+title))
return 1;

return 0;
}
int help(object me)
{
write(@HELP
指令格式 : querytitles <title> | <玩家ID>

使用这条命令可以查看你的称号。

HELP );
    return 1;
}
