

#include <ansi.h>

inherit ITEM;


void create()
{
            set_name(HIY"礼品柜"NOR, ({ "cabinet",  }) );
        set_weight(3000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个很大的礼品柜，每天在任何时间你都可以到这里来
    拿（na all from cabinet）一个你的礼物。每天只有一次噢！\n");
                set("value", 1000);
                set("material", "wood");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();

}


void init()
{
     add_action("do_qu","na");
}


int do_qu(string arg)
{ 
    object me,ob;
    mapping skl;
    string *sname;
    int i,how=0;
    string week, month, day, time, year;
    string item,from,check;
    
     if ( !arg )
              return notify_fail("命令格式： na all from cabinet \n");   

     sscanf(arg, "%s from %s", item,  from);

     if(from!="cabinet")
            return notify_fail("命令格式： na all from cabinet \n");    

            
     if(item!="all"&&item!="礼品盒")
          return notify_fail("你想拿什么？\n");     


     sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
    if(day=="")
     sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time, year);

        
    me = this_player();

         
    check=year+month+day;            
     if(me->query("weekend_gift")==check)
       return notify_fail("你好象拿过了耶！\n");

      
    if ((int)me->query("combat_exp") >=300000 ) 
         {
                 ob = new("/d/city/obj/qqtang");
     ob->move(me);
     me->set("weekend_gift",check);
     return notify_fail("你从礼品柜里拿出一小"+HIR"qq糖"NOR+"。\n");
	
	
          } 
          else
{
     ob = new("/d/city/obj/qqtang2",);
     ob->move(me,);
     me->set("weekend_gift",check);
     return notify_fail("你从礼品柜里拿出一大代"+HIR"qq糖"NOR+"。\n");
}
}
 
