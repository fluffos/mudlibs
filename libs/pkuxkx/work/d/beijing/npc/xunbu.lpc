// xunbu.c

inherit NPC;
#include "/d/beijing/autok.h"

void create()
{
     string *surname=({	"慕容","西门","公孙","上官","南宫","欧阳","司徒","紫云","流星",
     			"司马","上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫",
			"尉迟","公羊","澹台","公治","宗政","濮阳","淳于","单于","太叔",
			"申屠","公孙","仲孙","辕轩","令狐","钟离","宇文","长孙","幕容",
			"司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷",
			"公良","拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦",
			"段千","百里","东郭","南郭","呼延","归海","羊舌","微生","梁丘",
			"左丘","东门","西门","佰赏","南官",});
     set_name(surname[random(sizeof(surname))]+"巡捕", ({ "xun bu","police", "bu"}) );
     set("title", "朝廷鹰犬");
     set("gender", "男性" );
     set("age", 25 + random(20));
     set("str", 25 + random(20));
     set("int", 90);
     set("per", 15 + random (20));
     set("kar", 95);
     set("long",@LONG
巡捕个个身手矫健，强盗、山贼无不闻风丧胆。
LONG
);

     set("CatchWho",0);
     set("follow_killer", 1);//查看autok.h
     set("combat_exp", 1000000 + random(2000000));
     set("attitude", "friendly");
     set("startroom","/d/beijing/zijin/tianansquare");
     set("chat_chance_combat", 100);
     set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "blade.kuang" :),
                            }) );
     set ("inquiry",([
                "bribery":
"说哪里话来，县太爷清贫廉正，我们作手下的岂能辱没他的名声？\n"+
"收起你的钱吧！\n",
                "salary":
"哎，老爷俸银微薄，我们的年饷自然更少了......\n",
                "money":
"说实在的，我也想要钱。但要是让老爷知道了我收受贿赂(bribery)，\n不死也得扒层皮\n
",
                        ]));
     set ("chat_chance", 30);
     set ("chat_msg", ({
                      (: random_move :)
                      }) );
     set("pursuer",1);
	set_skill("force", 100 + random(200));
	set_skill("dodge", 100 + random(200));
	set_skill("cuff", 100 + random(200));
	set_skill("strike",100 + random(200));
	set_skill("hand",100 + random(200));
	set_skill("parry", 100 + random(200));
	set_skill("blade",100 + random(200));
	set_skill("sword",100 + random(200));
	set_skill("staff",100 + random(200));
	set_skill("whip",100 + random(200));
	set_skill("axe",100 + random(200));
	set_skill("halberd",100 + random(200));
	set_skill("spear",100 + random(200));
	set_skill("claw",100 + random(200));

    	set_skill("bixue-xinfa", 180 + random(200));
    	set_skill("longfeng-xiang", 100 + random(200));
    	set_skill("qingmang-jian", 100 + random(200));
    	set_skill("juemen-gun", 100 + random(200));
    	set_skill("fenglei-dao", 100 + random(200));
    	set_skill("taizu-quan", 100 + random(200));
    	set_skill("kuangfeng-dao", 180 + random(200));
    	set_skill("kuangfeng-jian", 100 + random(200));
    	set_skill("lujia-ji", 100 + random(200));
    	set_skill("bainiao-qiangfa", 100 + random(200));
    	set_skill("huzhua-shou", 100 + random(200));
    	set_skill("juehu-zhang", 100 + random(200));
    	set_skill("kuihua-zhua", 100 + random(200));
    	set_skill("duanyun-bian", 100 + random(200));
    	set_skill("leiting-axe", 100 + random(200));

    	map_skill("force", "bixue-xinfa");
    	map_skill("sword", "kuangfeng-jian");
    	map_skill("blade", "kuangfeng-dao");
    	map_skill("dodge", "longfeng-xiang");
    	map_skill("strike", "juehu-zhang");
    	map_skill("parry", "huzhua-shou");
    	map_skill("hand", "huzhua-shou");
    	map_skill("whip", "duanyun-bian");
    	map_skill("halberd", "lujia-ji");
    	map_skill("axe", "leiting-axe");
    	map_skill("claw", "kuihua-zhua");
    	map_skill("staff", "juemen-gun");
    	map_skill("spear", "bainiao-qiangfa");
    	map_skill("cuff", "taizu-quan");

    	prepare_wskill("sword", "kuangfeng-jian");
    	prepare_wskill("blade", "kuangfeng-dao");

    	prepare_skill("strike", "juehu-zhang");
    	prepare_skill("hand", "huzhua-shou");

	 set("neili", 2800);
	 set("max_neili", 2800);
	 set("max_qi", 2000);
	 set("eff_qi", 2000);
	 set("qi", 2000);

	 set("jiali", 150);

        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        set_temp("apply/attack", 300);
        set_temp("apply/defense", 800);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 100);
        create_family("朝廷", 7, "官员");
        set("pin", 5);
        set("class", "officer");
     setup();
     carry_object("/clone/weapon/changjian")->wield();
     carry_object("/clone/weapon/gangdao")->wield();
     carry_object(__DIR__"obj/junfu")->wear();
     add_money("silver",30);
}
void init()
{
	object ob;
	::init();
        if(!query_heart_beat())
        	set_heart_beat(1);
	command("open door");
 	command("open men");
    	auto_kill(this_player());
}
