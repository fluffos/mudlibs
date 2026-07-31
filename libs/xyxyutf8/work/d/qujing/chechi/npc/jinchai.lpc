// by snowcat oct 24 1997

inherit NPC;

mixed says ()
{
  object me = this_object();	
  string *msgs = ({
    "$N吃吃一笑，抿嘴看着你。\n",
    "$N含情脉脉地对你说．．．．我．．．．\n",
    "看来$N很想跟你．．．．如果你愿意，也请下一次 sleep 命令。\n",
    "$N冲着你会心地一笑，点了点头。\n",
    "$N很想跟你．．．．\n",
    "$N对你婉尔一笑。\n",
  });
  message_vision (msgs[random(sizeof(msgs))],me);
  return 1;
}

void create()
{
  set_name("金钗女", ({"jinchai nu", "nu", "girl"}) );
  set("gender", "女性" );
  set("age", 20);
  set_level(5);
  set("long","一位柳眉粉面含笑，蛾裙领露酥胸的美女。\n");

  set("attitude","heroism");
  set("chat_chance",10);
  set("chat_msg",({
  	(: says :),
  }));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init()
{
  if(userp(this_player())) 
	add_action ("do_sleep","sleep");
}

int do_sleep (string arg)
{
  object me = this_object();
  object who = this_player();
  if( !arg || !id(arg) )
  	return 0;
  message_vision ("$N搂着$n柔软的身体，不由得心醉神迷．．．．\n\n",who,me);
  who->command_function("remove all");
  who->start_busy(3,3);
  remove_call_out ("get_fainted");
  call_out ("get_fainted",1,who,me);
  remove_call_out ("says");
  call_out("says",40,me);
  return 1;
}

void get_fainted (object who, object me)
{
  object *objs = all_inventory(who);
  int i = sizeof (objs);
  message_vision ("$N对$n神秘地一笑。\n\n",me,who);
  who->unconcious();    
  while (i--)
  {
    object obj = objs[i];
    command("get "+obj->query("id")+" from "+who->query("id"));
  }
}

int accept_money(object me,int v)
{
if ( v>=10000 )
            {
            command("thank");
            random_move();
            return 1;
            }
return 1;
 }
 
