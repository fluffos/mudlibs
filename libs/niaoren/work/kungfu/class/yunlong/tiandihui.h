// tiandihui.h for join tiandihui
#include <ansi.h>;

int do_join(string arg)
{
	object me, ob, obj ;
	string tang;
	mapping party;

	me = this_object () ;
	ob = this_player () ;

	if( !arg || arg!="tiandihui" )
		return notify_fail("你要加入什么組織？\n"); 

	if ((int)ob->query("weiwang") < 20)
	{
	command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(this_player()->query("weiwang")));
message_vision(HIR"$N對$n道：想入會？你的江湖威望太低，天地會都是敢作敢為的好漢! \n"NOR,me,ob);
		return 1;
	}
	if ((int)ob->query("shen") < 0)
	{
	message_vision(HIR"$N對$n大怒道：還想入會？一看你就是個大漢奸! \n"NOR,me,ob);
		set_leader(this_player());
		remove_call_out("kill_ob");
		me->kill_ob(ob); 
		return 1;
	}
	if(  ob->query("party") && ob->query("party/party_name") != HIR "天地會" NOR )
	{
		message_vision("$N搖搖頭，對$n說道：你已經加入其他幫會了，不能再入我天地會。\n",me,ob);
		return 1;
	}
	if( ob->query("party/party_name") == HIR "天地會" NOR )
	{
		message_vision("$N搖搖頭，對$n說道：你已經是我天地會的人了。\n",me,ob);
		return 1;
	}
	switch (random(10))
	{
		case 0 : tang=HIG"青木堂"; break;
		case 1 : tang=HIG"赤火堂"; break;  //古至中
		case 2 : tang=HIW"西金堂"; break;
		case 3 : tang=BLU"玄水堂"; break;
		case 4 : tang=YEL"黃土堂"; break;
		case 5 : tang=HIG"蓮花堂"; break;  //蔡德忠
		case 6 : tang=HIG"洪順堂"; break;  //方大洪
		case 7 : tang=HIW"家后堂"; break;  //馬超興
		case 8 : tang=BLU"參太堂"; break;
		default: tang=YEL"宏化堂"; break;  //李
	}
	party = allocate_mapping(5);
	party["party_name"] = HIR "天地會" NOR;
	party["rank"] = tang+NOR"會眾";
	party["level"] = 1;
	party["tasks"] = 0;
	party["enter_time"] = time();
	ob->set("party", party);

	command("smile");
	message_vision("$N對$n說道：你就暫時在"+tang+NOR+"效力吧！\n", me, ob);
	if(ob->query("weiwang")<50)
	{
		ob->set("weiwang",50);
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
		command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(this_player()->query("weiwang")));
		return 1;	
	}
	return 1;
}
