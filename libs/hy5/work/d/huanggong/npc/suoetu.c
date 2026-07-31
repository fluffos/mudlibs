inherit NPC;
void create()
{
   set_name("索额图",({"suo etu"}));
   set("gender","男性");
   set("age",45);
   set("combat_exp",2000);
   set("mingwang",4000);
   
   set_skill("unarmed",20);
   set_skill("parry",20);
   set_skill("dodge",20);
   set_skill("literate",50);
   set("chat_chance",4);
   set("chat_msg",({
  "索额图道:明珠大人,你怎么看平西王此人?\n",
  "索额图道:明珠大人慧眼识珠,好生令人佩服.\n",
  "索额图道:皇上对西藏和蒙古的事情好生担忧哪.\n",
  "索额图道:钱是好东西啊!\n",
  "索额图道:在这宫里做什么事都少不了钱!\n",
  }));
   
   setup();
   add_money("silver",10);
}
int accept_object(object me, object obj)
{
	object pai;
	if (query("isok")==1) return 0;
        if( obj->query("money_id") && (int) obj->value() >= (10+ random(50)) * 10000)
	{
        message_vision("$N对$n哇的一声!：\n",this_object(),me);
        command("wa");
	command("say 好东西，我最喜欢金子了！太谢谢你了！这个给你！\n");
	pai = new("/d/city2/obj/book14_3");
	if(pai)
	pai->move(me);
this_object()->set("isok",1);
set("isok",1);
	
        message_vision("$N拿出一本42章经给$n。\n",this_object(),me);
	return 1;	
	}
else return 0;
}
