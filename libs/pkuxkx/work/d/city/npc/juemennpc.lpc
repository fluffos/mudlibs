// 多铎
inherit NPC;
#include <ansi.h>

int ask_fight();
int perform();
int askforhelp();

void create()
{
	set_name("闷棍测试砖家", ({ "tester", "zhuanjia"}));
	set("title",HIW"扣扣保镖 "HIY"360杀手"NOR);
	set("gender","男性");
	set("age", 20+random(5));

	
	set("attitude", "peaceful");
	set("combat_exp", 5000000);
	set("str", 20+random(5));
	set("int", 20+random(5));
	set("con", 20+random(5));
	set("dex", 20+random(5));
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("max_neili", 20000);
	set("neili", 5000);
	set("neili", 20000);
	set_temp("apply/armor", 100);
	set("jingli", 20000);
	set("max_jingli", 20000);
	set_skill("strike", 500);
	set_skill("cuff", 500);
	set_skill("hand", 500);
	set_skill("dodge", 500);
	set_skill("sword", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
	set_skill("blade", 500);
	set_skill("hammer", 500);
	set_skill("axe", 500);
	set_skill("staff", 500);
	set_skill("literate", 500);
	set_skill("whip", 500);
	set("no_get", 1);
    set("chaoting/wang",1);
    set("pin",1);
    set("chaoting/catch_feizei",500);
	add("inquiry", ([
		
		"测试" : (: ask_fight:),
        "fight" : (:ask_fight:),
	]));
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform :)
        }) );
    
	setup();
	
	carry_object(__DIR__"items/cloth3")->wear();
	carry_object("/clone/weapon/staff/shawei")->wield();
	
}



int perform()
{
    command("perform staff.shawei");
}
int copy(object me)
{
	object ob=this_object();
	int i;
	int exp,exp2,lv,qi;
	
	exp = me->query("combat_exp");
	lv=to_int(ceil(pow(to_float(exp)*10,0.3333333333)));
	ob->set_skill("dodge",lv);
	ob->set_skill("parry",lv);
	ob->set_skill("force",lv);
	ob->set_skill("claw",lv);
	ob->set_skill("longfeng-xiang",lv);
	ob->set_skill("bixue-xinfa",lv);
	ob->set_skill("kuihua-zhua",lv);
	ob->set_skill("juemen-gun",lv);
	ob->set_skill("staff",lv);
	ob->map_skill("force", "bixue-xinfa");
	ob->map_skill("dodge", "longfeng-xiang");
	ob->map_skill("claw", "kuihua-zhua");
	ob->map_skill("parry", "kuihua-zhua");
	ob->map_skill("staff", "juemen-gun");
	ob->prepare_skill("claw", "kuihua-zhua");

	ob->set("max_qi", me->query("max_qi"));
	ob->set("qi",  me->query("max_qi"));
	ob->set("max_jing", me->query("max_jing")*3/2);
	ob->set("jing", me->query("max_jing")*3/2);
	ob->set("max_neili", me->query("max_neili")*3/2);
	ob->set("neili", me->query("max_neili")*3/2);
	ob->set("combat_exp", exp*11/10);
	ob->set("max_jingli", me->query("max_jingli"));
	ob->set("jingli", me->query("max_jingli"));
  ob->fullme();
}

int ask_fight()
{
    object me=this_player();
    object ob=this_object();
    copy(me);
    me->fight_ob(ob);
    ob->fight_ob(me);
    return 1;
}