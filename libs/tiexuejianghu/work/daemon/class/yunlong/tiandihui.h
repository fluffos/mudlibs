// tiandihui.h for join tiandihui
#include <ansi.h>;

int do_join()
{
	object me, ob, obj ;
	string tang;

	me = this_object () ;
	ob = this_player () ;

	if ((int)ob->query("mingwang") < 200)
	{
message_vision(HIR"$N对$n道：想入会？你的江湖威望太低，天地会都是敢作敢为的好汉! \n"NOR,me,ob);
		return 1;
	}
	if ((int)ob->query("mingwang") < 0)
	{
	message_vision(HIR"$N对$n大怒道：还想入会？一看你就是个大汉奸! \n"NOR,me,ob);
		set_leader(ob);
		remove_call_out("kill_ob");
		me->kill_ob(ob); 
		return 1;
	}
	if(  ob->query("banghui") && ob->query("banghui") !="天地会")
	{
		message_vision("$N摇摇头，对$n说道：你已经加入其他帮会了，不能再入我天地会。\n",me,ob);
		return 1;
	}
	if( ob->query("banghui") =="天地会")
	{
		message_vision("$N摇摇头，对$n说道：你已经是我天地会的人了。\n",me,ob);
		return 1;
	}
	switch (random(10))
	{
		case 0 : tang=HIG"青木堂"; break;
		case 1 : tang=HIG"赤火堂"; break;  //古至中
		case 2 : tang=HIW"西金堂"; break;
		case 3 : tang=BLU"玄水堂"; break;
		case 4 : tang=YEL"黄土堂"; break;
		case 5 : tang=HIG"莲花堂"; break;  //蔡德忠
		case 6 : tang=HIG"洪顺堂"; break;  //方大洪
		case 7 : tang=HIW"家后堂"; break;  //马超兴
		case 8 : tang=BLU"参太堂"; break;
		default: tang=YEL"宏化堂"; break;  //李
	}
	
	command("smile");
	message_vision("$N对$n说道：你就暂时在"+tang+NOR+"效力吧！\n", me, ob);
	command("yaoqing "+ob->name());
	
	return 1;
}
