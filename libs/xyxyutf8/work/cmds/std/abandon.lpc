// abandon.c
#include <ansi.h>
inherit F_CLEAN_UP;

void do_abandon(string yn, object me, string arg,int lvl);
void do_abandon2(string yn, object me, string arg);

int main(object me, string arg)
{
	int lvl;
	mapping skills;
	if( !arg || arg=="" ) 
		return notify_fail("指令格式 abandon <技能名> [to <要保留的级别>]\n");
	if( sscanf(arg,"%s to %d",arg,lvl)!=2 )
		lvl = 0;	
	skills=me->query_skills();
	if( !skills || undefinedp(skills[arg]) )
		return notify_fail("你并没有学过这项技能。\n");
	if( lvl<0 )
		return notify_fail("想忘记「"+to_chinese(arg)+"」，直接用 abandon "+arg+" 命令。\n");
	if( SKILL_D(arg)->type()=="shentong" )
		return notify_fail("神通技能不能放弃。\n");
	if( skills[arg]<=lvl )
		return notify_fail("有这个必要吗？\n");
	if( SKILL_D(arg)->query_type()=="public" )
	{
		write(HIR"公共技能「"HIC+to_chinese(arg)+"("+arg+")"HIR"」放弃之后将再也不能学习，你确定(y/n)？"NOR);
	    	input_to("do_abandon2",me,arg);
	}		
	else if((int)skills[arg]>=10) 
	{
		write(HIY"你确定要放弃「"HIC+to_chinese(arg)+"("+arg+")"HIY"」至 "HIR+lvl+HIY" 级？(y/n)"NOR);
	    	input_to("do_abandon",me,arg,lvl);
	} 
	else	do_abandon("yes",me,arg,lvl);
	return 1;
}

void do_abandon(string yn, object me, string arg,int lvl)
{
	mapping skills,learned;
	if(!me || !living(me) ) 
		return;
	if(!yn) 
	{
		write("什么？\n");
		return;
     	}
	if(yn[0]=='y' || yn[0]=='Y' ) 
	{
		if(MISC_D->random_capture(me,8000,0)) 
			return;
		if( lvl==0 )
		{
			if( !me->delete_skill(arg) ) 
			{
				write("你没有学过这项技能。\n");
				return;
			}
			write("你决定放弃继续学习" + to_chinese(arg) + "。\n");
		}
		else	
		{
			skills=me->query_skills();
			skills[arg] = lvl;
			learned = me->query_learned();
			map_delete(learned,arg);
			write("你决定放弃" + to_chinese(arg) + " 到 "+lvl+" 级。\n");
		}
		return;
     } 
     else 
     {
	 write("你决定保留这项技能。\n");
	 return;
     }
}

void do_abandon2(string yn, object me, string arg)
{
	mapping skills,learned;
	if(!me || !living(me) ) 
		return;
	if(!yn) 
	{
		write("什么？\n");
		return;
     	}
	if(yn[0]=='y' || yn[0]=='Y' ) 
	{
		if( !me->delete_skill(arg) ) 
		{
			write("你没有学过这项技能。\n");
			return;
		}
		write("你决定放弃公共技能「"HIC + to_chinese(arg) + NOR"」。\n");
		me->set("public_skill/"+arg+"_abandon",1);
		write(HIR"你以后再也不能继续学习「"HIC+to_chinese(arg)+"("+arg+")"HIR"」了。\n"NOR);
		me->save(1);
		return;
     } 
     else 
     {
	 write("你决定保留这项技能。\n");
	 return;
     }
}

int help()
{
	write(@TEXT
指令格式：abandon|fangqi <技能名称>
	  abandon|fangqi <技能名称> [to <要保留的级别>]

这个指令使用的场合通常是用来删除或降低一些「不小心」练出来的技能，由於我们
假设你的人物随时都会从他／她的各种动作、战斗中学习，因此有些技能会因为你经
常地使用而出现在你的技能列表中，这个人物就必须花费一些精神去「记住」所学过
的一切，然而，人的资质各有不同，灵性高的人能够学习许多技能而成为多才多艺的
才子，灵性较差的人就只能专心於特定几项技能，如果你学的技能种类太多，超过你
的灵性，你会发现人物的学习速度将比只学几种技能的人慢，超过越多，学习效果低
落的情况越严重，这种情形就像是一个学期同时选修太多学分，虽然你仍然可以凭著
超人的意志力练下去，不过这将会多花费你许多宝贵的时间。

*注： 1、神通技能不能放弃
      2、这个命令会使你要放弃的技能的熟练度清零，同时要注意的是公共技能放弃
后，就再也不能学习同一公共技能了。公共技能查阅请参照 help public

TEXT
	);
	return 1;
}
