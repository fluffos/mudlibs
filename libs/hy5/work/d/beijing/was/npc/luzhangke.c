#include <ansi.h>


inherit NPC;
inherit F_MASTER;




void create()
{
        set_name("鹿杖客", ({ "luzhang ke", "luzhang", "ke" }));
	set("gender", "男性");
	set("title", WHT"玄冥二老"NOR);
        set("shen_type", -1);
        set("age", 52);
        set("str", 30);
        set("con", 38);
        set("int", 20);
        set("dex", 26);
        set("max_qi", 15400);
        set("max_jing", 12400);
        set("qi", 15400);
        set("jing", 12400);
        set("neili", 26500);
        set("max_neili", 26500);
        set("jiali", 220);
        set("combat_exp", 5200000);

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
        map_skill("parry",  "xuanming-zhang");
        map_skill("unarmed",  "xuanming-zhang");
        map_skill("strike",  "xuanming-zhang");
        prepare_skill("strike", "xuanming-zhang");
             
        create_family("玄冥谷", 2, "弟子");



        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({               
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.zhe" :),
                (: perform_action, "strike.lang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "张无忌"    :   "哼，臭小子屡次坏我大事！我非杀了他不可！\n",
                "赵敏"      :   "那丫头诡计多端，忘恩负义，枉我兄弟为她出生入死。\n",
                "百损道人"  :   "他是我恩师，你问这干什么？\n",
                "鹤笔翁"    :   "他是我师弟，我们从小跟着师父学艺，亲同手足。\n", 
        ]));

        set_temp("apply/attack", 180);
        set_temp("apply/damage", 180);
        set_temp("apply/armor", 380);



        setup();

        carry_object("/clone/cloth/baipao")->wear();
}

