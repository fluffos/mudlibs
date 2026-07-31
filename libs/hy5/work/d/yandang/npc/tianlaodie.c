inherit NPC;

void create()
{
	set_name("田老爹", ({ "laodie", "tian" }));
	set("gender", "男性");
	set("age", 65);
       set("long","田老爹蹲坐在屋角的一张圆凳上吸着旱烟!\n");
       set("inquiry", ([
             "落雁山庄" : "田老爹看都不看你一眼,拿旱烟杆向北指了指!",
             "雁荡派" : "田老爹翻了翻白眼说,没听说过!",
		]) );
      setup();	
      add_money("silver",2);
      carry_object(__DIR__"obj/hanyangan")->wield();
      carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who,object item)
{	
	if(item->query("id")=="sanqian_silver")
	{
	command("say 呵呵,真不好意思,老远让你还给送来,其实也没什么,没什么!\n");
       command("say 翠儿,给这位"+RANK_D->query_respect(who)+",来葫芦酒,带着路上喝!\n");
message_vision("卖酒女给$N一只紫金葫芦.\n",who);
clone_object("/d/yandang/obj/hulu")->move(who);		
return 1;
	}
	command("say 你这是什么意思,少给我来这一套。\n");
	return 0;
}
