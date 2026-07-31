#include <ansi.h>
inherit NPC;
#include "colors.h"

int test_player();

void create()
{
  set_name("胡敬德", ({"hu jingde", "hu", "jingde"}));
  set("long", "一位身披战袍，面容庄重严肃的御林都督。\n");
  set("title", "八十万御林都督");
  set("gender", "男性");
  set("age", 60);
  set("per", 35);
  set("attitude", "peaceful");
  set("class", "fighter");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("daoxing", 400000);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("force", 100);
  set_skill("spells", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",100);
  set("inquiry", ([
        "here":   "此乃禹王台也，水陆大会将不期举行，本都督在此预做法场，杀尽妖魔鬼怪！\n",
        "name":   "八十万御林都督胡敬德也，在此做法，以杀尽妖魔鬼怪！\n",
        "kill":   (: test_player() :),
        "妖魔":   (: test_player() :),
        "妖贼":   (: test_player() :),
        "鬼怪":   (: test_player() :),
        "牛鬼":   (: test_player() :),
        "蛇神":   (: test_player() :),
        "杀尽":   (: test_player() :),
        "杀":   (: test_player() :),
        "斩":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/zhanpao")->wear();
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "除妖灭怪，降服了"+who->query("quest/pending/kill/ture_name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+reason+"真是品行可嘉也。\n",me,who);
  reward = quest_reward(who, "kill");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  if( who->query("quest/kill/level")>=10 )
  	who->set("quest/kill/level",1);
  else
  	who->add("quest/kill/level",1);	  
  who->add("quest/kill/times",1);
  who->add("quest/kill/reward",reward);
  who->delete("quest/pending/kill");
  quest_done(who);
}

void check_player (object who)
{
  object me = this_object();
  int t;

  if (!who || !visible(who))
      return;

  if (! who || environment(who)!=environment(me))
    return;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+"身上祥云环绕，请速赴长安进宫请赏！\n",me,who);
    return;
  }

  if (! who->query("quest/pending/kill"))
    return;

  if (! who->query("quest/pending/kill/done"))
  {
    message_vision(who->query("quest/pending/kill/msg"),me,who);
    return;
  }

  t = who->query("quest/pending/kill/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n惊叹道：您已经回来了？不会这么快吧。\n",me,who);
    message_vision ("$N看了一眼香说道：这香还需"+chinese_number((t-uptime())/60+1)+"分钟才燃尽，到时您再来吧。\n",me,who);
    return 0;
  }
  rewarding (who);
}

void init ()
{
	if( userp(this_player()) )
		check_player(this_player());
}

int test_player()
{
  string ack,*strs = ({
    "$N迅速地一占卦，将惊堂木啪地一拍对$n说道：去将$w降服了！\n",
    "$N哼了一声对$n说道：老夫刚占了一卦，已知$w的阳寿已尽，去去，将之斩了！\n",
    "$N低头一看卦，对$n说道：$w罪该万死，您去一遭将此事了之。\n",
    "$N看完卦对$n说道：老夫正缺人去降服$w，您可否走一趟？\n",
    "$N怒发冲冠，对$n说道：$w为非作歹，您火速去将之了结掉！\n",
    "$N将卦一占，回头对$n说道：好，正是时候！您去将$w降服掉！\n",
    "$N占卦完毕对$n说道：去去，将$w杀掉！\n",
  });
  object ob,*temp,*obj,me = this_object();
  object who = this_player();
  mapping obj_msg;	
  string name,id,where,long;	
  string t_name,t_id,t_where,t_long,msg,file;	
  int i;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+"，老夫见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 1;
  }

  if( who->query("quest/pending/kill"))
  {
  	if( who->query("quest/pending/kill/done") )
  	{
  		rewarding (who);
  		return 1;
  	}
  	message_vision(who->query("quest/pending/kill/msg"),me,who);
  	return 1;
  }

  file = kill_file[random(sizeof(kill_file))];
  ob = new(file);
  if( !ob )
    return err_msg(name()+"叹气道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，老夫看您还是以后再来吧。\n");  
  
  obj_msg = query_obj_msg(ob,2);
  if( !obj_msg || !mapp(obj_msg) )
  {
  	if( ob )  destruct(ob);
    return err_msg(name()+"叹了一口气，说道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，老夫看您还是以后再来吧。\n");  
  }
  
  name = obj_msg["obj_name"]+"("+obj_msg["obj_id"]+")";
  msg = strs[random(sizeof(strs))];
  msg = replace_string (msg, "$w", name);
  message_vision(msg,this_object(),who);
  
  who->set("quest/pending/kill",([
  	"name" : obj_msg["obj_name"],
  	"id"   : obj_msg["obj_id"],
  	"ture_name" : obj_msg["ture_name"],
  	"ture_id"   : obj_msg["ture_id"],
  	"file" : base_name(ob),
  	"msg"  : msg,
  	"time" : time(), 
  ]));	 	        	   
  who->save();
  me->delete_temp("random_rel");
  if( ob ) destruct(ob);
  return 1;
}	
