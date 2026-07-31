inherit NPC;
inherit F_DEALER;

string ask_kaitong();
string ask_kuojian();

void create()
{
	set_name(HIW"老农"NOR, ({ "lao nong" }));
	set("long", "负责看管菜园的老农。\n");
	set("gender", "男性");
	set("age", 96);
	set("per", 24);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("qi",5000);
	set("jingli",6000);
	set("max_qi", 8000);
	set("max_jing", 5000);
	set("eff_jingli", 6000);
	set("jiali", 190);
	set("combat_exp", 9000000);
	set("shen", 25000);
	
	set("vendor_goods", ({
		__DIR__"seed/baicai_seed.c",
	}));
	
	set("inquiry", ([
		"开通" : (: ask_kaitong :),
		"扩建" : (: ask_kuojian :),
	]));
	
	setup();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_kaitong", "kaitong");
	add_action("do_kuojian", "kuojian");
}

int do_list()
{
	string *seed_file, *seed_name;
	int i;
	
	seed_file = list_dirs(__DIR__"seed/*.c");
	
	for(i = 0; i < sizeof(seed_file); i++)
		seed_file[i]  = (__DIR__"seed/" + seed_file[i]);

	set("vendor_goods", seed_file);
	::do_list();
	return 1;
}

string ask_kaitong()
{
	this_player()->force_me("kaitong");
	return "";
}

string ask_kuojian()
{
	this_player()->force_me("kuojian");
	return "";
}

int do_kaitong(string arg)
{
	object who = this_player();
	
	__DIR__"plant"->kaitong(who, arg);
	return 1;
}

int do_kuojian(string arg)
{
    object who = this_player();
    
    __DIR__"plant"->kuojian(who, arg);
    return 1;
}