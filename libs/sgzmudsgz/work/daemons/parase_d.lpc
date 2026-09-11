// parase_d.c
// this is used to parase the object
// by fire on Jan 1999
mixed sep_count_id(string str)
{
   string *sen;
   int s,num;
   if(!sizeof(str)) return 0;
   sen = explode(str, " ");
   s=sizeof(sen);
   if(s==1) return 0;
   num=to_int(sen[0]);
   if(num<=0) return 0;
   
   return ({ num, implode(sen[1..<1]," ")});
}

mixed sep_id_num(string str)
{
   string *sen;
   int s,num;
   if(!sizeof(str)) return 0;
   sen = explode(str, " ");
   s=sizeof(sen);
   if(s==1) return ({str,1});
   num=to_int(sen[s-1]);
   if(num<=0) return ({str,1});
   return ({implode(sen[0..<2]," "),num});

}
mixed retrieve_object(string str,mixed objs)
{
	object *theob;
	mixed ids;
	string id;
	int n;
	if(!sizeof(objs)) return 0;
    ids=sep_id_num(str);
	if(!ids) return 0;
	n=ids[1];
	id=ids[0];
	theob=filter_array(objs,(:member_array($(id),($1)->query_id())!=-1:));
	if(sizeof(theob)<n) return 0;
	   return theob[n-1];
}
mixed retrieve_num_object(string str,mixed objs)
{
   mixed ret;
   int num;
   ret=sep_count_id(str);
   if(!ret)
	   return retrieve_object(str,objs);
   num=ret[0];
   ret=retrieve_object(ret[1],objs);
   if(!ret) return 0;
   if((ret->query_is_money())||(ret->is_mergeable()))
	   return ({num,ret});
   return 0;
}
mixed query_my_ob(string str)
{
   return retrieve_object(str,all_inventory(this_body()));
}
mixed query_env_ob(string str)
{
	mixed obs=({});
	object env;
	env=environment(this_body());
	while(objectp(env))
	{
		obs+=all_inventory(env);
		env=environment(env);
	}
	return retrieve_object(str,obs);
}
mixed query_env_liv(string str)
{
	object env,env1;
	mixed obs;
	env=environment(this_body());
	env1=environment(env);
	while(objectp(env1))
	{
		env=env1;
		env1=environment(env);
	}
	obs=deep_inventory(env);
	obs=filter_array(obs,(: $1->is_living() :));
	return retrieve_object( str,obs);

}
mixed query_envmy_ob(string str)
{
	mixed ret;
	ret=query_env_ob(str);
	if(!ret)
		return query_my_ob(str);
	return ret;
}
mixed query_myenv_ob(string str)
{
	mixed ret;
	ret=query_my_ob(str);
	if(!ret)
		return query_env_ob(str);
	return ret;
}
mixed my_ob(string str)
{
	mixed ret;
	ret=query_my_ob(str);
	if(!ret) write("你身上没有"+str+"。\n");
	return ret;
}
mixed env_ob(string str)
{
	mixed ret;
	ret=query_env_ob(str);
	if(!ret) write("你周围没有"+str+"。\n");
	return ret;
}
mixed myenv_ob(string str)
{
	mixed ret;
	ret=query_myenv_ob(str);
	if(!ret) write("你身上和周围都没有"+str+"。\n");
	return ret;
}
mixed envmy_ob(string str)
{
	mixed ret;
	ret=query_envmy_ob(str);
	if(!ret) write("你周围和身上都没有"+str+"。\n");
	return ret;
}
mixed env_liv(string str)
{
	mixed ret;
	ret=query_env_liv(str);
	if(!ret) write("你周围没见到"+str+"。\n");
	return ret;
}