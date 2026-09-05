#include <ansi.h>
#define LIMIT_LENGTH    108

inherit NPC;
int give_award();
int do_clear();
int ask_xunbao();
string replace_long(string longs);

void create()
{
set_name("曲清",({"qu qing","quqing","qu"}));
set("gender","男性");
set("age",59);
set("attitude", "friendly");
set("uni_target",1);
set("shen_type", 0);

set("str", 99);
set("con", 40);
set("int", 40);
set("dex", 40);

set("max_jing",21848);
set("jing",2184);
set("max_qi",7055);
set("qi",7055);
set("max_jingli",5778);
set("jingli",5778);
set("max_neili",7717);
set("neili",7717);
set("jiali",100);
set("combat_exp",36325062);

set_skill("literate",1152);
set_skill("medical-skill",700);
set_skill("staff",701);
set_skill("fanwen",523);
set_skill("force",701);
set_skill("parry",702);
set_skill("strike",703);
set_skill("finger",700);
set_skill("dodge",701);
set_skill("sword",700);
set_skill("blade",701);
set_skill("taoism",310);
set_skill("throwing",701);
set_skill("daoxue-xinfa",101);

set_skill("huntian-qigong",377);
set_skill("jiuyin-shengong",514);
set_skill("bihai-shengong",273);
set_skill("hero-jianfa",701);
set_skill("taiji-shengong",340);
set_skill("taiji-jian",621);
set_skill("taiji-dao",589);
set_skill("xiake-shengong",469);
set_skill("jiuyin-shengong",540);
set_skill("xianglong-zhang",700);
set_skill("dagou-bang",655);
set_skill("luoying-shenfa",613);
set_skill("xiake-jianfa",502);
set_skill("xiake-daofa",700);
set_skill("tanzhi-shengong",700);

map_skill("parry","xianglong-zhang");
map_skill("strike","xianglong-zhang");
map_skill("staff","dagou-bang");
map_skill("force","jiuyin-shengong");
map_skill("dodge","luoying-shenfa");
map_skill("finger","tanzhi-shengong");
map_skill("sword","xiake-jianfa");
map_skill("blade","xiake-daofa");

prepare_skill("strike","xianglong-zhang");


	set("inquiry", ([
        "挖宝" : (: ask_xunbao :),
        "寻宝" : (: ask_xunbao :),
        "job" : (: ask_xunbao :),
		    "清除" : (: do_clear :),
        "放弃" : (: do_clear :),
        "fail" : (: do_clear :),
        "cancel" : (: do_clear :),
        ]));
setup();
}

int ask_xunbao()
{
  object me=this_player();
  object jing;
  object where;
  string region,desc,file_name;
  string respect = RANK_D->query_respect(me);
  if(time() - me->query("xunbao/fail_time") < 180)
  {
    command("say "+respect+"离上次失败不到3分钟，还是先下去休息吧");
    return 1;
  }
  if(time() - me->query("xunbao/last_give_time") < 180)
  {
    command("say "+respect+"不是刚刚做了任务，下去先休息休息吧？");
    return 1;
  }
  if(me->query("combat_exp") >= 1000000)
  {
   command("kick "+me->query("id"));
   command("say 这么大了就别来寻宝了。");
   return 1;
  }
  me->set("xunbao/on_job", 1);
  me->set("xunbao/last_give_time", time()); 
//过滤非法任务地点和不明区域 by segate@pkuxkx
   while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd")
   {
     where = TASK_D->random_place();
   }

  region =TASK_D->place_belong(where);
  desc= where->query("long");
  desc=replace_long(desc);
  file_name=file_name(where);
  jing=new("/d/city/player/obj/jing");
  jing->set("owner",me->query("id"));
  jing->set("region",region);
  jing->set("desc",desc);
  jing->set("file_name",file_name);
  jing->move(me);
  message_vision(CYN+name()+"说道:拿好这个通天镜，你有半天的时间挖宝，半天后这个通天镜就会消失！\n"+NOR,me);
  message_vision(CYN+name()+"说道:你可以用detect命令来找宝在哪里，用dig命令来挖宝！\n"+NOR,me);
  return 1;
}

int do_clear()
{
	object me;
	me=this_player();
	if (!me->query("xunbao/on_job"))
		return notify_fail("一边玩去，没事别消遣我！\n");  
	me->delete("xunbao/on_job");
	me->set("xunbao/fail_time",time());
	message_vision(CYN+name()+"说道：唉，我错信你了，你先下去吧。\n"+NOR,me);
	message_vision(CYN+name()+"挥了挥手，示意你下去休息。\n"+NOR,me);
  return 1;
}

int accept_object(object who, object ob)
{            
		if (ob->query("id") == "bao wu" && ob->query("owner")==who->query("id"))
		{
      call_out("give_award",1);
      this_player()->start_busy(1);
      this_object()->start_bisy(1);
      this_player()->delete("xunbao/on_job");
      call_out("destroy",1,ob);
			return 1;
		}
		return 0;
}
int give_award()
{
	int i,exp,pot;
	string items;
	object award;
	object me;
	me=this_player();
	i=random(1000);
  exp=200+random(100);
  pot=20+random(80);
  tell_object(me,"你获得了"+chinese_number(exp)+"点经验！\n");
  tell_object(me,"你获得了"+chinese_number(pot)+"点潜能！\n");
  me->add("combat_exp",exp);
  me->add("potential",pot);
  me->add("exp/xunbao",exp);
  me->add("pot/xunbao",pot);	
  me->add("balance",1000+random(1000));
  tell_object(me,"你获得了一些金钱的奖励，请查看你的户头！\n");
  CHANNEL_D->do_channel(this_object(), "sys_misc", 
  sprintf("%s在挖宝任务中获得经验：%d、潜能：%d。", me->name(), exp, pot));			
  if(i>=996) 
	{
		items="/d/shaolin/npc/obj/puti-zi";
		award=new(items);
		award->move(me);
		tell_object(me,"你获得了特别奖励：菩提子。\n");
	  CHANNEL_D->do_channel(this_object(),
	  sprintf("%s在挖宝任务中获得了菩提子的奖励。\n",me->name()));
	}
	if (i==500 || i==1)
	{
		items="/d/city/npc/obj/zaizaowan";
		award=new(items);
		award->set("owner",this_player()->query("id"));
		award->move(me);
		tell_object(me,"恭喜你获得了特等奖:再造丸！！！\n");
	  CHANNEL_D->do_channel(this_object(),
	  sprintf("%s在挖宝任务中获得了菩提子的奖励。\n",me->name()));		
	}
	return 1;
}
void unconcious()
{
        die();
}

void die()
{
        message("vision","转眼间曲清又生龙活虎地站在你面前。\n",environment(this_object()));
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}

string replace_long(string longs)
{
        string tmp="", target="";
        int length, start, i;
        int blank_flag=0;
        if(strwidth(longs)<1) return "";     
        for(i=0;i<strwidth(longs);i++)
                if(longs[i]>160 && longs[i]<255)
                        tmp+=longs[i..i];
        length=strwidth(tmp);
        start=random(length-LIMIT_LENGTH);
        if(start%2)
                start--;
        for(i=start;i<start+LIMIT_LENGTH;i+=2)
        {
                if(blank_flag<-random(2)-2)
                {
                        target+="■";
                        length++;
                        if(random(2) || length>2)
                        {
                                blank_flag=0;
                                length=0;
                        }
                }
                else
                {
                        blank_flag--;
                        target+=tmp[i..i+1];
                }
        }
        return target;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
