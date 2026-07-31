#include <ansi.h>
inherit NPC;
string *first_name = ({
"如", "若", "慧", "素", "贤", "佳", "文", "淑","瑞","妙","柔","翠","筱",
});
string *first_name_id = ({
"ru", "ruo", "hui", "su", "xian", "jia", "wen", "shu", "rui", "miao", "rou", "cui", "xiao",
});

string *name_words = ({
"梅", "兰", "竹" ,"菊", "云", "雨", "雾", "雯","雪","玫","玉","敏","萍",
});

string *name_words_id = ({
"mei", "lan", "zhu", "ju", "yun", "yu", "wu", "wen", "xue", 
"mei", "yu", "min", "ping", 
});
                               
void create()
{
	int i,j,k;
	string name,name_word;
	i = random(sizeof(first_name));
	name = first_name[i];
       
	j = random(sizeof(name_words));
	name += name_words[j]; 
	name_word = name_words_id[j];

	if( random(10) > 5 ){
		k = random(sizeof(name_words));
		name += name_words[k];
		name_word = name_word + name_words_id[k];
	}

	set_name(name, ({ first_name_id[i]+" "+name_word, first_name_id[i], name_word}) );
	set("title", HIY"灵鹫宫侍女"NOR);
	set("long", "这是一名"+this_object()->query("title")+"，名叫"+this_object()->query("name")+"。\n");
	set("gender", "女性" );
	set("age", 15+random(10));
	set("per",25+random(5));
	set("attitude", "peaceful");

	set("str",15+random(13));
	set("int",20);
	set("con",15+random(12));
	set("dex",15+random(10));
	set("max_qi", 300+random(200));
	set("max_jing", 200)+random(200);
	set("neili", 250+random(200));
	set("max_neili", 250+random(200));
	set("combat_exp", random(6000)+20000);

	create_family("灵鹫宫",4,"弟子");
        set_skill("force", 25+random(15));
        set_skill("bahuang-gong", 30);
        set_skill("dodge", 25+random(15));
        set_skill("pinxu-lingfeng", 30);
        set_skill("strike", 25+random(15));
        set_skill("liuyang-zhang", 30);
        set_skill("parry", 25+random(15));
	set_skill("literate", 60);

        map_skill("force", "bahuang-gong");
        map_skill("dodge", "pinxu-lingfeng");
        map_skill("parry", "liuyang-zhang");
        map_skill("strike", "liuyang-zhang");
        prepare_skill("strike", "liuyang-zhang");

	set("shen_type", 0);
	set("inquiry", ([
		"name": "奴家叫做"+this_object()->name()+"，从十五岁起便投在这里学艺。",
		"rumors": "最近很少见到宫主。",
		"here": "这里是灵鹫宫，你没事还是不要随便乱转的好。",
		"灵鹫宫": "这里就是灵鹫宫啊？！",
	]));
	setup();
	carry_object(__DIR__"obj/f-cloth")->wear();
}  

#include "npc.h"
