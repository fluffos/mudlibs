//装备自动回收函数
void auto_dest()
{
  object ob=this_object();
  
  if ( !ob->query("rent_time") )
    return;
  
  if ( ob->query("rent_time") &&
       ob->query("rent_time")<time() )
  {
    write("只见朝廷派来一个士兵收走了你租借的装备。\n");
    destruct(ob);
  }
  else
    call_out("auto_dest", 60);
}