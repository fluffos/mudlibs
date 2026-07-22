inherit BHNPC;

string query_save_file() { return DATA_DIR + "npc/»ÞÃ÷"; }
void create()
{
  set_name("»ÞÃ÷",({"hui ming","hui"}));
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
    

