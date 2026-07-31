// npc dizi.c 弟子
// diabio(青云)2003.3.5

inherit NPC;
inherit F_MASTER;

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

void create()
{
	set_name(name_1[random(sizeof(name_1))] + name_2[random(sizeof(name_2))], ({"luo ren", "luoren"}));
	set("gender", "男性");
	set("age", 26);
	set("title", "落人村民");
	set("long", 
		" 落人村的村民，正带着敌视的眼光看着你。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 15);
	set("con", 20);
	set("dex", 25);
	set("bac", 15);

	set("qi", 300);
	set("max_qi", 300);
	set("jingli", 200);
	set("max_jingli", 200);
	set("neili", 100);
	set("max_neili", 100);
       set("jiali", 30);
	
	set("combat_exp", 1000);
	
	set_skill("force", 10);
	set_skill("aikido", 10);
	set_skill("unarmed",10);
	set_skill("dodge", 10);  
	
	setup();
	set("chat_chance", 5);
	set("chat_msg", ({
              "落人村民道：明治政府的走狗们都该去死？\n",
              "落人村民用敌视的眼光看着你......\n",
	}));
        add_money("silver", 10+random(30));
}

