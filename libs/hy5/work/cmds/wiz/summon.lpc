// summon command..
//星星2000/4/9
inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
	object ob;
string wiz_status;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
	// moving
	tell_room(environment(ob),"天空中伸出一只大手把"+
	(string)ob->query("name")+"抓了起来, 然後不见了.\n", ob);
	tell_object(ob,"一只手把你抓了起来, 你眼前一阵黑....\n");
	ob->move(environment(me));
wiz_status = SECURITY_D->get_status(me);
	if( userp(me) && wizardp(me))
message("channel:chat", HIC"【玩家监督】"+me->name() + "SUMMON了" + 
                  ob->query("name")+HIC"!"NOR"。\n", users());
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
	tell_object(ob,".... 醒来时发现是"+(string)me->query("name")+
	"把你弄过来的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出现"+
	"在你眼前\n",({me,ob}));

//从此处开始是记录	
        log_file("cmds/summon",
		sprintf("%s(%s) summon %s(%s) on %s。\n",
		me->name(1), //记录使用命令的人名
		geteuid(me), //记录使用命令的ID
		ob->name(1),
		geteuid(ob),
		ctime(time()) ) ); //记录使用命令的时间
	// ok ..
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : summon <某人>

此指令可让你(你)将某人抓到你面前。
HELP
    );
    return 1;
}
