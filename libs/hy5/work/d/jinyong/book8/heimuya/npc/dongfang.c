// dongfang.c
#include <ansi.h>
inherit NPC;

void consider();

void create()
{
    set_name("东方不败", ({"dongfang bubai", "dongfang", "bubai"}));
    set("nickname", HIY "天下无敌" NOR );
    set("title", HIM"日月神教教主"NOR);
    set("gender", "男性");
    set("shen_type", -1);
    set("age", 42);
    set("long",
        "他就是日月神教教主。号称无人可敌，因此有一称号为「东方不败」。\n");
    set("attitude", "peaceful");

    set("per", 21);
    set("str", 61);
    set("int", 60);
    set("con", 66);
    set("dex", 66);

    set("chat_chance", 1);
    set("chat_msg", ({
 "东方不败叹了口气道：“唉 …… 我的杨大哥....他怎么还不回来,我好\n"
 "挂念他 ……东方不败眼中流露无限迷茫。\n",
        }));
    set("inquiry", ([
        "杨莲亭"   : "你敢直称我爱人的名字,想找死呀？ \n",
        "葵花宝典" : "如果你能帮我取得葵花宝典上册，我一定重重谢你。\n",
    ]));

    set("guard/flag", 1);
    set("guard/ok", 1);
    set("qi", 150000);
    set("max_qi", 150000);
    set("jing", 150000);
    set("max_jing", 150000);
    set("neili", 150000);
    set("max_neili", 150000);
    set("jiali", 200);

    set("combat_exp", 24500000);
    set("score", 0);

    set_skill("cuff", 500);
    set_skill("strike", 500);
    set_skill("force", 500);             // 基本内功
    set_skill("finger", 500);            // 基本指法
    set_skill("unarmed", 500);           // 基本拳脚
    set_skill("dodge", 500);             // 基本躲闪
    set_skill("parry", 500);             // 基本招架
    set_skill("sword", 500);             // 基本剑法
    set_skill("pixie-jian", 500);        // 辟邪剑法
    set_skill("changquan", 500);         // 太祖长拳
    set_skill("literate", 100);          // 读书识字
    set_skill("kuihua-xinfa", 500);      // 葵花心法
    set_skill("kuihua-dafa", 500);      // 葵花大法
    set_skill("kuihua-feiying", 500);      // 葵花身法
   set_skill("tmzhang", 500);
        set_skill("staff", 500);
         set_skill("tmjian", 500);
         set_skill("tmdao", 500);
         set_skill("pmshenfa", 500);
          set_skill("cuff",500);
         set_skill("blade", 500);
         set_skill("tmdafa", 500);
set_skill("tmquan", 500);       
    map_skill("force", "kuihua-xinfa");
    map_skill("sword", "kuihua-dafa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "kuihua-feiying");
    map_skill("parry", "pixie-jian");
    create_family("日月神教", 1, "教主");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tonggui" :),
                (: perform_action, "sword.pi" :),
                	(: perform_action, "sword.yinrou" :),
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.gui" :),
                (: perform_action, "parry.cimu" :),
                (: perform_action, "parry.huanying" :),
                (: perform_action, "parry.sanlianci" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: perform_action, "dodge.feiying" :),
                (: perform_action, "dodge.jue" :),
                (: perform_action, "unarmed.yuhuan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "powerup" :),                
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 900);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
    setup();
    carry_object("/d/heimuya/npc/obj/qijue")->wield();
    carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();

}

void init()
{
	object me = this_object();
	object who= this_player();
	if(me->is_fighting()) return;
	if (who && interactive(who)) 
		call_out ("fighting", 1, who);  
}


void fighting(object who)
{
	object where = environment(who);
	object dongfang = this_object();
	object ren = present("ren woxing",where);
	if(dongfang && ren) 
	{
		message_vision("$N对$n说道： 东方不败，你的死期到了 !\n",ren,dongfang);
		ren->kill_ob(dongfang);
	}
}