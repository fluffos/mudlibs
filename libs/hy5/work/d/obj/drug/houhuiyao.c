//后悔药                                               

inherit ITEM; 
#include <ansi.h>                                                                              

int do_eat(string);                                                                         
void init();                                                                                

void init()                                                                                 
{                                                                                           
  if (!wizardp(this_player())) {                                                            
    set("no_get","你手里一松，后悔药从指间滑落！\n");                                       
    set("no_give","这么珍贵的药，哪能随便给人？\n");                                        
    set("no_drop","这么宝贵的药，扔了多可惜呀！\n");                                        
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                                                                         
  add_action("do_eat", "eat");                                                              
}                                                                                           

void create()                                                                               
{                                                                                           
  set_name("后悔药", ({"houhui yao", "yao"}));                                    
  set_weight(90);                                                                           
  if (clonep())                                                                             
    set_default_object(__FILE__);                                                           
  else {                                                                                    
    set("unit", "包");                                                                      
    set("long", "一包颜色怪怪的药，味道一定不怎么样。\n");                                  
    set("value", 3500);                                                                        
    set("drug_type", "补品");                                                               
  }                                                                                         
  set("is_monitored",1);                                                                    
  setup();                                                                                  
}                                                                                           

int do_eat(string arg)                                                                      
{                                                                                           
  object me = this_player();                                                                
  if (arg!="yao" && arg!="houhui yao")   return 0;                                          

  me->set("eff_jing", (int)me->query("max_jing"));                                            
  me->set("jing", (int)me->query("max_jing"));                                                
  me->set("eff_gin", (int)me->query("max_gin"));                                            
  me->set("gin", (int)me->query("max_gin"));                                                
  me->set("eff_qi", (int)me->query("max_qi"));                                            
   me->delete("mieyao_mudage"); 
   me->delete("secmieyao_mudage");                                                            
   me->delete("bad_mudage");                                                                
  me->set("qi", (int)me->query("max_qi"));                                                
  me->set("mana", (int)me->query("max_mana"));                                              
  me->set("neili", (int)me->query("max_neili"));                                            
   message_vision(HIM "$N把后悔药往嘴里一放，苦的眼泪鼻涕一起流了下来。                     
\n" NOR, me);                                                                               
  destruct(this_object());                                                                  
  return 1;                                                                                 
}                                                                                           
