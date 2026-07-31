inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("芦娘", ({"lu niang"}));
        set("long",
"她头上插着几朵白色芦花，容颜虽然俏丽，却掩不住身上的妖气。\n");
        set("age", 20);
	set("title", "芦花精");
        set("attitude", "friendly");
        set("gender", "女性");
	set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 30);
        set("max_qi",800);
        set("max_jing", 800);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 15);
        set("combat_exp", 160000);
  set("combat_exp", 100000);



        setup();
        initlvl((500+random(500)),54);
        carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/qujing/bibotan/obj/luhua")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 3, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
	
	if((string)ob->query("family/family_name")=="陷空山无底洞" 
	&& (string)ob->query("family/family_name")=="乱石山碧波潭"
        && (string)ob->query("family/family_name")=="大雪山") {
	command("xixi " + ob->query("id"));
	return;
	}
	command("look " + ob->query("id") );
	command("say 又白又胖，正合老娘胃口。");
	command("chan " + ob->query("id") );
	kill_ob(ob);
	ob->fight_ob(this_object());

	return;
}
