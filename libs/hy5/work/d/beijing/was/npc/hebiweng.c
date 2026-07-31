#include <ansi.h>


inherit NPC;


void create()
{
        set_name("鹤笔翁", ({ "hebi weng", "hebi", "weng" }));
	set("gender", "男性");
	set("title", HIB"玄冥二老"NOR);
        set("shen_type", -1);
        set("age", 50);
        set("str", 30);
        set("con", 38);
        set("int", 20);
        set("dex", 26);
        set("max_qi", 14400);
        set("max_jing", 12200);
        set("qi", 14400);
        set("jing", 12200);
        set("neili", 15500);
        set("max_neili", 15500);
        set("jiali", 135);
        set("combat_exp", 3200000);

        set_skill("force", 250);
	set_skill("shenlong-xinfa", 380);
        set_skill("dodge", 200);
	set_skill("yixingbu", 380);
        set_skill("hand", 250);
	set_skill("shenlong-bashi", 380);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 380);
        set_skill("parry", 250);
set_skill("claw", 300);
set_skill("strike", 300);
        set_skill("staff", 200);
        set_skill("sword", 200);
        set_skill("zhaosheshu", 380);
        set_skill("yangsheshu", 380);
	set_skill("shedao-qigong", 380);
	set_skill("literate", 200);
	set_skill("dulong-shenzhua", 380);
	set_skill("xuanming-zhang", 380);
        
        set_skill("leg",200);
        set_skill("shenlong-tuifa",380);
        

        map_skill("strike", "xuanming-zhang");
        map_skill("force",  "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
        map_skill("parry",  "dulong-shenzhua");
        map_skill("unarmed",  "dulong-shenzhua");
        map_skill("claw",  "dulong-shenzhua");
	map_skill("hand", "shenlong-bashi");
        prepare_skill("claw", "dulong-shenzhua");

             
        create_family("玄冥谷", 2, "弟子");



        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({               
                (: perform_action, "claw.bao" :),
                (: perform_action, "claw.ju" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "张无忌"    :   "哼，臭小子屡次坏我大事！我非杀了他不可！\n",
                "赵敏"      :   "那丫头诡计多端，忘恩负义，枉我兄弟为她出生入死。\n",
                "百损道人"  :   "他是我恩师，你问这干什么？\n",
                "鹿杖客"    :   "他是我师兄，我们从小跟着师父学艺，亲同手足。\n", 
        ]));

        set_temp("apply/attack", 180);
        set_temp("apply/damage", 180);
        set_temp("apply/armor", 180);



        setup();

        carry_object("/clone/cloth/baipao")->wear();
}

