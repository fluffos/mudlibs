int is_unique()
{
    return 1;
}

nomask int violate_unique()
{
    object *ob;
    int i;

    if( !clonep(this_object()) ) return 0;
    // Find all the cloned instance of this_object()
    ob = filter_array( children(base_name(this_object())), (: clonep :) );
    return sizeof(ob) > 2;
}

object create_replica()
{
    string replica;
    object obj;
    seteuid(getuid());
    if( stringp(replica = this_object()->query("replica_ob")))
        obj = new(replica);
    else
        obj = 0;
    this_object()->move("/d/death/emptyroom");
    call_out("destruct_me",1,this_object());
    return obj;
}

void destruct_me(object ob)
{
   destruct(ob);
   return;
}

void init()
{
   call_out("check_rumor",2,this_object());
}

void check_rumor(object ob)
{
   object env;
   if(!objectp(ob)) return;

   env=environment(ob);
   if( env->is_character() && ob->query("rumor")!=env->query("id"))
   {
    foreach( object u_ob in all_inventory(env) )
   if( objectp(u_ob) && u_ob != ob && u_ob->is_unique() )
    {
        write(ob->name()
              +HIW"发出一道白光，消失了！看来是宝物拿太多了。 \n"NOR);
        destruct(ob);
        return;
    }
    ob->set("rumor",env->query("id"));    
    message("channel:rumor",HIM"【江湖传闻】据说"+env->query("name")
    +HIM"得到"NOR+ob->query("name")+HIM"啦！\n"NOR,users());
   } else
   if( !env->is_character() && ob->query("rumor")!=env->query("short")
      && ob->query("rumor")!=env->query("name"))
   {
    if( env->query("short") )
    {
      ob->set("rumor",env->query("short"));
      message("channel:rumor",HIM"【江湖传闻】据说"+ob->query("name")
      +HIM"在"+env->query("short")+HIM"中出现了！\n"NOR,users());
    } else
    {
      ob->set("rumor",env->query("name"));
      message("channel:rumor",HIM"【江湖传闻】据说"+ob->query("name")
      +HIM"在"+env->query("name")+HIM"中出现了！\n"NOR,users());
    }
   }                       
   return;
}
