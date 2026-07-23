//【蜀山派】mhxy-yushu 2001/2
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
   string ask_mieyao();
   string ask_cancel();
string expell_me(object me);
int ask_jiu();
int begin_go();
void create()
{
       set_name("酒剑仙", ({"jiu jianxian", "jianxian", "xian"}));
       set("title", HIC"醉道士"NOR);   
       set("long", "一人人送外号“酒剑仙”，行踪不定，或游历于名山大川之畔，或隐匿于街头闹市之中。\n");
       set("gender", "男性");
       set("age", 68);
       set("attitude", "peaceful");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("combat_exp", 800000);
       set("daoxing", 800000);
       set("max_kee", 1700);
       set("max_sen", 1700);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 120);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 120);
	set_skill("shushan-force", 240);
       set_skill("yujianshu", 260);
       set_skill("sword", 260);
       set_skill("unarmed", 230);
       set_skill("fumozhang", 230); 
       set_skill("dodge", 250);
       set_skill("literate", 110);
       set_skill("force", 250);
       set_skill("parry", 250);
       set_skill("spells", 260);
       set_skill("xianfeng-spells", 260);
       set_skill("zuixian-steps", 250);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "shushan-force");
       map_skill("spells", "xianfeng-spells");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
       set("inquiry", ([
                 "灵台观礼": (: begin_go :), 
	             "下山": (: expell_me :),
                 "leave": (: expell_me :),
                 "kill" : (: ask_mieyao :),
                 "cancel" : (: ask_cancel :),
                 "酒神" : (: ask_jiu :),

       ]) );
       create_family("蜀山派", 2, "弟子");
       setup();
       carry_object("d/obj/cloth/linen")->wear();
       carry_object("d/obj/weapon/sword/qinghong")->wield();
       carry_object("d/qujing/tianzhu/obj/jiuhu");
       carry_object("d/qujing/tianzhu/obj/jiuzhong");
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="蜀山派") {
	if ((int)ob->query("daoxing") < 300000 ) {
  	command("say 你的道行还不够，" + RANK_D->query_respect(ob) + "还需多加努力才行。\n");
	return;
	}
       if( (int)ob->query_skill("xianfeng-spells", 1) < 150 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "你的仙风云体术还不到火候,你还是找追云子他们练着吧!\n");
	command("sigh");
	return;
	}
       command("haha");
       command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
       command("recruit " + ob->query("id") );
	return;
	}
       command("shake");
       command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
       return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山酒剑仙弟子");

               } 
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}
string ask_mieyao()
{
   object me=this_player();

    if(me->query("family/family_name")!="蜀山派")
      return ("你不是本门中人!");

   command("pat "+me->query("id"));
    command("say 有志气！");
   return "/d/obj/mieyao"->query_yao(me);
}
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="蜀山派") {
                me->set_temp("betray", 1);
                return ("你真的要离开吗?你要付出一些代价,你可愿意(agree)?");
        }
        return ("不知。");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：愿意。\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/shushan", 1);
		  this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                if( this_player()->query_skill("shushan-force") )
		  this_player()->delete_skill("shushan-force");
                if( this_player()->query_skill("xianfeng-spells") )
		  this_player()->delete_skill("xianfeng-spells");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->save();
                command("say 那你去吧！\n");
                return 1;
                }
        return 0;
}

int ask_jiu()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "蜀山派")
    {
    command("say 你又不是蜀山派的，谁管你！");
    return 1;
    }
    if(ob->query("shushan/jiushen_cast"))
    { 
    command("say 你不是问过了吗? ");
    return 1;
    }
    if(ob->query("family/master_name") == "酒剑仙" )
    {
    command("say 这一招酒神，是为师唯一能给你的，绝不比任何法术差！它应该可以帮你保命的！");
    ob->set("shushan/jiushen_cast",1);
    return 1;
    }
}


int begin_go()
{
	object me;
    me=this_player();
	if (!me->query("fangcun/panlong_visite"))
	return 0;
	
	if (me->query_temp("fangcun/panlong_shushan_jiujianxian")=="begin")
	{
        message_vision("\n酒剑仙遥望天边道：酒,酒,酒,此酒只应天上有！\n"NOR,me);
		return 1;
    }
    message_vision("\n酒剑仙叹道：酒,酒,酒,美酒穿肠过,笑叹世间情！\n"NOR,me);
    me->set_temp("fangcun/panlong_shushan_jiujianxian","begin");
	return 1;
}

void return_ob (object ob, object who)
{
  if (ob)
    command ("give "+ob->query("id")+" to "+who->query("id"));
}

void destruct_me (object ob)
{
  destruct (ob);
}

int accept_object (object who, object ob)
{
object jiudai,pass;
string liquid_name;
string liquid_type;
object me = this_object();
liquid_name = YEL"仙酒"NOR;
liquid_type = "alcohol";
  if ((string)ob->query("liquid/type")!="alcohol")
   {
     command ("shake "+ob->query("id"));
	call_out ("return_ob",1,ob,who);
    return 1;
  }
  
  if (ob->query("liquid/remaining") == 0)
  {
    message_vision ("$N摇了一下头，说道：空的,拿来骗人吗?\n",me);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  if (ob->query("liquid/name") != liquid_name)
  {
    message_vision ("$N摇了一下头，说道：这种酒也称得上好酒?\n",me);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  if(!who->query_temp("yaochi_fill"))
  {
	   message_vision ("$N摇了摇头，说道：这不是凭你自己的本事拿到的酒！\n",me);
    call_out ("return_ob",1,ob,who);
    return 1;
    
  }
 
  message_vision (HIW"$N一口气喝干了仙酒开怀大笑道：好酒,好酒！" + RANK_D->query_respect(ob) + ",这个东西你拿去,哈哈,真是好酒啊！\n"NOR,me);
  message_vision ("$N给你一个空酒葫芦.\n"NOR,me);
  pass=new("/d/shushan/obj/jiujianxian-pass");
  pass->move(who);
  return 1;
  
  
}

