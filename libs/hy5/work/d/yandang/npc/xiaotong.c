inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("青衣小童", ({"xiaotong", "xiaohai", }) );
        set("gender", "男性" );
        set("age", 14);
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("rank_info/respect", "小哥");

        set("inquiry", ([
              "zhuangzhu": "庄主在大厅,他平时很少来了!\n",
              "庄主": "庄主在大厅,他平时很少来了!\n",
              "剑": "你说的是墙上的那把剑哪,庄主平时都不许别人碰的." ,
]) );


        setup();

        carry_object("/clone/misc/cloth")->wear();
add_money("silver",1);
}
void init()
{      object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");

                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	object *inv;
	int count;

        if( !ob || environment(ob) != environment() ) return;
	inv=all_inventory(ob);
	for(count=0;count<sizeof(inv);count++)
	    if(inv[count]->query("name")=="白玉杯")
	return;
else
     if(ob->query("family/family_name")=="雁荡派" ) 
  {
  say("青衣小童给"+ob->query("name")+"递上一杯茶。\n");
  clone_object(__DIR__"obj/baiyubei")->move(ob);
	return;
}
return;
}
