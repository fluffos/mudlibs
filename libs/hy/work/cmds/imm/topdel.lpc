// cmds/imm/topdel.c
// idea@yqyl 7.6.2000
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string type,player;
	
	seteuid(geteuid(me));
	
	if (!arg||sscanf(arg,"%s %s",type,player)!=2)
		return notify_fail("指令格式 : topdel <类型> <玩家ID>\n");
		
	if( ob = new("/clone/topten/magic-rice") )
		ob->del_one(player,type);
		else return notify_fail("topten的magic-rice出问题了\n");

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : topdel <类型> <玩家ID>

注意:<类型>请用 B1,B2,B3...
再讲它几句,因为只有当有人走来init()的时候,他才会更新榜上的内容,
所以topdel完,要再次走到topboard,让他init就是了,不然看到的可能是旧的,没变
HELP
    );
    return 1;
}