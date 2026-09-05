// shihou.c 狮吼子

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("狮吼子", ({ "shihou zi", "shihou" }));
	set("nickname", "星宿派二师兄");
          set("title",HIR "星宿派" NOR + GRN +"邪士" NOR);
	set("long", 
		"他就是丁春秋的二弟子狮吼子。\n"
		"他三十多岁，狮鼻阔口，一望而知不是中土人士。\n");
	set("gender", "男性");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 200000);
	set("score", 30000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	set_skill("force", 80);
        set_skill("handu-xinfa", 80);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 70);
              set_skill("strike", 80);
	set_skill("xingxiu-duzhang", 80);
        set_skill("hand", 80);
        set_skill("zhaixing-shou", 80);
	set_skill("staff", 80);
  	set_skill("tianshan-zhang", 80);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
               map_skill("strike", "xingxiu-duzhang");
               map_skill("hand", "zhaixing-shou");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
               prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
  	//carry_object("/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("score")< 200)
          {
           command("say 你对师门的忠心还不够呀，我不能收你");
           
          }
        else
          { 
           command("say 好吧，我就收下你了。");
	   command("recruit " + ob->query("id"));
           
          }
}
#include "/kungfu/class/xingxiu/kill.h"

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        command("exert qisuck " + target->query("id"));
}
