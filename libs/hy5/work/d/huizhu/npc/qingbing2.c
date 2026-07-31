// qingbing.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("绿营高手", ({ "qing bing","bing" }) );
	set("gender", "男性");
	set("title", HIR"血滴子"NOR);
	set("age", 25);
	set("long",
		"这是位绿营高手，满脸凶狠。\n");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "heroism");

 set("max_qi",15000+random(1690));
  set("max_jing",15000+random(1890));
   set("max_neili",15000+random(1890));
set("neili",15000);
        set_skill("necromancy", 380);
        set_skill("xiaowuxiang", 380);
        set_skill("force", 280);
        set_skill("longxiang", 380);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 380);
        set_skill("parry", 220);
        set_skill("cuff", 200);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 380);
        set_skill("lamaism", 250);
        set_skill("literate", 200);
        set_skill("hammer", 380);
        set_skill("riyue-lun", 380);
	set_skill("dashou-yin", 380);
        set_skill("staff", 380);
        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 380);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
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
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.riyue" :),
                (: perform_action, "hammer.lian" :),
                (: perform_action, "hammer.yuan" :),
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.riyue" :),
                (: perform_action, "hammer.lian" :),
                (: perform_action, "hammer.yuan" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}
        set_temp("apply/attack", 100);
        set_temp("apply/defense",100);
        set_temp("apply/armor", 850);
        set_temp("apply/damage", 850);

	setup();
carry_object("/d/xueshan/obj/jinlun")->wield();
        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
	add_money("silver", 10);
}
