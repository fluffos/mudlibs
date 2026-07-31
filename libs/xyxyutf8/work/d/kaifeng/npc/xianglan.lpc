#include <ansi.h>
inherit NPC;
#include "colors.h"

int test_player();

void create()
{
  set_name("香兰", ({"xiang lan", "xiang", "lan"}));
  set("gender", "女性");
  set("age", 28);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 5500);
  set_skill("unarmed", 45);
  set_skill("dodge", 45);
  set_skill("parry", 45);
  set_skill("force", 45);
  set_skill("spells", 45);
  set_skill("baihua-zhang", 45);
  set_skill("moondance", 45);
  set_skill("moonshentong", 45);
  map_skill("spells", "moonshentong");
  map_skill("unarmed", "baihua-zhang");
  map_skill("force", "moonforce");
  map_skill("spells", "moonshentong");
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",200);
  set("max_mana",200);
  set("force_factor",20);
  set("inquiry", ([
        "here":   "此乃高姓兰亭府也，姑娘在此收集奇珍异宝。\n",
        "name":   "高家小姐香兰也。\n",
        "cloth":   (: test_player() :),
	    "异宝":   (: test_player() :),
        "募捐":   (: test_player() :),
        "捐":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/pinkskirt")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}

void rewarding (object who, object ob)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "不辞劳苦寻得"+COLOR_D->clean_color(ob->query("name"))+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+reason+"本姑娘感激不尽！\n",me,who);
  reward = quest_reward(who, "armor");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/cloth/times",1);
  if( who->query("quest/cloth/level")>=10 )
  	who->set("quest/cloth/level",1);
  else
  	who->add("quest/cloth/level",1);	
  who->add("quest/cloth/reward",reward);
  who->delete("quest/pending/cloth");
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
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "身上祥云环绕，请速赴长安进宫请赏！\n",me,who);
    return;
  }

 if( ! who->query("quest/pending/cloth"))
    return;

  ob = present (who->query("quest/pending/cloth/ture_id"),who);
 if( ! ob || ! ob->query("no_give"))
    return;

 if( who->query("quest/pending/cloth/ture_name") != COLOR_D->clean_color(ob->query("name")) )
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
  string msg,file, *strs = ({
    "$N对$n一笑：姑娘想起有人想要",
    "$N对$n咯咯地笑道：正好正好，姑娘募捐，听说有人打听能否寻得",
    "$N对$n说道：哦，对了，姑娘想帮人找一找什么",
    "$N对$n点头笑着说道：谢谢啦，姑娘想替人找",
    "$N微笑着对$n一点头说道：有人曾打听是否有",
  });
  int i;
  object ob,*temp,*obj,who,me = this_object();
  
  who = this_player();
  
  if( who->query("quest/reward") > 0)
    return err_msg(name()+"对你说道：这位"+RANK_D->query_respect(who)+"，本姑娘见你身上祥云环绕，何不去从速赴长安进宫请赏？\n");

  if( who->query("quest/pending/cloth"))
  {
  	message_vision(who->query("quest/pending/cloth/msg"),me,who);
  	return 1;
  }

  file = cloth_file[random(sizeof(cloth_file))];
  ob = new(file);	  
  obj_msg = query_obj_msg(ob,2);
  if( !obj_msg || !mapp(obj_msg) )
    return err_msg(name()+"叹了一口气，说道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，本姑娘看您还是以后再来吧。\n");  
  
  msg = strs[random(sizeof(strs))];
  msg+= "那个叫什么"+obj_msg["obj_name"]+"("+obj_msg["obj_id"]+")的，";
  msg+= "这位"+RANK_D->query_respect(who)+"能否替姑娘想个办法？\n";
  message_vision(msg,this_object(),who);
  
  who->set("quest/pending/cloth",([
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
  return 1;
}  

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

 if( who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+"，本姑娘见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 0;
  }

 if( ! who->query("quest/pending/cloth"))
  {
    message_vision ("$N对$n说道：本姑娘不需要这个。\n",me,who);
    return 0;
  }

 if( ob->is_character()) return 0;

 if( who->query("quest/pending/cloth/ture_name") != COLOR_D->clean_color(ob->query("name"))
  || who->query("quest/pending/cloth/ture_id") != ob->query("id")
  || who->query("quest/pending/cloth/file") != base_name(ob) )
  {
    message_vision (who->query("quest/pending/cloth/msg"),me,who);
    return 0;
  }
  t = who->query("quest/pending/cloth/time");

 if( t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n摇头道：这么快就回来了？本姑娘怕是有假。\n",me,who);
    message_vision ("$N又吩咐道：您再花个"+chinese_number((t-uptime())/60+1)+
                    "分钟去寻寻。\n",me,who);
      return 0;
  }
  rewarding (who, ob);
  return 1;
}