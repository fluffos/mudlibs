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
   	"车夫一皱眉：据说如果杀了我，就有机会获得什么称号，真是胡扯！\n",
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
      "「欺软怕硬」的称号！\n");
     ob->set_temp("rank/class","欺软怕硬");
   }
   
   return ::die();
   
}