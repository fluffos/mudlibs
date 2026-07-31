
inherit NPC;

void create()
{
   set_name("游客",({ "you ke","you","ke"}) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是一个来南昌观光的游客。\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("chat_chance",30);
   set("chat_msg",({
	   "游客说道：这次来南昌，一定要好好地玩一趟！\n",
	   "游客叹道：如今世事难料，兵荒马乱，不知道什么时候能再来南昌了。\n",
	   "游客说道：李财主的女儿比武招亲，我也很想去试试啊！\n",
	   (:random_move:),
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

