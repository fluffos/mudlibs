inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(CYN"磨刀石"NOR, ({"modao shi", "shi", "stone" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块普普通通的磨刀石，不知道有啥用处。\n");
                set("unit", "块");
                set("value", 200);
                set("point", 1); //恢复永久耐久的点数
               
        }
}

void init()
{	
	add_action("do_mo", ({ "mo", }));
}

int do_mo(string arg)
{
    object ob;
    object who=this_player(), uitem;
    
    if (who->is_busy() || who->is_fighting())
    {
      tell_object(who,"你正忙着哪！\n");
	    return 1;
    }
   
    if (!arg)
	  {
		  return notify_fail("你要打磨什么神兵？\n");
	  }

    if(!ob=present(arg,who))
    {
        return notify_fail("你要打磨什么神兵？\n");
    }
    
    if(!ob->is_gems() || 
    	 (!ob->query("cjg_weapon") &&
    	  ob->query("suit")!="cjg_level1") )
    {
        return notify_fail("这个东西无法打磨！\n");
    }
    
    if ( ob->query("max_rigidity") >= 300 )
    {
        return notify_fail("这个东西已经足够锋利，不需要再打磨了！\n");
    }
    
    if(!ob->query("weapon_prop"))
    {
        return notify_fail("只能用来打磨神兵！\n");	
    }
    
    uitem=new(UITEM_OB);
    uitem->set("id", who->query("id"));
//    if ( uitem->check_save() )
      uitem->restore();
    
    if(ob->query("max_rigidity") < ob->query("rigidity"))
    {
        //bug weapon
        ob->set("max_rigidity", ob->query("rigidity"));
		    if(ob->query("gem_ob_autoloaded") == 1)
		    {
          if ( ob->query("autoload_serial") )
            uitem->update_autoload(ob->query("autoload_serial"), "set", ([ "rigidity": ob->query("max_rigidity") , "max_rigidity":ob->query("max_rigidity") ]));
		    }
    }
    
    ob->add("max_rigidity",this_object()->query("point"));
    ob->set("rigidity",ob->query("max_rigidity"));
    
	  if(ob->query("gem_ob_autoloaded") == 1)
	  {
      if ( ob->query("autoload_serial") )
        uitem->update_autoload(ob->query("autoload_serial"), "set", ([ "rigidity": ob->query("max_rigidity") , "max_rigidity":ob->query("max_rigidity") ]));
	  }
	  
	  uitem->save();
    destruct(uitem);
    write(sprintf("%s闪闪发光，锋利更胜从前！\n",ob->query("name")));          
    destruct(this_object());
    return 1;
}