//whuan
//duan yanqing

#include <ansi.h>
inherit NPC;
int ask_fengmo();//疯魔pfm

void create()
{
	set_name("段延庆", ({"duan yanqing", "yanqing", "qing"}));
	set("gender", "男性");
	set("nickname",HIR"恶贯满盈"NOR);
	set("age", 45);
	set("long", 
		"他就是四大恶人之首，人称恶贯满盈的段延庆。\n"
		"他本是大理段氏皇子，由于大臣反叛作乱而双腿残废、罹\n"
		"毒甚深。流落江湖后与叶二娘、南海鳄神、云中鹤和称四\n"
		"大恶人。在江湖上端的是无恶不作。\n"
		"他身穿一件青布长袍，身高五尺有余，脸上常年戴一张人\n"
		"皮面具，喜怒哀乐一丝不露。体格瘦长，双腿齐膝而断，\n"
		"只能用腋下的两根镔铁拐杖代步，但行走如飞，反比常人\n"
		"更快！\n");
	set("str", 30);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("max_qi", 1200);
	set("qi",1200);
	set("max_jing", 800);
	set("jing",800);
	set("max_neili", 1800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 80);
	set("combat_exp", 4000000);
	set("attitude", "peaceful");
	set("shen_type", 1);	
	set("chat_chance", 1);
	set("chat_msg", ({
		"段延庆叹了口气道：“唉……不知何时才能重登大理宝座！”\n",
		"段延庆喃喃道：“段正德那厮若知我回来，定会将皇位拱手相让，哈哈哈！\n",
	}));	
	set("inquiry", ([	
		"一阳指" : (: ask_fengmo() :),
		]));

	set_skill("finger", 300);
	set_skill("force", 300);
	set_skill("strike", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("staff", 300);
	set_skill("cuff", 300);
	set_skill("literate", 300);
	set_skill("sun-finger", 300);
	set_skill("duanjia-jian",300);
	set_skill("duanshi-shenfa",300);
	set_skill("duanjia-xinfa",300);
	set_skill("qingyan-zhang", 300);
	set_skill("jinyu-quan", 300);
	map_skill("cuff","jinyu-quan");
	map_skill("staff","sun-finger");
	map_skill("dodge","duanshi-shenfa");
	map_skill("parry", "duanjia-jian");
	map_skill("force","duanjia-xinfa");
	map_skill("strike","qingyan-zhang");
	map_skill("finger","sun-finger");
	prepare_skill("finger","sun-finger");
	set("yiyangzhi/staff",1);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	}) );

	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/d/dalicheng/obj/zipao")->wear();
}

void attempt_apprentice(object ob)
{
  command("say 老夫从不收徒。\n");
  return;
}

int ask_fengmo()
{
	object me=this_player();
	//要通过一灯task
	mapping myfam;
  myfam = (mapping)me->query("family");
        
  if (myfam && myfam["family_name"] != "大理王府"){
    command("ah "+(string)me->query("id"));
    command("say "+ RANK_D->query_respect(me) +"这话从何说起？n");
    return 1;
  }
    
	return 1;
}

                                    
