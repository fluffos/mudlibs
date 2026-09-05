#include <ansi.h>
inherit ITEM;

int do_throw_in(object me, object obj, object dest);
void remove_in_use(object dest);

void init()
{
        add_action("do_put", "put");
        add_action("do_throw", "throw");
        add_action("do_get", "get");
}

void create()
{
        set_name(YEL"熔炉"NOR, ({"rong lu", "furnace", "lu"}));
        set_weight(1000000);
        set("no_get",1);
        set_max_encumbrance(70000);
        set("no_put",1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "鼎");
                set("long", "一鼎小巧精致的熔炉，可以用来铸造各种武器和防具。\n"NOR);
                set("value", 100000);
        }
setup();
}

int do_put(string arg)
{
	      string target, item;
        object obj, dest;
        object me = this_player();
        if(!arg) 
        	return notify_fail("你要将什么东西放进哪里？\n");
        if( sscanf(arg, "%s in %s", item, target)!=2 )
          return notify_fail("你要给谁什么东西？\n");
	      dest = present(target, me);
        if( !dest || living(dest) ) 
        	dest = present(target, environment(me));
        if( !dest || living(dest) )
          return notify_fail("这里没有这样东西。\n");
        if(dest->query("id") == "rong lu")
        {
        tell_object( me,"往熔炉里扔东西还是用throw命令吧。\n");	
        return 1;
        }
}	

int do_throw(string arg)
{
        string target, item;
        object obj, dest, *inv;
        object me = this_player();
        int i, amount, found;
        if(!arg)
        	return notify_fail("你要将什么东西扔进熔炉？\n");
        if( sscanf(arg, "%s in %s", item, target)!=2 )
          return notify_fail("你要扔什么东西？\n");       
        dest = present(target, me);
        if( !dest || living(dest) ) 
        	dest = present(target, environment(me));
        if( !dest || living(dest) )
          return notify_fail("这里没有这样东西。\n");
        if(dest->query("id") != "rong lu")
        	return notify_fail("只能往熔炉里扔东西。\n");
        if(sscanf(item, "%d %s", amount, item)==2 || item=="all")
        	return notify_fail("倒垃圾呢你！只能一件一件扔！\n");
        if(!objectp(obj = present(item, me)))
        {
                		found = 0;
                		inv = all_inventory(me);
                		for (i=sizeof(inv)-1;i>=0;i--)
                			if (COLOR_D->uncolor(inv[i]->query("name")) == item)
                			{
                				obj = inv[i];
                				found = 1;
                			}
                		if (!found)
         			       return notify_fail("你身上没有这样东西。\n");
       	}
        if ( (item == target)||(obj==dest) ) {
                return notify_fail("你不能把一样东西放进它自己！\n");
        }
        if( obj->query("no_give_user") )
                return notify_fail("这样东西不能乱放。\n");
        if (obj->is_draft() ) //打造图不能forge，ZINE
        	return notify_fail("这是什么破玩意儿，你还是自个儿留着吧。\n");
        if (!obj->query("newgem") && !obj->query("forge")&&!obj->is_tanjing() ) //把判断newgem放到query siling前面，因为有别的东西根本不是宝石也set("siling")的，返回信息就很奇怪，ZINE
        	return notify_fail("这是什么破玩意儿，你还是自个儿留着吧。\n");
        if (obj->query("type") == "siling" && obj->query("yinyang")!="zhong" )
          return notify_fail("这个...四灵宝石暂时还无法熔化。\n");  
        
        inv = all_inventory(dest);
        if (sizeof(inv)>5)
        	return notify_fail("熔炉已经满了，不能再塞了！\n");
        if (stringp(dest->query("in_use")) && dest->query("in_use") != me->query("id"))
        	return notify_fail("有人正在用这个炉子，你还是等等吧。\n");
        return do_throw_in(me, obj, dest);
}

int do_throw_in(object me, object obj, object dest)
{
     if( dest->reject(obj) ) return 0;
     if ( obj->query("no_put") )
       return notify_fail("这东西不能随便乱放。\n");
	   if( obj->move(dest) ) {
                message_vision( sprintf("$N将一%s%s扔进%s。\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        me );
                dest->set("in_use", me->query("id"));
                call_out("remove_in_use",300,dest);
                me->set_temp("is_forging",1);
                return 1;
        }
        else return 0;
}

int do_get(string arg)
{  
	 string from, item;
        object me = this_player(),obj, env;

        if( !arg ) return notify_fail("你要捡起什么东西？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");
        if( sscanf(arg, "%s from %s", arg, from)==2 ) 
        	{
             env = present(from, me);
             if(!env) env = present(from, environment(me));
             if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n");
        if(stringp(env->query("in_use")) && env->query("in_use") != me->query("id") && env->query("id") == "rong lu")
    	{
    	tell_object(me,"人家正在这儿锻造呢，你都想偷东西？不怕烫死你！\n");
    	return 1;
      }
      }

      
  else return 0;
}

void remove_in_use(object dest)
{
dest->delete("in_use");
}