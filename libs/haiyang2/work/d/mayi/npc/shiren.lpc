
inherit NPC;
void create()
{
   
   set_name("书生",({ "shu sheng","shu","sheng"}) );
   set("gender", "男性" );
   set("age",20+random(10));
   set("long", "这是一个书生，不过看起来有些落魄。\n");
   set("combat_exp", 100000);
   set("str", 30); 
   set("chat_chance",20);
   set("chat_msg",({
     "落魄书生叹道：时不与我，如今乱世，我的才华如何发挥？\n",
     "书生叹了口气：若无和平盛世，我纵有千万文章又有何用？\n",
     "书生一甩袖子：哼！我不如闻鸡起舞，去当兵杀突厥人好了！\n",
     (:random_move:),
    }));    
   setup();
    carry_object("/clone/misc/cloth")->wear();
  
  
}

  
