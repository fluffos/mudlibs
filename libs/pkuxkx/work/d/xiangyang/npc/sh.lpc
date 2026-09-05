inherit NPC;

string ask_for_toujun();

void create()  
{	set_name("襄阳守将", ({ "shou jiang","jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 45);
	set("dex", 26);
	set("long", "他站在那里，浑身杀气,让人心惊胆寒。\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 90);
	set_skill("force", 80);
	set_skill("halberd", 90);
	set_skill("lujia-ji", 90);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	map_skill("halberd", "lujia-ji");
	map_skill("parry", "lujia-ji");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 50);
        
        set("inquiry",([
                "投军"  : (: ask_for_toujun :),
        ]));


        set("chat_chance", 1);
        set("chat_msg", ({
       "郭大侠嘱咐,一定要加强防范,不能让鞑子兵混进城里.\n
         但对那些立志投军报国的壮士我们可不能怠慢.\n"
        }) );

        setup();
	carry_object("/clone/weapon/fangtianji")->wield();
	carry_object(__DIR__"obj/tiejia")->wear();

}

void init()
{
	object ob=this_player();
	::init();
	if(ob->query("killed")) call_out("kill_ob",1,ob);
	add_action("do_kill","kill");

}

string ask_for_toujun()
{
        object me,ob;
        me = this_player();
        if ((int)me->query_str() < 16 )
           return "这位好汉体质太差,手无缚鸡之力,还是不要从军的好。\n";
           command("wa " + me->query("id"));
           command("admire " + me->query("id"));
//           command("give armor to " + me->query("id"));
//         me->move("/u/chenchen/work/xysouth3");
//          object ob; 
        ob = new(__DIR__"obj/yaopai");
	ob->move(this_player());
         message_vision("守将给了$N一块腰牌。\n", me);
        me->set_temp("shoujiang_asked", 1);  
          return "请到城中郭大侠府上讨个差事吧.\n";
}
int do_kill(string arg)
{
	object me , ob,obj;
	me=this_player();
	ob=this_object();
	obj=present(arg,environment(me));
	me->set_temp("killed",1);
	ob->kill_ob(me);
	me->kill_ob(ob);
	return 1;
}
 


