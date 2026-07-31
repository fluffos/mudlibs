// special

#include <ansi.h>
#define TITLE_D "/adm/daemons/titled.c"
inherit F_CLEAN_UP;
int reach_player(object me,string title);

int main(object me, string arg)
{
	string msg,fmsg;
	mapping ss;
	string title;
	object ob;
	string pro,sname;
	int i,z;
	if (wizardp(me) && stringp(arg) &&
	    objectp(ob = find_player(arg)))
		// 查看其他玩家的特殊技能
		arg = 0;
	else
		ob = me;

	pro = (ob == me) ? "你" : ob->name(1);

	if (! ob->query("born"))
		return notify_fail(pro + "还没有出生呐，哪里有什么成就呢？\n");
    if (arg&&sscanf(arg,"%s==%s",msg,title) >= 2&&msg=="buy")
	{ 
      TITLE_D->buy_title(me,title);
	  return 1;
	}
	
	if (arg&&sscanf(arg,"%s==%s",msg,title) >= 2&&msg=="eee")
	{ 
      TITLE_D->use_title(me,title);
	  return 1;
	}
     if (! mapp(ss = TITLE_D->alltitles())|| ! sizeof(ss))
		 	return notify_fail(pro + "现在好像什么成就都没有哦，等待研发吧。\n");
		
     if(!arg)
	 {msg= ZJOBLONG+"在江湖中目前可以通过努力获取的成就如下：\n"NOR;
		msg+=ZJOBACTS2+ZJMENUF(2,2,10,38);
		foreach (title in keys(ss))
		{ 
		fmsg =HIC+title+NOR;
		fmsg+=me->query("titles/"+title)?"["HIY"已获取"NOR"]":"["HIR"未获取"NOR"]";
		msg+=fmsg+":titles1 "+title+ZJSEP;
		}
		msg +="\n";
		write(msg);
		return 1;
	    }
		else
			if(arg && (ob == me))
		{
          if(me->is_busy())
          return notify_fail("你现在忙着呢，不能佩戴成就\n");
	      title = arg;
		  if (!ss[title])
			  return notify_fail("你没有这个成就\n");
		  msg=ZJOBLONG+TITLE_D->query_title(me,title);
		  msg = replace_string(msg,"\n",ZJBR)+"\n";
		  msg+=ZJOBACTS2+ZJMENUF(1,1,10,38);
		  msg+="佩戴成就:titles2 "+title+ZJSEP;
		  msg+="激活成就:titles1 buy=="+title;
		  //msg+="返回界面"":titles1";
		}
		msg += "\n";
		write(msg);
		return 1;
        }

	int reach_player(object me,string title)
	{
		
		if(me->query("titles/"+title))
			return 1;

		
		return 0;
		
		
    }
	
int help(object me)
{
write(@HELP
指令格式 : titles1 <title> | <玩家ID>

使用这条命令可以查看你的成就。

HELP );
    return 1;
}
