// dizi.c

inherit NPC;

void create()
{
	int skill;

	set_name("中年渔翁", ({ "yu weng", "fisherman", "laoyuweng" }) );
	set("gender", "男性" );
	set("age", 60+random(10));
	set("long", "这是一位满脸红光的中年人,身披绿蓑衣,悠然自得。
由于他经常出海,你可以向他打听出海的事情.\n");

	set("combat_exp",4000);


	set_skill("dodge", 110);
	set_skill("unarmed", 110);

	setup();
	carry_object("/d/hainan/obj/shuoyi")->wear();
}
void init()
{
   add_action("do_ask","ask");
}
void on_board()
{
	object ob,room;
      room = load_object("/d/hainan/duchuan");
	room->delete("exits/out");
      room = load_object("/d/hainan/haibian");
	room->delete("exits/enter");
		message("vision", "老渔翁把踏脚板收了起来，划起桨来，扁舟向波涛汹涌的大海中驶去。\n",room );	
		message_vision("$N把踏脚板收了起来，划起桨来，扁舟向波涛汹涌的大海中驶去。\n",this_object());	
remove_call_out("on_board");
		if( clonep(this_object()) ) call_out("arrive", 30);
	else
		this_object()->move("/d/hainan/haitan");
}

void arrive()
{
	object ob,room;
      ob=this_player();
   if (living(ob)&&environment(ob)==environment())  {
	room = load_object("/d/hainan/haibian");
      message_vision("老渔翁把一块踏脚板搭上堤岸，道:到啦。\n",this_object());
      message("vision", "大海中摇来一艘小船，小船慢慢的停在了港边。船夫把一块踏脚板搭上堤岸。\n",room);
		message_vision("$N顺着踏脚板走上岸去。\n",ob);
		message("vision",ob->name()+"顺着踏脚板走上岸来。\n",room);
		ob->move("/d/hainan/haibian");
      message("vision", "老渔翁收起踏脚板，慢慢的把小船驶向大海。\n",room);
    }
	this_object()->move("/d/hainan/haitan");
    return;
}

int do_ask(string arg)
{
	object me,room;

	me=this_player();	
	
      if((arg!="yu weng about out")&&(arg!="yu weng about 出海")) return 0;
	message_vision("老渔翁从大石后面拖出一条小船，对$N道:这位客官,上船吧。\n",me);
	load_object("/d/hainan/haitan")->set("exits/enter","/d/hainan/duchuan");
	this_object()->move("/d/hainan/duchuan");
	load_object("/d/hainan/duchuan")->set("exits/out", "/d/hainan/haitan");

	if( clonep(this_object()) ) call_out("on_board", 10);

      return 1;
}
