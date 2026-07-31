
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	    object ob1;
        int min, hrs, day, mon, age;
        me=this_player();
        
        if (! arg || arg == "")
                return notify_fail("你要激活什么称号！\n");
                         
        if (me->is_fighting())
                return notify_fail("你正忙着打架呢，哪有时间做这种事？\n");

        if (me->is_busy())
                return notify_fail("你正忙，没法静下心来。\n");
                					
					
		if (arg == "quxiao")
        {
                        
                
                me->delete("chjh");
		    	me->delete("chjl");
		    	me->delete("title");
                me->delete("chenghao");
			    me->delete("titlea");
            write(HIR"取下前缀称号成功，你可以激活其他称号了。\n");
        }			 
		if (arg == "quxiao1")
        {
                        
                
                me->delete("chenjch");
//		    	me->delete("chjl");
//		    	me->delete("title");
//               me->delete("chenghao");
			
            write(HIR"取下成就称号成功，你可以激活其他成就称号了。\n");
        }	
		
         if (arg == "守陵人")
        {        
                if (!me->query("titles/守陵人"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[守陵人]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
         if (arg == "纵马江湖")
        {        
                if (!me->query("titles/纵马江湖"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[纵马江湖]"NOR);
            write(HIR"激活成就称号成功。\n");
        }


         if (arg == "slr")
        {
                        
                if (!me->query("chenghao/slr"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n"); 	    
                    
                me->add("chjh",1);
		    	me->add("chjl/str",5);
		    	me->add("chjl/int",5);
		    	me->add("chjl/con",5);
		    	me->add("chjl/dex",5);
				me->add("chjl/max_jing",500);
		    	me->add("chjl/max_qi",500);
		    	me->add("chjl/max_jingli",500);	
		    	me->add("chjl/max_neili",10);
		    	me->set("title",HIY"守陵人"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "zmjh")
        {
                        
                if (!me->query("chenghao/zmjh"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/str",5);
		    	me->add("chjl/int",5);
		    	me->add("chjl/con",5);
		    	me->add("chjl/dex",5);
				me->add("chjl/max_jing",500);
		    	me->add("chjl/max_qi",500);
		    	me->add("chjl/max_jingli",500);	
		    	me->add("chjl/max_neili",10);
		    	me->set("title",HIM"纵马江湖"NOR);
                			
            write(HIR"激活称号成功。\n");
        } 

        return 1;
}

