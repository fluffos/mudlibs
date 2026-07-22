// Npc: /d/tianshan/npc/f-dizi.c
// By Linux

#include <ansi.h>

inherit NPC;

string *first_name = ({ "赵","何","谢","李","苏","吴","郑","文","张","陈","刘","林" }); 
string *first_name_id = ({
"zhao","he","xie","li","su","wu","zheng","wen","zhang","chen","liu","lin"});
string *name_words = ({
"春","丹","芳","芬","凤","姑","红","虹","娇","娟","菊","兰","岚","丽",
"莉","莲","玲","琳","娜","琴","芹","倩","萍","婷","霞","香","艳","燕",
"英","瑛","玉","珍","珠",
});
string *name_words_id = ({ 
"chun","dan","fang","fen","feng","gu","hong","hong","jiao","juan","ju","lan","lan","li",
"li","lian","ling","lin","na","qin","qin","qian","ping","ting","xia","xiang","yan","yan",
"ying","ying","yu","zhen","zhu", });

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
	set("gender", "女性" );
	set("age", 15+random(10));
	set("per",25+random(5));
	set("attitude", "peaceful");
	set("str",15+random(13));
	set("int",20);
	set("con",15+random(12));
	set("dex",15+random(10));
	set("max_qi", 400+random(200));
	set("eff_jingli", 400);
	set("max_jing", 200)+random(200);
	set("max_neili", 750+random(200));
	set("combat_exp", random(16000)+25000);

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

void init()
{
	object me=this_object();
	string room;
	room=environment(me)->query("short");
	switch (room) {
		case "昊天部":
			me->set("title",WHT"灵鹫宫昊天部弟子"NOR);
		break;
		case "阳天部":
			me->set("title",HIC"灵鹫宫阳天部弟子"NOR);
		break;
		case HIR"赤天部"NOR:
			me->set("title",HIR"灵鹫宫赤天部弟子"NOR);
		break;
		case "朱天部":
			me->set("title",HIR"灵鹫宫朱天部弟子"NOR);
		break;
		case "成天部":
			me->set("title",HIG"灵鹫宫成天部弟子"NOR);
		break;
		case "幽天部":
			me->set("title",HIY"灵鹫宫幽天部弟子"NOR);
		break;
		case "鸾天部":
			me->set("title",HIB"灵鹫宫鸾天部弟子"NOR);
		break;
		case "钧天部":
			me->set("title",HIW"灵鹫宫钧天部弟子"NOR);
		break;
		case "玄天部":
			me->set("title",MAG"灵鹫宫玄天部弟子"NOR);
		break;
		default:
    			me->set("title",WHT"灵鹫宫弟子"NOR);
    		break;
	}
	set("long", "这是一名"+this_object()->query("title")+"，名叫"+this_object()->query("name")+"。\n");
}

#include "npc.h";
