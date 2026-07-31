inherit NPC;

void create()
{
   set_name("衙役",({ "yayi"}) );
        set("gender", "男性" );
        set("age",30+random(10));
   set("long", "这是一个九江衙门的衙役。\n");       
   set("combat_exp",10000);
   set("str",28);
   set_skill("parry",40);
   set_skill("unarmed",40);
   set_skill("dodge",40);
   set_skill("staff",40);

   set("attitude", "peaceful");
   set("chat_chance",10);
   set("chat_msg",({
       "衙役叹了口气。\n",
   }));
  
   setup();
   carry_object(__DIR__"obj/yayi-fu")->wear();
   carry_object(__DIR__"obj/yayi-mao")->wear();
   carry_object(__DIR__"obj/shuihuo-bang")->wield();
  
}

