// by snowcat oct 24 1997

inherit NPC;

mixed says ()
{
	object me = this_object();
  	string *msgs = ({
    "$N“啪”地拍了一下惊堂木。\n",
    "$N绘声绘色地说着什么。\n",
    "$N滔滔不绝地说着书。\n",
    "$N说得眉飞色舞。\n",
    "$N卖了个关子，停下不说了。\n",
    "$N端起碗喝了几口水，又说开了。\n",
  	});
  	message_vision (msgs[random(sizeof(msgs))],me);
	return 1; 
}

void create()
{
  set_name("说书老", ({"shuoshu lao", "lao"}) );
  set("gender", "男性" );
  set("age", 55);
  set("long","一位口若悬河的老人，正在敲木说书。\n");

  set("combat_exp", 5500);
  set("str", 25);
  set("attitude","heroism");
  set("chat_chance",10);
  set("chat_msg",({
  	(: says :),
  }));
  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("silver", 2);
}
