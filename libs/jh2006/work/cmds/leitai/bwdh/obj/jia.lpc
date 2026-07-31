
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "物品架" NOR, ({ "wupin jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "个");
        set("long", "这是一个专门用来放各种物品的架子。
你可拿自己喜欢的物品 ( na <物品名称> from jia )。
里面有：
    刀(dao, blade)，       鞭(bian, whip)，
    剑(jian, sword)，      棍(gun, club)，
    针(zhen, needle)，     杖(zhang, staff)，
    令(ling)，             棒(bang, stick)，
    铁甲(jia, armor)，     锤(chui, hammer)，
    钩(gou, hook)，        斧(fu)，
    火折(fire)，           毒粉(fen)，
    轮(lun)，              石子(shi)，
    笔(bi,brush)。

\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get",({"拿","na"}));
}

int do_get(string arg)
{
  object me,ob;
  string arg1,arg2;
  me=this_player();
  if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
         return notify_fail("命令格式: na <物品名称> from jia。\n");
  if (arg2!="jia")
     return notify_fail("命令格式: na <物品名称> from jia。\n");
    switch (arg1){
          case "sword":                
          case "jian":
                ob=new(BINGQI_D("changjian")); break;   
          case "blade":               
          case "dao":
                ob=new(BINGQI_D("blade")); break;   
          case "whip":                
          case "bian":
                ob=new(BINGQI_D("whip")); break;         
          case "ling":
                ob=new(BINGQI_D("tieling")); break;
          case "zhang":                  
          case "staff":   
                ob=new(BINGQI_D("gangzhang")); break;
          case "zhen":
          case "needle":
                ob=new(BINGQI_D("xiuhua")); break;
          case "gun":                 
          case "club":
                ob=new(BINGQI_D("tiegun")); break;           
          case "hammer":
          case "chui":
                ob=new(BINGQI_D("falun1")); break;
          case "bang":
          case "stick":
                ob=new(BINGQI_D("zhubang")); break; 
          case "armor": 
          case "jia":              
                ob=new(ARMOR_D("armor")); break;
          case "fire": 
          case "huo":              
                ob=new(MISC_D("fire")); break;
          case "fen":             
                ob=new("/d/xingxiu/obj/yao"); break;
          case "fu" :
                ob=new(BINGQI_D("dafu"));break;
          case "gou":
          case "hook":
                ob=new(BINGQI_D("hook"));break;
          case "lun":
                ob=new(BINGQI_D("falun1"));break;
          case "shi":
                ob=new(BINGQI_D("feihuangshi"));break;
          case "bi":
          case "brush":
                ob=new("/d/tiezhang/obj/tiebi");break;

          default :
                 return notify_fail("没有这种东西。\n");
                }
       if(!ob) return 0;
       ob->delete("value");
       if(ob->query("weapon_prop/damage"))
          ob->set("weapon_prop/damage", 50);
       ob->move(me);
       message_vision("$N从物品架上拿出一"+ob->query("unit")+"$n。\n",me, ob);  
       return 1;
}
