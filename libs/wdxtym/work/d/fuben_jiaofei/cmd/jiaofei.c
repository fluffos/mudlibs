int main(object me, string arg)
{
	string str;
	
	if (!environment(me)->query("is_fuben"))
	{
		tell_object(me,"该指令只能在副本中使用。\n");
		return 1;
	}
	
	if (!arg)
	{
		str = "你要执行什么功能\n" + ZJOBACTS2 + ZJMENUF(2,2,9,30);
		str += "使用追杀令:use zhuisha ling" + ZJSEP;
		str += "回到营地:jiaofei go_yingdi";
		tell_object(me, ZJOBLONG + str + "\n");
		return 1;
	}
	
	if (arg == "go_yingdi")
	{
		me->move((me->query_temp("fb_mem"))->query("yingdi"));
		tell_object(me, "你来到了营地。\n");
		return 1;
	}
	
	return 1;
}