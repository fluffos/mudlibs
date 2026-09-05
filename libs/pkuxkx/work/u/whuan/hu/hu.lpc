// huyidao.c
// by whuan@pkuxkx
#define MAX_WAIT_TIME 600
#include <ansi.h>;
inherit NPC;
int ask_job();
int ask_cancel();
int ask_times();
int ask_pfm();
int give_reward(object me);
string *quest_fail_msg = ({
    CYN"看了看你，然后又失望地摇了摇头，什么也不说。\n"NOR,
    CYN"看起来很是生气，但似乎又发作不出来，只是轻轻哼了一声。\n"NOR,
    CYN"惊奇地问：”什么，连这个都没做好？？！！！”\n"NOR,
    CYN"沮丧地望着你，并不说话，但明显很失望。\n"NOR,
    CYN"叹了口气：“本来对你期望甚高，怎知你却如此辜负于我的苦心...”\n"NOR,
    CYN"摇了摇头：“我本不应该让你去的......”\n"NOR,
    CYN"冷哼一声：“怎的你竟是如此不中用？！！”\n"NOR,
    CYN"拍拍你的肩膀：“不要灰心，我知道你尽力了...”\n"NOR,
    CYN"对着你摇了摇头，说：“连这点事都做不好.....下去吧。”\n"NOR,
    CYN"看上去很不高兴，皱了皱眉头对你说：“下去歇着吧。”，嘴\nNOR"
    CYN"里嘟囔着：“真是没用。。。。”\n"NOR,
    CYN"疑惑地看着你：“怎么回事？怎么你。。。”\n"NOR,
    CYN"失望地看看你，慢慢地转过头去，跟别人说话去了。\n"NOR,
    CYN"嚷道：真是个饭桶！\n"NOR,
    CYN"一晃脑袋，叹息道：也罢，也罢，我本不该让你做这件事的。\n"NOR,
});

void create()
{
	set_name("胡一刀", ({"hu yidao", "yidao", "hu"}));
	set("gender", "男性");
	set("title", HIR"辽东"HIY"大侠"NOR);
	set("age", 35);
	set("long","这人生得当真凶恶，一张黑漆脸皮，满腮浓髯，头发却又不结辫子，蓬蓬松松的堆在头上。\n他生平只要遇到做坏事的，立时一刀杀了，所以名字叫作胡一刀。\n");
	set("attitude", "peaceful");
  set("no_get", "1");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 17);
	set("qi", 3000);
	set("max_qi", 30000);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 1000);
	set("combat_exp", 19000000);
	set("score", 200000);
	 
	set_skill("force", 500);             // 基本内功
	set_skill("hujia-daofa", 550);       // 胡家刀法	
	set_skill("blade", 520);             // 基本刀法
	set_skill("hunyuan-yiqi", 520);      // 混元一气功
	set_skill("dodge", 520);             // 基本躲闪
	set_skill("shaolin-shenfa", 520);    // 胡家身法
	set_skill("parry", 520);             // 基本招架
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
	set("inquiry",([
		"job":     (: ask_job :),
		"盗宝人":  (: ask_job :),
		"取消":    (: ask_cancel :),
		"cancel":  (: ask_cancel :),
		"次数":    (: ask_times :),
		"times":   (: ask_times :),
		"绝招" :   (: ask_pfm :),
	   ]));
	setup();
  carry_object("/d/city/npc/obj/gangdao")->wield();
  carry_object("/d/city/obj/cloth")->wear();
}

int ask_job()
{
	object me=this_player();
	object ob=this_object();
	object killer; //杀手
	object where; //出现的地点
	if(!userp(me))
        return 0;
  if( (int)me->query("yidao/last_asked") + MAX_WAIT_TIME >= time() )
    {
    message_vision("$N说道：你刚刚不是要过任务么，你先下去休息吧!\n",ob);
    return 1;
    }
  if ( me->query("yidao/on_job")==1)
  	{
    message_vision("$N皱眉道：上次的任务你还没有完成任务呢!\n",ob);
    return 1;
    }
  if ( me->query("combat_exp")<=3000000)
  	{
    message_vision("$N笑道：这件事可没你想的那么简单，你好好练功吧!\n",ob);
    return 1;
    }
   me->set("yidao/last_asked",time());
   me->set("yidao/on_job",1);
   killer=new(__DIR__"killer1");
   killer->do_copy(me);
   where = TASK_D->random_place();
   killer->move(where);
   killer->random_move();
   killer->random_move();
   killer->random_move();
   message_vision("$N说道：“我收到消息，听说"+TASK_D->place_belong(where)+"有盗宝人找到了闯王宝藏的地图,$n可否帮忙找回来！”\n",ob,me);
   command("care");
   return 1;   
}

int ask_cancel()
{
	object me=this_player();
	object ob=this_object();
  if ( me->query("yidao/on_job")==0)
  	{
    message_vision("$N皱眉道：你又没有要任务，取消什么？\n",ob);
    return 1;
    }
  if( (int)me->query("yidao/last_asked") + 300 >= time() )
    {
    message_vision("$N说道：你再去找找看啊，不要轻言放弃！\n",ob);
    return 1;
    }
   tell_object(me,ob->query("name")+quest_fail_msg[random(sizeof(quest_fail_msg))]);
   command("disapp1");
   me->delete("yidao/ob_job");
   me->add("combat_exp",-5000);
   me->add("potential",-1000);
   me->delete("yidao/on_job");
   return 1; 
}

int ask_times()
{
	command("say 到目前为止，你共完成了"+this_player()->query("yidao/times")+"次任务！");
	return 1;
}

int accept_object(object who, object ob)
{
	if(ob->query("id")=="cangbao tu" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",8);
			give_reward(who);
			return 1;
		}
	if(ob->query("id")=="map piece1" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
			return 1;
		}
	if(ob->query("id")=="map piece2" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
			return 1;
		}
	if(ob->query("id")=="map piece3" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
			return 1;
		}
	if(ob->query("id")=="map piece4" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
			return 1;
		}
	if(ob->query("id")=="map piece5" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
			return 1;
		}
		return 0;					
}

int give_reward(object me)
{
	int reward,preward;//exp奖励
	int sk,lvl;//胡家刀法的等级,奖励的等级（碎片1，地图8）
	sk=me->query_skill("hujia-daofa",1);
	lvl=me->query_temp("yidao/lvl");
	reward  = (int)me->query_skill("force",1);
	reward += (int)me->query_skill("dodge",1);
	reward += (int)me->query_skill("parry",1);
	reward += pow(me->query("combat_exp")/100.0,1.0/3)*10;
	reward = 1000*lvl + reward + random(reward);
	preward = reward/2+random(reward)/2;
	me->add("combat_exp",reward);
	me->add("exp/yidao",reward);
	me->add("potential",preward);
	me->add("pot/yidao",preward);
	me->add("repute",150*lvl);
	if (lvl==8)
		{
			me->set_skill("hujia-daofa",sk+1);
			command("say "+RANK_D->query_respect(me)+"如此辛苦帮我寻回藏宝图，我就将我祖传的胡家刀法传授一二！\n");
			me->add("yidao/times",1);
		}
	command("thank "+me->query("id"));
	me->delete_temp("yidao/lvl");
	tell_object(me,HIY"你的经验提高了，你的潜能提高了，你的江湖声望提高了！\n"NOR);
	return 1;
}
int ask_pfm()
{
	if (this_player()->query_skill("hujia-daofa",1)<250)
		{
			tell_object(this_player(),HIY"胡一刀给你讲了讲【刀影连环】的诀窍，不过你听了半天也不明白他在说什么。\n"NOR);
			return 1;
		}
	this_player()->set("daoying",1);
	tell_object(this_player(),HIY"胡一刀给你讲了讲【刀影连环】的诀窍。\n"NOR);
	return 1;
}
