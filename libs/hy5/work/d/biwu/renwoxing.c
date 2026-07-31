// renwoxing.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("任我行", ({ "ren woxing", "ren","woxing" }));
	set("title", BLU "日月神教教主"NOR );
	set("long", "只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清秀，
身材甚高，一头黑发，穿的是一袭青衫。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 130);
	set("per", 127);
	set("int", 130);
	set("con", 130);
	set("dex", 130);
	
	set("max_qi", 450000);
	set("max_jing", 450000);
	set("neili", 453000);
	set("max_neili", 453000);
	set("jiali", 100);
	set("combat_exp", 105000000);
	set("score", 500000);

	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "sword.sanjue" :),
               
       }) );

	set_skill("literate", 1000);
	set_skill("force", 1300);
	set_skill("dodge", 1300);
	set_skill("unarmed", 1300);
	set_skill("parry", 1300);
	set_skill("sword", 1300);
	set_skill("changquan", 1300);
	set_skill("hunyuan-yiqi", 980);
	set_skill("lingxu-bu", 980);
	set_skill("damo-jian", 980);
	set_skill("taiji-jian", 980);
	set_skill("huifeng-jian", 980);
	set_skill("taishan-sword", 1300);
	set_skill("hengshan-jian", 1300);
	set_skill("hengshan-sword", 1300);
	set_skill("huashan-sword", 1300);
	set_skill("songshan-sword", 980);

	map_skill("dodge", "lingxu-bu");
	map_skill("force", "hunyuan-yiqi");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
     set_skill("sword", 1380);
          set_skill("parry", 1300);
        set_skill("literate",1200);
          set_skill("dodge", 1300);
          set_skill("unarmed", 1300);
          set_skill("whip", 1250);
          set_skill("force", 1300);
         set_skill("tmzhang", 1380);
        set_skill("staff", 1160);
         set_skill("tmjian", 1380);
         set_skill("tmdao", 1380);
         set_skill("pmshenfa", 1380);
          set_skill("strike",1300);
          set_skill("cuff",1300);
         set_skill("blade", 1300);
         set_skill("tmdafa", 1320);
set_skill("tmquan", 1380);
        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        map_skill("strike", "tmzhang");
        map_skill("cuff", "tmquan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.diansha" :),
                (: perform_action, "sword.xuan" :),
                (: perform_action, "sword.tmbiao" :),
                	(: perform_action, "sword.jianshen" :),
                		(: perform_action, "sword.moshen" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "blade.xuan" :),                	
                (: perform_action, "blade.yueshen" :),                	
                (: perform_action, "strike.huashen" :),                
                (: perform_action, "strike.zhen" :),                
                (: perform_action, "strike.tmduan" :),                
                (: perform_action, "cuff.tianmo" :),                
                (: perform_action, "cuff.dimo" :),                
                (: perform_action, "cuff.renmo" :),

        }) );

prepare_skill("cuff","tmquan");

prepare_skill("strike","tmzhang");

        set_temp("apply/attack", 500);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);

 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
    if (random(2)==0) carry_object("/p/item/ritemtz3/wblade38")->wield();
    carry_object("/p/item/ritemtz3/wsword38")->wield();
    
    carry_object("/p/item/ritemtz3/ahands39")->wear();
}

