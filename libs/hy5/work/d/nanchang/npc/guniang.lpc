
inherit NPC;

void create()
{
   set_name("卖花姑娘",({ "girl"}) );
   set("gender", "女性" );
   set("age",15);
   set("long", "这是一个在南昌卖花的姑娘。\n");
       
   set("combat_exp",100);
   set("str", 10);
   set("per", 20);
   set("attitude", "peaceful");
   set("chat_chance",4);
   set("chat_msg",({
     "卖花姑娘喊道：新鲜的鲜花了，谁买啊，刚摘的鲜花？\n",
     "卖花姑娘说道：看鲜花多香啊，快来买一束吧！\n",
     (:random_move:),
   }));
   set("inquiry",([
     "鄱阳湖":"就在西边了，去看看吧！\n",
     ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

