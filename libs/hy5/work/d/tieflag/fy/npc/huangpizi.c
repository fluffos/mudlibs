#include <ansi.h>
inherit NPC;
int *stat =({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
int *low_index = ({});
void pay_him(object who, int amount);
void clear_stat();
void pre_cal();
void create()
{
        int i,amun;
        set_name( "黄痞子", ({ "pizi", "huang pi zi" }) );
        set("long", "一个在银钩赌坊的输疯了的小流氓。\n");
        set("attitude", "friendly");
        set("title", HIW "赌棍"NOR);
        set("force_factor", 30);
        //set("reward_npc", 1);
        //("difficulty", 40);
        set("fly_target",1);
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_neili", 2000);
        set("neili", 2000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("age", 33);
        //temp("apply/damage",600);
        set("gender", "男性" );  
        set("str", 35);
        set("cor", 30);
        set("cps", 25);
        set("per",5);
        set("lower_limit",1);
        set("too_late",0);
        set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0); 
        set("force_factor",250);
        set_skill("throwing",30);
        set_skill("unarmed",20);
        set_skill("dodge",50);
   set("combat_exp", 500000);
        setup();
                carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/stone")->wield();

}
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
//        add_action("do_bet", "bet");
        
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "黄痞子笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，过来赌两手，碰碰运气吧。\n");
                        break;
                case 1:
                        say( "黄痞子晃了晃手中的骰子，叫道：这位" + RANK_D->query_respect(ob)
                                + "，小赌怡情，小赌怡情。来吧！\n");
                        break;
                case 2:
                        say( "黄痞子说道：这位" + RANK_D->query_respect(ob)
                                + "，过来！过来！ 我这比黄麻子的划算得多！\n");
                        break;
        }   
        return; 
}
 
