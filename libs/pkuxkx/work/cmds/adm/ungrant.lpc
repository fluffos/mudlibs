// ungrant command..
//by mudy
inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
	// moving
	tell_object(me,"你剥夺"+ob->query("name")+"在地图扩充系统中，开辟疆土的所有权力!\n");
	tell_object(ob,me->query("name")+"剥夺你在地图扩充系统中开辟疆土的所有权力!\n");
	ob->delete("canexpand_forever");
	ob->delete_temp("canexpand_temp");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : ungrant <某人>

此指令可让你(你)剥夺某人在地图扩充系统中开辟疆土的所有权力!
HELP
    );
    return 1;
}
