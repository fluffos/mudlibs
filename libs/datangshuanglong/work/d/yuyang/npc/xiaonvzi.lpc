
inherit NPC;

void create()
{
   set_name("小姐",({ "xiao jie","xiao","jie"}) );
   set("gender", "女性" );
   set("age",20+random(2));
   set("long", "这是一位大家闺秀。\n");
       
   set("combat_exp", 100000);
   set("per",25);
   set("chat_chance",20);
   set("chat_msg",({
    "小姐娇声道：最近战火不断，我可真是害怕死了！\n",
    "小姐幽幽道：常听人说寇仲、徐子陵如何了得，我可真想看一看他们啊！\n",
    "小姐低声道：最近经常有很多恶人打我的主意，我该怎么办？\n",
    "小姐自言自语：据说谁杀了我就有机会获得某个称号，真是担心死我了！\n",
   }));
   
   set("inquiry",([
    "寇仲":"我可真想见他，如果能嫁给他，我也不用整天这么害怕了！\n",
    "徐子陵":"据说他人品很好，真想见识一下。\n",
    ]));
   
   
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
  
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   if(!userp(ob)) return ::die();
   
   if(random(100)>95){
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"杀死弱女，获得了"+
      "「江湖流氓」的称号！\n");
     ob->set_temp("rank/class","江湖流氓");
   }
   
   return ::die();
   
}