inherit NPC;
void create()
{
  set_name("流氓",({ "liu mang","liu","mang"}) );
  set("gender", "男性" );
  set("age", 35);
   set("long", "这是一个蛮横的流氓。\n");
   set("combat_exp",3000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   
   set("chat_chance",20);
   set("chat_msg",({
    "流氓哼道：都他妈给老子滚开，别挡路！！\n",
    "流氓骂道：大爷我在长安吃顿饭都不给钱，在这里还敢朝老子要钱？！\n",
    "流氓一跺脚：听没听过“长沙一虎”？那就是老子我！！\n",
    "乞丐晒道：据说谁杀了我会获得什么称号，谁敢啊？！！\n",
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
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"杀死流氓，获得了"+
      "「正义侠客」的称号！\n");
     ob->set_temp("rank/class","正义侠客");
   }
   
   return ::die();
   
}
