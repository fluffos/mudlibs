// updateall.c


int main(object me, string arg)
{
	string *strs,str;
 
	int i;

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;
	seteuid(geteuid(me));

	if(!arg)
	{
		strs = AFK_D->afk_list();
		str = ZJOBLONG"请选择挂机任务：\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		for(i=0;i<sizeof(strs);i++)
		{
			str += AFK_D->query(strs[i]+"/name")+":"+"afk "+strs[i];
			if(i<(sizeof(strs)-1)) str += ZJSEP;
		}
		str += ZJSEP"更新任务:afk -u";
		write(str+"\n");
		return 1;
	}

	if(arg == "-u")
	{
		AFK_D->load_afks();
		write("挂机任务数据更新完毕。\n");
		return 1;
	}

	if(!mapp(AFK_D->query(arg)))
		return notify_fail("系统中没有你要挂机的挂机任务！\n");

	me->delete("afk");
	me->set("afk/file",arg);
	me->set("afk/room",environment(me));
	write("开始准备挂机【"+AFK_D->query(arg+"/name")+"】....\n");
	return 1;
}