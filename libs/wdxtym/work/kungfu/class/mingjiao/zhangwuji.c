//zhangwuji.c

inherit F_MASTER;
inherit F_QUESTER;
inherit F_UNIQUE;
inherit NPC;

#include <ansi.h>
#include "mingjiao.h"

void greeting(object ob);
string ask_ling();
int ask_pfm(string);
int accept_ask2(object me, string topic);

void create()
{
    seteuid(getuid());
    set_name("张无忌", ({ "zhang wuji", "zhang", "wuji" }));
    set("long", @LONG
明教教主张无忌，统领天下十万教众，豪气干云，叱咤千秋，
「九阳神功」、「乾坤大挪移」独步天下，是江湖中不世出的
少年英雄。
LONG );
    set("title",HIG "明教" HIM " 教主" NOR);
    set("gender", "男性");
    set("age", 20);
	set("no_get", 1);
    set("shen_type",1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("str", 33);
    set("int", 35);
    set("con", 38);
    set("dex", 33);

	set("qi", 580000);
	set("max_qi", 580000);
	set("jing", 27000);
	set("max_jing", 27000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 120);

    set("combat_exp", 2900000);
    set("score", 455000);
    
        set_skill("force", 3000);
        set_skill("unarmed", 3000);
        set_skill("dodge", 3000);
        set_skill("parry", 3000);
        set_skill("cuff", 3000);
        set_skill("sword", 3000);
        set_skill("blade", 3000);
        set_skill("strike", 3000);
        set_skill("claw", 3000);
        set_skill("throwing", 3000);
        // set_skill("duoming-jinhua", 450);
        set_skill("jiuyang-shengong", 3000);
        set_skill("shenghuo-xinfa", 3000);
        set_skill("shenghuo-shengong", 3000);
        set_skill("lingxu-bu", 3000);
        set_skill("shenghuo-bu", 3000);
        set_skill("qingfu-shenfa", 3000);
        set_skill("qiankun-danuoyi", 3000);
        set_skill("qishang-quan", 3000);
        set_skill("taiji-quan", 3000);
        set_skill("taiji-jian", 3000);
        set_skill("taiji-dao", 3000);
        set_skill("lieyan-dao", 3000);
        set_skill("liehuo-jian", 3000);
        // set_skill("yingzhua-shou", 450);
        // set_skill("hanbing-mianzhang", 450);
        set_skill("shenghuo-ling", 3000);
        set_skill("guangming-zhang", 3000);
        set_skill("medical", 300);
        set_skill("literate", 300);
        set_skill("martial-cognize", 3000);
        set_skill("guangming-jing", 3000);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("unarmed", "jiuyang-shengong");
        map_skill("strike","guangming-zhang");
        map_skill("cuff", "qishang-quan");
        map_skill("sword","shenghuo-ling");
        map_skill("parry","qiankun-danuoyi");
        map_skill("blade","taiji-dao");
        // map_skill("claw", "yingzhua-shou");
        // map_skill("throwing", "duoming-jinhua");
        // map_skill("strike", "hanbing-mianzhang");

        prepare_skill("cuff", "qishang-quan");

    create_family("明教", 34, "教主");
        set_temp("apply/attack", 180);
        set_temp("apply/damage", 180);
        set_temp("apply/unarmed_damage", 180);
        set_temp("apply/armor", 180);
    
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: command("perform sword.hua") :),
                (: command("perform sword.xi") :),
                (: command("perform sword.lian") :),
                (: command("perform sword.can") :),
                (: command("perform cuff.shang") :),
                (: command("perform cuff.fei") :),
                (: command("yun shield") :),
                (: command("yun powerup") :),
                (: command("yun recover") :),
        }) );
	   
    set("chat_chance", 1);
    set("chat_msg", ({
	"张无忌愤然说道“大丈夫当以国为家, 捐躯沙场, 抗元大业未成, 同辈仍需努力!”\n",
	"张无忌叹道“人生失一知己, 生亦何欢, 死亦何忧, 敏儿, 你在哪里?”\n",
	"张无忌道“我教兄弟听了: 生于乱世, 当克己为公, 行侠仗义, 荡寇驱魔!”\n",
    }));

    set("inquiry",([
	  "明教" :     "你打听我们明教做什么？。\n",
	  "金毛狮王" : "那是我义父谢大侠的职司。\n",
	  "谢逊" :     "他就是我义父的大号。\n",
	  "张翠山" :   "你想找我父亲有事麽? \n",
	  "殷素素" :   "我妈是明尊座下紫微堂主。\n",
	  "张三丰" :   "我太师父近来可好? \n",
	  "赵敏" :     "人生失一知己, 生亦何欢, 死亦何忧, 敏儿, 你在哪里?\n",
	  "小昭" :     "小昭我可一直念着她的好处。\n",
	  "周芷若" :   "找她就去峨嵋山, 别来烦我。\n",
		"#1-铁焰令"   : (: ask_ling :),
		"#11-九曦混阳"  : (: ask_pfm("九曦混阳") :),
		"#21-骄阳劈天"  : (: ask_pfm("骄阳劈天") :),
		"#31-混沌一阳"  : (: ask_pfm("混沌一阳") :),
		"#41-金阳破岭"  : (: ask_pfm("金阳破岭") :),
		"#51-魔光日无极"  : (: ask_pfm("魔光日无极") :),
    ]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	// carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/book/shenghuo-ling")->wield();
	add_money("silver", 70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		this_player()->add_temp("beat_count", 1);
	}       
	if (interactive(ob=this_player()) && ! is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}
int ask_pfm(string arg)
{
	if (arg) {
		object me = this_player();
		
		return accept_ask2(me, arg);
	}
	return 1;
}

void greeting(object ob)
{
	if (! ob || environment(ob)!=environment()) return;
	if ((int)ob->query("shen") < -50000)
	{
		command("wield yitian jian");
		command("hit" + (string)ob->query("id"));
		command("unwield yitian jian");
	} else
	if ((int)ob->query("shen") < -5000)
	{
		command("say 魔从心起，于武学不利，其道必诛，劝君放下屠刀，"
			"立地成佛。");
	} else
	if((int)ob->query("shen") < -100)
	{
		command("say 这位朋友，人行江湖，言行当正，切务走进邪魔歪道。");
	} else
	if((int)ob->query("shen") >= 0)
	{
		command("say 光明正道任人走，劝君多加保重。");
	} else
	if((int)ob->query("shen") > 50000)
	{
		command("say 大侠在上，受无忌一礼，大侠它日必为武林翘楚。");
	}
	return;
}
void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping ob_fam;
        mapping my_fam = me->query("family");

        string name, new_name;

        if (! permit_recruit(ob))
                return;

        if( !(ob_fam=ob->query("family")) || ob_fam["family_name"] != "明教" )
        {
                command("say " + RANK_D->query_respect(ob) + "与本教素无来往，不知此话从何谈起？");
                return;
        }
/*
        if ( ob_fam["generation"] > my_fam["generation"] + 2)
        {
                command("say " + RANK_D->query_respect(ob) + "，你先去找教内其他兄弟好好学学武功吧。");
                return;
        }
*/
        if( ob->query("shen")<100000 )
        {
                command("say 你行侠仗义的事做得还不够，还是请回吧。");
                return;
        }

        if( ob->query("combat_exp")<1000000 )
        {
                command("say 你的修为太少，好好再去江湖闯荡闯荡，可别给我明教丢脸啊 !");
                return;
        }

        command("say 恩，好！本教又培养出一位江湖高手，真是可喜可贺 !");

        command("say 恭喜你荣升为明教光明使者！");
        command("recruit "+ob->query("id"));

        return;
}

int accept_fight(object ob)
{
	if ((ob->query("combat_exp") < 30000) && (ob->query("shen") > 0))
	{
		message_vision("武林中人最忌争强斗狠，你不是我的对手，"
			       "回去吧。\n",ob);
		return 0;
	}
	message_vision("张无忌一拱手说道：这位" + RANK_D->query_respect(ob) +
		       "，在下领教了。\n", ob);
	return 1;
}
string ask_ling()
{
	mapping family, skl; 
	string *sname;
	object ob;
	int i;
	
	if ( !(family = this_player()->query("family")) || family["family_name"] !=  "明教" )
		return RANK_D->query_respect(this_player()) + "与本教素无来往，不知此话从何谈起？";

	skl = this_player()->query_skills();
	sname  = sort_array( keys(skl), (: strcmp :) );

	ob = new("d/mingjiao/obj/tieyanling");
	ob->move(this_player());
	message_vision("$N要得一面铁焰令。\n",this_player());

	return "好吧，凭这面铁焰令，你可自由向你的尊长挑战。";

}

int accept_ask2(object me, string topic)
{
	int gongxian = me->query("gongxians");
	if(!gongxian>20000)
		return notify_fail("你师门贡献不够。");
	if (me->query("can_skill/jiuyang-shengong") && me->query("family/family_name") == "明教")
	switch (topic)
	{
        case "九曦混阳" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/jiu",
                           "name"    : "九曦混阳",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 80,]));
                break;

        case "骄阳劈天" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/pi",
                           "name"    : "骄阳劈天",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 120,]));
                break;
        case "混沌一阳" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/hun",
                           "name"    : "混沌一阳",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 180,]));
                break;
        case "金阳破岭" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/po",
                           "name"    : "金阳破岭",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 200,
                           "sk2"     : "martial-cognize",
                           "lv2"     : 200,]));
                break;
        case "魔光日无极" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/ri",
                           "name"    : "魔光日无极",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 250,
                           "sk2"     : "martial-cognize",
                           "lv2"     : 250,]));
                break;

        default:
			break;
	}
	tell_object(me, name()+"：你说什么？再说一遍？\n");
	return 1;
}
