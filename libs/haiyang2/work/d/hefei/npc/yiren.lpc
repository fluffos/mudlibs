
inherit NPC;

void create()
{
   set_name("艺人",({ "yi ren","yi","ren"}) );
   set("gender", "男性" );
   set("age", 22);
   set("long", "这是一位在合肥卖艺求生的艺人。\n");
       
   set("combat_exp", 50000);
   set("str", 25);
   set("per", 22);
   set_skill("unarmed",50);
   set_skill("parry",50);
   set_skill("dodge",50);
   
   set("chat_chance",20);
   set("chat_msg",({
    "艺人叹道：做人难，做人难，做个艺人更难啊！\n",
    "艺人喊道：有钱的捧个钱场，没钱的捧个人场，给各位献丑了！\n",
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void die()
{
	message_vision("$N大声喊道：连卖艺的都杀，我做鬼都不放过你！\n",this_object());
	return ::die();
}

