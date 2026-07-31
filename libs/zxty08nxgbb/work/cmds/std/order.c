inherit F_CLEAN_UP;
int main(object me, string arg)
{
  string cmd,name;
  object obj;
  if( !arg || arg=="" || sscanf(arg, "%s to %s",name,cmd)!=2 )
  return notify_fail("你想让你的宠物干什么？\n");
  
  seteuid(getuid());
//  obj=LOGIN_D->find_body(name);
  obj=find_living(name);
  obj = present(name, environment(me));
  
  if (!obj) return notify_fail("宠物不在你的身边呢！\n"); 
  
  if (me->query("beastdied"))
        return notify_fail("你的神兽已经死亡，请用<recall reborn>让它先复活。\n");
  
  if(environment(me) != environment(obj))              
        return notify_fail("宠物不在你的身边呢！\n");        
  
    if ( obj->query("owner")!=me->query("id") )  
    	return notify_fail("你无权对"+obj->query("name")+"发号施令！\n");
  obj->force_me(cmd);
  write("执行命令OK!\n");
  return 1;
}

int help(object me)
{
     write(@HELP
指令格式:order ** to sth.
让主人可以对自己的宠物下任意命令	
HELP
    );
    return 1;
}

