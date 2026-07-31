// ssdizi.c  嵩山弟子

#include <ansi.h>
inherit NPC;

string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈", "刘","林",
"冯","卫","蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","余"});
string *first_name_id = ({ "zhao","qian","sun","li","zhou","wu","zheng","wang","zhang","chen", "liu","lin",
"feng","wei","jiang","shen","han","yang","zhu","qin","you","xu","he","lv","shi","yu" });
string *name_words = ({ "顺","昌","振","发","财","俊","良","志","忠", "孝","雄","益","添","金",
"辉","长","盛","胜","进","安","福","同","满", "富","万","龙","隆","祥","栋","国","亿","寿","杨",
"藤","殷","罗","华","安","常","珏" });
string *name_words_id = ({ "shun","chang","zhen","fa","cai","jun","liang","zhi","zhong", "xiao","xiong","yi","tian","jin",
"hui","chang","sheng","sheng","jin","an","fu","tong","man", "fu","wang","long","long","xiang","dong","guo","yi","shou","yang",
"teng","yin","luo","hua","an","chang","jue" });

void create()
{
	string name , name_word;
	int i, j, k;

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

       set_name(name, ({ first_name_id[i]+" "+name_word, first_name_id[i], name_word }) );
       i = random(3)+1;
       set("gender", "男性" );
       set("shen_type", 1);
       set("age", 25);
       set("per", 12+random(15));
       set("str", 25);
       set("con", 15);
       set("int", 20);
       set("dex", 20);
       set("combat_exp", 10000*i);
       set("attitude", "peaceful");
       set("inquiry", ([
               "嵩山派" : "我们嵩山派是五岳剑派之首！\n",
               "五岳剑派" : "我们五岳剑派在武林之中势力巨大，可与少林、武当抗衡。\n",
               "左冷禅" : "他就是我们的掌门人，功夫深不可测。\n",
       ]) );
       set_skill("force", 20*i);
       set_skill("songshan-qigong", 20*i);
       set_skill("dodge", 20*i);
       set_skill("zhongyuefeng", 20*i);
       set_skill("strike", 20*i);
       set_skill("songyang-zhang", 20*i);
       set_skill("parry", 20*i);
       set_skill("sword", 20*i);
       set_skill("songshan-jian", 20*i);
       set_skill("literate", 20);
       map_skill("force", "songshan-qigong");
       map_skill("dodge", "zhongyuefeng");
       map_skill("strike", "songyang-zhang");
       map_skill("parry", "songshan-jian");
       map_skill("sword", "songshan-jian");
       prepare_skill("strike", "songyang-zhang");
       set("max_qi", 500);
       set("max_jing", 300);
       set("eff_jingli", 500);

       create_family("嵩山派", 5, "弟子");
       setup();

       carry_object(BINGQI_D("changjian"))->wield();
       carry_object(ARMOR_D("changpao1"))->wear();
}
