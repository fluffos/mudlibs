#include <ansi.h>;
inherit ROOM;
int do_look(string arg);

void init()
{
        add_action("do_look","zhao");
}
        
int do_look(string arg)
{
      string a,b,c,d;
      int x,y,z,o,i,total;
      object ob = this_player();
      string *number = ({"1","2","3","4","5",
                       "6","7","8","9","10"});
      
      if ( !ob->query_temp("askok") 
           && ob->query("family/family_name") != "唐门世家"
           && ob->query_temp("minchen") != query("short") )
          return notify_fail("你就不要凑热闹了！\n");;
      
      if ( !arg || arg != "wenzi")
          return notify_fail("你找什么啊！\n");
          
      if ( ob->query_temp("askok"))
      {
            ob->set_temp("lianyl",1);
            ob->delete_temp("askok");
            tell_object(ob,"你可要加油啊！\n");
                 
            a = number[random(10)];                 
            b = number[random(10)];
            c = number[random(10)];
            d = number[random(10)];
                  
            for ( i=0; i<sizeof(number); i++)
            {
              if ( a == number[i] ) x = i+1;
              if ( b == number[i] ) y = i+1;
              if ( c == number[i] ) z = i+1;
              if ( d == number[i] ) o = i+1;
            }      
            
            switch(random(3))
            {
                case 0:  
                     total = (int)(x*y/(z+o));
                     write(a+"*"+b+"/"+"("+c+"+"+d+")"+"=");
                     break;
                case 1:
                     total = (int)(x+y/(z+o));
                     write(a+"+"+b+"/"+"("+c+"+"+d+")"+"=");
                     break;
                default :
                     total = (int)(x*y/z+o);
                     write(a+"*"+b+"/"+c+"+"+d+"=");
                     break;
            }   
            if ( wizardp(ob) )
                write("\n"+total+"\n");     
            input_to("get_jiguo", ob, total);
      }     
      
      return 1;
}     
      
void get_jiguo(string arg,object me,int total)
{
      object where;
      object ob;
      
      
      if ( arg+total==arg+arg ) 
      {
          
              where=environment(me);
              ob = new("/d/tangmen/npc/wenzi.c");
              ob->set("d3name",me->query("id") );
              ob->apply_condition("tmjob2",3);
              me->apply_condition("tmjob",5);
              ob->move(where);
              tell_object(me,HIC"一只蚊子，猛然在你的眼前掠过，定睛一看......\n"NOR);
              return;
      }  
      write(HIG"好可怜啊！\n"NOR);
               me->set_temp("tmjob_failed",1);
       me->apply_condition("tmjob",2);
       me->delete_temp("started");
      return;  
}          

