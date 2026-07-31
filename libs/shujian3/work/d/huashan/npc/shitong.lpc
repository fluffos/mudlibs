// NPC: /d/huashan/npc/shitong.c
// Date: Look 99/03/25

inherit NPC;

string ask_gonglao(object me);

void create()
{
	set_name("侍童", ({ "shi tong" }));
	set("long", "他是一个专门在祭坛侍奉的小童。\n");
	set("age", 17);
	set("combat_exp", 20000);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("str", 20);
       set("attitude", "peaceful");
	set("shen_type", 1);

	set("max_qi", 300);
	set("qi", 300);
	set("max_jing", 300);
	set("jing", 300);
	set("eff_jingli", 300);
	set("jingli", 300);
	set("max_neili", 300);
	set("neili", 300);

	set_skill("huashan-jianfa", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("huashan-shenfa", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zixia-gong", 50);
	set_skill("strike", 50);
	set_skill("hunyuan-zhang", 50);

	map_skill("strike", "hunyuan-zhang");
	map_skill("force", "zixia-gong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");

	prepare_skill("strike", "hunyuan-zhang");
	
        set("inquiry", ([
              "善事" : (: ask_gonglao :),                        
        ]));

	setup();
	carry_object(BINGQI_D("sword/sword"))->wield();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}

string ask_gonglao(object who)
{
	mapping fam;
	int i;
        object me=this_player();
        fam = me->query("family");
	i = me->query("job_time/华山");
        if(!intp(i = me->query("job_time/华山"))) return "你没为我华山百姓出过任何力，跑来问什么功劳呢?"; 
       	if(random(10) > 3) return RANK_D->query_respect(me)+"为华山百姓做些善事，就不要问来问去的了。\n";
        message_vision("$N指着祭坛对$n说道，"+RANK_D->query_respect(me)+"已经为华山百姓做了" + CHINESE_D->chinese_number(i) + "次善事。\n",who,me);
        return RANK_D->query_respect(me)+"加油干啊！";
}
