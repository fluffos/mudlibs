inherit BHNPC;

string query_save_file() { return DATA_DIR + "npc/观证"; }
void create()
{
  set_name("观证",({"guan zheng","guan"}));
  this_object()->init_bhnpc();
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/std/armor/pijia")->wear();
	carry_object("/obj/weapon/sword")->wield();
}
void init()
{
  ::init();
   command("guard up");
}
    

