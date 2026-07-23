#include <ansi.h> 
#include <combat.h> 
      
int do_huanyuan(string arg)  
{ 
object me = this_player();  
object ob = this_object();  
object wuqi; 
if ( !present(ob,me) )  return 1;
wuqi=new("/d/snowtu/obj/weapon/wuxian");
wuqi->move(me);
message_vision( HIW"$N哈哈一笑，将"+ob->query("name")+ HIW"在手中一抖一捏，"+ob->query("name")+ HIW"已然不见，只见$N手中多了一块奇形怪状的金属。\n"NOR, me);  wuqi=new("/u/snowtu/obj/weapon/wuxian");
destruct(ob);  
return 1;           
}

int hit_ob(object me,object target)
{
object *inv, obj;
int temp_dodge,temp_spells,temp_armor;
string name;
name = this_object()->query("name");
if ( random( me->query("combat_exp") ) > target->query("combat_exp") *2 )
	{
	message_vision(name+BLINK+HIR"忽然发出一道绚丽的光彩！\n"NOR, target);
	if(target->query_temp("armor")||target->query_temp("weapon")) 
		{
		if (target->query_temp("weapon")) 
			{
			obj=target->query_temp("weapon");
			message_vision(HIW "只听见「啪」地一声，$N手中的" + obj->name()+ "已经拿捏不住！\n" NOR, target);
			obj->unequip();
			target->reset_action(); 
			obj->set("name",HIC"被"+me->query("name")+HIC"打脱的"NOR+obj->query("name"));
			obj->move(target);
			target->delete_temp("weapon");
			} 
		if( target->query_temp("armor") ) 
			{
			inv = all_inventory(target);
			obj = inv[random(sizeof(inv))];
			obj->delete("equipped");
			message_vision(HIY"$N身上的$n被打的松脱开来！\n"NOR, target,obj);
				//防止有效轻功和法术不消失.
			temp_dodge=(int)obj->query("armor_prop/dodge",1);
			temp_spells=(int)obj->query("armor_prop/spells",1);
			temp_armor=(int)obj->query("armor_prop/armor",1);
			if (temp_dodge)
			target->add_temp("apply/dodge",-temp_dodge);
			if (temp_spells)
			target->add_temp("apply/spells",-temp_spells);
			if (temp_armor)
			target->add_temp("apply/spells",-temp_armor);
			obj->set("name",HIC"被"+me->query("name")+HIC"打掉的"NOR+obj->query("name"));
			obj->unequip();
			obj->move(target);
			target->delete_temp("armor");
//			call_out("remove_broken_cloth",random(300)+60,obj);
			}
		}
	else 	{
                   if ( random(1)==0 ) return 1;
                   else {
                message_vision(HIC"$n惊的目瞪口呆！\n"NOR,me,target);
              //  target->start_busy(random(2)); 
              target->receive_damage("kee",50+random(50),me); 
              target->receive_wound("kee",50,me); 
              message_vision(HIR"\n"+COMBAT_D->damage_msg(50+random(50), "内伤")+NOR,me,target); 
}
		}
	}
return(8+random(10));
}

/*
void remove_broken_cloth(object obj)
{
  if(obj && environment(obj)) {
    tell_object(environment(obj),
      "一阵微风吹过，"+obj->name()+"化为片片尘土，消失不见了。\n");
    destruct(obj);
  }
}
*/
