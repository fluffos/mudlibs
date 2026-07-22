// by snowtu
#include <ansi.h>
inherit NPC;
#include "colors.h"

int test_player();

void create()
{
  set_name("相婆", ({"xiang po", "xiang", "po"}));
  set("gender", "女性");
  set("title", "御赐");
  set("age", 75);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 15000);
  set("daoxing", 50000);

  set_skill("unarmed", 10);
  set_skill("dodge", 25);
  set_skill("parry", 25);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",10);
  set("inquiry", ([
        "here":   "此乃御赐相府也，妾身在此专门收集盔甲。\n",
        "name":   "相良之妻也。\n",
        "armor":   (: test_player() :),
        "盔甲护具":   (: test_player() :),
        "盔甲":   (: test_player() :),
        "护具":   (: test_player() :),
        "收集":   (: test_player() :),
        "征集":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void rewarding (object who, object ob)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "不辞劳苦寻得"+COLOR_D->clean_color(ob->query("name"))+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+reason+"妾身感激不尽！\n",me,who);
  reward = quest_reward(who, "armor");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/armor/times",1);
  if( who->query("quest/armor/level")>=10 )
  	who->set("quest/armor/level",1);
  else
  	who->add("quest/armor/level",1);	
  who->add("quest/armor/reward",reward);
  who->delete("quest/pending/armor");
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

 if( ! who->query("quest/pending/armor"))
    return;

  ob = present (who->query("quest/pending/armor/ture_id"),who);
 if( ! ob || ! ob->query("no_give"))
    return;

 if( who->query("quest/pending/armor/ture_name") != COLOR_D->clean_color(ob->query("name")) )
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
    "$N想想对$n说道：今天妾身正准备请人去找",
    "$N细想了一下对$n说道：魏大人托话，说是京城有人想要什么",
    "$N对$n说道：听说长安有兵器护具坊需要",
    "$N对$n点头说道：相公刚说了，让妾身征集什么",
    "$N对$n一点头说道：这里尚缺些",
    "$N想想对$n说道：可否帮相府寻得",
  });  
  int i;
  object ob,*temp,*obj,who,me = this_object();
  
  who = this_player();
  
  if( who->query("quest/reward") > 0)
    return err_msg(name()+"对你说道：这位"+RANK_D->query_respect(who)+"，妾身见你身上祥云环绕，何不去从速赴长安进宫请赏？\n");

  if( who->query("quest/pending/armor"))
  {
  	message_vision(who->query("quest/pending/armor/msg"),me,who);
  	return 1;
  }

  file = armor_file[random(sizeof(armor_file))];
  ob = new(file);	  
  obj_msg = query_obj_msg(ob,2);
  if( !obj_msg || !mapp(obj_msg) )
  {
  	if( ob )  destruct(ob);
    return err_msg(name()+"叹了一口气，说道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，妾身看您还是以后再来吧。\n");  
  }
  msg = strs[random(sizeof(strs))];
  msg+= "好似称作「"+obj_msg["obj_name"]+"("+obj_msg["obj_id"]+")」的护具，";
  msg+= "这位"+RANK_D->query_respect(who)+"能否帮相府个忙？\n";	
  message_vision(msg,this_object(),who);
  
  who->set("quest/pending/armor",([
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
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，妾身见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 0;
  }

 if( ! who->query("quest/pending/armor"))
  {
    message_vision ("$N对$n说道：相府不需要这个。\n",me,who);
    return 0;
  }

 if( ob->is_character()) return 0;

 if( who->query("quest/pending/armor/ture_name") != COLOR_D->clean_color(ob->query("name"))
  || who->query("quest/pending/armor/ture_id") != ob->query("id")
  || who->query("quest/pending/armor/file") != base_name(ob) )
  {
    message_vision (who->query("quest/pending/armor/msg"),me,who);
    return 0;
  }
  t = who->query("quest/pending/armor/time");

 if( t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n摇头道：这么快就回来了？妾身怕是有假。\n",me,who);
    message_vision ("$N又吩咐道：您再花个"+chinese_number((t-uptime())/60+1)+
                    "分钟去寻寻。\n",me,who);
      return 0;
  }
  rewarding (who, ob);
  return 1;
}