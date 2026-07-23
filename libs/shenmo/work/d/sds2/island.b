// Room: /d/sds2/d_island2.c 
        
#include <ansi.h> 
inherit ROOM; 

void fullup(object obj);
int update(object obj);
void dark(object who,object where);
        
void create () 
{ 
set ("short", "死亡岛迷谷"); 
set ("long", YEL+@LONG 

这里是死亡凤凰岛。远处的火山不住的冒着浓烟。在这个远离 
人世的岛上，感觉天地都是红色的。四周弥漫着死亡的气息。 
山上寸草不生，连岩石也已是干瘪龟裂，不住的冒着红色的雾 
气。 

LONG+NOR); 

set ("objects", ([ 
	"/d/sds2/npc/d_phix" : 1, 
])); 

set("exits",([
	"west": __DIR__"d_island"+sprintf("%d",2+random(10)),  //2-12
	"east": __DIR__"d_island"+sprintf("%d",2+random(10)) , //2-12
	"north": __DIR__"d_island"+sprintf("%d",2+random(10)),  //2-12
	"south": __DIR__"d_island"+sprintf("%d",2+random(10)),  //2-12
	"northeast": __DIR__"d_island"+sprintf("%d",2+random(10)),  //2-12
	"northwest": __DIR__"d_island"+sprintf("%d",2+random(10)),  //2-12
	"southeast": __DIR__"d_island"+sprintf("%d",2+random(10)),  //2-12
	"southwest": __DIR__"d_island"+sprintf("%d",2+random(10)),  //2-12
]));	
set("alternative_die",1);
set("water", 1); 
set("no_magic", 1); 
setup(); 
} 

void init() 
{ 
add_action("do_none","move"); 
} 

int do_none( )
{
message_vision(HIR"四周毒雾弥漫，$N失去了方向感！\n"NOR,this_player() );
return 1;
}

void alternative_die(object me)
{
int i,k;
if (!userp(me)&&me->query("id")=="black pheonix") 
	{
	object ob=(me->query_temp("my_killer"));
	if ( ob->query("sds/number")>=4 )
		{
		ob->add_temp("afh_num",1);
		i = (int)ob->query_temp("afh_num");
		k= (int)ob->query("kar");   //福缘
		k=55-k;
		if ( i>=k )  
			{  
			message_vision(HIW"\n经过一番恶战，$N终于杀尽了所有的黑暗凤凰，找到了恐怖的死亡迷谷的入口。\n"NOR,ob);
			message("chat",HIY+"【死亡岛】基鲁提(Guility):"+ob->name()+ "打死了我的暗黑军团，气死我也!\n"NOR,users());    
		       i=random(i)*5000;
			ob->add("daoxing", i );    
			tell_object(ob,BLINK+HIR"你赢得了"+HIW+COMBAT_D->chinese_daoxing(i)+HIR"道行！\n"NOR);  //COMBAT_D->chinese_daoxing
			ob->set("sds2/island","done");
		       ob->set_temp("block_msg/all",1); 
			call_out("dark",random(5) + 5, ob, this_object() ); 
			}  
		else  	tell_object(ob,HIW"\n继续吧，你还需要找去其他残余的"+chinese_number(k-i)+HIW"位暗黑凤凰。\n"NOR);
		fullup(ob);	
		}
	else      {
		message_vision(HIC"\n$N终于将$n打败，夺得了胜利！\n"NOR,ob,me);   
		destruct(me);
		ob->move("/d/sds2/d_island1"); 
		}
	}
fullup(me);
me->set_temp("afh_num",0);
me->move("/d/changan/westseastore");
message("chat",HIY"【"+BLU"死亡岛"+HIY"】沙织(Sha zhi):"+HIW+me->name()+ HIY"输掉了死亡岛的战斗!\n"NOR,users());  
message_vision("$N输掉了死亡岛战役，灰溜溜的离开死亡凤凰岛。\n",this_player() );  
update(this_object());
}

void die(object who)
{
    alternative_die(who);
}

void unconcious(object who)
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

int valid_leave (object who, string dir) 
{ 
int i,k;
object dark = present("black pheonix", this_object()); 
i = (int)who->query("sds2/bing/number");
k= (int)who->query("kar");   //福缘
k=  55-k;
if ( dark ) 
          return notify_fail("战斗吧，女神在等你的好消息呢！\n"); 
return ::valid_leave(who,dir); 
} 
      
void dark(object who,object where) 
{ 
if(!who) return; 
who->set_temp("block_msg/all", 0); 
who->move(__DIR__"d_island0");
message_vision(YEL"\n$N走出恐怖的死亡迷谷，不由长长松了一口气。\n"NOR,who);
} 
