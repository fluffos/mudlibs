// zhu.c 朱熹
// CLEANSWORD 1996/2/2

inherit NPC;
inherit F_DEALER;
inherit F_MAILQUEST;

void create()
{
	set_name("朱熹", ({ "zhu xi", "zhu" }));
	set("long", "朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
	set("gender", "男性");
	set("age", 65);
     set("start_room","/d/city/shuyuan");

	set_skill("literate", 300);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
set("vendor_goods",({
__DIR__"obj/shu2",
"/d/city/obj/baodian",
}));
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"朱熹说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
		"朱熹说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		"朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
	}) );
		carry_object("/d/riyuejiao/npc/obj/shuaiyitie");
}

void init()
{
   ::init();
   add_action("do_apply", "apply");
   add_action("do_confirm","confirm");
   this_player()->delete_temp("new_rank");
    add_action("do_list","list");
    add_action("do_buy","buy");
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/朱"))
		return 0; 
	ob->add_temp("mark/朱", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 50);
		return 1;
	}
	return 0;
}
int do_apply(string arg)
{
  string type,rank;   
  object me=this_player();
  string msg="你准备将";
  int afford;

   if (!arg) return notify_fail(@LONG
格式： apply <类别> to <称谓>
类别／价格／经验要求：
self        对自己的称呼      五百两黄金   1,000,000
rude        对自己的粗鲁称呼  五百两黄金   1,000,000
respect     别人对自己的尊称  五百两黄金   5,000,000

又：请勿使用不恰当的称谓。不然称呼被取消，500两
金子就白白扔了。至于恰当与否，则由巫师决定。

LONG);
  if (sscanf(arg,"%s to %s",type,rank)!=2)   return notify_fail(@LONG
格式： apply <类别> to <称谓>
类别／价格：
self          对自己的称呼         五百两黄金
rude          对自己的粗鲁称呼     五百两黄金
respect       别人对自己的尊称     五百两黄金

又：请勿使用不恰当的称谓。不然称呼被取消，500两
金子就白白扔了。至于恰当与否，则由巫师决定。

LONG);
  
  if (type!="self" && type!="respect" && type!="rude")
    return notify_fail("不能设置这种类型的称呼。\n");

  if (type!="respect" && me->query("combat_exp")<1000000) 
    return notify_fail("你经验那么低，本来就没人听说过你，不改也罢。\n");
  if ( type=="respect" && me->query("combat_exp")<5000000)
    return notify_fail("你本领还不够，别人不会听你这样叫的。\n");

  if( !(afford=me->can_afford(5000000)) )  {
     write("你带的钱不够。\n");
     return 1; 
  } else if( afford == 2 )  {
      write("现金交易，不收银票。你带的现金不够。\n");
      return 1;
  }

  switch (type) {
    case "self" : msg+="对自己的称呼从现在的“"+RANK_D->query_self(me);break;
    case "self_rude" : msg+="对自己的粗鲁称呼从现在的“"+RANK_D->query_self_rude(me);break;
    case "respect" :  msg+="别人对自己的尊称从现在的“"+RANK_D->query_respect(me);break;
  }
  msg+="”改成“"+rank+"”，是这样吗？(confirm)\n";
  write(msg);
  me->set_temp("new_rank/type",type);
  me->set_temp("new_rank/ready",1);
  me->set_temp("new_rank/rank",rank);
  return 1;
}

int do_confirm() {
  object me=this_player();
  int afford;

  if (!me->query_temp("new_rank/ready"))
     return notify_fail("你要确认什么？\n");

  if( !(afford=me->can_afford(5000000)) )  {
       write("你带的钱不够。\n");
       return 1; 
  } else if( afford == 2 )  {
      write("现金交易，不收银票。你带的现金不够。\n");
      return 1;
  }

  message_vision("$N拿出五百两金子，交给了$n。\n",me,this_object());
  message_vision("$N点了点头，拿出一份卷宗写了几笔。\n",this_object());
  me->pay_money(5000000);
  if (me->query_temp("new_rank/rank")=="cancel")
     me->delete("rank_info/"+me->query_temp("new_rank/type"));
  else 
     me->set("rank_info/"+me->query_temp("new_rank/type"),me->query_temp("new_rank/rank"));
  write("改动完毕。\n");
 log_file("change_rank",me->query("id")+" changes "+me->query_temp("new_rank/type")+" to "
      +me->query_temp("new_rank/rank")+" on "+ctime(time())+".\n");
 
 me->delete_temp("new_rank");
  return 1;
}

