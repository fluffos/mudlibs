inherit BHNPC;

string query_save_file() { return DATA_DIR + "npc/´ó±¯"; }
void create()
{
  set_name("´ó±¯",({"da bei","da"}));
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
    

