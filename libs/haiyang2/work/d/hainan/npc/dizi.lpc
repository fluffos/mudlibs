// 女弟子

inherit NPC;
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

	set_skill("unarmed", 150);
	set_skill("force", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	
	set_skill("sword", 150);
		set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",220);
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	

	
	set("combat_exp",50000);
	set("mingwang",1000);
	
	set("inquiry", ([
		"here" : "这里就是海南白云庵呀,你居然不知道么?",
	"梵音神尼":"我师傅啊,她老在经堂,也不出来!",
	]) );	

	setup();
	carry_object("/d/hainan/obj/shaqun")->wear();
       carry_object("/d/hainan/obj/roujing_sword")->wield();
            add_money("silver",5);
}
