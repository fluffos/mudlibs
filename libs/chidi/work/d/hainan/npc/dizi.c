// 女弟子

inherit BHNPC;
string *names = ({"峭","冥","影","铁","馗","离","寒","飞","莱",});
void create()
{
	set_name(names[random(sizeof(names))]+"云", ({ "dizi","nv dizi" }) );

	set("gender", "女性");
	set("age", 15+random(10));
	

	set("long","白云庵传人,等闲不出江湖,所以不为人知。\n");
	create_family("白云庵", 4, "传人");
        set("chat_chance", 8);
        set("chat_msg", ({
                "听说师傅年轻时候在附近海中得到过一把宝刀,不知是什么样!\n",
                (: random_move :), 
                "小师妹不知道又躲到哪去了,到处都找不到.\n",
                (: random_move :), 
                "这几天老是有人闯进来,师傅叫我们多加留意!\n",
                (: random_move :) 
        }) );

	set_skill("unarmed", 350);
	set_skill("force", 350);
	set_skill("parry", 350);
	set_skill("dodge", 350);
	
set_skill("bitao-shengong",340);
	set_skill("baihua-zhang", 345);
	set_skill("feixian-jian",355);

	map_skill("unarmed", "baihua-zhang");
	map_skill("parry", "feixian-jian");
map_skill("force", "bitao-shengong");
	
	
	set("combat_exp",5000000);
	set("score",1000);
	
	set("inquiry", ([
		"here" : "这里就是海南白云庵呀,你居然不知道么?",
	"梵音神尼":"我师傅啊,她老在经堂,也不出来!",
	]) );	

	setup();
	carry_object("/d/hainan/obj/shaqun")->wear();
       carry_object("/d/hainan/obj/roujing_sword")->wield();
            add_money("silver",5);
}
