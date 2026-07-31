// xiaoxilou.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;
int ask_me();
int potential_lv(int exp);

void create()
{
	int jibie;
	jibie = 6000;
	set("xyzx_sys/level", jibie*8/10+random(jibie*4/10));	//2016.5.22阿飞调整NPC属性
        set_name("萧西楼", ({ "xiao xilou", "xiao" }) );
        set("gender", "男性");
        set("age", 60);
        set("long",
                "萧西楼是浣花剑派的掌门，他是个年近六旬的老人，身板硬朗得很。\n");
        set("attitude", "peaceful");

        set("str", 50);
        set("cor", 30);
        set("int", 24);
        set("dex", 30);
        set("per",25);
        set_max_encumbrance(100000000);

        set("neili", 6000000);
        set("max_neili", 3000000);
        set("jiali", 5500);
        set("max_jing", 1100000);
        set("max_qi", 3000000);

        set("combat_exp", 300000000);
        set("score", 200000);
        set("shen",15000);
        set("chat_chance_combat", 80);
        set("inquiry", ([
                "难事" : (: ask_me :), 
                "帮忙" : (: ask_me :),
        ]));
        
        set_skill("cuff", 500+jibie/3+random(jibie/5));
        set_skill("strike",500+jibie/3+random(jibie/5));
        set_skill("force", 500+jibie/3+random(jibie/5));    
        set_skill("dodge", 500+jibie/3+random(jibie/5));    
        set_skill("parry", 500+jibie/3+random(jibie/5));    
        set_skill("sword", 500+jibie/3+random(jibie/5));    
        set_skill("literate",500+jibie/3+random(jibie/5));    
        set_skill("unarmed",500+jibie/3+random(jibie/5));    
        set_skill("huanhua-jian",500+jibie/3+random(jibie/5));    
        set_skill("tiexian-quan",500+jibie/3+random(jibie/5));    
        set_skill("guiyuan-dafa",500+jibie/3+random(jibie/5));    
        set_skill("feihua-wuping",500+jibie/3+random(jibie/5));    

        map_skill("force","guiyuan-dafa");
        map_skill("unarmed","tiexian-quan");
        map_skill("sword","huanhua-jian");
        map_skill("dodge","feihua-wuping");
        map_skill("parry","huanhua-jian");     
        create_family("浣花剑派", 1, "掌门人"); 
        set("chat_chance_combat", 300);    
        set("chat_msg_combat", ({    
        (: perform_action, "sword.snow" :),    
        (: exert_function, "recover" :),    
        }) );    
        set("no_get",1);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huanhua/obj/ccloth")->wear();    
        }

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("萧西楼叹了口气:孩子不在身边，心里挺挂念的。\n");
}

int ask_me()
{
        object me,obj;
        mapping fam;
        me=this_player();
        obj=this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "浣花剑派") {
                say("你并非本派弟子，不知此话从何谈起？");
                return 1;
        }

        command("sigh");
        command("say 这位"+RANK_D->query_respect(me)+",易人出门已经很长时间了。");
        command("say 你能不能帮我打听一下他的消息？");
        me->set_temp("find_ren",1);
        return 1;
}

int accept_object(object who, object ob)
{
        object obj;
        int bonus;
        obj=this_object();
        if(! who->query_temp("find_ren") ) return 0;
        if ( ob->query("id") != "black sword" || userp(ob) )
                return 0;
        if(ob->query("gived"))
        {
                message_vision("萧西楼对$N笑道：咦，这不是你刚给我的那个吗？怎么又跑到你那里去了？！\n",who);
                remove_call_out("destroy");
                call_out("destroy", 0, ob);             
                return 0;
        }
        tell_object(who,GRN"萧西楼对你由衷地表示感谢，你得到了50点潜能和200点修为。\n"NOR);
        who->add("combat_exp",200);
//      who->start_busy(2);
        bonus = (int)who->query("potential");
        bonus = bonus - (int)who->query("learned_points");
        bonus = bonus + 50;
        if ( bonus > potential_lv((int)who->query("combat_exp")) )
                bonus = potential_lv((int)who->query("combat_exp"));
        bonus += (int)who->query("learned_points");
        who->set("potential", bonus );
        who->delete_temp("find_ren");
        ob->set("gived",1);
        remove_call_out("destroy");
        call_out("destroy", 0, ob);

        return 1;
}

void destroy(object ob)
{
        destruct(ob);
}
void attempt_apprentice(object ob)
{
        if((int)ob->query("combat_exp")<300000) {
                message_vision("萧西楼对$N笑道：你的修为太低了,我还不能收你！\n",ob);
                return ;
        }
        if ((int)ob->query("score") < 500 ) {
                command("say 你对本门的贡献还不够,还得努力呀!");
                return;
        }
        message_vision("萧西楼拍拍$N的头，微微点了点头。\n",ob);
        ob->set("class", "swordsman");
        ob->set("title","浣花剑派二代弟子");   
        command("recruit " + ob->query("id"));
        return;
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500 ;
        return grade;
}

void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "xiao xilou" || arg == "xiao")
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