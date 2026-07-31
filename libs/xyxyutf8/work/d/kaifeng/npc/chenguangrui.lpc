// by snowcat 
#include <ansi.h>
inherit NPC;
#include "colors.h"

string *Asks = ({
"送经书","取经之道","诗歌","佛道","算卦术",
"讲授医术","讲拳法","法术","讲玄道","呼风唤雨",
"歌艺舞艺", "国子监","讲授龟艺","斗鸡术","太乙仙法",
"生财之道","烹调术","移行换位术","比武","黄梁一梦",
"砍树","姻缘术", "大乘佛法","修禅","待客之方","军机",
"采贝术","潜海术","降雨", "西域","舞技","水陆大会",
"参加水陆大会","下山比武","传授口技","派使来访",
"讲授宫政","宫中舞艺","来访水陆大会","订购家什",
"讲授锡艺","家政","园艺","传授酿酒术","来大唐说书",
"来大唐唱戏","来大唐教外语", "交流武艺","交流武艺", 
"恭请光临","邀请下凡","讲授西域律法","清理道场",
"做道场","传授道教","传授佛教", "宣传佛教","宣传道教",
"宫亭内政", "西域国政","官僚术","插花艺","烹饪术",
"金银匠艺", "西域语","金银匠艺", "医术","西域商事",
"烹饪术","祭祀术","传授武功","起风","布云","打雷",
"闪电","邀请观礼水陆大会","邀请观礼","花艺","西域药理",
"西域服饰","来唐唱歌","种植园艺","西域服装","商务","马术",
"佛学","捕鱼术","烹鱼技艺","互访","捐助水陆大会","募捐",
"主持道场", "祭祀术","西域民法","避火法","火焰山",
"锻铁术","茶道","鹤发","奈何桥","可怜人","生死","诗歌",
"讲习成精法术","讲习","拳法","访问大唐国","治水术",
"得道秘法", "避妖术","妖魔大会","朝闻道夕死可矣",
});

string *strs = ({
    "$N燃起一根香祭祀一番，对$n说道：祖灵在天，请您去拜见$w并询问有关$o一事。\n",
    "$N将手中香点燃对$n说道：老夫祭毕祖宗，得知有$w知道$o之事，您可否去请见？\n",
    "$N拈香向祖宗一拜，转身对$n说道：可否去拜见$w，并告知$o一事？\n",
    "$N将香点燃，对$n说道：在天祖灵让您就$o一事拜访$w，请尽早动身也。\n",
    "$N对$n说道：老夫拜了祖宗，正缺人去拜访$w，告知$o之事。\n",
    "$N燃香完毕，回头对$n说道：不知可否去拜见$w，探问$o一事。\n",
    "$N在香火中缓缓向祖宗一拜，再对$n说道：祖灵在天请您去拜见$w并告知$o之事。\n",
  });  

// mon 3/22/99
string get_message()
{
    string str;
    string *msg1=({"$N燃起一根香祭祀一番，对$n说道：祖灵在天，请您去"});
    string *msg2=({"拜见","朝问","问候","拜访","求见","看望","访问","致意",
	    "问候一下","拜访一次","拜见一次","问候一回","看望一下","求见一次",
	    "访问一次","访问一回","拜访一回","致意一次","拜访一下","看望一下",
	    "拜见拜见","问候问候","拜访拜访","看望看望"});
    string *msg3=({"，顺路","，并","，并且","，一定","，尽力",
	    "并","并且",});
    string *msg4=({"探听","索问","请问","打听","探问","查询","探知","寻查",
	           "探访","调查","查知","探访","调查","过问","打探","查明",
	    "探访探访","寻查寻查","打探打探","务必探明","一定探知","调查调查",
	    "探听有关","打探有关","打听有关","查询有关","探知有关","探问有关",
            "探听关于","打探关于","打听关于","查询关于","探知关于","探问关于",
	    "查问有关","查问关于","调查有关","调查关于","请问有关","请问关于",
	    "探听探听","打听打听","探问探问","查明有关","过问有关"});
    string *msg5=({"一事","之事","的消息","的情况","的问题",});
    string *msg6=({"！","。","。。。",});
    
    if(random(10)<2)
      str = strs[random(sizeof(strs))];
    else {
	str=msg1[random(sizeof(msg1))]+
	    msg2[random(sizeof(msg2))]+"$w"+
	    msg3[random(sizeof(msg3))]+
	    msg4[random(sizeof(msg4))]+"$o"+
	    msg5[random(sizeof(msg5))]+
	    msg6[random(sizeof(msg6))]+"\n";
    }
    return str;
}

void show_message(object who)
{
    string str;

    if(!who) return;
    if (! who->query("quest/pending/ask"))
	return;
    str=who->query("quest/pending/ask/message");
    if(!str) 
      message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫不是请您去见"+who->query("quest/pending/ask/name")+
                    "询问"+who->query("quest/pending/ask/topic")+"一事吗？\n",
		    this_object(),who);
    else
      message_vision(str,this_object(),who);
}

int test_player();

void create()
{
  set_name("陈光蕊", ({"chen guangrui", "chen", "guangrui"}));
  set("long", "陈光蕊乃玄奘之父，当朝大阐都纲御赐状元。\n");
  set("title", "大阐都纲");
  set("gender", "男性");
  set("age", 50);
  set("per", 35);
  set("attitude", "peaceful");
  set("class", "scholar");
  set("shen_type", 1);
  set("combat_exp", 40000);
  set("daoxing", 100000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("literate", 180);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",400);
  set("max_mana",400);
  set("force_factor",20);
  set("inquiry", ([
        "here":   "此乃禹王台也，水陆大会将不期举行，本状元在此预做法场以祭祖求贤。\n",
        "name":   "玄奘之父陈光蕊也，在此做法祭祖求贤。\n",
        "ask":   (: test_player() :),
        "祭祖":   (: test_player() :),
        "求贤":   (: test_player() :),
        "招贤":   (: test_player() :),
        "贤人":   (: test_player() :),
        "贤士":   (: test_player() :),
        "善哉":   (: test_player() :),
        "招":   (: test_player() :),
        "求":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/changpao")->wear();
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "祭祖拜贤，就"+who->query("quest/pending/ask/topic")+"一事拜见了"+who->query("quest/pending/ask/ture_name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+reason+"真是品行可嘉也。\n",me,who);
  reward = quest_reward(who, "ask");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/ask/times",1);
  if( who->query("quest/ask/level")>=10 )
  	who->set("quest/ask/level",1);
  else
  	who->add("quest/ask/level",1);	
  who->add("quest/ask/reward",reward);
  who->delete("quest/pending/ask");
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

  if (! who->query("quest/pending/ask"))
    return;

  if (! who->query("quest/pending/ask/done"))
  {
    message_vision(who->query("quest/pending/ask/msg"),me,who);
    return;
  }

  t = who->query("quest/pending/ask/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n惊叹道：您已经回来了？不会这么快吧。\n",me,who);
    message_vision ("$N看了一眼香说道：这香还需"+chinese_number((t-uptime())/60+1)+
                    "分钟才燃尽，到时您再来吧。\n",me,who);
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
  string ack,*acks = ({
    "知道了。\n",
    "我这就会动身，您请先回吧。\n",
    "好的。\n",
    "多谢来访，我这就去办。\n",
    "好，我马上就去准备。\n",
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

  if( who->query("quest/pending/ask"))
  {
  	if( who->query("quest/pending/ask/done") )
  	{
  		rewarding (who);
  		return 1;
  	}
  	message_vision(who->query("quest/pending/ask/msg"),me,who);
  	return 1;
  }

  file = npc_file[random(sizeof(npc_file))];
  obj = children(file);
  if( !obj || !arrayp(obj) )
    return err_msg(name()+"对你叹气说道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，老夫看您还是以后再来吧。\n");
  temp = ({});
  for(i=0;i<sizeof(obj);i++)
  {
  	if( !environment(obj[i])
  	 || environment(obj[i])->is_character() )
      continue;
    temp+= ({obj[i]});
  }
  if( sizeof(temp)<1 )
    return err_msg(name()+"对你叹气说道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，老夫看您还是以后再来吧。\n");
  
  ob = temp[random(sizeof(temp))];
  if( !ob )
    return err_msg(name()+"叹气道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，老夫看您还是以后再来吧。\n");  
  
  obj_msg = query_obj_msg(ob,1);
  if( !obj_msg || !mapp(obj_msg) )
    return err_msg(name()+"叹了一口气，说道：这位"+RANK_D->query_respect(who)+"该做的事做了不少，老夫看您还是以后再来吧。\n");  
  
  msg = get_message();
  ack = Asks[random(sizeof(Asks))];
  name = obj_msg["who_name"]+"的"+obj_msg["obj_name"]+"("+obj_msg["obj_id"]+")";
  msg = replace_string (msg, "$w", name);
  msg = replace_string (msg, "$o", ack);
  message_vision(msg,this_object(),who);
  
  who->set("quest/pending/ask",([
  	"name" : obj_msg["obj_name"],
  	"id"   : obj_msg["obj_id"],
  	"ture_name" : obj_msg["ture_name"],
  	"ture_id"   : obj_msg["ture_id"],
  	"file" : base_name(ob),
  	"msg"  : msg,
  	"time" : time(), 
  	"acknowledge" : acks[random(sizeof(acks))],
  	"topic" : ack,
  ]));	 	        	   
  who->save();
  me->delete_temp("random_rel");
  return 1;
}