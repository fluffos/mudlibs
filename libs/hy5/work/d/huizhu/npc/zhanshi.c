inherit NPC;
void create()
{
   set_name("回族战士",({"zhan shi"}));
   set("gender","男性");
   set("score",900);
   set("combat_exp",4000+random(500000));
set("long", "虽然回族战士的武艺不能和武林人士相比，可是他们讲究的是人多力量大。\n");
set("attitude", "peaceful");

   set("age",19+random(30));
   set("qi",500+random(1000));
   set("jing",500+random(1000));
   set("max_qi",500+random(1000));
   set("max_jing",500+random(1000));
   set("neili",100+random(500));
   set("max_neili",100+random(500));
   set("force_factor",10+random(50));

   set_skill("dodge",40+random(100));
   set_skill("force",40+random(100));
   set_skill("parry",40+random(100));
   set_skill("unarmed",40+random(100));
   set_skill("whip",40+random(100));
   set_skill("sword",40+random(100));
   set_skill("club",40+random(100));
   
   set("chat_chance",1);
   set("chat_msg",({
   	(:random_move:),
   }));

   setup();
   add_money("silver",1);
carry_object(__DIR__"obj/pijia")->wear();
carry_object(__DIR__"obj/tieqiang")->wield();
}
