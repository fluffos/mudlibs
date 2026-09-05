#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "蒙面头巾", ({ "mask" }) );
        set("long", "这是普普通通的蒙面黑巾。\n");

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "silk");
                set("armor_prop/armor", 1);
                set("value", 4000);
                set("no_store",1);
                set("no_put",1);
                set("no_drop",1);
//mask属性标识这个物品是面具类物件，look的时候如果头上戴着面具类物件被识破会自动解除面具。
                set("mask",1);
//min_level和max_level两个属性指的是伪装复杂度限定，关联是否可以佩戴面具以及是否可以提升技能等级。
                set("max_level", 50);
//add_level表示佩戴面具以后获得的伪装复杂度增益，提供除技能等级以外的伪装复杂度
                set("add_level", 10);
//max_complex表示该伪装工具能够提供的最高伪装复杂度
                set("max_complex", 100);
        }
        setup();
}

int wear()
{
	object owner;
	mapping mask;
	int complex,tt;

  if ( !environment() ) 
  	return 0;
  
  if ( !(owner = environment())->is_character() ) 
  	return 0;
  
  if ( owner->is_busy() )
  	return 0;
  if (!userp(owner)) //npc使用这个命令，会报错。zine 20110727
    return 0;
  if ( !DISGUISE_D->valid_disguise(this_object(), owner) ) 
  {
  	message_vision("$N伪装技能不足，无法装备"+name()+"。\n",owner);
  	return 0;
  }

  if ( owner->is_mask() )
  	mask=owner->check_mask(0);
  
  if( mask &&
  	  mask["mask"]=="mask" )
  {
  	message_vision("$N已经佩戴了面具，无法再带上"+name()+"。\n",owner);
    return 0;
  }
  
  if ( ::wear() ) 
  {
    complex=DISGUISE_D->query_complex(this_object(), owner);
    owner->set_face("mask", "蒙面人", "", complex );
//当复杂度在限定范围内的时候可以获得伪装技能的经验提升奖励。
    if ( complex <= query("max_level") + query("add_level") )
      DISGUISE_D->improve_disguise(0, complex, owner);
    return 1;
  }
  else
  	return 0;
}

int unequip()
{
	object owner;
	mapping mask;

  if ( query("equipped") ) 
  {
  	call_out("destroying",1,this_object());

    if( (owner = environment())->is_character() &&
  	    owner->is_mask() )
	  {
	  	owner->add_busy(2);
 		  mask=owner->check_mask(0);
 		  if ( mask["mask"]=="mask" )
        owner->uncover_mask();
    }
  }

	return ::unequip();
}

void destroying(object obj)
{
	if ( !query("equipped") )
	  destruct(obj);
}