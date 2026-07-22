// cook.c, created by mes
// updated 9-5-97 pickle
#include <ansi.h>
inherit NPC;

void give_baozi(object cook, object me, string OBNAME, int reward);
int check_ratio(object me, object ob);
int check_base_reward(object baozi, int ratio);

void create()
{
	set_name("鼹鼠精", ({"yan shu", "yanshu", "monster", "chu zi", "cook"}));
	set("long",
"他几经修练，终于成了人形。但因他天生眼睛就不好，洞里没人\n"
"喜欢他。若不是因为他蒸得好包子，早被玉鼠赶出去了。\n");
	set("title", "厨子");
	set("gender", "男性");
	set("per", 10);
	set("age", 25);
	set("str", 70);
	set("attitude", "peaceful");
	set_level(39);
	set("inquiry", ([
        	"name": "什么名字！我自己都不记得了！",
        	"here": "这里是厨房，你看不出来？",
        	"rumors" : "唉，那白毛老鼠又去抓了个和尚，还是得我来蒸！真烦！",
        	"和尚": "找别人去问！",
        	"人肉包子": "你不给我活人，我怎么蒸？！",
        ]));
	setup();
	carry_object("/d/obj/cloth/linen")->wear();
}


void init()
{
	add_action("do_sell", "sell");
	add_action("do_sell", "mai");
    	if(wizardp(this_player()))
    	{
		add_action("do_tellme", "tellme");
		add_action("do_giveme", "giveme");
		add_action("do_manifest", "list");
    	}
}

int do_sell(string arg)
{
	object me=this_player(),ob;
  	int baoziexp, pot, sell_delay;
  	int myscore, ratio, base_reward, reward, pot_reward;
  	object cook=this_object(), baozi;
  	int no_pk;
  
  	if( !arg ) 
  		return 0;
  	if(me->is_busy()) 
  		return err_msg("你正忙着呢。\n");
  	if(is_busy()) 
  		return err_msg("对方正忙着呢。\n");
  	if(query_temp("processing"))
    		return err_msg(CYN"鼹鼠精怒道：没看我正忙着蒸包子呢嘛！？\n"NOR);
  	if( base_name(environment())!="/d/qujing/wudidong/kitchen" )
    		return err_msg(CYN"鼹鼠精摇头道：这里不是我的厨房，你就算把原料给了我我也没法做成包子。\n"NOR);
    	if( me->query("family/family_name") != "陷空山无底洞")
      		return err_msg(CYN"鼹鼠精仔细打量了你几眼，道：你是哪儿来的？我怎么不认得你？\n" NOR);
  	ob=present(arg, me);
  	if( !ob || !objectp(ob))
      		return err_msg("你没有这样 "+arg+"。\n");
  	if( !ob->is_character())
      		return err_msg(CYN "鼹鼠精摇了摇头，说道：这儿是厨房，不是废品回收站。\n" NOR);
  	if( me->query("family/sell_allowed")> time())
      		return err_msg(CYN"鼹鼠怒道：你怎么刚去就又来了！？肯定是路边捡的！我老远就闻到一股恶臭！\n"NOR);
  	if( ob->query("race") != "人类")
      		return err_msg(CYN"鼹鼠精骂道：浑帐！叫你去弄人肉来，这是人吗！？\n"NOR);
  	baoziexp = ob->query_level()*4500;
  	no_pk = me->query_condition("no_pk_time");
	if( userp(ob) && (baoziexp<100000 || no_pk>480) )
      		return err_msg(CYN "鼹鼠精摇了摇头，说道：这肉不新鲜，我不要。\n" NOR);
  	if( ob->query_temp("last_fainted_from") 
  	 && ob->query_temp("last_fainted_from")!=me->query("id"))
		return err_msg(CYN"鼹鼠精皱了皱眉，道：这是你哪里捡来的？怎么都臭了？\n");
  	message_vision("$N将晕倒了的$n交给厨子。\n", me, ob);
  	message_vision(CYN "$N笑眯眯地凑到$n身边，道：我一看就知道你肯定有货。\n"NOR, cook,me);
  	message_vision(CYN"$N：以后再有就赶紧送来，肯定不会亏了你的！\n"NOR, cook);
  	ratio=check_ratio(me, ob);
  	base_reward=check_base_reward(ob, ratio);
  	reward = base_reward * ratio/100+1;

	pot_reward = (10+random(10))*ratio/50 +random(2);

	set("pot_monitor/"+me->query("name")+"("+me->query("id")+")/"+time(),me->query("potential"));
  	if( userp(ob)) pot_reward*=2;

	pot=me->query("potential")-me->query("learned_points");

  	log_file("npc_kill","["+XYJTIME_D->chinese_time(time())+"] "+me->query("id")+" got "+pot_reward+" pots by selling "+base_name(ob)+".("+me->query_level()+" sell "+ob->query_level()+")\n");
  	
	if(pot+pot_reward<=200)
    		me->add("potential", pot_reward);
  	else if( pot<200) 
  		me->set("potential", 200+me->query("learned_points"));
  	me->set("family/last_sold", ob->query("id"));
  	me->add("family/sell_count", 1);
  	me->set("family/sell_time", time());

	sell_delay=random(reward*36/15);
  	if(sell_delay<60) 
  		sell_delay=60;
  	if( !wizardp(me) || !me->query("env/test"))
    		me->set("family/sell_allowed", time()+sell_delay);
  	ob->set("family/last_sold_by", me->query("id"));
  	ob->add("family/sold_count", 1);
  	me->add_temp("wudidong/received_renroubao", 1);
  	message_vision(CYN"$N对$n道：稍等一会，我马上就蒸。\n"NOR, cook, me);
  	call_out("give_baozi", 15+random(20), cook, me, ob->query("name"), reward);
  	set_temp("processing", 1);
  	if( userp(ob))
  	{
		me->apply_condition("no_pk_time",no_pk+240);
      		message_vision(CYN"$N高兴地说道：嘿，这个特新鲜，直接蒸了吧！\n"NOR, cook);
      		message_vision("$N将$n扔进了蒸笼。\n", cook,ob);
      		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("听说"HIW"%s"HIM"被"HIR"s"HIM"做成了人肉包子！"NOR,ob->name(1), me->name(1)));
      		ob->move("/d/qujing/wudidong/steamer");
      		message("vision", "只听「咚」的一声，"+ob->name()+"被扔了进来。\n",environment(ob), ob);
      		ob->set("startroom_old", ob->query("startroom"));
      		ob->set("startroom", environment(ob));
      		ob->save(1);
      		ob->revive();
  	}
  	else
  	{
      		message_vision("$N利索地将$n放在案板上，剁成了肉馅。\n",cook,ob);
      		message_vision("$N将肉馅裹上面粉，扔进了蒸笼。\n",cook);
      		destruct(ob);
  	}
  	return 1;
}

int check_ratio(object me, object ob)
{
    	int ratio;
    	int myexp, baoziexp;

	if( !me || !ob )
		return 0;
    	baoziexp=(ob->query_level()*4500+ob->query("daoxing"))/2;
    	myexp = me->query("daoxing");// myexp 是卖者的强度。
	if( myexp==0) myexp=1;
    	ratio = baoziexp*100/myexp;
    	if( ratio>150) 
    		ratio = 150;
    	else if( ratio < 100)
      		ratio = ratio * ratio / 100;
    	return ratio;
}

int check_base_reward(object baozi, int ratio)
{ 
    	int base_reward,baoziexp,adjust=ratio/10;

	if( !baozi )
		return 0;
	baoziexp = (baozi->query_level()*4500+baozi->query("daoxing"))/2;
    	if( baoziexp > 2000000)
		base_reward=1500; 
    	else if(baoziexp>1000000)
        	base_reward=1200;
    	else if(baoziexp>500000)
        	base_reward=800;
    	else if(baoziexp>100000)
        	base_reward=500;
    	else if(baoziexp>50000)
        	base_reward=350;
    	else if(baoziexp>10000)
        	base_reward=200;
    	else if(baoziexp>5000)
        	base_reward=100;
    	else if(baoziexp>1000)
        	base_reward=50;
    	else	base_reward=30;

    	if( userp(baozi)) 
    		base_reward *= 2;
	return base_reward;
}

void move_ob(object ob)
{
  	return;
}

void destroy(object ob)
{
  destruct(ob);
  return;
}
/************************************************************/

void give_baozi(object cook, object me, string OBNAME, int reward)
{
    	object baozi;

    	delete_temp("processing");
    	message_vision(CYN"$N揭开蒸笼的盖子闻了闻，眼睛一亮，道：熟了！\n"NOR, cook);
    	if(!me || me->is_yinshen() || !present(me, environment()))
    	{
		tell_room(environment(), CYN"鼹鼠精叹了口气，道：唉，这么香的包子，看来"+me->name()+"是没福享受了。\n"NOR);
		return;
    	}
    	baozi=new(__DIR__"obj/renroubao");
    	baozi->set("type", "有奖励");
    	baozi->set("reward", reward);
    	baozi->set("owner", me->query("id"));
    	baozi->set("long", "

一个香喷喷、热腾腾的人肉包子，据说肉馅是
"+OBNAME+"的肉做的，上面还沾着一些血丝。
其肉味道之鲜美，不由得让人垂涎欲滴。\n");
	if( baozi->move(me) )
		message_vision("$N递给$n一个热气腾腾的人肉包子。\n",this_object(),me);
	else
	{
		if( baozi ) destruct(baozi);
		tell_object(me,HIR"【系统】你的包裹满了。"NOR"\n");
	}
    	return;
}

int do_manifest(string arg)
{
	object me=this_player();
    	mapping list, ind_list;
    	mixed *tms;
    	int i, j,dd;

    	if(!wizardp(me)) 
    		return 0;
    	list=query("pot_monitor");
    	if( !list || !mapp(list) || sizeof(list)<1 )
    		return err_msg("没有记录\n");
    	i=sizeof(keys(list));
    	while(i--)
    	{
		tell_object(me, keys(list)[i]+"\n");
		ind_list=list[keys(list)[i]];
		tms = keys(ind_list);
		j = sizeof(tms);
		while(j--)
		{
			sscanf(tms[j],"%d",dd);
			tell_object(me,XYJTIME_D->chinese_time(ctime(dd))+"\t: "+ind_list[tms[j]]+"\n");
		}
    	}
    	return 1;
}

int do_tellme(string arg)
{
    	object me=this_player(), seller, baozi;
    	string butcher, meat, msg;
    	int ratio, baoziexp, sellerexp, base_reward, pot_reward, reward;

    	if( !wizardp(me)) 
    		return 0;
    	if( !arg) return err_msg("什么？\n");
    	sscanf(arg, "%s sell %s", butcher, meat);
	if( !meat) 
		return err_msg("必须提供被卖者的名字。\n");
    	if( !objectp(baozi=present(meat, environment(me))))
		baozi=find_player(meat);
    	if( !baozi) 
    		baozi=find_living(meat);
    	if( !baozi) 
    		return err_msg("目前游戏中找不到这位 "+meat+" 。\n");
    	if( !butcher) 
    		seller=this_player();
    	else 	
	{
		seller=find_player(butcher);
		if( !seller) 
			return err_msg("这位 "+butcher+" 现在不在游戏中。\n");    
    	}
    	ratio=check_ratio(seller, baozi);
    	base_reward=check_base_reward(baozi, ratio);
    	reward=ratio*base_reward/100;
    	msg=GRN+seller->query("name")+"（经验："+(seller->query_level()*4500+seller->query("daoxing"))+"），";
    	msg+="卖"+baozi->query("name")+"（经验："+(baozi->query_level()*4500+baozi->query("daoxing"))+"）。\n";
    	msg+="基本奖励为 "+base_reward+" 经验，二人强度比例为 "+ratio+"％\n";
    	msg+=seller->query("name")+"得 "+reward+" 经验。\n"NOR;
    	tell_object(me, msg);
    	return 1;
}

int do_giveme(string arg)
{
    	int exp;
    	object me=this_player(), dummy;

    	if( !arg || !sscanf(arg,"%d",exp)!=1 )
    		exp=2*me->query_level();
	dummy=new(__DIR__"dummy");
	dummy->set_level(exp);
	dummy->setup();
    	dummy->move(me);
    	tell_object(me, "你得到了一个测试大米。\n");
    	dummy->unconcious();
	dummy->set_temp("last_fainted_from", me->query("id"));
    	return 1;
}

int accept_fight(object who)
{
	::kill_ob(who);
	return 0;
}

void kill_ob(object who)
{
	all_inventory(environment())->remove_killer(this_object());
	this_object()->remove_all_killer();
	say(HIC+name()+HIC"冷冷的看着你。"NOR"\n");
}