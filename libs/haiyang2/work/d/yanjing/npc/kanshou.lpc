inherit NPC;
void create()
{
   set_name("王府看守",({"kan shou"}));
   set("gender","男性");
        set("shen_type",-1);
	set("combat_exp",50000);
   
   set("age",46);
   set("qi",580);
   set("max_qi",580);
   set("food",250);
   set("water",250);
   set("neili",580);
   set("max_neili",580);
   set("force_factor",20);

	set_skill("dodge",100);
	set_skill("force",100);
	set_skill("parry",100);
	set_skill("unarmed",100);
	set_skill("club",100);
	set_skill("blade",100);
 
   setup();
   add_money("silver",2);
carry_object(__DIR__"obj/pijia")->wear();
carry_object(__DIR__"obj/blade")->wield();
}
