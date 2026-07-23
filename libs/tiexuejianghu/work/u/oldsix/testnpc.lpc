inherit KZZNPC;

string query_save_file() { return DATA_DIR + "npc/liumang"; }
void create()
{
	object lingpai;
	restore();
	set_name(query("name"),({query("id")}));
	set("kee",query("max_kee"));
	set("eff_kee",query("max_kee"));
	set("gin",query("max_gin"));
	set("eff_gin",query("max_gin"));
	set("sen",query("max_sen"));
	set("eff_sen",query("max_sen"));
	set("force",query("max_force"));
	if(query("banghui"))	{
		lingpai=new("/obj/lingpai");
		lingpai->move(this_object());
		lingpai->autoload(query("banghui"));
	}
	setup();
}


