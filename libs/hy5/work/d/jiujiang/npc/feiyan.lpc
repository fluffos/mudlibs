
inherit NPC;

void create()
{
   set_name("斐炎",({ "fei yan","fei","yan"}) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是大江联的斐炎。\n");
       
   set("combat_exp",200000);
   
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);

   set("chat_chance",20);
   set("chat_msg",({
   	(:random_move:),
   }));
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

