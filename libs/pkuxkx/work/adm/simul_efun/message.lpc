// message.c
// Modified by iszt@pkuxkx, 2007-03-12, added mixed skip_combat in combat_msg()
// seagate@pkuxkx 2010/12/04
// gender获得改用me->gender()函数获得

//_othersclass, specified class name if this message is relay to others in the same room
//it's designed for user hide others message. For example, wield, wear.
//please read /cmds/std/wield.c

varargs void message_vision(string msg, object me, object you,string _othersclass)
{
  string my_gender, your_gender, my_name, your_name;
  string str1, str2, str3;

  if(!_othersclass) _othersclass = "vision";

  my_name= me->name();
  my_gender = me->gender();
  str1 = replace_string(msg,  "$P", gender_self(my_gender));
  str1 = replace_string(str1, "$N", gender_self(my_gender));
  //偷懒用在这里判定pfm是否需要简化信息输出
  if (me->query_temp("pfm_skip"))
  {
	if( you ) {
		your_name= you->name();
		your_gender= you->gender();
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		message("vision", str2, you);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
	  }
	  message("vision", str1, me);
  }
  else
	{
	  str3 = replace_string(msg,  "$P", my_name);
	  str3 = replace_string(str3, "$N", my_name);
		 
	  if( you ) {
		your_name= you->name();
		your_gender= you->gender();
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		message("vision", str2, you);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	  }
	  message("vision", str1, me);

	  if (environment(me))
	  {
		if (!environment(me)->query("least_msg") && !environment(me)->query("real_dark"))
		{
		  message(_othersclass, str3,  environment(me), ({ me, you}) );
		}
	  }
	}
}

/*varargs void message_vision_old(string msg, object me, object you,string _othersclass)
{
  string my_gender, your_gender, my_name, your_name;
  string str1, str2, str3;

  if(!_othersclass) _othersclass = "vision";

  my_name= me->name();
  my_gender = me->gender();
  str1 = replace_string(msg,  "$P", gender_self(my_gender));
  str1 = replace_string(str1, "$N", gender_self(my_gender));
  str3 = replace_string(msg,  "$P", my_name);
  str3 = replace_string(str3, "$N", my_name);
	 
  if( you ) {
	your_name= you->name();
	your_gender= you->gender();
	str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
	str2 = replace_string(str2, "$p", gender_self(your_gender));
	str2 = replace_string(str2, "$N", my_name);
	str2 = replace_string(str2, "$n", gender_self(your_gender));
	message("vision", str2, you);
	str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
	str1 = replace_string(str1, "$n", your_name);
	str3 = replace_string(str3, "$p", your_name);
	str3 = replace_string(str3, "$n", your_name);
  }
  message("vision", str1, me);

  if (environment(me))
  {
	if (!environment(me)->query("least_msg") && !environment(me)->query("real_dark"))
	{
	  message(_othersclass, str3,  environment(me), ({ me, you}) );
	}
  }
 }
//pfm_skip用于一些大数量使用的pfm，让其不对房间内的id发出信息,
//使用这个在pfm文件里面里面控制比较好,不需要是个pfm就判断一次，减少消耗
varargs void message_perform(string msg, object me, object you)
{
  string my_gender, your_gender, my_name, your_name;
  string str1, str2;
  my_name= me->name();
  my_gender = me->gender();
  str1 = replace_string(msg,  "$P", gender_self(my_gender));
  str1 = replace_string(str1, "$N", gender_self(my_gender));

 if( you ) {
	your_name= you->name();
	your_gender= you->gender();
	str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
	str2 = replace_string(str2, "$p", gender_self(your_gender));
	str2 = replace_string(str2, "$N", my_name);
	str2 = replace_string(str2, "$n", gender_self(your_gender));
	message("vision", str2, you);
	str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
	str1 = replace_string(str1, "$n", your_name);
 }
 message("vision", str1, me);
 
}
*/
varargs void combat_msg(string msg,int msg_level, object me, object you)
{
  string my_gender, your_gender, my_name, your_name;
  string str1, str2, str3;
  object *ob;
  int i;
  mixed skip_combat;

    object room = environment(me);

        
  my_name= me->name();
  my_gender = me->gender();
  str1 = replace_string(msg,  "$P", gender_self(my_gender));
  str1 = replace_string(str1, "$N", gender_self(my_gender));
  str3 = replace_string(msg,  "$P", my_name);
  str3 = replace_string(str3, "$N", my_name);
  ob = all_inventory(environment(me));

  if( you )
  {
    skip_combat = you->query("env/skip_combat");
    if(!intp(skip_combat))
      skip_combat = 2;
    your_name= you->name();
    your_gender= you->gender();
    str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
    str2 = replace_string(str2, "$p", gender_self(your_gender));
    str2 = replace_string(str2, "$N", my_name);
    str2 = replace_string(str2, "$n", gender_self(your_gender));
    if(skip_combat <= msg_level)
          message("vision", str2, you);
    str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
    str1 = replace_string(str1, "$n", your_name);
    str3 = replace_string(str3, "$p", your_name);
    str3 = replace_string(str3, "$n", your_name);
  }
  skip_combat = me->query("env/skip_combat");
  if(!intp(skip_combat))
    skip_combat = 2;
  if(skip_combat <= msg_level)
    message("vision", str1, me);
    
  for(i=0;i<sizeof(ob);i++)
  {
    skip_combat = ob[i]->query("env/skip_combat");
    if(!intp(skip_combat))
      skip_combat = 2;
    
    if( (skip_combat <= msg_level) && 
        (userp(ob[i]) || ob[i]->is_relay_npc()==1) && 
        ob[i]!=me && 
        ob[i]!=you )
    {      
//在某些房间里屏蔽掉他人的战斗信息，避免刷屏
//环境变量broadcast_combat非0的时候表示战斗信息需要广播，否则禁止广播战斗信息
      if( (objectp(room) && room->query("least_msg") == 1) || (!ob[i]->query("env/broadcast_combat") && me->get_damage_origin_object()!=ob[i]) )
      {
        if(member_array(me,ob[i]->query_enemy()) == -1)               
          continue;
      }
      message("vision", str3,  ob[i]);
    }
  }
}

void tell_object(object ob, string str)
{
  message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{
  if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{
  message("shout", str, users());
}

void write(string str)
{
  if( this_player() )
    message("write", str, this_player());
  else if( previous_object() )
    message("write", str, previous_object());
  else
    efun::write(str);
}

varargs void say(string str, mixed exclude)
{
  if( living(previous_object()) )
    message("say", str, environment(previous_object()), previous_object());
  else if( this_player() )
    message("say", str, environment(this_player()), this_player());
}
