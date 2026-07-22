inherit BHNPC;

string query_save_file() { return DATA_DIR + "npc/¾»¼Ã"; }
void create()
{
   set_name("¾»¼Ã",({"jing ji","jing"}));
  this_object()->init_bhnpc();
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/std/armor/pijia")->wear();
}
void init()
{
  ::init();
   command("guard up");
}
    

