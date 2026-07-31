#include <ansi.h>
int do_walk();
inherit NPC;
string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈","柳","风","刘","林", }); 
string *name_words = ({ "一","二","三","四","五","六","七","八","九","十", });
string *color_title = ({"[天杀门]杀手","[地煞门]杀手",});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["name":"武将",	"id":"wu jiang",	"mw":-1,	]),
(["name":"山贼头",	"id":"shan zeitou",	"mw":1,	]),
(["name":"客店伙计",	"id":"huo ji",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"仕卫",	"id":"shi wei",	"mw":1,	"weapon":"changqiang",	]),
(["name":"铁匠",	"id":"tie jiang",	"mw":1,	"weapon":"gangdao",	]),
(["name":"流氓头",	"id":"liumang tou",	"mw":-1,	"weapon":"gangjian",	]),
(["name":"贵公子",	"id":"gui gongzi",		"mw":1,	"weapon":"gangjian",	]),
(["name":"行者",	"id":"xing ze",	"mw":1,	"weapon":"gangdao",]),
(["name":"土匪头",	"id":"tufei tou",	"mw":-1,	"weapon":"changbian",	]),
(["name":"戏子",		"id":"xi zi",	"mw":-1,	"weapon":"lianzi",]),
(["name":"台夷商贩",	"id":"shang fan",		"mw":-1,	"weapon":"hammer",	]),
(["name":"江湖艺人",	"id":"yi ren",	"mw":1,	"weapon":"gangjian",]),
(["name":"砍竹人",	"id":"kanzu ren",	"mw":-1,	"weapon":"changbian",	]),
(["name":"猎人",		"id":"lie ren",	"mw":-1,	"weapon":"lianzi",]),
(["name":"台夷猎人",	"id":"old lieren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"牧羊人",	"id":"muyang ren",	"mw":1,	"weapon":"gangjian",]),
(["name":"农夫",	"id":"nong fu",	"mw":1,	"weapon":"gangjian",]),
(["name":"皮货商",	"id":"pihuo sang",	"mw":-1,	"weapon":"changbian",	]),
(["name":"石匠",		"id":"shi jiang",	"mw":-1,	"weapon":"lianzi",]),
(["name":"道人",	"id":"dao ren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"游客",	"id":"you ke",	"mw":1,	"weapon":"gangjian",]),
(["name":"书童",	"id":"shu tong",	"mw":1,	"weapon":"gangjian",]),
(["name":"绿营会众",	"id":"guan bing",	"mw":-1,	"weapon":"changbian",	]),
(["name":"员外",		"id":"yuan wai",	"mw":-1,	"weapon":"lianzi",]),
(["name":"比丘",	"id":"bi qiu",		"mw":-1,	"weapon":"hammer",	]),
(["name":"流氓",	"id":"liu mang",	"mw":1,	"weapon":"gangjian",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",20000);
	if( weapon)	set_skill("blade",20);
	set_skill("unarmed",20);
        set("tasknpc",1);
        set("dex",100);
	set_skill("sword",20);
	set_skill("club",20);
	set_skill("whip",20);
	set_skill("throwing",20);
	set_skill("parry",20);
	set_skill("dodge",20);
	set("shen_type",npc["mw"]);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
           (: random_move :),
           (: random_move :),
           (: random_move :),
        }) );

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 20+random(80));

        setup();
        set("check_time", time());
	carry_object("/clone/cloth/cloth")->wear();
//	if( weapon)
// 	carry_object("/clone/weapon/"+weapon)->wield();
	add_money("silver",50+random(50));
}
       
int do_walk()
{
        string start_room;
 string name,weapon;
        object room;
        object ob;
        mapping obmap;
        int n;
        int i;
	object *inv;
        if (! environment())
                return 0;
        name = color_title[random(sizeof(color_title))]+first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
//1800
//        if (time() - query("check_time") > 3600)
      if (time() - query("check_time") > 3000 && random(100)>98 || !query_heart_beat(this_object()))
        {
       set_name((order[random(13)])+name, ({ "killer", "shashou", "sha shou" }));
       set("gender", "男性");
       set("title", color_title[random(sizeof(color_title))]);
        n = 0;
	inv = all_inventory(this_object());

	for (i = 0; i < sizeof(inv); i++)
        {
                if (inv[i]->query("dynamic_quest"))
command("chat "+inv[i]->query("name")+(order[random(13)])+"我已经拿到手了。。。撤!!  \n"NOR);
        }

                        message_vision("$N笑了笑说：东西已经到手，任务完成，撤了！\n"NOR, this_object());
                        destruct(this_object());
                        return 0;
        }

        n = 0;
        foreach (ob in all_inventory(environment()))
        {
                if (!ob->query("dynamic_quest"))
                        continue;
        command ("get all");
                n++;
        }

                        
        random_move();
        return 1;
}

int accept_fight(object ob)
{
				command("say " + RANK_D->query_self(this_object())
					+ "怎么可能是" + RANK_D->query_respect(ob)
					+ "的对手？\n");
		  return 0;
}

int kill_ob(object ob)
{
		  command("fear");
		  command("say 不好，我被识破了!!");
//if (random(3)==1)
//{
command("say 逃啊!!");
//if (random(2)==1)
//{
command("go south");
command("go west");
//}
//else
//{
command("go north");
command("go east");
//}
//}
if (ob->query("combat_exp") > 1500000)
{
set("qi",2000);
set("jing",2000);
set("eff_qi",2000);
set("eff_jing",2000);
set("max_qi",2000);
set("max_jing",2000);
}
		  return 1;
}


