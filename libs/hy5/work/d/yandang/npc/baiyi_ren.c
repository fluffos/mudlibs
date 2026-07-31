inherit NPC;
int kill_sb();
int have_book=1;

void create()
{
	set_name("白衣人", ({ "baiyi ren", "baiyi", "man" }) );
	set("gender", "男性" );
	set("age", 54);
	set("long",
		"一身雪白的长衫,在风中飘拂,神情间暗带阴郁。\n");
	set("combat_exp", 100000);
        set("str", 34);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
	set("attitude", "peaceful");
      set("inquiry",([
       "小梅":(:kill_sb():),
       "xiaomei":(:kill_sb():),
       "落雁山庄":"从此向东,再向北,别再来烦我了!\n",
        ]));	

        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("unarmed",120);
        set_skill("sword",120);
        set_skill("taiji-jian",120);
        map_skill("sword","taiji-jian");
        setup();
        carry_object(__DIR__"obj/xue_cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
	add_money("coin", 100);
}
int kill_sb()
{
  object me,ob;
  me=this_player();
  if( me->query("str")<24)
{  if (have_book==0) command("say 你来晚了,来晚了,等下次吧,阿门,愿主赐福于你!\n");
   else
 {  clone_object("/d/yandang/obj/book1")->move(me);
    command("say 情天恨海,从此相见无期,你我相遇也是有缘,这本书就送给你吧。\n");  
    message_vision("白衣人送给$N一本破烂的书.\n",me);
    have_book=0;   
  return 1;}
  return 1;
 }
  else command("say 伤心人别有怀抱,你就不要来纠缠我了!\n");
  return 0;
}

