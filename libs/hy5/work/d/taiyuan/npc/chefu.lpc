inherit NPC;
void create()
{
   set_name("车夫",({ "che fu","che","fu" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是一名普通的车夫。\n");
   set("combat_exp", 20000);
   set("attitude", "friendly");
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   set("chat_chance",20);
   set("chat_msg",({
   	"车夫高声喊道：喂，借个道，谢谢了！\n",
   	(:random_move:),
   	}));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
