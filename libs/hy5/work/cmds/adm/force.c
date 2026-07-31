inherit F_CLEAN_UP;
int main(object me, string arg)
{
  string cmd,objname;
  object obj;
  if( !arg || arg=="" || sscanf(arg, "%s to %s",objname,cmd)!=2 )
  return notify_fail("你想让他干什么？\n");
  seteuid(getuid());
//  obj=LOGIN_D->find_body(objname);
  obj=find_living(objname);
  obj = present(objname, environment(me));
  if(!obj)   obj=find_living(objname);
  if(!obj) return notify_fail("find_body找不着人那！\n");
    if ((int)wiz_level(me) < (int)wiz_level(obj) )  return notify_fail("你无权对"+me->name(1)+"发号施令。\n");
  obj->force_me(cmd);
  log_file("force_cmds",sprintf("%s force %s to %s",me->short(1),obj->short(1),cmd));
  return 1;
}

int help(object me)
{
     write(@HELP
指令格式:force sb. doing sth.
HELP
    );
    return 1;
}

