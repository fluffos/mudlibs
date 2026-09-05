#pragma save_binary
#include <dbase.h>
#include <login.h>
#include <ansi.h>
int time_period(int timep, object me);
string sysmsg;
/*int prevent_learn(object me, string skill)
{
	mapping	my_family, family;
        int	betrayer, mylvl, lvl;

	lvl = this_object()->query_skill(skill, 1);
	mylvl = me->query_skill(skill, 1);
        if( betrayer = me->query("betrayer") ) 
		{
            if( mylvl >= lvl - betrayer * 20 ) 
			{
				message_vision("$N神色间似乎对$n不是十分信任，\n也许是想起$p从前背叛师门的事情\n...。\n", this_object(), me );
				command("say 嗯 .... \n师父能教你的都教了，其他的你自己练吧。");
				return 1;
			}
		}       

        return 0;
}*/
int prevent_learn(object me, string skill)
{
	int betrayer;

	if (betrayer = me->query("betrayer" )) {
		if( ( betrayer>0 && me->query_skill(skill, 1) >= this_object()->query_skill(skill, 1) - betrayer * 20 ) ||
			    betrayer>20 ) {
			message_vision("$N神色间似乎对$n不是十分信任，也许是想起$p从前背叛师门的事情 ...。\n",
				this_object(), me );
			command("say 嗯 .... 师父能教你的都教了，其他的你自己练吧。");
			return 1;
		}
	}

	if( !me->is_apprentice_of(this_object())
	&&	(int)this_object()->query_skill(skill, 1) <= (int)me->query_skill(skill, 1) * 3 ) {
//		command("hmm");
//		command("pat " + me->query("id"));
		command("say 虽然你是我门下的弟子，可是并非我的嫡传弟子 ....");
		command("say 我只能教你这些粗浅的本门功夫，其他的还是去找你师父学吧。");
		return 1;
	}

	return 0;
}

int give_wsquest(string arg)
{
	mapping my_family, master_family, wsquest ;
	object me;
	int j, combatexp, timep, lvl=0;
        mixed *local;
        int  t;
	string tag = "1000000";
	string *levels = ({
    "1000",
    "2000",
    "4000",
    "8000",
    "12000",
    "20000",
    "30000",
    "50000",
    "80000",
    "120000",
    "180000",
    "250000",
    "400000",
    "600000",
    "900000",
    "1500000",
        "2500000",
        "50000000",
	});
	if( ! arg || !sscanf(arg, "%d", lvl))
	lvl = 0;
	if(lvl<0) lvl=0;
	me = this_player();
        if (me->query("combat_exp",1)<1100)
        {
           command("say 你的经验太低，做不了什么任务的！");
           return 1;
        }
/*        if (me->query("combat_exp")>35000000)
	{
           command("say 你的经验已经很高了，没有任务可做了！");
	   return 1;
	}*/
	if((int) me->is_ghost())
	{
		write("鬼魂不可要任务．\n");
		return 1;
	}

// Let's see if this player still carries an un-expired task
   
	if( !mapp(my_family = me->query("family")) ) 
		return 1;
	if( !mapp(master_family = this_object()->query("family")) ) 
		return 1;
	if (my_family["family_name"]!=master_family["family_name"])
	{
		command("say 你不是本派弟子，我怎么敢当呢？");
		return 1;	
	}	
	if((wsquest =  me->query("wsquest")))
	{
		if( ((int) me->query("task_time")) >  time() )
		{
			command("say 你的任务还没完成，还不快点去完成！");
			return 0;
		}
		else
		me->delete("wsquest_number");
	}
	combatexp = (int) me->query("combat_exp");
    for(j= sizeof(levels) - 1 ; j>=0; j--)
    {
		if( atoi(levels[j])  <= combatexp )
        {
			tag = levels[j];
//			if(j < (sizeof(levels)- lvl)) tag = levels[j+lvl];
            break;
		}
	}
//    if(!random(40) ) tag = "_new";
//	if(!random(10) ) tag = "_common";
	wsquest = BQUEST_D(tag)->query_quest();
//	to use less mem...
	timep = wsquest["time"];	
//	timep = 600;   // each quest give 10 mins.
// A factor here to make time random
	timep = random(timep/2)+timep/2;
	time_period(timep, me);
	if (wsquest["quest_type"] == "寻")
	{
        tell_object(me,"找回『"+wsquest["quest"]+HIW"』给我。\n" NOR);
		sysmsg +="找回『"+wsquest["quest"]+"』。";
	}
	if (wsquest["quest_type"] == "杀")
    {
		tell_object(me,"替我杀了『"+wsquest["quest"]+HIW"』。\n" NOR);
		sysmsg +="杀了『"+wsquest["quest"]+"』。";
    }
	if (wsquest["quest_type"] == "胜")
	{
		tell_object(me,"战胜『"+wsquest["quest"]+HIW"』。\n" NOR);
		sysmsg +="战胜『"+wsquest["quest"]+"』。";
	}
 	me->set("wsquest", wsquest);
	me->set("task_time", (int) time()+(int) timep);
	if((int)me->query("wsquest_number") < 30)
	me->add("wsquest_number",1);
//	CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)：%s", 
//	me->query("name"),me->query("id"),sysmsg));

return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n请在" + time + "内");
		sysmsg = "在" + time + "内";
        return 1;
}

int accept_object(object who, object ob)
{
	int bonus, exp, pot, score, val;
	string test;
	mapping my_family, master_family, wsquest;
	val = ob->value();
	if( !mapp(my_family = who->query("family")) ) 
		return 1;
	if( !mapp(master_family = this_object()->query("family")) ) 
		return 1;
	if (my_family["family_name"]!=master_family["family_name"])
	{
		command("say 你给我这个干什么？你又不是本门派的弟子。");
		return 0;	
	}
	
	if (val)
	{
		if( val < (33 - random((int)who->query("kar"))) * 500)
			tell_object(who,sprintf("%s",this_object()->name())+"在你耳边悄悄说道：这．．这太少了点儿吧．．\n");
		else{
			who->set("wsquest", 0 );
			who->set("wsquest_number",0);
			tell_object(who,sprintf("%s",this_object()->name())+"说道：好吧，这个任务就算了吧．．\n");
			}
		return 1;
	}
	if(!(wsquest =  who->query("wsquest"))){
		tell_object(who,sprintf("%s",this_object()->name())+"说道：这不是我想要的。\n");
		return 0;
		}
	if( (string)ob->query("name") != wsquest["quest"]){
		tell_object(who,sprintf("%s",this_object()->name())+"说道：这不是我想要的。\n");
		return 0;
		}
	if( ob->is_character()){
		tell_object(who,sprintf("%s",this_object()->name())+"说道：这不是我想要的。\n");
		return 0;
		}
	if ((int) who->query("task_time") < time() ){
		tell_object(who,sprintf("%s",this_object()->name())+"说道：真可惜！你没有在指定的时间内完成！\n");
		return 1;
		}
	else{
		tell_object(who,sprintf("%s",this_object()->name())+"说道：恭喜你！你又完成了一项任务！\n");
		exp = wsquest["exp_bonus"] + random(wsquest["exp_bonus"]);
		pot = wsquest["pot_bonus"] + random(wsquest["pot_bonus"]);
		if (who->query("wsquest_number")/4<5)
		{
			exp += exp*who->query("wsquest_number")/4;
			pot += pot*who->query("wsquest_number")/4;
		}
		else 
		{
			exp += exp*5;
			pot += pot*5;
		}
		score = 1;
		bonus = (int) who->query("combat_exp");
		bonus += exp;
		who->set("combat_exp", bonus);
		bonus = (int) who->query("potential");
		bonus = bonus - (int) who->query("learned_points");
		bonus +=pot;
//                if( bonus > 1000) bonus = 1000;
		bonus += (int) who->query("learned_points");
		who->set("potential", bonus );
		bonus = (int) who->query("score");
		bonus += score;
		who->set("score", bonus);
		tell_object(who,HIW"你被奖励了：\n" +
		chinese_number(exp) + "点实战经验\n"+
		chinese_number(pot) + "点潜能\n"NOR);
		who->set("wsquest", 0);
                   call_out("destroying", 1, ob);
		return 1;
		}
	return 1;
	}
void destroying(object obj)
{
   if(obj) destruct(obj);
}
