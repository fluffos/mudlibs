
// herbalist.c
#include <ansi.h>
inherit NPC;

mixed heal_me(mixed what);
void goodbye(object);
void remove_waiter(object);

void create()
{
	set_name("杨掌柜", ({ "herbalist" }) );
	set("title", "桑邻药铺");
	set("gender", "男性" );
	set("age", 54);
	set("long",
		"杨掌柜是这附近相当有名的大善人，常常施舍草药给付不起药钱的穷人\n"
		"。此外他的医术也不错，年轻时曾经跟著山烟寺的玄智和尚学医，一般\n"
		"的伤寒小病直接问他开药吃比医生还灵。\n" );
	set("combat_exp", 1300);
	set("attitude", "friendly");
	set("inquiry", ([
			"治伤": (: heal_me :),
			"开药": (: heal_me :),
	        "治病": (: heal_me :),
        	"疗伤": (: heal_me :),
	        "救命": (: heal_me :),
        	"恢复": (: heal_me :),
        	"解毒": 
"哎哟，你不说我倒忘了，过两天我一定去向玄智大师请教......\n",
	]) );

	set_skill("literate", 70);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set("score",-200000);
	setup();
	add_money("silver", 10);
}

mixed heal_me(mixed what)
{
int damage_type=0;
int dec1,dec2,dec3;
object me;
me=this_player();
if (dec1=me->query("max_gin")-me->query("eff_gin"))
                damage_type=1;
if (dec2=me->query("max_kee")-me->query("eff_kee"))
                damage_type=2;
if (dec3=me->query("max_sen")-me->query("eff_sen"))
                damage_type=4;
if (!objectp(what))
	{
	switch (what)
        	{
	        case 1: return dec1;
        	case 2: return dec2;
	        case 3: return dec3;
        	default:
		}
	}
if (is_fighting())
	return notify_fail("没看见有人要杀我吗?!\n");
if (query("healing")) 
	return notify_fail("对不起，我正忙着呢，请稍候。\n");
if (damage_type)
        {
        message_vision("$N对$n说道:"+
                       "这位"+RANK_D->query_respect(me)+", 气色不太好嘛! \n",
                       this_object(),me);
        me->set_temp("pending/recover",1);
	remove_call_out("remove_wait");
	set_temp("waiting",1);
call_out("remove_wait",5,me);
        add_action("do_agree","agree");
        return (RANK_D->query_respect(me)+"要我给你看看麽(agree)? 不过可别吝惜钱噢.\n");
        }
return (RANK_D->query_respect(me)+", 你身子骨儿很结实, 没啥好治的.\n");
}

void remove_wait(object me)
	{
	me->delete_temp("pending/recover");
	tell_room(environment(),this_object()->query("name")+"说道: "+
		"咳!"+me->query("name")+
		"连治病的钱都不舍得花! 真是..........@#@!$%^&*!\n");
	command("scowl");
	this_object()->delete_temp("waiting");
	return;
	}

int do_agree(string arg)
{
object me,*ob;
int i,money,tmp,cure;
me=this_player();
set("healing",1);
if (!me->query_temp("pending/recover")) return 0;
remove_call_out("remove_wait");
money=(heal_me(2)+heal_me(2)+heal_me(1))*300; //coin
ob=all_inventory(me);
i=sizeof(ob);
while(i--)
	if (ob[i]->query("id")=="account book")
			break;
if (i<0)
	return notify_fail("你应该去申请一本帐簿!\n");
cure=ob[i]->query("rich");
if (cure<money)
      {
	  write(HIR "哎呀,"+RANK_D->query_respect(me)+
     		"钱好象不够耶!\n"+"我只能尽力而为了, 真是对不起.\n");
ob[i]->set("rich",0);
ob[i]->save();
      cure/=300;
tmp=cure;
      cure-=heal_me(1);
      if (cure<0)  me->receive_curing("gin",tmp);
      else  
      	{
      	me->receive_curing("gin",heal_me(1));
tmp=cure;
      	cure-=heal_me(2);
      	if (cure<0)  me->receive_curing("kee",tmp);
	    else
	    	{
	    	me->receive_curing("kee",heal_me(2));
tmp=cure;
    	    cure-=heal_me(3);
	        if (cure<0)  me->receive_curing("sen",tmp); 
      		else  
      			me->receive_curing("sen",heal_me(3)); 
      		}
      	}
      }
else    {
        me->receive_curing("gin",heal_me(1));
        me->add("eff_kee",heal_me(2));
        me->add("eff_sen",heal_me(3));
	ob[i]->add("rich",-money);
	ob[i]->save();
        }
me->delete_temp("pending/recover");
call_out("goodbye",2,me);
return 1;
}

void goodbye(object patient)
{
say("欢迎再来，不过以后在江湖上行走可要当心哦！\n");
if (query("healing")) delete("healing");
command("smile");
}
