#include <ansi.h>
inherit F_CLEAN_UP;

void check_title(object me,object who)
{
	string *strs,str;
	int i;
	
	if( !me || !living(me) || !who )
		return;
	strs = who->query_titles();
	if( !strs || !arrayp(strs) || sizeof(strs)<1 )
	{
		write(sprintf("%s目前没有任何称号。\n",me==who?"你":who->name()));
		return;
	}
	str = sprintf(" %s目前拥有的称号有：\n",me==who?"你":who->name());
	for(i=0;i<sizeof(strs);i++)
	{
		if( strs[i]==who->query_temp_title() )
			str+= "\t"HIC"◆"NOR+TITLE_D->title_list(strs[i]);
		else	str+= "\t  "+TITLE_D->title_list(strs[i]);
	}
	write(str);
	return;	
}		

int check_legal_title(string addtitle, int titlelength)
{
       	int i;

	i = strlen(addtitle);

	if(titlelength<=0){
		write("对不起，目前你还不能给自己设头衔。\n");
    		return 0;
	}

	if(titlelength < strlen(addtitle)){
    		printf("对不起，目前你最多只能设%s个中文字作为头衔。\n", chinese_number(titlelength));
    		return 0;
	}

	while(i--) {
               	if( addtitle[i]<=' ' ) {
                       	write("对不起，你的头衔不能用控制字元。\n");
                       	return 0;
               	}
               	if( !is_chinese(addtitle) ) {
                       	write("对不起，请您用「中文」设头衔。\n");
                       	return 0;
               	}
       	}

	return 1;
}

int main(object me,string arg)
{
	object ob;
	string str;
	if( !arg || arg=="list" )
	{
		ob = me;
		check_title(me,ob);
		return 1;
	}
	else if( sscanf(arg,"-a %s",arg)==1 )
	{
		if( arg=="list" )
		{
			printf("你目前的头衔及门派：\n");
    			printf(BOLD "%s" NOR " %s\n\n", RANK_D->query_rank(me), me->short(1));
    			if(strlen(me->query("added_title"))>1)
		  		printf("其中头衔自设部份：%s\n", (string)me->query("added_title"));
    			return 1;
		}
		else if( arg=="none" ) 
		{
			me->delete("added_title");
			printf("好，删掉头衔自设部份。\n");
			return 1;
		}
		else
		{
			int tlen;
			if( me->query_level()<90 )
				tlen = 4;
			else if( me->query_level()<150 )
				tlen = 6;
			else	tlen = 8;
			if(check_legal_title(arg, tlen) == 0) 
				return 1;
			if( arg==me->query("added_title") )
				return notify_fail("和你目前设置的头衔没有区别。\n");		
			if( me->query("gin")<10 )
				return notify_fail("你的活力不够。\n");
			me->add("gin",-10);		
			me->set("added_title", arg);
			CHANNEL_D->do_channel(this_object(),"rumor","听说"+me->name()+HIM"自号为"HIG"「"+arg+HIG"」"HIM"。"NOR);
			return 1;	
		}
	}
	else if( arg=="all" )
	{
		str = TITLE_D->title_list();
		me->start_more(str);
		return 1;
	}
	else if( arg=="none")
	{
		str = me->query_temp_title();
		if( !str )
			return notify_fail("你目前并未激活任何称号。\n");
		if( me->query("eff_kee")<me->query_maxkee() )
			return notify_fail("你现在气血不够充沛，不能使用这个命令。\n");
		if( me->query("kee")<me->query("eff_kee")/10*9 )
			return notify_fail("你目前气血不满，不能使用这个命令。\n");
		if( me->query("eff_sen")<me->query_maxsen() )
			return notify_fail("你现在精神不够充沛，不能使用这个命令。\n");
		if( me->query("sen")<me->query("eff_sen")/10*9 )
			return notify_fail("你目前精神不满，不能使用这个命令。\n");
		if( me->is_fighting() || me->is_busy() )
			return notify_fail("你现在正忙着呢。\n");				
		if( !me->remove_title(str) )
			return notify_fail("好似有问题，请联系在值巫师。\n");
		write("你取消了你的称号，如果你想再次激发称号，请用 title <称号>命令。\n");
		me->start_busy(1);
		return 1;	
	}
	else if( !is_chinese(arg) )
	{	
		ob = find_player(arg);
		if( !ob )
			ob = present(arg,environment(me));
		if( !ob )
			return notify_fail("没有这个人。\n");
		if( !wizardp(me) )
			return notify_fail("你没有这个权限。\n");	
		check_title(me,ob);			
		return 1;
	}
	else
	{
		if( me->is_fighting() || me->is_busy() )
			return notify_fail("你现在正忙。\n");
		if( me->query("eff_kee")<me->query_maxkee() )
			return notify_fail("你现在气血不够充沛，不能使用这个命令。\n");
		if( me->query("kee")<me->query("eff_kee")/10*9 )
			return notify_fail("你目前气血不满，不能使用这个命令。\n");
		if( me->query("eff_sen")<me->query_maxsen() )
			return notify_fail("你现在精神不够充沛，不能使用这个命令。\n");
		if( me->query("sen")<me->query("eff_sen")/10*9 )
			return notify_fail("你目前精神不满，不能使用这个命令。\n");			
		if( me->set_title(arg) )
			write("ok\n");
		me->start_busy(1);	
		return 1;	
	}	
}

int help(object me)
{
	string msg = @LONG
指令格式 : title <称号>     设置自己的称号
	   title <id>	    查看某人的称号，当id不为自己时，仅限巫师使用。	
	   title list	    查看自己所拥有的所有称号
	   title all	    查看泥潭中的所有称号以及其附加属性
	   title none	    取消你目前激活的称号
	   title -a list    查看自己的系统头衔以及自设头衔
	   title -a none    取消自己的自设头衔
	   title -a <称号>  设定自己的自设头衔
在泥潭中，各称号通过解密、任务取得，一旦你获得了这个称号，你可以使用这个
命令来激发此称号的附加属性，如果你有更好的选择，你也可以通过此命令来变更
你的称号。当称号不被激活时，其对应的附加属性也将不被激活。
	   
LONG;		
	write(msg);	
    	return 1;
}

