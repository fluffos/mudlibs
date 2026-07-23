void fullup(object obj);

void alternative_die(object me)
{
object ob=me->query_temp("last_damage_from");
fullup(me);
me->remove_killer(ob);
ob->remove_killer(me);
me->move(__DIR__"center"); 
tell_object(me,HIY"\n因为你被玩家在店里杀死，所以不算死亡，重新进入游戏。\n"NOR);
message_vision(CYN"\n$N重新进入这个世界。ＧＯＯＤ　ＬＵＣＫＹ～\n"NOR,me);
return;
}
  
void die(object who)
{
object ob=who->query_temp("last_damage_from");
if ( !ob || !userp(who) || !userp(ob) ) 
	return;
alternative_die(who);
}

void fullup(object obj) 
{
  if (!obj) return;
  obj->set("kee",(int)obj->query("max_kee"));
  obj->set("eff_kee",(int)obj->query("max_kee"));
  obj->set("sen",(int)obj->query("max_sen"));
  obj->set("eff_sen",(int)obj->query("max_sen"));
  obj->set("force",(int)obj->query("max_force")/4);
  obj->set("mana",(int)obj->query("max_mana")/4);
  obj->set("food",(int)obj->query("food")/4);
  obj->set("water",(int)obj->query("water")/4);
}
