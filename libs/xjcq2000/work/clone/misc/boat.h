#include <ansi.h>
void dest(object ob);
void over(object ob);
int turnning(object me, string dir);

void init()
{
   add_action("do_turn","turn");
   add_action("do_out","out");
   add_action("do_start","start");
   add_action("lookout","lookout");
   add_action("do_stop","stop");
}
int lookout()
{   
    object ob = this_object();
    string msg;
    int stepe,stepw,steps,stepn;
    stepe=ob->query_temp("stepe");
    stepw=ob->query_temp("stepw");
    steps=ob->query_temp("steps");
    stepn=ob->query_temp("stepn");	    
    msg = "船的外面是一片汪洋，一望无际，";
    if(ob->query("boat_of")){
        msg += "船还停在岸边没开呢。\n";
        tell_object(this_player(), msg);
        return 1; 
        }
    if(stepw >10 && steps >10 && steps < 20){
        if(steps<15) msg += "就在西南方";
        if(steps>15) msg += "就在西北方";
        if(steps==15) msg += "就在西方";
        msg += "不远处好象是个渔港，四周也有不少的渔船来来往往。\n";
        }
    else if(stepe >95 && stepe < 105 && steps >0 && steps < 10){
        if(stepe>100) msg += "在西";
        if(stepe<100) msg += "在东";
        if(stepe==100) msg += "在";
        if(steps<5) msg += "南方";
        if(steps>5) msg += "北方";
        if(steps==5) msg += "方";
        msg += "不远处好象有块小岛。\n";
        }
    else if(stepe >195 && stepe < 205 && stepn >940 && stepn < 960){
        if(stepe>200) msg += "在西";
        if(stepe<200) msg += "在东";
        if(stepe==200) msg += "在";
        if(stepn<950) msg += "北方";
        if(stepn>950) msg += "南方";
        if(stepn==950) msg += "方";
        msg += "的天边好象是有东西在燃烧，火焰印红了天空。\n";
        }
    else {
        msg += "你似乎迷失了方向。\n";
          if(stepn && stepn>20){
              if(stepn>=130) msg += WHT"船已经很难再前进了，四周都是白茫茫的一遍，围满了浮冰。\n"NOR;
              else if(stepn>=100) msg += HIW"船里的淡水也已经结冻，海面漂浮着一块块的浮冰。\n"NOR;
              else if(stepn>=70) msg += HIB"阵阵寒风呼啸而过，海水里也漂来一块块小浮冰。\n"NOR;
              else if(stepn>=50) msg += HIM"海风已经变得刺骨，天空也阴沉沉地。\n"NOR;
              else msg += "海风日渐强烈，温度也开始降低了。\n";
              }    
          else{
              msg += "海面风和日丽，";
              if(stepe) msg += "不时还可以看见从来没见过的怪鱼在海中游弋。\n";
              else if(stepw) msg += "不时有几只海鸥在天空盘旋，看来离海岸不远。\n";
              else msg += "看不见海鸟，看来已经离开海岸线很远了。\n";
              }
       }    
    tell_object(this_player(), msg);
    return 1;       
}


void dest(object ob)
{    	
  destruct(ob);        
}
int do_out()
{
        object me, ob, room, *inv;
        int i;
        me = this_player();
        
        if(!query("boat_of")) return 0;
        if(!(room = find_object(query("boat_of"))))
             room = load_object(query("boat_of"));
        if(room = find_object(query("boat_of"))){
               message_vision("$N从船上跳了下去。\n\n", me);
               me->move(room);
               message("vision",me->name()+"象猴子一样从"+this_object()->name()+"上跳了下来。\n",environment(me), ({me}) );
               return 1;
               }
        else write("sea boat error, please call wizard. \n");
        return 1;
}       

int do_stop()
{
        object me, ob, room, *inv;
        int i;
        me = this_player();
        
        if(query("boat_of")) return notify_fail("船没有在海上航行。\n");
        message_vision("$N将"+this_object()->name()+"的帆缓缓将下，船便停在了大海上。\n"NOR, me);
        remove_call_out("turnning");
        return 1;
}   

int do_start()
{
        object me, ob, room, *inv;
        int i;
        me = this_player();
        
        if(!query("boat_of")) return notify_fail("船已经在海上航行了。\n");
        if(!(room = find_object(query("boat_of"))))
             room = load_object(query("boat_of"));
        if(room = find_object(query("boat_of"))){
               me->delete_temp("haichuan_paid");
               room->delete("boat_on_sea");
               message_vision("$N大喊一声：开船喽！将"+this_object()->name()+"缓缓驶向大海。\n"NOR, me);
               tell_room(room, HIY+this_object()->name()+"缓缓驶向了大海。\n"NOR);
               delete("boat_of");
               remove_call_out("over"); 
               call_out("over", 500+(random(2800)), this_object());
               return 1;
               }
        else write("sea boat error, please call wizard. \n");
        return 1;
}       
int do_turn(string arg)
{
	string dir;
        object me, ob;
        me=this_player();
        ob=this_object();

        if (!arg) return notify_fail("你要往哪个方向开船？\n");
        if(ob->query("boat_of"))
           return notify_fail("船还没开呢。\n");
        if (me->is_busy()) return notify_fail("你正忙着呢。\n");
        remove_call_out("turnning");
        switch(arg) {
                case "东":
                case "east":
                case "e": dir = "东"; break;
                case "西":
                case "west":
                case "w": dir = "西"; break;
                case "北":
                case "north":
                case "n": dir = "北"; break;
                case "南":
                case "south":
                case "s": dir = "南"; break;
                default:
                        return notify_fail("你要往哪个方向开？\n");
                }        
        write("你把"+ob->name()+"向"+dir+"面驶去。\n");
	message("vision", me->name()+"把"+ob->name()+"向"+dir+"面驶去。\n",environment(me), ({me}));
        if(random(2)==1) me->start_busy(1); 
        remove_call_out("turnning");
        call_out("turnning", 0, me, dir);
        return 1;	
}

int turnning(object me, string dir)
{
        object ob, *obj;
        int stepe,stepw,steps,stepn, i;
        ob=this_object();
        stepe=ob->query_temp("stepe");
        stepw=ob->query_temp("stepw");
        steps=ob->query_temp("steps");
        stepn=ob->query_temp("stepn");
        switch(dir) {
                case "东": if(stepe>=300) over(ob);
                           else if(stepw>0) ob->add_temp("stepw", -random(3)); 
                           else ob->add_temp("stepe", random(3)); 
                           break;
                case "西": if(stepw>=15 || (stepw>=100 && stepn>300)){
                              write("西边是海岸悬崖，你不能再往西面行驶了。\n");
                              return 1;
                              }
                           if(stepe>0) ob->add_temp("stepe", -random(3));  
                           else ob->add_temp("stepw", random(3)); 
                           break;
                case "北": if(stepn>=1400) over(ob);
                           if(steps>0) ob->add_temp("steps", -random(3));  
                           else ob->add_temp("stepn", random(3)); 
                           break;
                case "南": if(stepw>=15 && stepn<301){
                              write("南边是海岸悬崖，你不能再往南面行驶了。\n");
                              return 1;
                              }
                           if(steps>=400) over(ob); 
                           if(stepn>0) ob->add_temp("stepn", -random(3));        
                           else ob->add_temp("steps", random(3)); 
                           break;
                default: break;
                }
        if(random(10) > 5)
  	       random(2)?message("vision", ob->name()+"正破浪向"+dir+"面驶去。\n",environment(me)):
                         message("vision", ob->name()+"迎风破浪，向"+dir+"面驶去。\n",environment(me));

//宁波出海口在 w15,s15,
	if (steps>=14 && steps<=16 && stepw>=15){
                set("boat_of", "/d/mingjiao/xikou");
                message_vision("只听咚的一声，"+ob->name()+"触到了岸边。\n", me);
                message_vision(HIY+ob->name()+"渐渐地在宁波溪口靠了岸，你可以上岸(out)了。\n"NOR, me);
                remove_call_out("close_passage");
                call_out("close_passage", 20, ob);                
	        return 1;
	        }
//灵蛇岛在 e100,s5,
	if (steps>=4 && steps<=6 && stepe>=99 && stepe<=101){ 
                set("boat_of", "/d/mingjiao/lsd/anbian");
                message_vision("只听咚的一声，"+ob->name()+"触到了岸边。\n", me);
                message_vision(HIY+ob->name()+"渐渐地在一个不大的小岛旁靠了岸，你可以上岸(out)了。\n"NOR, me);         
                remove_call_out("close_passage");
                call_out("close_passage", 20, ob);              
	        return 1;
	        }	
//冰火岛在 e200,n950,
	if (stepn>=948 && stepn<=951 && stepe>=198 && stepe<=202){
                message_vision(HIR"\n只听嘣地一声，"+ob->name()+"碰上了一座冰山，所有人都从船舱中被甩了出去！\n"NOR);
                obj = all_inventory(ob);     
                for(i=0; i<sizeof(obj);i++) {
                   if(userp(obj[i])){                     
                       obj[i]->unconcious();
                       obj[i]->move("/d/mingjiao/bhd/dbshan");
                       message("vision", "只听嘣地一声，一个"+obj[i]->name()+"从触礁的海船里被抛了出来！\n",environment(obj[i]), ({obj[i]}));
                       }
                   } 
                call_out("dest", 3, ob);                                          
	        return 1;
	        }
        remove_call_out("turnning");
        call_out("turnning", 1+random(3), me, dir);
        return 1;	
}
void over(object ob)
{
     object *obj, *inv;
     int i,j;
     obj = all_inventory(ob);
     call_out("dest", 3, this_object());
       if(!obj) return;
       else{                
        write(HIR"突然一阵狂风吹过，刮断了桅杆，海船也被抛上了天！\n"NOR);
        for(i=0; i<sizeof(obj); i++) {
           inv = all_inventory(obj[i]);
              for(j= 0;j< sizeof(inv);j++){
                if(!inv[j]->query("unique")) continue;
                       destruct(inv[j]);
                }
           obj[i]->unconcious();
           obj[i]->move("/d/mingjiao/xikou");
           message("vision", "突然一阵大风刮过，将一个"+obj[i]->name()+"从海里吹上岸来！\n",environment(obj[i]), ({obj[i]}));           
           }
        return;              
        }   
}
void close_passage(object room)
{        
        object *ob;
        int i;
        if(query("boat_of")) return;
        else{
          tell_room(room, "你想道：“既然都下船了，我也下去吧。”\n", ({}));
          ob = all_inventory(room);
          for(i = 0; i < sizeof(ob); i++) {
             if(userp(ob[i])) {
                   if (!living(ob[i])) tell_room(room, "$N被抬下了船。\n", ob[i]);
                   ob[i]->move(room->query("boat_of"));
                   if (!living(ob[i])) tell_room(room->query("boat_of"), ob[i]->name() + "被抬下了船。\n", ({ob[i]}));
                   else tell_room(room->query("boat_of"), ob[i]->name() + "走下了船。\n", ({ob[i]}));
                   }
              }
          call_out("dest", 3, room);   
          }
}

