// bingqi.c 兵器库 
// Modify By River@SJ 99.06
// Modify By Looklove@SJ 2000.10.9

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{ 
       set("short",HIW"兵器库"NOR);
       set("long", @LONG
这里是明教的兵器库。有一个放置着各种兵器的兵器架（jia)摆放在房间
的正中。上面摆满了各种兵器和防具，另人眩目。北方出去就是烈火旗了。
LONG);    
	set("exits", ([
		"north" : __DIR__"huoqi",				
	]));                     
	set("objects",([
                BINGQI_D("tieling") : 2,
                BINGQI_D("sjian") : 2,
                CLASS_D("mingjiao") + "/wu" : 1,
	]));
        set("item_desc", ([
                "jia" : "这是一个专门用来放各种兵器的架子。\n"+
                        "里面有：\n\n"+
                        "       鞭(bian)，        锤(chui)， \n"+
                        "       棍(gun)，         棒(bang)， \n"+
                        "       杖(zhang)，       剑(sword)，\n"+
                	"       刀(dao)， 	 令(ling)，  \n"+
                	"       铁甲(armor)，\n"+
                        "等武器，你可以拿(na)来使用，也可以把不要的兵器放(fang)在上面，\n"+
                        "穿过的破损铁甲就不用放回来了。\n\n"]));
        set("jian_count", 20);            
        set("dao_count", 20);   
        set("bang_count", 20);      
        set("gun_count", 20);
        set("zhang_count", 20);
        set("chui_count", 20);           
        set("bian_count", 20); 
        set("ling_count", 20);
        set("armor_count", 20);
        
   	setup(); 
}

void init()
{
	object me = this_player();
	if ( userp(me))
		me->start_busy(1);
	if(me->query_temp("mj/xunluo") && !me->query_temp("bingqi"))
		me->set_temp("bingqi",1);
        add_action("do_get","na");
        add_action("do_put","fang");
}

int do_get(string arg)
{
       	object me,ob;
       	string arg1;
       	me=this_player();

       	if(!arg) return notify_fail("命令格式: na <兵器名称> \n");
       	switch (arg){
          case "jian": arg1="/clone/weapon/changjian"; break;             
          case "dao": arg1="/clone/weapon/blade"; break;   
          case "bian": arg1="/clone/weapon/whip"; break;         
          case "zhang": arg1="/clone/weapon/gangzhang"; break;
          case "gun": arg1="/clone/weapon/tiegun"; break;           
          case "chui": arg1="/clone/weapon/tiechui"; break;
          case "bang": arg1="/clone/weapon/zhubang"; break; 
          case "ling":arg1="/clone/weapon/tieling";break;
          case "armor":arg1="/clone/armor/armor";break;
          default : return notify_fail("没有这种兵器。\n");
       	}
       	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
       	if(query(arg+"_count") < 1)
        	return notify_fail("这种兵器已经被拿光了。\n");
       	if(me->query_temp("bingqi/get")>3)
       		return notify_fail("你已经拿过好几件兵器了，为其他弟子留点吧。\n");
       	add(arg+"_count", -1);
       	ob=new(arg1);
       	if(ob) ob->move(me);
       	ob->set("value", 10);
       	if(!me->query_temp("bingqi/get")) 
       	me->set_temp("bingqi/get",1);
       	else me->add_temp("bingqi/get",1);
       	message_vision("$N从兵器架上拿出一"+ob->query("unit")+"$n。\n",me, ob);  
       	return 1;
}

int do_put(string arg)
{
       	object me, ob;
       	string arg1;
       	me=this_player();
       	if (!arg) return 0;
       	if (me->is_busy()) return notify_fail("你正忙着呢。\n");
       	if( !objectp(ob = present(arg, me)) )
        	return notify_fail("你身上没有这样东西。\n");
       	if(!ob->query("weapon_prop")) 
        	return notify_fail("你只能将武器放在兵器架上。\n");
       	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
       	arg1=ob->query("skill_type");
       	switch (arg1){
        	case "sword": add("jian_count", 1); break;             
          	case "blade": add("dao_count", 1); break;   
          	case "stick": add("bang_count", 1); break;         
          	case "club": add("gun_count", 1); break;
          	case "stuff": add("zhang_count", 1); break;
          	case "hammer": add("chui_count", 1); break;           
          	case "whip": add("bian_count", 1); break;
          	case "ling": add("ling_count", 2); break;
          	case "armor": add("armor_count", 1); break;
          	default :
                	return notify_fail("你不能将这种兵器放在兵器架上。\n");
       	}
       	message_vision("$N拿出一"+ob->query("unit")+"$n放在兵器架上。\n",me, ob);  
       	me->add_temp("bingqi/get",-1);
       	destruct(ob);
       	return 1;
}
