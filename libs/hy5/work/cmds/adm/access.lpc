// 安全系统v0.1 Write By JackyBoy@CuteRabbit Studio for CCTX & SDXL
// 注意：
// 本程序必须在正确分配了权限的情况下才可以正确使用，一旦权限分配出错就会造成系统无法启动
// 此时，只有手动更改存储文件里的设置或者删除该文件才可以再次启动！
// 所以，必须只有可以登录主机的用户才可以使用该安全系统！！！
// 虽然本程序提供了最灵活的权限设置方法，但是建议要留一份原来的系统的安全设置
// 初写于：1999/7/14
// 7/15修改：将权限设置修改为可以一次设置多个有权者
// 例子：access add trusted_read kungfu/skill "(player)"

#undef SECURITY_D
#define SECURITY_D "/adm/daemons/securd"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string type,acc,op,user,*tmp;
	
	if( me!=this_player(1) ) return 0;
	if( wiz_level(me)<wiz_level("admin"))
		return notify_fail("你无权使用该命令！\n");
//	if(1)
//		return notify_fail("这个命令一般不开放！\n");

	if(!arg||arg=="print")
		arg="print all";
	if(arg=="wizlist")
	{
		write(implode(SECURITY_D->get_wizlist(),"\n")+"\n");
		return 1;
	}
	if(sscanf(arg,"set %s %s",user,acc)!=2)
	{
		if(sscanf(arg,"print %s",type)!=1)
		{
			if(sscanf(arg,"add %s %s",type,acc)!=2)
			{
				if(sscanf(arg,"del %s %s",type,acc)!=2)
					return notify_fail("命令错误！\n格式为：access print|wizlist|modify [类型] [存取设置]\n");
				else
					op="del";
			}
			else
				op="add";
			//还要从acc里分析出file和access_user
			if(sscanf(acc,"%s %s",acc,user)!=2)
				return notify_fail("存取控制表项输入错误！\n");
		}
		else
			op="print";
	}
	else
	{
		//设置巫师级别！注意这是无严格检查的，可以非在线提升巫师，所以千万不能提升错误！
		seteuid(geteuid());
		if( !(SECURITY_D->set_status(user, acc)) )
			return notify_fail("修改失败。\n");
		message_vision("$N将"+user+"的权限改为 " + acc + " 。\n", me);
		return 1;
	}
	if(op=="print")
		me->start_more(SECURITY_D->print_access_list(me,type));
	else
	{
		user=replace_string(user,"\"","");
		//应该将user修改为string*，这样可以一次输入多行！
		tmp=explode(user,",");
		write("分解得"+sizeof(tmp)+"项!\n");
		(SECURITY_D->modify_access_list(me,op,type,acc,tmp))?write("成功!\n"):write("失败!\n");
	}
	return 1;
}

#undef SECURITY_D
#define SECURITY_D "/adm/daemons/securityd"

int help()
{
write(@HELP

权限管理指令。

指令格式 : 
列出权限分配情况：access print [类型] 
列出游戏巫师表  ：access wizlist
设置或提升巫师  ：access set 用户ID 权限级别
设置权限分配表  ：access add 类型 文件 有权者
删除权限分配表项：access del 类型 文件 有权者
其中类型为trusted_read,trusted_write,exclude_read,exclude_write四个之一
有权者是一组该文件的级别或者精确的UID的数组，格式如下：
jackyboy或者(admin)或者"jackyboy"或者jackyboy,(admin)或者"(admin)","jackyboy"
它用逗号分隔每个有权者，至于引号可以忽略不计！对于直接授权给某人则使用该人的ID
否则是一个巫师级别名称，比如(admin)，注意，括号不能少！

HELP
    );
    return 1;
}
