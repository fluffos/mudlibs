#include <ansi.h>
int stepe,stepw,steps,stepn;
string lookout();
void del_tmp(object me);
void over(object ob);
string lookout()
{
    object ob = this_object();    
    string msg;
    stepe=ob->query_temp("stepe");
    stepw=ob->query_temp("stepw");
    steps=ob->query_temp("steps");
    stepn=ob->query_temp("stepn");	    
    msg = "船外面是一片汪洋，一望无际，";
    if(stepw >10 && steps >10 && steps < 20){
        if(steps<15) msg += "就在西南方";
        if(steps>15) msg += "就在西北方";
        if(steps==15) msg += "就在西方";
        msg += "不远处好象是个渔港，四周也有不少的渔船来来往往。\n";
        return msg; 
        }
    if(stepe >55 && stepe < 65 && steps >0 && steps < 10){
        if(stepe>60) msg += "在西";
        if(stepe<60) msg += "在东";
        if(stepe==60) msg += "在";
        if(steps<5) msg += "南方";
        if(steps>5) msg += "北方";
        if(steps==5) msg += "方";
        msg += "不远处好象有块小岛。\n";
        return msg; 
        }
    if(stepe >15 && stepe < 25 && stepn >125 && stepn < 135){
        if(stepe>20) msg += "在西";
        if(stepe<20) msg += "在东";
        if(stepe==20) msg += "在";
        if(stepn<130) msg += "北方";
        if(stepn>130) msg += "南方";
        if(stepn==130) msg += "方";
        msg += "的天边好象是有东西在燃烧，火焰印红了天空。\n";
        return msg; 
        }
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
    if(ob->query("exits/out"))
      msg = "船还没开呢。\n";
    return msg;       
}

void init()
{
   object me;
   object ob;
   if(interactive(me = this_player())){
        ob=this_object();
        del_tmp(ob);
        me->delete_temp("haichuan_paid");
        remove_call_out("over"); 
        call_out("over", 300+(random(600)), this_object());
        } 
   add_action("do_turn","turn");
}

int do_turn(string arg)
{
	string dir;
        object me, ob, *obj;
        int i;
        me=this_player();
        ob=this_object();
        stepe=ob->query_temp("stepe");
        stepw=ob->query_temp("stepw");
        steps=ob->query_temp("steps");
        stepn=ob->query_temp("stepn");	
        if (!arg) return notify_fail("你要往哪个方向开船？\n");
        if(ob->query("exits/out"))
           return notify_fail("船还没开呢。\n");
        if (me->is_busy()) return notify_fail("你正忙着呢。\n");
        switch(arg) {
                case "东":
                case "east":
                case "e": dir = "东";
                          if(stepe>=70) over(ob);
                          else if(stepw>0) ob->add_temp("stepw", -random(3)); 
                          else ob->add_temp("stepe", random(3)); 
                          break;
                case "西":
                case "west":
                case "w": dir = "西"; 
                          if(stepw>=15) return notify_fail("西边是海岸悬崖，你不能再往西面行驶了。\n");
                          if(stepw>=5 && stepn>50) return notify_fail("西边是海岸悬崖，你不能再往西面行驶了。\n");
                          if(stepe>0) ob->add_temp("stepe", -random(3));  
                          else ob->add_temp("stepw", random(3)); 
                          break;
                case "北":
                case "north":
                case "n": dir = "北"; 
                          if(stepn>=140) over(ob);
                          if(steps>0) ob->add_temp("steps", -random(3));  
                          else ob->add_temp("stepn", random(3)); 
                          break;
                case "南":
                case "south":
                case "s": dir = "南";
                          if(steps>=40) over(ob); 
                          if(stepn>0) ob->add_temp("stepn", -random(3));        
                          else ob->add_temp("steps", random(3)); 
                          break;
                default:
                        return notify_fail("你要往哪个方向开？\n");
                }
        write("你把船向"+dir+"面驶去。\n");
	message("vision", me->name()+"把船驶向"+dir+"面。\n",environment(me), ({me}));
        if(random(2)==1) me->start_busy(1); 
//出事地点在
	if((steps==35 && stepe==1) || (steps==1 && stepe==1) ||
           (stepn==1 && stepe==1)  || (steps==1 && stepw==1) ||
           (stepn==1 && stepw==1)  || (stepn==55 && stepe==10) ||
           (stepn==75 && stepe==20) || (stepn==35 && stepw==5) ||
           (stepe==30 && stepn==1)  || (steps==10 && stepe==15)){
                over(ob);                            
	        return 1;
	        }       
//宁波出海口在 w15,s15,
	if (steps==15 && stepw>=15){
                del_tmp(ob); 
                ob->set("exits/out", "/d/mingjiao/xikou");
                ob->set_temp("arrive", "/d/mingjiao/xikou");
                message_vision("海船渐渐地在宁波溪口靠了岸，艄公把一块踏脚板搭上了堤岸。\n", me);
                remove_call_out("close_passage");
                call_out("close_passage", 20, ob);                
	        return 1;
	        }
//灵蛇岛在 e60,s5,
	if (steps==5 && stepe==60){
                del_tmp(ob); 
                ob->set("exits/out", "/d/mingjiao/lsd/anbian");
                ob->set_temp("arrive", "/d/mingjiao/lsd/anbian");
                message_vision("海船渐渐地在一个不大的小岛旁靠了岸，艄公把一块踏脚板搭上了堤岸。\n", me);         
                remove_call_out("close_passage");
                call_out("close_passage", 20, ob);              
	        return 1;
	        }	
//冰火岛在 e20,n130,
	if (stepn==130 && stepe==20){
		del_tmp(ob); 
                message_vision(HIR"只听嘣地一声，海船碰上了一座冰山，所有人都从船舱中被甩了出去！\n"NOR, me);
                obj = all_inventory(ob);     
                for(i=0; i<sizeof(obj);i++) {
                   if(userp(obj[i])){                     
                     obj[i]->unconcious();
                     obj[i]->move("/d/mingjiao/bhd/dbshan");
                     message("vision", "只听嘣地一声，一个"+obj[i]->name()+"从触礁的海船里被抛了出来！\n",environment(obj[i]), ({obj[i]}));
                     }
                   }
                ob->delete_temp("arrive");
                ob->delete("yell_trigger");
                ob->delete("exits/out");                                          
	        return 1;
	        }
        return 1;	
}
void del_tmp(object me)
{
  me->delete_temp("stepw");
  me->delete_temp("stepe");
  me->delete_temp("steps");
  me->delete_temp("stepn");
}
void over(object ob)
{
     object *obj, *inv;
     int i,j;
     obj = all_inventory(ob);
     del_tmp(ob); 
     ob->delete("yell_trigger"); 
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
        room->delete("exits/out");
        tell_room(room, "艄公朗声说道：“都下船吧，我们也要回去了。”\n", ({}));
            ob = all_inventory(room);
            for(i = 0; i < sizeof(ob); i++) {
                if(userp(ob[i])) {
                   if (!living(ob[i])) tell_room(room, "艄公把$N抬下了船。\n", ob[i]);
                   else tell_room(room, "$N听了艄公的话，乖乖地下了船。\n", ({ob[i]}));
                   ob[i]->move(room->query_temp("arrive"));
                   if (!living(ob[i])) tell_room(room->query_temp("arrive"), ob[i]->name() + "被抬下了船。\n", ({ob[i]}));
                   else tell_room(room->query_temp("arrive"), ob[i]->name() + "走下了船。\n", ({ob[i]}));
                   }
                }
        message("vision", "艄公把踏脚板收起来，把海船缓缓驶向大海。\n", room);
        room->delete_temp("arrive");
        room->delete("yell_trigger"); 
}

