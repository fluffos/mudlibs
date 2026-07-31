//Change by Server (5/25/2001)
// tell.c
//2002-10-10 changed by xkxmud for ★侠客梦★(@xkm)	添加自动回复功能

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);
void create(){seteuid(getuid());}
int main(object me,string arg)
{
	string target,msg,mud;
	object obj;
	if(!arg||sscanf(arg,"%s %s",target, msg)!=2)	return help(me);
	if(sscanf(target,"%s@%s",target,mud)==2)
	{
		GTELL->send_gtell(mud,target,me,msg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}
	obj=find_player(target);
	if(!obj||!me->visible(obj))	return notify_fail("没有这个人....。\n");
	if(!wizardp(me)&&obj->query_temp("pigging_seat"))
		return notify_fail("正在拱猪的人听不到悄悄话……。\n");
	if(!wizardp(me)&&wizardp(obj)&&obj->query("env/block")=="YES"&&obj->query("env/no_block")!=(string)me->query("id"))
		return notify_fail(obj->name()+"很忙，有什么事待会儿再说吧。\n");
	if(!wizardp(me)&&obj->query("env/block")==(string)me->query("id"))
		return notify_fail(obj->name()+"不想听你罗唆。\n");
	if(!wizardp(me)&&obj->query("env/block")=="ALL" && obj->query("env/no_block")!=(string)me->query("id"))     
		return notify_fail(obj->name()+"现在不想和人说话。\n");
	if(obj==me)	return notify_fail("自己说给自己听？\n");
	write(GRN"你告诉"+obj->name(1)+"："+msg+"\n"NOR);
	tell_object(obj,sprintf(GRN"%s告诉你：%s\n"NOR,me->name(1)+"("+me->query("id")+")",msg));
	if(obj->query("env/msg_reply")&&obj->query("env/reply")==1)
		write(HIG+obj->name(1)+HIG"给你的留言是:"+obj->query("env/msg_reply")+"。\n"NOR);
	else
	{
		if(interactive(obj)&&query_idle(obj)>120)
			write(HIW+"但是"+obj->name(1)+HIW"已经发呆"HIR+chinese_number(query_idle(obj)/60)+NOR
			HIW"分钟，看来你是得不到任何答复了！\n"+NOR);
	}
	obj->set_temp("reply",me->query("id"));
	return 1;
}
int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;
	if(ob=find_player(to))
	{
		if(wizardp(ob)&&ob->query("env/block")=="YES")	return 0;
		if(ob->query("env/block")=="ALL")
			return notify_fail(ob->name()+"现在不想和人说话。\n");
		if(cname)
			tell_object(ob,sprintf(HIG"%s(%s@%s)千里传音告诉你：%s\n"NOR,
				cname,capitalize(from),mud,msg));
		else
			tell_object(ob,sprintf(HIG"%s@%s告诉你：%s\n"NOR,
				capitalize(from),mud,msg));
		ob->set_temp("reply",from+"@"+mud);
		return 1;
	}
	else
		return 0;
}
int help(object me)
{
	write(@HELP
指令格式：tell <某人> <讯息>

你可以用这个指令和其他地方或其他站点的使用者说话。

可以使用 set msg_reply <留言内容> 来设定留言
当 set reply 1 时，如果别人 tell 你，就会自动将留言回复给他。

其他相关指令：reply, mudlist
HELP);
	return 1;
}