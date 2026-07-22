inherit NPC;
void create()
{
   set_name("小姐",({ "xiao jie","xiao","jie" }) );
   set("gender", "男性" );
   set("age", 22);
   set("long", "这是一位小姐。\n");
   set("combat_exp", 20000);
   set("attitude", "friendly");
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   set("chat_chance",20);
   set("chat_msg",({
   	"小姐微微一笑：现在打仗，这里没什么好玩的，以前可不是这个样子。\n",
   	"小姐叹道：什么时候才能过上好日子，我的夫君不知道在战场上是死是活。\n",
   	"小姐叹道：据说杀了我会获得什么名号。如果我夫君在身边，谁还敢如此造谣？\n",
   	(:random_move:),
   	}));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   if(!userp(ob)) return ::die();
   
   if(random(100)>95){
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"杀死车夫，获得了"+
      "「无情血手」的称号！\n");
     ob->set_temp("rank/class","无情血手");
   }
   
   return ::die();
   
}