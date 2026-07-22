inherit NPC;
void create()
{
  set_name("乞丐",({ "qi gai","qi","gai"}) );
        set("gender", "男性" );
        set("age", 35);
   set("long", "这是一个可怜的乞丐。\n");
   set("combat_exp",3000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
    "乞丐低声道：行行好，给点钱吧！\n",
    "乞丐哭道：我家有八十老母，还有一个妻子，六个孩子，行行好吧！\n",
    "乞丐可怜地说道：我已经三天没吃饭了！\n",
    "乞丐哭道：据说谁杀了我会获得什么称号，我怎么这么命苦啊！！\n",
    }));
  setup();
  
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   if(!userp(ob)) return ::die();
   
   if(random(100)>95){
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"杀死乞丐，获得了"+
      "「丧尽天良」的称号！\n");
     ob->set_temp("rank/class","丧尽天良");
   }
   
   return ::die();
   
}
