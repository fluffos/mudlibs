 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        set_name("盘灯孚尔", ({ "pan deng"}) );
        set("gender", "男性" );
        set("title",HIY"恒河三佛"NOR);
        set("age", 70+random(10));
        set("class","lama");        
        set("long",
                "天竺高僧，此次聚众到东林寺,妄图一统武林。\n"
                );
        set("class","lama");
        set("combat_exp", 4500000);
        set("score", 900);
        set("reward_npc", 1);
        set("difficulty",5);
        set("fle",50);
        set("cor",40);
        set("cps",40);
        set("str",40);
        
     
                
        set("no_busy",5);
        set("resistance/kee",50);
        set("resistance/gin",20+random(40));
        set("resistance/sen",50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "盘灯孚尔说：嘿嘿，其实恒河只是条小河，咱们兄弟总想若是能改成‘黄河三佛’
那可真有意思！\n",
                }) );
        
     set("str", 150);
	set("int", 50);
	set("con", 50);
	set("dex", 150);

	set("combat_exp", 5800000);
	set("score", 500000);
 set_temp("fanzhen",1);
	set_skill("buddhism", 500);
	set_skill("literate", 300);

	set("jing", 26000);
	set("max_jing", 26000);

	set("qi", 26000);
	set("max_qi", 26000);
	set("neili", 26000);
	set("max_neili", 26000);
	set("jiali", 80);


	set_skill("force", 150);
	set_skill("whip", 250);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);

	set_skill("hunyuan-yiqi", 150);
	set_skill("riyue-bian", 381);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");
set_skill("weituo-chu", 380);
	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 350);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);
set_skill("ranmu-daofa", 380);
	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 290);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 290);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 290);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 190);
	set_skill("zui-gun", 190);
	set_skill("buddhism", 200);
map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "wuying-jian");
	map_skill("whip", "riyue-bian");
	map_skill("blade", "ranmu-daofa");
	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
(: perform_action, "cuff.fumo" :),
	(: perform_action, "cuff.jin" :),
		(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "strike.sanhua" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );
                set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 1100);
        set_temp("apply/damage", 1100);
        setup();
        
        carry_object("/d/shaolin/obj/jingangchu")->wield();
        carry_object(__DIR__"obj/lamacloth1")->wear();
        carry_object(__DIR__"obj/ring1")->wear();
        
} 
smart_fight()
{
        int j,i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        
        for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie() && random(2))
                {       who->cast_spell("ni");
                   return;
                }               
        }
        return;
} 
void win_enemy(object loser)
{
        say("盘灯孚尔哈哈一笑说道：好说，好说。\n"); 
} 
void lose_enemy( object winner)
{
        object gweapon;
        say("\n盘灯孚尔大惊失色道：厉害，厉害！！！我还是回去吧。\n\n");
        if (winner->query("class")=="legend" && winner->query_temp("marks/tie_ask"))
        if (!winner->query("marks/番僧3")) {
                winner->set("marks/番僧3",1);
        }
} 
void die()
{
        object me;
        if(objectp(me=query_temp("last_damage_from") ))
        if(!me->query("marks/番僧1") && me->query("class")=="legend")
        {
                me->set("marks/番僧1",1);
        }
        ::die();
}
