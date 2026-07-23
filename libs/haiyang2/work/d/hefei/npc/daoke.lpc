
inherit NPC;

void create()
{
   set_name("刀客",({ "dao ke","dao","ke"}) );
   set("gender", "男性" );
   set("age", 20);
   set("long", "这是一名刀客。\n");       
   set("combat_exp",100000);
  
   set("chat_chance",30);
   
   set_skill("parry",100);
   set_skill("dodge",100);
   set_skill("force",100);
   set_skill("blade",100);
   set("chat_msg",({
     "刀客抽出刀晃了几晃，亮了个招式！\n",
     "刀客冷冷一笑，说道：将来没准老子也能成为用刀的高手！\n",
   }));
   setup();
   
   carry_object(__DIR__"obj/blade")->wield();
   
}

