#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
int kill_him(); 
int wieldsword();
void create()
{ 
        set_name("袁秋云",({"yuan qiuyun","yuan","qiuyun"}));
        set("title",WHT"白云山庄庄主"NOR);
        set("long", "这人当然已是个老人，是个很有威仪的老人。他穿着也极考究，态度却比柳东来还
严肃有威，\n");
        set("age",59);
        set("combat_exp", 6400000);
        set("attitude", "friendly");
        
        set("inquiry", ([
             "白天羽" : (: kill_him :),
        ]));
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",100); 
        set("str",100);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("reward_npc", 1);
        set("difficulty", 10);
        
        set_skill("move", 150);
        
        set_skill("parry", 180);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 180);
        set_skill("sword", 240);
        set_skill("unarmed",100);
        set_skill("music",220);
        set_skill("feixian-steps",220);
        set_skill("feixian-sword",200);


        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");


        map_skill("move","feixian-steps"); 

        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
   
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                 (: wieldsword  :),

        }) );
         
        CHAR_D->setup_char(this_object());
       // auto_npc_setup("xuebin",250,180,1,"/obj/weapon/","fighter_w","taiji");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/loulan/obj/sword");
}  
void init()
{
        add_action("do_killing", "kill");
        ::init();
} 
int kill_him()
{
        object me, another;
        
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"袁秋云现在没空回答你。\n");
                return 1;
                }
        message_vision("$N的笑声突然停顿，目光中忽然露出恐惧之色，一张严肃的脸，也突然变得扭
曲变形，失色道：“你是白……白大侠的什么人？”\n"NOR,this_object());
        message_vision("$N「哼」了一声，「果然是你！」\n\n只见$N手中兵器一闪。。。。。。\n\n"NOR,me);
        message_vision("血慢慢从胸膛渗出来，$N目光溃散，渐渐变成了死灰色，\n留下最後一句话：「当天。。。我，不在。。。梅花庵外。。。」\n"NOR,this_object());
        me->set_temp("killed_yuan_ma",1);
        this_object()->die();
        return 1;
}
  
int wieldsword()
{
command("wield sword");
perform_action("dodge.tianwaifeixian");
command("unwield sword");
return 1;
}


int do_killing(string arg)
{
        
        object player, victim, weapon;
        string name;
        player = this_player();
        if( !arg) return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = (string)victim->name();
                if( (string)name == "柳东来")
                {
                message_vision("$N皱了皱眉头：新郎倌让开，让我来收拾。\n", this_object());
                this_object()->kill_ob(player);
                player->kill_ob(this_object());
                return 0;
                }
        }
        return 0;               
}   
