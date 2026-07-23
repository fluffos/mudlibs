#include <ansi.h>

int update(object obj);
void fullup(object obj);

void alternative_die(object me)
{
  if ( userp(me) )
	{
	fullup(me);
       me->move("/d/changan/westseastore");
	message("chat",HIY"【"+BLU"死亡岛"+HIY"】沙织(Sha zhi):"+HIW+me->name()+ HIY"输掉了死亡岛的战斗!\n"NOR,users());  
	message_vision("$N输掉了死亡岛战役，灰溜溜的离开死亡凤凰岛。\n",this_player() );  
	update(this_object());
	}
else  destruct(me);
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

int do_none()
{
message_vision("$N像着无头苍蝇，四处乱转。\n",this_player());
return 1;
}