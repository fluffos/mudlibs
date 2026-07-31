#include <ansi.h>
inherit F_VENDOR;
inherit NPC;
void mimicurse();
int do_answer1();
void create()
        {
        set_name("瞎子阿鸣", ({ "xiazi aming","aming" }) );
        set("title",HIR"算命的"NOR);
        set("gender", "男性" );
        set("age", 25);
        set("class","yinshi");
        set("attitude", "friendly");
        set("long","脸色苍白，两眼翻白，据说是济南府一带颇有名气的相士。\n");
        set("combat_exp", 3500000);
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set("int",70);
        set("fle",40);
        set("cps",60);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("mana", 500);
        set("max_mana", 500);
        
        

          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);     
        set_skill("bloodystrike", 160);
        set_skill("iron-cloth",150);
        
    
    set("inquiry", ([
           "叛师次数" : (: do_answer1 :), 
        ]) );
        
    set("chat_chance", 2);
    set("chat_msg", ({
            "瞎子阿鸣长叹了一口气：大脑一片空白，什么都算不出来。。。\n",
            "瞎子阿鸣笑着说：“海洋II是最好的！！我爱海洋II！！”\n",
            "瞎子阿鸣恨恨说：“那个花街恶少，每次来都逼我给他算命，跟催命似的。。”\n",
            "瞎子阿鸣神秘地说：“想知道自己叛师次数吗？\n",
           "瞎子阿鸣低声道：“想知道海洋II的几大秘密吗？保证精彩，欲成一代大侠者不可不看。。。”\n"
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
     
        
} 
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {       remove_call_out("greeting");
                call_out("greeting", 1, ob);    
   }        
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
     say( "瞎子阿鸣对"+ob->query("name")+"微笑道：这位" + RANK_D->query_respect(ob)
                                + "看起来眉直鼻挺，一看就知道是大富大贵之相。\n"); 
} 
int do_answer1()
{
        int betray;     
        string respect; 
        if(!this_player()->query_temp("money_given") )
        {
    say("瞎子阿鸣嘿笑道：“这个。。呵呵。。。最近物价涨得很厉害。。。当算命的油水很少呢。。。”\n瞎子阿鸣伸出了一只手指，晃了一晃。\n");
        return 1;
        }
        betray=this_player()->query("betrayer");
        respect=RANK_D->query_respect(this_player());
        if(!betray)
                {
                command("admire "+this_player()->name());
       say("瞎子阿鸣赞许地说道：“这年头，人心不古，象"+respect+"那么专一的人真是难得呀。。\n皇天必定佑汝。。”\n");
                }
        else if(betray==1)
                {
                command("admire "+this_player()->name());
        say("瞎子阿鸣赞许道：“这年头，人心不古，象"+respect+"这样只换过一个门派的人也算\n难得了。。皇天必定佑汝。。”\n");
                }
                
        else if(betray<6)
                {
                command("pat "+this_player()->name());
         say("瞎子阿鸣讨好道：“树挪死，人挪活，"+respect+"果然见识不凡，虽然换过"+chinese_number(betray)+"次门派，\n但必定多了很多次的历练，他日必能成就大业。“\n");
                }
        else
                {
                command("?");
                say("见习巫师手忙脚乱的扳着手指。。。\n");
                command("faint "+this_player()->name());
        say("瞎子阿鸣无奈一摊手掌：“我土，实在是数不清楚。。。”\n");
                command("cry");
                }
        this_player()->delete_temp("money_given");
        return 1; 
}
          
int accept_object(object who, object ob)
{
        if(ob->name()=="黄金")
        {
    say("瞎子阿鸣嘴上说道“这怎么行。。。”，但手却紧紧握着黄金，生怕"+this_player()->name()+"拿回去的样子。\n");
        this_player()->add_temp("money_given",1);
        return 1;
        }
        
    return notify_fail("瞎子阿鸣讪笑道：“此物虽好，只是恕难接受了。。。\n");
}  
