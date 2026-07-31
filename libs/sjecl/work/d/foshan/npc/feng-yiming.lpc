//feng-yiming.c  凤一鸣

inherit NPC;

void create()
{

        set_name("凤一鸣", ({ "feng yiming", "feng" }));
        set("long", "他身穿蓝绸长衫，右手摇着折扇，脸上英气勃勃，显是武功不弱。\n");
        set("gender", "男性" );
        set("age", 23);
        set("no_quest", 1);
	set("attitude", "peaceful");
	set("shen", -2000);

	set("str", 22);
        set("int", 25);
        set("con", 22);
        set("dex", 21);
        set("unique", 1);
        
	set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);

        set("jingli",1500);
        set("eff_jingli",1500);
        set("jiali", 30);   
	set("combat_exp", 200000);

	set_skill("force",100);
        set_skill("dodge",100);
        set_skill("strike",100);
        set_skill("parry",100);
        set_skill("wuhu-duanmendao", 120);
        set_skill("qingmang-jian", 120);
        set_skill("cuixin-zhang", 120);

        map_skill("blade", "wuhu-duanmendao");
        map_skill("parry", "wuhu-duanmendao");
        map_skill("dodge", "qinmang-jian");
        map_skill("strike", "cuixin-zhang");
        prepare_skill("strike","cuixin-zhang");
	setup();

	carry_object(ARMOR_D("cloth"))->wear();
        carry_object(BINGQI_D("blade"))->wield();
}

void die()
{
	object ob,me;
	me=this_player();
	message_vision("\n$N遭此一击，浑身一阵抽搐，眼看是活不成了。\n",this_object());
	ob = unew("/d/foshan/npc/fengtiannan");
        if(!clonep(ob)){
           destruct(this_object());
           return;
        }
        if(clonep(ob) && ob->violate_unique()){
           destruct(this_object());
           destruct(ob);
           return ;
        } 
        message_vision("\n凤天南急匆匆的跑了过来，一把抱起凤一鸣的尸体，大哭起来。\n",this_object());
	ob->move(environment(this_object()) );
::die();
}

void unconcious()
{ 
      die();
}
