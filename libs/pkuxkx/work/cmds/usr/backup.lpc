// backup.c
// by pal@pkuxkx

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string name;

	seteuid(getuid());
        if(time()-me->query("last_backup_time")<1800)
		return notify_fail("请不要过于频繁地备份。\n");
         if (me->query("combat_exp")<2000)
                return notify_fail("你的经验太少，不能备份。\n");
	name=me->query("id");
	cp(me->query_save_file() + ".o", "/data/backup/" + name[0..0] + "/" + name + ".o");
	write("档案备份成功。\n");
	me->set("last_backup_time",time());
        me->set("last_backup_mudage",me->query("mud_age")); 
	return 1;

}
int help(object me)
{
	write(@HELP
指令格式：backup

对你的档案进行备份，一小时只能备份一次。
由于服务器空间问题，只能做一个备份。
HELP
	);
	return 1;
}
