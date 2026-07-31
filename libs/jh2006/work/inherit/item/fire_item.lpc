// fire_item.c

inherit ITEM;

void fire_decay()
{
    object obj, env;
    
    obj = this_object();
    if(!obj) return;
    
    add("light/time", -1);
    
    if(query("light/time") >= 1 && query("light/on"))
             call_out("fire_decay", 1);
    else {
    	     if((string)query("light/env")){
    	          if(!env = find_object(query("light/env")))
                       env = load_object(query("light/env"));
                  if(env->query_temp("light_id") == obj){
    	               env->light_gone();   // turn light off in the room.
                       env->delete_temp("light_id");
                       }
                  }
             delete("light/on");   // turn it off now.
             set("light/time", obj->query("light/time"));

             if((string)obj->query("light/off_msg"))
	             message_vision(obj->query("light/off_msg"), obj);
             else message_vision("$N慢慢熄灭了。\n", obj);  	    
        }
}

