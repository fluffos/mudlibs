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
(["name":"仕卫",	"id":"she wei",	"mw":1,	"weapon":"changqiang",	]),
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
	if( weapon)	set_skill("blade",50);
	set_skill("unarmed",50);
	set_skill("sword",50);
	set_skill("club",50);
	set_skill("whip",50);
	set_skill("throwing",50);
	set_skill("parry",50);
	set_skill("dodge",50);
	set("shen_type",npc["mw"]);

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 20+random(80));

        setup();
	carry_object("/clone/cloth/cloth")->wear();
}
       
