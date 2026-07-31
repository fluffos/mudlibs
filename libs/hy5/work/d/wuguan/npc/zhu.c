//by cool 98.3.25

inherit NPC;
int study_book();
void create()
{
	set_name("朱宇", ({ "zhu yu","zhu","yu", "guanzhu" }));
	set("title", "襄阳武馆馆主");
       set("nick", "铁掌龙威");
	set("gender", "男性");
	set("age", 50);
	set("str", 30);
	set("dex", 26);
	set("long", "这人紫金脸庞，面带威严，威武有力，站在那里就象是一座铁塔。\n");
	set("combat_exp", 800000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 140);
	set_skill("force", 140);
        set_skill("strike", 140);
	set_skill("hammer", 100);
        set_skill("kunlun-zhang", 180);
        set_skill("xuantian-wuji", 160);
        set_skill("kunlun-shenfa", 160);
        set_skill("dodge", 140);
	set_skill("parry", 140);
        map_skill("dodge", "kunlun-shenfa");
        map_skill("parry", "kunlun-zhang");
        map_skill("force", "xuantian-wuji");
        map_skill("strike", "kunlun-zhang");
        prepare_skill("strike","kunlun-zhang");
        set("qi", 2500);
	set("max_qi", 2500);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);
        set("inquiry",  ([
            "工作" : "呵呵，你去找张总管吧，他会安排你的。",
            "练功" : "东西练武场都可以练的，你去那练吧。",
            "学习" : (: study_book :),
        ]));
	setup();
        carry_object("clone/cloth/cloth")->wear();
}

void init()
{
     object ob;
     ::init();

     if (interactive(ob = this_player()) && !is_fighting() && !wizardp(ob)){
        if((int)ob->query("combat_exp") > 50000){ 
            command("say 咦？你是怎么跑这里来的？回去回去。 \n");
            message_vision("$N一巴掌打在$n脸上，只听$p“啪~~”地一声，带着一个斗大的掌印直飞了出去！\n", this_object(), ob);
            ob->move("/d/wuguan/dayuan2");
            command("say 这一招有个名堂，叫作：脑袋向下，大雁南飞式。");
            tell_room(environment(ob), "只听“哇~~”一声大叫，一个"+ob->name()+"从武馆大厅飞了过来，脸上带着个红红的巴掌印！\n", ({ ob }));
            }
         if((int)ob->query_condition("killer")){        
            command("say 你竟敢在武馆杀人！\n");
            command("club "+ob->query("id"));
            ob->unconcious();
            } 
         }

}

int study_book()
{
       object me, ob;

       me = this_object();
       ob = this_player();
       if (!me->query_temp("book_get")) {
       command("pat" +ob->query("id"));
       command("say 书房里有些我常看的书，你去翻翻看，有没有自己需要的。");
       ob->set_temp("wg_study",1);
       }
       else message_vision("$N不是刚拿过一本书吗？先慢慢看那本吧！\n", this_player());

       return 1;
}
