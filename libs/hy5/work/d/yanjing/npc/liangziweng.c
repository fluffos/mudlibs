inherit NPC;
void create()
{
   set_name("梁子翁",({"liang ziweng"}));
   set("gender","男性");
   set("mingwang",-5000);
   set("combat_exp",260000);
   set("title","长白参客");
   
   set("age",64);
   set("qi",8800);
   set("max_qi",8800);
   set("food",250);
   set("water",2500);
   set("neili",8000);
   set("max_neili",8000);
   set("force_factor",40);

   set_skill("dodge",190);
   set_skill("force",190);
   set_skill("parry",190);
   set_skill("unarmed",190);
   set_skill("spear",290);
   set_skill("sword",290);
   

   setup();
   add_money("silver",10);
carry_object(__DIR__"obj/changpao")->wear();
carry_object(__DIR__"obj/yaochu")->wield();
}
void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}


void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}