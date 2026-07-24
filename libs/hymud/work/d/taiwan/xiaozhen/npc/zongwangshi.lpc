#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("宗王师",({"zong wangshi","zong"}));
    set("gender","男性");
    set("age",27);
    set("long","一身锦袍,越发显得潇洒风流,据说武功在年轻一
    辈中,可称翘楚。\n");
    set("title",RED"幽冥山庄少宗主"NOR);
    set("combat_exp",1000000);
    set("kee",1000);
    set("max_kee",1000);
    set("force",1000);
    set("max_force",1000);
    set("force_factor",25);
    set("food",200);
    set("water",200);
    
    set("inquiry",([
    "幽冥山庄":"自从二十年前被各大门派围攻,我爹就躲到了此处?\n",
    "道心种魔大法":"我门中无上大法，可惜早几代就失传了.\n",
    ]));
        set("shen_type",-1);
    
    set("chat_chance",3);
    set("chat_msg",({
    CYN"我教中人才凋零,看来要多招人手才行.\n"NOR,
    CYN"听说我教中还有位长老,不过我也从没见过.\n"NOR,
    CYN"这大屋修建得还算不错,任谁也想不到机关在池塘底下。\n"NOR,
    }));
    
     set("combat_exp", 9999999);
    set("score", random(90000));
    
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
	set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);

    
create_family(RED"幽冥山庄"NOR,5,"少宗主");    
    setup();
    carry_object("/d/ghost/npc/obj/cloth3")->wear();
    carry_object("/d/ghost/npc/obj/hat")->wear();
    carry_object("/d/ghost/npc/obj/swordd")->wield();
    add_money("gold",1);
 }
