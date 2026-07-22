#include <ansi.h>
inherit NPC;

void create()
{
        set_name("兵器架", ({ "bingqi jia" }) );
        set("gender", "男性" );
        set_temp("apply/long", ({"这是一个专门用来放各种物品的架子。
你可拿自己喜欢的物品 ( na <物品名称> )。\n"}));
          set("age", 14);       
        set("str", 30);
        set("dex", 25);
        set("con", 25);
        set("int", 30);            
        set("attitude", "friendly");
        set_temp("apply/id", ({ "jia" }));
        set_temp("apply/short", ({HIW"兵器架"NOR"(Jia)"}));
        setup();
}

void init()
{
	add_action("do_get",({"拿","na"}));
}

int do_get(string arg)
{
  	object me,ob;
  	me=this_player();
  	
  	if( !arg )return notify_fail("命令格式: na <物品名称> 。\n");

    	switch (arg){
          	case "sword":                
          	case "jian": 	ob=new(BINGQI_D("changjian")); break;   
          	case "blade":               
          	case "dao": 	ob=new(BINGQI_D("blade")); break;   
          	case "whip":                
          	case "bian":	ob=new(BINGQI_D("whip")); break;         
          	case "ling":	ob=new(BINGQI_D("tieling")); break;
          	case "zhang":                  
          	case "staff":   ob=new(BINGQI_D("gangzhang")); break;
          	case "zhen":
          	case "needle":	ob=new(BINGQI_D("xiuhua")); break;
          	case "gun":                 
          	case "club":	ob=new(BINGQI_D("tiegun")); break;           
            case "xiao":    ob=new(BINGQI_D("yuxiao")); break;           
          	case "hammer":
          	case "chui":	ob=new(BINGQI_D("falun1")); break;
          	case "bang":
          	case "stick":	ob=new(BINGQI_D("zhubang")); break;
          	case "gou": 
          	case "hook":    ob=new(BINGQI_D("hook")); break; 
          	case "armor": 
          	case "jia":     ob=new(ARMOR_D("armor")); break;
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
                ob=new(BINGQI_D("tiebi"));break;

          	case "fire": 
          	case "huo":     ob=new(MISC_D("fire")); break;
              case "fen":     ob=new("/d/xingxiu/obj/yao3"); break;
          	default :	return notify_fail("没有这种东西。\n");
        }
        
       	if(!ob) return 0;
       	ob->delete("value");
       	if(ob->query("weapon_prop/damage"))
          	ob->set("weapon_prop/damage", 50);
	if(ob->query("armor_prop/armor"))
          	ob->set("armor_prop/armor", 70);
       	ob->move(me);
       	ob->set("dzd_obj",1);
       	message_vision("$N从物品架上拿出一"+ob->query("unit")+"$n。\n",me, ob);  
       	return 1;
}

