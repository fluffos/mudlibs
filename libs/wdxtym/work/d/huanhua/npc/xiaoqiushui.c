// xiaoqiushui.c 萧秋水
#include <ansi.h>
inherit NPC;
void init();
string ask_me_1();
inherit F_MASTER;
int flag=0;
void create()
{
	int jibie;
	jibie = 4000;
	set("xyzx_sys/level", jibie*8/10+random(jibie*4/10));	//2016.5.22阿飞调整NPC属性
        set_name("萧秋水", ({ "xiao qiushui", "xiao", "qiushui" }));
        set("nickname", HIR "大侠"NOR);
        set("long", 
"萧秋水身材不高，但长的浓眉阔眼，看上去气宇暄昂，他在\n"
"浣花萧家排行老三，但在江湖是数一数二的顶尖好手。\n");
        set("gender", "男性");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("per",30);
        set("max_qi", 80000);
        set("jing", 80000);
        set("max_jing", 80000);
        set("neili", 1500000);
        set("max_neili", 4400);
        set("jiali", 3000);
        set("combat_exp", 100000000);
        set("score", 100000);
        set_skill("cuff", 500+jibie/3+random(jibie/5));	
        set_skill("strike",500+jibie/3+random(jibie/5));	
        set_skill("force", 500+jibie/3+random(jibie/5));	
        set_skill("dodge", 500+jibie/3+random(jibie/5));	
        set_skill("parry", 500+jibie/3+random(jibie/5));	
        set_skill("unarmed",500+jibie/3+random(jibie/5));	
        set_skill("sword", 500+jibie/3+random(jibie/5));
        set_skill("literate",500+jibie/3+random(jibie/5));
        set_skill("huanhua-jian",500+jibie/3+random(jibie/5));	
        set_skill("tiexian-quan",500+jibie/3+random(jibie/5));
        set_skill("guiyuan-dafa",500+jibie/3+random(jibie/5));	
        set_skill("feihua-wuping",500+jibie/3+random(jibie/5));	
         map_skill("force","guiyuan-dafa");
         map_skill("unarmed","tiexian-quan");
         map_skill("sword","huanhua-jian");
         map_skill("dodge","feihua-wuping");
     
        create_family("浣花剑派", 2, "弟子");
        
        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: perform_action, "sword.snow" :),
                (: exert_function, "recover" :),
        }) );
        
       
        set("inquiry", ([
                "神州结义" : "这是我和几个好朋友行走江湖时所创下的.\n",
                "唐方" : "你有她的消息吗？说罢，你见他神情激动,好象眼睛红红的！\n",
                "长歌"       : (: ask_me_1 :),                
             ]));
      
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/huanhua/obj/changge")->wield();
      
}
/*
void init()
{
       object ob;
       ::init();
       if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        ob = this_player();
        if((int)ob->query("score") < 50 &&ob->query("family/master_id")=="xiao qiushui")
        {
                    command("chat "+ob->query("name")+"!你为人不忠不义，我岂能仍是你的师傅。\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","浣花剑派" + RED + "弃徒" NOR);   
        }
 }
                
}
*/
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("萧秋水叹了口气:唐方,唐方你在哪里?\n");
        
}
string ask_me_1()
{
        mapping fam; 
        object obj,me;
        
        me=this_object();
        if(objectp(obj = present("changge sword", me)))
        {
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "浣花剑派")
                return RANK_D->query_respect(this_player()) + 
                "并非本派弟子，不知此话从何谈起？";
        if ( (int)this_player()->query("shen") < -1000 )
                return RANK_D->query_respect(this_player()) + 
                "你杀气太重，长歌怎能交你手上？";
        
        command("give changge sword to "+this_player()->query("id"));        
        message_vision("$N获得一把长歌剑。\n",this_player());
        
        return ("好吧，拿着这把剑，不要辱没了我们浣花萧家。");
        }
        else return("你来晚了，长歌已经被人拿走了!\n");                 
        
}
void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<100000)
        {
          message_vision("萧秋水对$N笑道：你的修为太低了,我还不能收你！\n",ob);
        return ;
         }
   if ((int)ob->query("score") < 300 ) {
        command("say 你对本门的贡献还不够,还得努力呀!");
                return;
          }
   message_vision("萧秋水拍拍$N的头，微微点了点头。\n",ob);
   ob->set("class", "swordsman");
   ob->set("title","浣花剑派三代弟子");   
   command("recruit " + ob->query("id"));
   return;
}
void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;
        if (arg == "xiao qiushui" || arg == "xiao")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}
       
int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));
        if ( me->is_fighting()) return 0;
        if ( !present(ob, environment()) ) return 0;
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}
int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;
        if ( !present(ob, environment()) ) return 1; 
        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");
        if( me->is_fighting() ) 
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {
                   
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }
        return 1;  
}
