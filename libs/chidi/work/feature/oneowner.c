// rewrite by lonely@wmkj
// the function check_owner() should be put in init() of a given object.
// it will ensure that only the first user who get this 
// object can keep it, otherwise it will disappear automatically.

private static string obj_owner=0;
nomask void self_destroy();

void check_owner()
{
  object env=environment();

  if(!clonep()) return;

  if(!env) {
    call_out("self_destroy",1);
    return;
  }
    
  //for room or other containers.  
  if(!env->is_character()) {
    if(obj_owner) call_out("self_destroy",5+random(5));
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
  if(!obj_owner)
    obj_owner=env->query("id");
  else {
    if(obj_owner!=env->query("id"))
      call_out("self_destroy",2+random(5));
    else
      remove_call_out("self_destroy");  
      //one can still pick it up if loses it for a short while.
  }
}

void self_destroy()
{
  object env=environment();

  if(env) {
    if(env->is_character()) { 
      tell_object(env,"你突然发觉有人就在你身后，你猛然转身，那个人吓了一跳，连忙溜走了！\n");
      tell_object(env,"你赶紧检查身上的东西，发现"+this_object()->query("name")+"居然被那人偷走了，哎，只可惜没看清那人的样子。\n");  
    } else {
      tell_object(env,"有个人影溜了出来，趁所有人不注意，偷偷的拣起"+this_object()->query("name")+"溜走了。\n");
    }
  }
  
  destruct(this_object());
}

