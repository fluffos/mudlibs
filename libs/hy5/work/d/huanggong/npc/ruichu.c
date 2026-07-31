inherit NPC;
void create()
{
   set_name("蕊初",({"rui chu"}));
   set("age","女性");
   set("nickname","小宫女");
   set("age",15);
   set("combat_exp",200);
   
   set_skill("unarmed",5);
   set("chat_chance",5);
   set("chat_msg",({
   "蕊初道:那天海公公深夜到慈宁宫来,我可没看见.\n",
   "蕊初道:以前小桂子常到这来玩.\n",
   "蕊初道:我听说宫里陈皮大虾特别好吃，真想吃一吃.\n",
   "蕊初道:上次在北海吃过一会陈皮大虾,忘也忘不了.\n",
   }));
   setup();
   carry_object("/clone/cloth/female5-cloth.c")->wear();
}
 int accept_object(object me, object obj)
{
	object pai;
	if (query("isok")==1) return 0;
        if( (string) obj->query("name") == "陈皮大虾"
        || obj->query("id") =="cp dx")
	{
        message_vision("$N对$n笑了笑：\n",this_object(),me);
        command("love");
	command("say 太谢谢你了，我就是喜欢吃这个！\n");
	command("say 这本42章经，就送给你吧！\n");
	pai = new("/d/city2/obj/book14_6");
	if(pai)
	pai->move(me);
	this_object()->set("isok",1);
set("isok",1);
        message_vision("$N拿出一本42章经给了$n。\n",this_object(),me);
        call_out("destroying", 0, obj,me);                       
	return 1;	
	}
else       return 0;
}

void destroying(object obj, object ob, object me)
{   

   if(obj) destruct(obj);
}
