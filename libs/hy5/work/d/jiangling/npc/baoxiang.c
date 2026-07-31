// /kungfu/class/xueshan/baoxiang.c  宝象
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("宝象", ({ "bao xiang", "bao", "xiang" }));
        set("long",@LONG
一个极高极瘦的僧人，俩眼凶芒四射。此人在血刀老祖门下，最是心狠手辣。
LONG
        );
        set("title",HIR"血刀门第五代弟子"NOR);
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi",  18000);
        set("max_jing", 18000);
        set("neili", 35000);
        set("max_neili", 35000);
        set("jiali", 100);
        set("combat_exp", 8500000);
        set("score", 500000);

        set_skill("necromancy", 380);
        set_skill("force", 200);
        set_skill("xiaowuxiang", 380);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 380);
        set_skill("strike", 320);
        set_skill("parry", 200);
        set_skill("cuff", 200);
        set_skill("sword", 200);
        set_skill("mingwang-jian", 380);
        set_skill("lamaism", 380);
        set_skill("literate", 100);
        set_skill("staff", 100);
        set_skill("xiangmo-chu", 380 );
        set_skill("strike", 300 );
        set_skill("huoyan-dao", 380);
	set_skill("dashou-yin", 320);
	        set_skill("xiangmo-chu", 380);
       // set_skill("magic", 380);
        //set_skill("kwan-yin-spells", 380);
//map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
	set("inquiry", ([
		"十三龙象袈裟" : "这是本门佛宝，不能轻易给你，这样吧帮我找一朵藏红花吧！\n",
	]));


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "huoyan-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        map_skill("strike","huoyan-dao");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.yan" :),
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.yan" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}
prepare_skill("strike", "huoyan-dao");
        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        //carry_object("/clone/weapon/gangdao")->wield();

        add_money("gold",1);
}

void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
              //me->add("score",1);        
        message_vision(RED"$N一声怒吼，浑身鲜血直流，逃了出去!\n"NOR,ob,me);
        


        me->set_temp("killxs1",1);


               destruct(ob);
        return;
}