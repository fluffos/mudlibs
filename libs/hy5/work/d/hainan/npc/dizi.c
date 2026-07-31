// 女弟子

inherit NPC;
string *names = ({"峭","冥","影","铁","馗","离","寒","飞","莱",});
void create()
{
//	set_name(names[random(sizeof(names))]+"云", ({ "dizi","nv dizi" }) );
set_name("白云庵女弟子", ({ "dizi","nv dizi" }) );
	set("gender", "女性");
	set("age", 15+random(10));
	

	set("long","白云庵传人,等闲不出江湖,所以不为人知。\n");
	create_family("白云庵", 4, "传人");
        set("chat_chance", 8);
        set("chat_msg", ({
                "听说师傅年轻时候在附近海中得到过一把宝刀,不知是什么样!\n",
               
                "小师妹不知道又躲到哪去了,到处都找不到.\n",
  
                "这几天老是有人闯进来,师傅叫我们多加留意!\n",

        }) );

	set_skill("unarmed", 150);
	set_skill("force", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	
    set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
  
set_skill("demon-strike",280);
set_skill("yubi-jian",280);
set_skill("zhuifeng-quan",280);
set_skill("bitao-shengong",280);
set_skill("baihua-zhang",280);
set_skill("feixian-jian",280);
set_skill("qiongya-bufa",280);

        set_skill("literate",280);
        set_skill("unarmed",280);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",280);
	set_skill("blade",280);
	set_skill("changquan",280);
	set_skill("strike",280);
	set_skill("cuff",280);
	set_skill("sword",280);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);

        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        map_skill("strike","baihua-zhang");
        map_skill("cuff","zhuifeng-quan");
        map_skill("sword","yubi-jian");
        map_skill("force","bitao-shengong");
        map_skill("dodge","qiongya-bufa");
        map_skill("parry","yubi-jian");

	prepare_skill("strike", "baihua-zhang");
	prepare_skill("cuff", "zhuifeng-quan");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: exert_function, "roar" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.feixian" :),
                (: perform_action, "sword.rouqing" :),	
                (: perform_action, "sword.tianwaifeixian" :),	
                (: perform_action, "sword.wan" :),	                	
                (: perform_action, "parry.shi" :),
                (: perform_action, "cuff.hantian" :),
(: perform_action, "cuff.luori" :),
(: perform_action, "cuff.nx" :),
(: perform_action, "cuff.qiankun" :),		             
(: perform_action, "cuff.qin" :),		             
(: perform_action, "cuff.qzwd" :),		             	             
        }) );  
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	

	
	set("combat_exp",50000);
	set("mingwang",1000);
	create_family("白云庵", 4, "弟子");
	set("inquiry", ([
		"here" : "这里就是海南白云庵呀,你居然不知道么?",
	"梵音神尼":"我师傅啊,她老在经堂,也不出来!",
	]) );	

	setup();
	carry_object("/d/hainan/obj/shaqun")->wear();
       carry_object("/d/hainan/obj/roujing_sword")->wield();
            add_money("silver",5);
}
