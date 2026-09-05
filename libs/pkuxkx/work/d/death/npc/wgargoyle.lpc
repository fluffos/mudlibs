// gargoyle.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;
string* revive_rooms = ({"/d/city/wumiao","/d/luoyang/wumiao","/d/hangzhou/chenghuang","/d/changan/xuanduguan"});
string *death_msg = ({
     HIW "白无常说道：喂！新来的，你叫什么名字？怎么死的？\n\n" NOR,
     HIW "白无常用奇异的眼光盯著你：可惜呀，可惜。。。\n\n" NOR,
     HIW "白无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,
     HIW "白无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
     HIW "白无常搔了搔头，笑道：也罢，回阳间去，发奋作人吧，别再这么窝囊了。\n\n"
             "一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
     HIY "慢慢地你终于又有了知觉....\n\n" NOR,
});

void create()
{
	set_name("白无常", ({ "white gargoyle", "gargoyle" }) );
	set("long",
		"白无常伸著长长的舌头瞪著你，死白的脸上看不出任何喜怒哀乐。\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
//		(: this_object(), "random_move" :),
		"白无常发出一阵像呻吟的声音，当他发现你正注视著他的时候，瞪了你一眼。\n",
		"白无常把长长的舌头伸出来，缓缓地舔了舔自己又白又长的手指。\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_qi", 900);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
    set("is_ghost",1);
	set("shen_type",1);set("score",0);setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object())
	||	wizardp(previous_object()) ) return;
	call_out( "death_stage",5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	int i;
    string id;
	object *inv, cloth, record;

	if( !ob || !present(ob) ) return;

    record = load_object("/d/death/gate");
    id = ob->query("id");

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5*(record->query_temp("record/"+id+"/times")+1), ob, stage );
		return;
	} else
		ob->reincarnate();

    inv = all_inventory(ob);
    for (i = 0; i < sizeof(inv); i++)
        DROP_CMD->do_drop(ob, inv[i]);
    
	if(ob->query_temp("revive_room") && objectp(load_object(ob->query_temp("revive_room"))))
	{
		ob->move(ob->query_temp("revive_room"));
	}
	else
	{	
		ob->move(revive_rooms[random(sizeof(revive_rooms))]);
	}
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
		"很久了，只是你一直没发觉。\n", environment(ob), ob);
	cloth = new("/clone/misc/cloth");
	cloth->move(ob);
	cloth->wear();
}

void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}


