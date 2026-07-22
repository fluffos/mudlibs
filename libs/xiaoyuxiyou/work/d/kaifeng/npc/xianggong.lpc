// by snowtu
#include <ansi.h>
inherit NPC;
#include "colors.h"

int test_player();

void create()
{
    set_name("相公", ({"xiang gong", "xiang", "gong"}));
    set("gender", "男性");
    set("title", "御赐");
    set("age", 80);
    set("per", 25);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("combat_exp", 20000);
    set("daoxing", 100000);

    set_skill("unarmed", 20);
    set_skill("dodge", 20);
    set_skill("parry", 20);
    set("max_gin",400);
    set("max_kee",400);
    set("max_sen",400);
    set("max_force",100);
    set("max_mana",100);
    set("force_factor",10);
    set("inquiry", ([
        "here":   "此乃御赐相府也，老夫被御准在此收集武器。\n",
        "name":   "姓相名良也。\n",
        "weapon":   (: test_player() :),
        "武器":   (: test_player() :),
        "兵器":   (: test_player() :),
        "法宝":   (: test_player() :),
        "收集":   (: test_player() :),
        "征集":   (: test_player() :),
        "宝":   (: test_player() :),
      ]));
    setup();
    carry_object(0,"cloth",1)->wear();
}

void rewarding (object who, object ob)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "不辞劳苦寻得"+COLOR_D->clean_color(ob->query("name"))+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+reason+"老夫感激不尽！\n",me,who);
  reward = quest_reward(who, "weapon");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/weapon/times",1);
  if( who->query("quest/weapon/level")>=10 )
  	who->set("quest/weapon/level",1);
  else
  	who->add("quest/weapon/level",1);	
  who->add("quest/weapon/reward",reward);
  who->delete("quest/pending/weapon");
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

 if( ! who->query("quest/pending/weapon"))
    return;

  ob = present (who->query("quest/pending/weapon/ture_id"),who);
 if( ! ob || ! ob->query("no_give"))
    return;

 if( who->query("quest/pending/weapon/ture_name") != COLOR_D->clean_color(ob->query("name")) )
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
    "$N略有所思，然后对$n说道：老夫正想请人去找",
    "$N想了一下，对$n说道：老夫听说军务处想要",
    "$N对$n说道：军机大臣已托人传话，说是近来需要什么",
    "$N对$n说道：老夫即将遣人送兵器去京城，尚缺",
    "$N对$n一点头说道：老夫清点了一下兵器库，发现还少",
    "$N想想对$n说道：最近有些兵器来货不足，尤其是少了",
  });  
  int i;
  object ob,*temp,*obj,who,me = this_object();
  
  who = this_player();
  
  if( who->query("quest/reward") > 0)
    return err_msg(name()+"对你说道：这位"+RANK_D->query_respect(who)+"，老夫见你身上祥云环绕，何不去从速赴长安进宫请赏？\n");

  if( who->query("quest/pending/weapon"))
  {
  	message_vision(who->query("quest/pending/weapon/msg"),me,who);
  	return 1;
  }

  file = weapon_file[random(sizeof(weapon_file))];
  ob = new(file);	  
  obj_msg = query_obj_msg(ob,2);
  if( !obj_msg || !mapp(obj_msg) )
  {
  	if( ob )  destruct(ob);
    return err_msg(name()+"叹了一口气，说道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，老夫看您还是以后再来吧。\n");  
  }  
  
  msg = strs[random(sizeof(strs))];
  msg+= "好似称作「"+obj_msg["obj_name"]+"("+obj_msg["obj_id"]+")」的兵器，";
  msg+= "这位"+RANK_D->query_respect(who)+"能否帮相府个忙？\n";	
  message_vision(msg,this_object(),who);
  
  who->set("quest/pending/weapon",([
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
  if( ob )  destruct(ob);
  return 1;
}

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

 if( who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+"，老夫见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 0;
  }

 if( ! who->query("quest/pending/weapon"))
  {
    message_vision ("$N对$n说道：相府不需要这个。\n",me,who);
    return 0;
  }

 if( ob->is_character()) return 0;

 if( who->query("quest/pending/weapon/ture_name") != COLOR_D->clean_color(ob->query("name"))
  || who->query("quest/pending/weapon/ture_id") != ob->query("id")
  || who->query("quest/pending/weapon/file") != base_name(ob) )
  {
    message_vision (who->query("quest/pending/weapon/msg"),me,who);
    return 0;
  }
  t = who->query("quest/pending/weapon/time");

 if( t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n摇头道：这么快就回来了？老夫怕是有假。\n",me,who);
    message_vision ("$N又吩咐道：您再花个"+chinese_number((t-uptime())/60+1)+"分钟去寻寻。\n",me,who);
      return 0;
  }
  rewarding (who, ob);
  return 1;
}