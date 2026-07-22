
inherit NPC;
void create()
{
   
   set_name("小贩",({ "xiao fan","xiao","fan"}) );
        set("gender", "男性" );
        set("age",25);
   set("long", "这是一个走街串巷的小贩。\n");
   set("combat_exp",5000);
   set("str",25);
   set("chat_chance",60);
   set("chat_msg",({
   	(:random_move:),
   	}));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
