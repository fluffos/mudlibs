#include <ansi.h>
inherit NPC;
#include "colors.h"

int test_player();

void create()
{
  set_name("猪八戒", ({ "zhu bajie", "zhu", "bajie" }));
  set("age", 600);
  set("gender", "男性");
  set("long", "嘿嘿，连老猪都不认识啦？\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("daoxing", 2000000);

  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 1500);
  set("force", 1500);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 90);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("rake", 150);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("baguazhou", 80);
  set_skill("yanxing-steps", 70);
  set_skill("skyriver-rake", 180);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  set("inquiry", ([
        "here":   "此乃天蓬帅府也，老猪西天归来后唐太宗御赐在此开府，专事饮食慈善业。\n",
        "name":   "猪八戒，谁人不知也。\n",
        "food":   (: test_player() :),
        "美食":   (: test_player() :),
        "美酒":   (: test_player() :),
        "美宴":   (: test_player() :),
        "佳肴":   (: test_player() :),
        "食物":   (: test_player() :),
        "饮水":   (: test_player() :),
        "吃":   (: test_player() :),
        "喝":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

void rewarding (object who, object ob)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "为唐人美宴寻得"+ob->query("name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+reason+"真是为大唐天下民众造福哇！\n",me,who);
  reward = quest_reward(who, "food");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/food/times",1);
  if( who->query("quest/food/level")>=10 )
  	who->set("quest/food/level",1);
  else
  	who->add("quest/food/level",1);	
  who->add("quest/food/reward",reward);
  who->delete("quest/pending/food");
  quest_done(who);
}

void check_player (object who)
{
  object me = this_object();
  object ob;

 if( !who || !visible(who))
      return;

 if( ! who || environment(who)!=environment(me))
    return;

 if( who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+"身上祥云环绕，请速赴长安进宫请赏！\n",me,who);
    return;
  }

 if( ! who->query("quest/pending/food"))
    return;

  ob = present (who->query("quest/pending/food/ture_id"),who);
 if( ! ob || ! ob->query("no_give"))
    return;

 if( who->query("quest/pending/food/ture_name") != COLOR_D->clean_color(ob->query("name")) )
    return;

  message_vision ("$N见$n手上拿着"+COLOR_D->clean_color(ob->query("name"))+"，急忙双手接过去。\n",me,who);
  rewarding (who, ob);
}

void init ()
{
	if( userp(this_player()) )
		check_player(this_player());
}

int test_player()
{
  mapping obj_msg;	
  string name,id,where,long;	
  string t_name,t_id,t_where,t_long;	
  string msg,file,*strs = ({
    "$N略有所思地点点头对$n说道：俺老猪想给大唐人凑个美宴，正缺",
    "$N对$n说道：老猪我四处寻求天下美味佳肴，正要找",
    "$N对$n说道：对了乡下发大水灾，有几个灾民想要什么",
    "$N对$n说道：京城客到，在开封府上，其中有一官人让老猪我代寻什么",
    "$N对$n点头说道：水陆大会即将开宴请各路法师到会，听说有法师想要什么",
    "$N对$n一点头说道：俺老猪救济饥民，听说正需要",
    "$N想想说：有人倒是想让俺老猪给找个什么什么",
  });
  int i;
  object ob,*temp,*obj,who,me = this_object();
  
  who = this_player();
  
  if( who->query("quest/reward") > 0)
    return err_msg(name()+"对你说道：这位"+RANK_D->query_respect(who)+"，俺见你身上祥云环绕，何不去从速赴长安进宫请赏？\n");

  if( who->query("quest/pending/food"))
  {
  	message_vision(who->query("quest/pending/food/msg"),me,who);
  	return 1;
  }

  file = food_file[random(sizeof(food_file))];
  ob = new(file);	  
  obj_msg = query_obj_msg(ob,2);
  if( !obj_msg || !mapp(obj_msg) )
  {
  	if( ob )  destruct(ob);
    return err_msg(name()+"叹了一口气，说道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，俺看您还是以后再来吧。\n");  
  }
  msg = strs[random(sizeof(strs))];
  msg+= "什么劳什子「"+obj_msg["obj_name"]+"("+obj_msg["obj_id"]+")」，";
  msg+= "这位"+RANK_D->query_respect(who)+"可否赏老猪个大脸设法子去给弄来？\n";	
  message_vision(msg,this_object(),who);
  
  who->set("quest/pending/food",([
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

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

 if( who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+"，俺见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 0;
  }

 if( ! who->query("quest/pending/food"))
  {
    message_vision ("$N对$n说道：老猪不需要这个。\n",me,who);
    return 0;
  }

 if( ob->is_character()) return 0;

 if( who->query("quest/pending/food/ture_name") != COLOR_D->clean_color(ob->query("name"))
  || who->query("quest/pending/food/ture_id") != ob->query("id")
  || who->query("quest/pending/food/file") != base_name(ob) )
  {
    message_vision (who->query("quest/pending/food/msg"),me,who);
    return 0;
  }
  t = who->query("quest/pending/food/time");

 if( t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n摇头道：这么快就回来了？俺怕是有假。\n",me,who);
    message_vision ("$N又吩咐道：您再花个"+chinese_number((t-uptime())/60+1)+"分钟去寻寻。\n",me,who);
      return 0;
  }
  rewarding (who, ob);
  return 1;
}