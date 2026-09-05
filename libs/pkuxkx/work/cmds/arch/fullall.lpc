
inherit F_CLEAN_UP;

string *gifts=({ "qi","jing" });
string *gifts1=({"jingli","neili" });

int main(object me, string str)
{
    int i;
    object obj;

    if( !str || str == "")
        obj = me;
    else if ( !obj = present(str,environment(me)))
        return notify_fail("对象错误: 找不到"+str+"\n");
    
    for( i = 0; i < sizeof(gifts); i++ )
    {
        obj->set(gifts[i],obj->query("max_"+gifts[i]));
        obj->set("eff_"+gifts[i],obj->query("max_"+gifts[i]));
    }
    for( i = 0; i < sizeof(gifts1); i++ )
    {
        obj->set(gifts1[i],obj->query("max_"+gifts1[i]));
    }
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
      obj->clear_condition();
  if(me!=obj)
	  log_file("wiz/full",sprintf("[%s] %s full %s\n",
                        ctime(time()), geteuid(me), geteuid(obj)));
    write("恢复成功。\n");
    return 1;
}

int help(object obj)
{
  write(@HELP
指令格式 : full <对象>

利用此指令可完全恢复生物的状态并清除一切condition。
HELP
    );
    return 1;
}
