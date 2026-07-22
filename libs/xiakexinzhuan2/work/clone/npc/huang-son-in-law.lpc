// huang-son-in-law 桃花岛女婿

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define SONINLAW NPCDATA + "huang-son-in-law"

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

int do_clone(object me, object ob);

string query_save_file()
{
	return SONINLAW;
}

void create()
{
	seteuid(getuid());

	if (!restore()) {
		set_name("郭靖", ({ "nvxu" }) );
		set("title", "黄药师之女婿" );
		set("gender", "男性" );
		set("age", 19);
		set("long","他就是黄药师的乘龙快婿，黄蓉的心上人！\n");
		set("attitude", "peaceful");

		set("str", 25);
		set("con", 25);
		set("int", 25);
		set("dex", 25);

		set("max_qi", 500);
		set("eff_qi", 500);
		set("qi", 500);
		set("max_jing", 300);
		set("jing", 300);
		set("neili", 500);
		set("max_neili", 500);
		set("jiali", 40);
		set("shen", 1000000);
		set("shen_type", 1);

		set("no_clean_up",1);
		set("combat_exp", 500000);

		set_skill("force",  100); 
		set_skill("unarmed",100);
		set_skill("sword",  100);
		set_skill("dodge",  100);
		set_skill("parry",  100);

		set("armor", "/clone/misc/cloth");

		setup();

		carry_object("/clone/misc/cloth")->wear();        
	}
	else {
		set("id", "nvxu");
		set_name(query("name"), ({ query("id") }));
		setup();
		if( this_object()->query("weapon") ) carry_object(this_object()->query("weapon"))->wield();
		if( this_object()->query("armor") )  carry_object(this_object()->query("armor"))->wear();        
	}
}

int do_copy(object me, object ob)
{
	seteuid(getuid());

//	me->add("generation", 1);	

	me->set("name",  ob->query("name") );
	me->set("title", "桃花岛乘龙快婿");
	me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");

	ob->set_temp("apply/short", ({me->query("short")}));
	
	me->set("short", me->query("title") + " " + me->query("name") + "( Taohuadao nvxu)");
	me->delete("title");

	do_clone(me, ob);

	return 1;
}

int do_clone(object me, object ob)
{
	seteuid( geteuid(me) );
	me->set("winner", ob->query("id"));
	me->set("death_count", ob->query("death_count"));

	save();
	return 1;
}
