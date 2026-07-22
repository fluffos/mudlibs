//jisuan.c
inherit F_CLEAN_UP;
object find_player(string target)
{
      int i;
	object *str;
	str=users();
	for (i=0;i<sizeof(str);i++)
		if (str[i]->query("id")==target)
			return str[i];
	return 0;
}
int main(object me, string str)
{
	object ob;
	string pos;
       int j,i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) ob=find_player(str);
	if (!ob) ob=find_living(str);
       if (!ob||(!me->visible(ob)&&me->query("id")!="pyter"))
                return notify_fail("咦... 有这个人吗?\n");
      j=ob->query("合成装备/成功次数",1);
      i=ob->query("合成装备/失败次数",1);
      tell_object(me, ob->query("name")+"合成装备成功次数"YEL+CHINESE_D->chinese_number(j)+NOR"次。\n"NOR); 
      tell_object(me, ob->query("name")+"合成装备失败次数"YEL+CHINESE_D->chinese_number(i)+NOR"次。\n"NOR); 
	return 1;
}
int help(object me)
{
write(@HELP
指令格式 : chaitem<某人>
此指令可让你查看某个玩家的装备合成记录。
HELP
    );
    return 1;
}
