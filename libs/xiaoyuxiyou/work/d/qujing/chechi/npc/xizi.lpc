// by snowcat oct 24 1997

inherit NPC;

mixed says ()
{
  string *msgs = ({
    "$N在台上走了几步。\n",
    "$N高声唱着什么。\n",
    "$N在空中使了一个花步，一个跟头翻了过来。\n",
    "$N口中念念有辞。\n",
    "$N一个回身走向台角。\n",
    "$N鞠了个躬。\n",
  });
  message_vision (msgs[random(sizeof(msgs))],this_object());
  return 1;
}

void create()
{
  set_name("戏子", ({"xi zi", "zi"}) );
  set("gender", "男性" );
  set("age", 35);
  set("long","一位装扮极为奇特的车迟国戏子。\n");

  set_level(2);
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

void init()
{
  remove_call_out ("says");
  call_out("says",random(3),this_object());
}



