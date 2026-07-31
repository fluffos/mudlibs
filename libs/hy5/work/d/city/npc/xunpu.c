// yamen_police.c
#include <ansi.h>
inherit NPC;

void create()
{
     string *surname=({"慕容","西门","公孙","上官","南宫","欧阳","司徒","紫云","流星",});
     set_name(surname[random(sizeof(surname))]+"巡捕", ({ "xun bu","police"}) );
     set("gender", "男性" );
     set("no_get",1);
     set("no_put",1);
     set("age", 25);
     set("str", 65);
     set("cor", 60);
     set("dex", 60);
     set("cps", 65);
     set("int", 60);
     set("per", 60);
     set("kar", 65);
     set("long",@LONG
巡捕个个身手矫健，强盗、山贼无不闻风丧胆。
LONG
); 
     set("combat_exp", 5000000);
     set("attitude", "heroism");
     set ("inquiry",([
                "bribery":
"说哪里话来，县太爷清贫廉正，我们作手下的岂能辱没他的名声？\n"+
"收起你的钱吧！\n",
                "salary":
"哎，老爷俸银微薄，我们的年饷自然更少了......\n",
                "money":
"说实在的，我也想要钱。但要是让老爷知道了我收受贿赂(give)，\n不死也得扒层皮\n
",
                        ]));
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
        	(: command("unwield sword") :),
                  (: perform_action, "parry.xiaohun" :),
                (: perform_action, "parry.jingtao" :),
                (: perform_action, "parry.sad" :),
                (: perform_action, "parry.anran" :),
                (: perform_action, "sword.feihongrudian" :),
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "sword.botao" :),
                (: perform_action, "sword.lei" :),
                (: perform_action, "sword.juan" :),
                (: perform_action, "sword.dong" :),
                (: perform_action, "sword.dang" :),
                (: perform_action, "sword.hai" :),					
                (: perform_action, "sword.qianjun" :),						

        }) );
     set ("chat_chance",50);
     set ("chat_msg", ({
                      (:call_out,"patrol",0:),
                      }) );
     set("pursuer",1);
        set("jing",20000);
        set("max_jing",20000);
        set("eff_jing",20000);
        set("qi",20000);
        set("max_qi",20000);
        set("eff_qi",20000);
        set("neili",20000);
        set("max_neili",20000);
	set("jiali",50);
	set_skill("sword", 300);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("anranxiaohun-zhang",400);
	set_skill("xuantie-sword", 450);
	set_skill("xiantian-qigong", 400);
	set_skill("yunv-shenfa",400);
	set_skill("yunv-xinfa",400);
	set_skill("yunv-shenfa",400);
        set_skill("yunv-jian", 420);  
        set_skill("tianluo-diwang", 420); 
                set_skill("meinv-quan", 420); 
                        set_skill("wuzhan-mei", 420); 
                                set_skill("yinsuo-jinling", 420);   

	map_skill("sword", "xuantie-sword");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "yunv-shenfa");
	map_skill("force", "yunv-xinfa");
     setup();
     //carry_object("/quest/shenshu/book1test");
     carry_object("/clone/weapon/changjian")->wield();
     carry_object("/clone/misc/cloth")->wear();
     add_money("silver",30);
}
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
	ob->apply_condition("qx_snake_poison",220);
                ob->start_busy(6);
		remove_call_out("kill_ob");
		call_out("follow_ob", 0, ob);
		call_out("kill_ob", 0, ob);
command("kill "+ob->query("id"));
	}
}
void unconcious()
{
    die();
}
int hit_ob(object me, object ob, int damage)
{

if (ob=me)
{
me->add("qi",me->query("max_qi")/20);
me->add("eff_qi",me->query("max_qi")/20);
me->add("jing",me->query("max_jing")/20);
me->add("eff_jing",me->query("max_jing")/20);
me->set("neili",me->query("max_neili"));
}

if (ob!=me)
{
if (me->is_busy())
me->start_busy(1);
ob->start_busy(5);

	ob->apply_condition("qx_snake_poison", 220);
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "你觉得被砍中的地方一阵麻痒！\n" NOR );
}
}


int accept_object(object who, object ob)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount,p;
	string wiz_status;
	obj=this_object();
p=0;
        if (! ob->query("money_id"))
        {
               command("say 这玩艺我可没啥兴趣！");
               return 0;
        }

        if (ob->value() < 20000000)
        {
		command("shake " + who->query("id"));
                command("say 说哪里话来，县太爷清贫廉正，我们作手下的岂能辱没他的名声？");
                return 0;
        }

        command("say 唉！哎，老爷俸银微薄，我们的年饷自然更少了......我就通一次人情吧！");
//command("give silver to hxsd");
		inv = all_inventory(obj);
		for(i=0; i<sizeof(inv); i++) {
if(inv[i]->query("dynamic_quest"))
{
message("channel:chat", HIC"【神书信息】"GRN + who->query("name")+"得到"+HIR"神书:" + inv[i]->query("name")+HIG"啦！\n"NOR,users() );
inv[i]->move(who);
p=1;
}
		}

        if (p ==0 && !ob->query_condition("killer"))
        {
		command("shake " + who->query("id"));
                command("say 我没什么可以帮你的! ");
                return 0;
        }

        if (ob->value() >= 50000000)
{
    command("say 唉！走吧，不要再让我看到......");
        	 who->clear_condition("killer");
}
//      destruct(ob);
        return 1;
}
