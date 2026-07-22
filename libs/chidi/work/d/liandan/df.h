void init()
{ 
        add_action("do_zhuyao","zhuyao");
        add_action("do_fangdan","fangyao");
        add_action("do_liandan","liandan"); 
}

int do_zhuyao(string arg)
{
    object obj;
    object ob;
    object me = this_player();

    if(!arg) return notify_fail("你要拿什么东西当主药？\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("你身上并没有这样东西!\n");

  if(me->is_busy())
  return notify_fail("您现在正忙,等一下再挖吧!\n");


    return do_yao(me, obj);

}

//检查主药是否放置成功
int do_yao(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
    me = this_player();
 
    if (me->query_temp("zhuyao"))
    return notify_fail("对不起你已经拿"+me->query_temp("zhuyaoname")+"做主药了!\n");

    foreach ( ob in all_inventory(me)){
    if (ob->short(1)!=arg) continue;
    if (!ob->query("zhuyao")) {
    write("这样东西并不能做主药!\n");
      return 1;
    }
    write(HIR"你拿"+ob->name()+HIR"做主药!\n"NOR);
    me->set_temp("zhuyao",ob->query("zhuyao"));
    me->set_temp("zhuyaoname",""+ob->name()+"");
    destruct(ob);
    return 1;
    }
}

//检查副药是否放置成功
int do_fangdan(string arg)
{
    object obj;
    object ob;
    object me = this_player();

    if(!arg) return notify_fail("你要放什么药进去？\n");

    if( !me->query_temp("zhuyao"))
    return notify_fail("练丹要先放主药,要不然练不出好丹!\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("你身上并没有这样东西!\n");

    return do_dan(me, obj);

}


// 设置炼药的是否成功的一些参数，重点是jh_dan
int do_dan(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
  
    foreach ( ob in all_inventory(me)){
    if (ob->short(1)!=arg) continue;
    if (!ob->query("yao")) {
    write("这样东西并不能拿来练药!\n");
    return 1;
    }

    if (me->query_temp("danname/"+ob->query("id")+""))
    return notify_fail("你已经把"+ob->name()+"放进练丹炉了!\n");

	if (ob->query("random"))
    me->add_temp("liandan/random",ob->query("random"));

    me->set_temp("danname/"+ob->query("id")+"",1);

	///////////////////////////////////////////////////////
    me->add_temp("jh_dan",1);  //控制炼药成功的核心值，大于4,小于20则可以容易练成
    ////////////////////////////////////////////////////////
	
	write(HIR"你把"+ob->name()+HIR"放进了炼丹炉!\n"NOR);
    destruct(ob);
    return 1;
    }
}


int do_liandan(string arg)
{
    int shoubi,tui,all,zhuyao,all2,jh,liandan;
    object dan;
    object me = this_player();
    shoubi = me->query_temp("liandan/shoubi");
    tui = me->query_temp("liandan/tui");
    all = me->query_temp("liandan/all");
    all2 = me->query_temp("liandan/random");
    zhuyao = me->query_temp("zhuyao");
    jh = me->query_temp("jh_dan");
    liandan = me->query_skill("liandan-shu",1);

    if (!arg) return notify_fail("你要练哪个种类的丹？\n");

    if (!me->query_temp("liandan"))
    return notify_fail("你没放丹,你练个屁!\n");


	// By jh@ty 以下是随机炼丹的程序!    
    if (arg == "random") {
    me->add("combat_exp",1000);
    me->delete_temp("zhuyaoname");
    me->delete_temp("danname");
    
	// By jh@ty 炼丹的额外奖励!
    me->improve_skill("liandan-shu", me->query_int()*300+random(100));
    me->add("combat_exp",jh*1000+random(1000));
    me->add("potential",jh*100+random(500));
    me->start_busy(5);
    write(HIR"你在炼丹的时候不知不觉经验也随着上去了!\n"NOR);


