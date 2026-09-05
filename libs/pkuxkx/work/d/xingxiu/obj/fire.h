int do_make(string arg)
{
	object *obj, me, wood, fire;
	string name, name2;
	int i;
	me = this_player();
        if (arg!="fire") 
        	return notify_fail("你要用火折来干什么？\n");
  if(!environment(me)->query("outdoors"))
  	return notify_fail("只能在室外生火。\n");
  obj = all_inventory(me);
  for(i = 0; i < sizeof(obj); i++)
  {
  	wood = obj[i];
  	if(wood->query("material") == "wood")
  		break;
  }
  if(wood->query("material") != "wood") 
  	return notify_fail("你没有引火用的木柴，无法生火。\n");
  name = wood->query("name");
  name2 = this_object()->query("name");

  message_vision("$N用" + name2 + "，点燃了" + name + "，生起一堆篝火。\n", this_player());
  fire = new("/obj/recipe/campfire.lpc");
  fire->move(environment(me));
  destruct(wood);
	destruct(this_object());
  return 1;
}