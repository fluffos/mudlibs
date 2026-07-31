inherit NPC;
void create()
{
   set_name("明珠",({"mingzhu"}));
   set("gender","男性");
   set("age",45);
   set("combat_exp",10000);
   set("mingwang",4000);
   
   set_skill("unarmed",20);
   set_skill("parry",20);
   set_skill("dodge",20);
   set_skill("literate",50);
  set("chat_chance",5);
  set("chat_msg",({
  "明珠道:平西王居然想造反,我看是不想活了.\n",
  "明珠道:皇上手下的韦都统抓住了熬拜,现关在康亲王府.\n",
  "明珠道:太后那边昨天有出刺客了,我总绝得不大对.\n",
  "明珠道:前几天洋人进贡的西洋表，真是个好东西。\n",
  "明珠道:我要是有这么一块西洋表就好了....\n",
  }));
   
   setup();
   add_money("silver",10);
}
 int accept_object(object me, object obj)
{
	object pai;
	if (query("isok")==1) return 0;
        if( (string) obj->query("name") == "西洋表"
        || obj->query("id") =="xiyang biao")
	{
        message_vision("$N对$n点了点头：\n",this_object(),me);
        command("thank");
	command("say 这个东东，我太喜欢了！\n");
	command("say 这本42章经，就给你吧！\n");
	pai = new("/d/city2/obj/book14_8");
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
