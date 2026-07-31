//shiren.c copy
//diabio(青云)2003.4.3
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

string *name_3 = ({
"三绝","神鹰","百毒","神拳","铁腕","无影","无名","绝灭",
"瘟疫","血影","暗杀","灭口","明王"
});

string *weapon = ({
"changjian","hammer","tiezhang","changbian","zhubang","changqiang","qimeigun","gangdao"
});

void create()
{
	set_name(name_1[random(sizeof(name_1))] + name_2[random(sizeof(name_2))], ({"bai xing", "bai", "xing"}));
	set("gender", "男性");
	set("age", 26);
	set("long", 
		"普通的百姓正礼貌的冲着你笑。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 15);
	set("con", 20);
	set("dex", 25);
	set("bac", 15);

	set("qi", 300);
	set("max_qi", 300);
	set("jingli", 100);
       set("jiali", 100);
	
	set("combat_exp", 1000);
	
	setup();
            carry_object(__DIR__"obj/shoes")->wear();
           carry_object(__DIR__"obj/hefu")->wear();
	set("chat_chance", 10);
	set("chat_msg", ({
                                         "百姓礼貌的冲你打了个招呼！！\n",
                        (: random_move :)          
                                     
	}));
        add_money("silver", 10+random(30));
}
