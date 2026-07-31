// sun 孙三毁  
 
inherit NPC;
 
void create()
{
	set_name("大盗孙三毁", ({ "sun sanhui", "sun" }));
	set("nickname", "神箭八雄");
	set("long", 
        "原是武林中的巨寇，后来为躲避官府和仇家，随便起了个假名字。\n");
	set("gender", "男性");
	set("age", 46);
	set("attitude", "peaceful");
	set("shen", -8000);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 5500);
	set("max_jing", 5500);
	set("neili", 5800);
	set("max_neili", 5800);
	set("jiali", 100);
	set("combat_exp", 600000); 
	 set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "strike.sanhua" :),
         }));
         set_skill("force", 140);
         set_skill("hunyuan-yiqi", 320);
         set_skill("dodge", 140);
  

        set_skill("kunlun-shenfa", 320);
        set_skill("strike", 140);
        set_skill("sanhua-zhang", 320);
        set_skill("parry", 140);
        set_skill("literate", 80);
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "sanhua-zhang");
  	map_skill("parry", "sanhua-zhang");
  	prepare_skill("strike", "sanhua-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"
