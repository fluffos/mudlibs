
inherit NPC;

void create()
{
   set_name("流氓",({ "liu mang","liu","mang" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是南昌城内整天到处惹事生非的流氓。\n");
       
   set("combat_exp", 30000);
   set("str", 23);
   set("per", 22);
   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
	   "流氓笑道：南昌城内，谁敢不买我的帐？\n",
		   (:random_move:),
	   "流氓向地上吐了口吐沫：都给我站着！\n",
       "流氓一跺脚：你们是不是活够了？都给我滚开！\n",
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   add_money("coin",80);
  
}

