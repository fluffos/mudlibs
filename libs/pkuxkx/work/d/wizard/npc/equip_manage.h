#include <ansi.h>
#include <localtime.h>
inherit F_GEMS;
void autoloading(string arg, object ob,object who);
void disloading(string arg, object ob,object who);

//重新装载武器
int do_reload()
{
  int i, ltime, lbal;
  string  ldate;
  string *autoloads;
  object  uitem;
  object obj;
    
  object pl = this_player();
  object* invs = all_inventory(pl);
  
 if (pl->query_temp("get_taskob"))
  {
    if(pl->query("balance") < 2000000)
    {
      tell_object(pl,HIY"TASK状态下重新加载武器需要200金，你的存款不够！\n"NOR);
      return 1;
    }
    if (!pl->query_temp("confirm_task_reload"))
	{
		pl->set_temp(("confirm_task_reload"), 1);
        tell_object(pl, HIG"TASK状态下重载武器需要花费200金，如果你确定要重载，请再输入(reload)一次。\n"NOR);
		return 1;
	}
	pl->delete_temp("confirm_task_reload");
    tell_object(pl,"你花费了200金存款用于重新加载武器。\n");
    pl->add("balance",-2000000);
  }
/*   
  ldate=gctime(time(), 1);
  if ( pl->query("reload_date")!=ldate )
  {
    pl->set("reload_date", ldate);
    pl->set("reload_times",1);
  }
  else
  {
    ltime=pl->query("reload_times");
    ltime++;
    if ( ltime<=3 )
      lbal=1;
    else if ( ltime<=10 )
      lbal=15;
    else if ( ltime<=20 )
      lbal=30;
    else
      lbal=50;
    
    if ( pl->query("balance") < lbal*10000 )
    {
      tell_object(pl,"今日第"+chinese_number(ltime)+"次加载装备需要"+chinese_number(lbal)+"金。\n");
      return 1;
    }
    
    tell_object(pl,"今日第"+chinese_number(ltime)+"次加载装备支付了"+chinese_number(lbal)+"金。\n");
    pl->add("balance",-lbal*10000);
    pl->set("reload_times", ltime);
  }
*/  
  for(i=0;i<sizeof(invs);i++)
  {
    if(invs[i]->query("gem_ob_autoloaded"))
    {
      destruct(invs[i]);
    }
	else if (invs[i]->query("auto_load") && invs[i]->query("unwield_msg"))
	{
      destruct(invs[i]);
	}
  }
  
  uitem=new(UITEM_OB);
  uitem->set("id", pl->query("id"));
  uitem->check_save();
  uitem->restore();
/*  else
    tell_object(pl, sprintf("%s档案不存在。\n",uitem->query("id")));*/

	if ( arrayp(autoloads = pl->query("auto_load")) )
	{
		for (i = sizeof(autoloads)-1; i >= 0; i--)
		{
			if(autoloads[i][0..2]=="/u/"&&!wizardp(pl)) continue;
			if ( objectp(obj = new(autoloads[i])) && obj->move(pl) )
				write("\n" + obj->name() + "  loaded.\n\n");
			else
				write(HIY "你觉得好象失落了什么重要的东西，赶快通知巫师吧！\n\n" NOR);
		}
	}
  
  if ( uitem->load_equip(pl) )
    tell_object(pl,"好了，你走吧！\n"); 
  
  destruct(uitem); 
  return 1;
}

int do_autoload(string arg)
{
        object ob,who;
        mapping num,ob_dbase;
        who = this_player();
        if(!userp(who))
                return 0;
        if(who->query("level")<=15)
                return notify_fail("你根本没有资格自动加载，至少需要16级。\n");
        if(!arg)
                return notify_fail("你要设定什么为自动加载物品？\n");
        if(!ob=present(arg,who))
                return notify_fail("你要设定什么为自动加载物品？\n");
        if(!ob->is_gems())
                return notify_fail("这件东西不能设为自动加载！\n");
        if(!ob->query("weapon_prop")&&!ob->query("armor_prop"))
                return notify_fail("目前只能自动加载武器和盔甲！\n");
        if(ob->query("gem_ob_autoloaded"))
                        return notify_fail("这件东西已经是自动加载物品了！\n"); 
		 if (!ob->query("no_report_jh"))
		 {
		  return notify_fail("未鉴定物品不能加载。\n");
		 }

        if( ob->query("equipped") )
        {
                tell_object(who,"你必须先放下这样东西方可自动加载。\n");
                return 1;
  }
        tell_object(who,"你确定要把"+ob->query("name")+"设为自动加载物品吗？(请输入yes或者no。)\n");
        input_to( (: autoloading :), ob ,who);
        
        return 1;
        
}

void autoloading(string arg, object ob,object who)
{
     string okey;
     object uitem;
     
     if(arg!="y"&&arg!="Y"&&arg!="yes"&&arg!="YES")
       return ;
     
     uitem=new(UITEM_OB);
     uitem->set("id", who->query("id"));
//     if ( uitem->check_save() )
      uitem->restore();
                
     if(uitem->query("gem_weapon_autoload_num") > 2&&ob->query("weapon_prop"))
     {
       tell_object(who,"你已经设定过三件自动加载的武器了，请用disload <物品id>取消某件的自动加载。\n");
       return ;
     }
     else if(uitem->query("gem_armor_autoload_num")>11&&ob->query("armor_prop"))
     {
       tell_object(who,"你已经有十二件设定过自动加载的盔甲了，请用disload <物品id>取消某一件的自动加载。\n");
       return ;
     }
     if (who->query("balance")<=100000)
     {
       tell_object(who,"自动加载是要花钱的，你的银行上可没有足够的钱。\n");  
       return;
     }
     tell_object(who,"目前自动加载无需费用。\n");
     okey=uitem->autoload_equip(ob, who);
     uitem->save();
     destruct(uitem);
   
     command("walkby "+who->query("id"));
     tell_object(who,ob->query("name")+"已经被设定为自动加载物品！\n");
     return ;        
}

int do_disload(string arg)
{
        object ob,who;
        
        mapping num,ob_dbase;
        who = this_player();
        if(!userp(who))
                return 0;
        if(!arg)
                return notify_fail("你要取消哪个自动加载物品？\n");
        if(!ob=present(arg,who))
                return notify_fail("你要取消哪个自动加载物品？\n");
        if(!ob->query("gem_ob_autoloaded"))
                        return notify_fail("这件东西不是自动加载物品！\n");
        if(ob->query("owner_id") &&
           ob->query("owner_id")!=getuid(who) )
          return notify_fail("你只能取消自己拥有的装备的自动加载状态。\n");
        if( ob->query("equipped") )
        {
                tell_object(who,"你必须先放下这样东西方能取消自动加载。\n");
                return 1;
  }
        tell_object(who,"你确定要把"+ob->query("name")+"取消自动加载吗？(yes/no)\n");
        input_to( (: disloading :), ob ,who);
        return 1;
        
}

void disloading(string arg, object ob,object me)
{
     string okey;
     object uitem;
     
     if(arg!="y"&&arg!="Y"&&arg!="yes"&&arg!="YES")
       return ;

     uitem=new(UITEM_OB);
     uitem->set("id", me->query("id"));
//     if ( uitem->check_save() )
       uitem->restore();
/*     else
     {
       tell_object(me,"你应该先转换成新装备存储模式以后再来进行disload。\n");
       return;
     }*/
     
     uitem->disload_equip(ob, me);
     uitem->save();
     destruct(uitem);
                
     command("die "+me->query("id"));
     tell_object(me,ob->query("name")+"已经被取消自动加载！\n");
}

int do_rename(string arg)
{
        object  me,ob;
        string item,msg,arg_old;
        int cost;
        
        me = this_player();
        
        if( !arg ) return notify_fail("你要给什么取个名字？\n");
        
        if(sscanf(arg,"%s as %s",item,msg) != 2)
            return notify_fail("格式为rename <物品id> as <名字>。\n");

        if(me->query("level")<=15)
            return notify_fail("你根本没有资格修改装备名称，至少需要16级。\n");
        
        if(!(ob=present(item,me)))
            return notify_fail("你身上没这样东西啊。\n");
        
        if(!ob->is_gems())
            return notify_fail("不能给这样东西改名！\n");
        
        if(!ob->query("weapon_prop")&&!ob->query("armor_prop"))
            return notify_fail("目前只能自动给武器和盔甲改名！\n");         
        
        if(ob->query("no_gem_rename")||ob->query("suit"))
        {
            tell_object(me,"这样东西不能更改名字！\n");
            return 1;       
        }   
        
        if(ob->query("gem_ob_autoloaded"))
        {
            tell_object(me,"这样东西正在自动加载，不能再更改名字了。\n");
            return 1;               
        }
         
        msg += "$NOR$";       
        msg = replace_string(msg, "$BNK$","");//不允许闪烁
        msg = replace_string(msg, "$REV$","");//不允许反色
        msg = replace_string(msg, "$U$","");//不允许下划线              
        msg = F_NAME->replace_color(msg);
       
        if(strwidth(msg)-COLOR_D->color_len(msg) > 25)
            return notify_fail("名字也太长了，不可以接受！\n"); 
        
        cost=10;
        if ( me->query("equip_rename_times")<3 )
          cost=cost/10;
        
        if (me->query("advance_balance")<=cost)
            return notify_fail("改名是要花钱的，你的银行上可没有足够的钱。\n");  
        
        me->add("advance_balance",-cost); //扣5gold
        me->add("equip_rename_times",1); //计算修改名字的次数
        tell_object(me,"已经从你户头扣除"+to_chinese(cost)+"根金条来抵扣改名费用。\n");  
        ob->set("name",msg);
        ob->set("have_set_name",1);
        ob->delete("armor/name");
        ob->delete("weapon/name");
        ob->delete("ring/name");
        command("wait");
        write("ＯＫ！\n");
        return 1;
}
