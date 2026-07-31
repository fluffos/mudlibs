inherit NPC;
void create()
{
   set_name("小桂子",({"xiao guizi"}));
	set("gender", "男性");
   set("age",14);
   set("combat_exp",200);
   
   set_skill("unarmed",5);
   set_skill("parry",5);
   set_skill("dodge",5);
   set("chat_chance",5);
   set("chat_msg",({
 "小桂子道:当了太监好,吃穿不用跑.\n",
 "小桂子道:要想见皇上的,住大屋子的,跟我当太监来哪.\n",
 "小桂子道:当了太监,老婆就管不着啦,有多好.\n",
 "小桂子道:真想出去赌二把.\n",
 "小桂子道:要是我有一把骰子就好了.\n",
 }));
   set("inquiry",([
   "进宫":"你问海公公就是.\n",
   "太监":"你问海公公就是.\n",
   ]));
 setup();
 add_money("silver",1);
 }

 int accept_object(object me, object obj)
{
	object pai;
	if (query("isok")==1) return 0;
        if( (string) obj->query("name") == "骰子"
        || obj->query("id") =="shai zi")
	{
        message_vision("$N对$n笑了笑：\n",this_object(),me);
        command("cool");
	command("say 真了解我，我就是要这个！\n");
	command("say 我手上的42章经五，送给康亲王了！\n");
	this_object()->set("isok",1);
set("isok",1);
        call_out("destroying", 0, obj,me);                       
	return 1;	
	}
else       return 0;
}

void destroying(object obj, object ob, object me)
{   

   if(obj) destruct(obj);
}
