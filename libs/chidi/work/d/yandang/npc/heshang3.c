inherit BHNPC;

string query_save_file() { return DATA_DIR + "npc/널밖"; }
void create()
{
  set_name("널밖",({"cheng guan","cheng"}));
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
    

