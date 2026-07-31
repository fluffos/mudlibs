//回收的灵石必须原价格大于10
int jiage(object ob)
{
  if (ob->query("yuanbao")>10)
 return ob->query("yuanbao")/10;
 
 return 0;
}
int do_huishou(string arg)
{
    string msg,id_name;
	object me = this_player();
	object obj;
	int amount,duoyu;
     if (!arg)
     {
	object *pobj;
	pobj = all_inventory(me);
	pobj = filter_array(pobj,(: jiage($1) :));
	
	if (!sizeof(pobj))
	return 1;
	
	msg = ZJOBLONG"请选择你需要回收的物品：\n"
		ZJOBACTS2+ZJMENUF(2,2,6,30);
		
	 foreach (obj in pobj)
	 {
	  amount = obj->query_amount()?obj->query_amount():1;
	  msg += sprintf("%d份%s"ZJBR"(%d灵石):huishou %s"ZJSEP,amount,obj->query("name"),jiage(obj),obj->query("id"));
     }
     
	  msg += "取消:look\n";
	 tell_object(me,msg);
	 return 1;
	}
	//默认是string 需要后续转换成int
	if (sscanf(arg, "%s==%s", id_name, arg) == 2)
	{
	
	 obj = present(id_name,me);
	 amount = to_int(arg);
	 duoyu=amount-1;
	 if (duoyu < 0)
	 {
		 duoyu=0;
		}
	 if (amount < 1)
	 {
	     write("参数错误，请重新输入。\n");
	     return 1;
	 }
	 
	 if (!objectp(obj))
	 return notify_fail("你没有该物品\n");
	 
	 if (obj->query_amount()<amount)
	 return notify_fail("你好像没有那么多"+obj->query("name")+"\n");
	 
	 log_file("pay/huishou", ctime(time()) + "  " + me->query("name") + me->query("id") + "回收了" + chinese_number(amount) + "个" + obj->query("name") + "\n");
     //为啥我要放前面呢？如果物品数量没有了呢？小千穆注意一下哦！
     //emmmmm……
     me->add("yuanbao",jiage(obj)+jiage(obj)*(duoyu));
     obj->add_amount(-amount);
     
      write("你成功回收了该物品\n");
      return 1;
      
	}
	
	if (arg)
	{
	 obj = present(arg,me);
	 amount = obj->query_amount();
	 
	 if (amount)
	 return notify_fail(INPUTTXT("你有"+amount+"份，请问你要回收多少份"+obj->query("name"),"huishou "+arg+"==$txt#")+"\n");
	 	
	me->add("yuan_bao",jiage(obj));
	log_file("pay/huishou", ctime(time()) + "  " + me->query("name") + me->query("id") + "回收了一个" + obj->query("name") + "\n");
//	destruct(obj);
	destruct(obj);
	write("你成功回收了该物品\n");
	return 1;
	}
	return 1;
}
int help (object me)
{
	write(@HELP
指令格式: arm
 
可列出你(你)目前身上所携带的所有物品。
 
 
HELP );
	return 1;
}