// oneowner.c
// the function check_owner() should be put in init() of a given object.
// it will ensure that only the first user who get this 
// object can keep it, otherwise it will disappear automatically.

// mon 2/7/98

protected nosave string obj_owner=0;
nomask void self_destroy();

void check_owner()
{
  object *ob_list;
  object env=environment();
  int preorder;
  
  if(!clonep()) return;
  if(!env) {
    call_out("self_destroy",1);
    return;
  }
  //for room or other containers.  
  if(!env->is_character()) {
    if(obj_owner) call_out("self_destroy",5+random(5));
    preorder = this_object()->query("preorder");
    if (preorder)
	  call_out("self_destroy",1);
    return;
  }  
  //for npc.
  if(!userp(env)) {
    if(obj_owner)
      call_out("self_destroy",5+random(5));
    return; 
    //allow NPC to carry it if no one has own it.
  }  
  //following is for user.   
/*  if(!obj_owner)
    obj_owner=env->query("id");
  else {
    if(obj_owner!=env->query("id"))
      call_out("self_destroy",2+random(5));
    else
      remove_call_out("self_destroy");  
      //one can still pick it up if loses it for a short while.
  }
*/
  ob_list = children(base_name(this_object()));
  if (sizeof(ob_list) > 1)
	  call_out("self_destroy",1);
}

void self_destroy()
{
  object env=environment();
  object *ob_list;
  object oldenv,oldobj;
  int i;
  int preorder;//先拿优先
  string msg;

  if(env) {
    ob_list = children(base_name(this_object()));
    for (i=0;i<sizeof(ob_list);i++)
	    if (ob_list[i] != this_object())
	    {
		    oldenv = environment(ob_list[i]);
		    oldobj = ob_list[i];
		    if (oldenv)
			    break;
	    }
	preorder = this_object()->query("preorder");
    if (!oldenv)
    {
    	if (preorder)
    		this_object()->delete("env/invisibility");
	    return;
	}
	    
	if (!preorder)	{//后拿优先
	    if (env->is_character())
		    msg = "飞到了" + env->name() + "手中。\n";
	    else return;
	    tell_object(oldenv,"天上忽然传来一声断喝："+ this_object()->query("name")+"现在归我了！\n");
	    tell_object(oldenv,"只见"+this_object()->query("name")+"凌空而去," + msg);  
	    destruct(oldobj);
    }
    else { //先拿优先
    	//这样可能会造成先拿的兵器destruct后,原有update出的兵器仍然不可见
    	//但cleanup后即可解决,只会影响更新速度,不会有根本问题
    	this_object()->set("env/invisibility",1);
    }
  }
  
}
