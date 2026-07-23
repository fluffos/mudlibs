#include <ansi.h>
inherit ROOM;

void fullup(object obj);

int update(object obj);

void create()
{
set ("short",HIW"银河战"NOR+HIY"擂台"NOR);
set("long",@LONG
财团为本次100人次银河战役而特制的擂台，仿照
古角斗场设置，圆形的擂台，正中是五角形的黑白
图案。
LONG);
set("water",1);
set("alternative_die",1);
set("objects",([
    "/d/sds/npc/xiannv" : 1 ,
]));
setup(); 
}

void alternative_die(object me)
{

  if (!userp(me)&&me->query("id")=="a shun") {

     object ob=(me->query_temp("my_killer"));
      fullup(ob);

    if( present("sai zhang",ob) && ob->query("sds/xiannv")!="done" )  
	{  
	message("chat",HIY+"【银河战役】沙织(Sha zhi):"+ob->name()+"打败了仙女座：阿瞬!\n"NOR,users());  
	ob->set("sds/xiannv","done");  
	ob->add("sds/number",1);  
	ob->add("daoxing", 20000);  
	tell_object(ob,BLINK+HIY"你赢得了二十年道行！\n"NOR);  
	}  
     message_vision(HIC"\n$N终于将$n打败，夺得了这场比赛的胜利！\n"NOR,ob,me);   
     destruct(me);
     ob->move("/d/sds/leitai2"); 

    return;
  }
  
      fullup(me);
       me->set_temp("sds/fail",1);
	me->move("/d/sds/saichang");
          message("chat",HIY+"【银河战役】沙织(Sha zhi):"+me->name()+ "败在了仙女座：阿瞬的手下!\n"NOR,users());  
	message_vision("$N输掉了银河战，灰溜溜的离开了擂台。\n",this_player() );  
       update(this_object());

}

void die(object who)
{
    alternative_die(who);
}

void fullup(object obj) {
  if (!obj) return;
  obj->set("kee",(int)obj->query("max_kee"));
  obj->set("eff_kee",(int)obj->query("max_kee"));
  obj->set("sen",(int)obj->query("max_sen"));
  obj->set("eff_sen",(int)obj->query("max_sen"));
  obj->set("force",(int)obj->query("max_force")*2);
  obj->set("mana",(int)obj->query("max_mana")*2);
}


int update(object obj)
{
	int i;
	object *inv;


	inv = all_inventory(obj);
	i = sizeof(inv);
                   while(i--)
				if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
				else inv[i] = 0;
		destruct(obj);


	return 1;
}

