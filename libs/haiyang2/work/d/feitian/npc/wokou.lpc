//shiren.c copy
//diabio(青云)2003.4.3
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void away();

string *name_1 = ({
"山本","龟田","姿三","大岛","松下","横田","东芝","候本","川野","山口",
"铃木","岗仓","小岛","井上","安奈","浅田","佐藤","广末","大竹","大村",
"伯佐","富冈","东乡",
});

string *name_2 = ({
"太郎","次郎","三郎","四郎","五郎","十一郎","十四郎","二十六","俊树",
"宁次","英机","冶字","俊雄","牧夫","光夫","敬一","英世","漱石","渝吉",
"一叶","子规","稻造","伊冲","松园","深水","大观","丰国","孝和","茂",
"川","卫","岛寿","光云","安治","山乐","梦二",
});

string *name_3 = ({
"三绝","神鹰","百毒","神拳","铁腕","无影","无名","绝灭",
"瘟疫","血影","暗杀","灭口","明王"
});

string *weapon = ({
"changjian","hammer","tiezhang","changbian","zhubang","changqiang","qimeigun","gangdao"
});

void create()
{
	set_name(name_1[random(sizeof(name_1))] + name_2[random(sizeof(name_2))], ({"wo kou", "wokou", "kou"}));
	set("gender", "男性");
	set("age", 26);
	set("title", HIR"海盗倭寇"NOR);
	set("long", 
		"海上的海盗倭寇，他正不怀好意的看着你。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 15);
	set("con", 20);
	set("dex", 25);
//       set("bac", 15);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jingli", 1000);
	set("max_jingli", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
       set("jiali", 40);
	
	set("combat_exp", 10000);
	
	set_skill("force", 100);
	set_skill("aikido", 100);
	set_skill("unarmed",100);
	set_skill("dodge", 100);  
        set_skill("blade", 100); 
	set_skill("shayi-xinfa", 100); 
	set_skill("wuxing-dun", 100); 
	set_skill("parry", 100); 
	set_skill("wuxing-dun", 100); 
	set_skill("aikido", 100); 
	set_skill("shayi-xinfa", 100); 
	set_skill("feitian-yujianliu", 100); 
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "feitian-yujianliu");	
	set("chat_chance", 20);
	set("chat_msg", ({
              "海盗倭寇喝道：杀！杀！杀！全部给我杀！！\n",
	}));
	
	setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/wushidao")->wield();

        add_money("silver", 30+random(30));
}
void init()
{
        remove_call_out("leave");
        call_out("leave",50);
}
void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "撤！一阵烟雾过后，倭寇不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
