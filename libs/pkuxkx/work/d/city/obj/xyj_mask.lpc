#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "西游记人物面具", ({ "complex mask", "mask" }) );
        set("long", "这是印有西游记人物头像的面具。\n");

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "wood");
                set("armor_prop/armor", 1);
                set("value", 8000);
                set("no_store",1);
                set("no_put",1);
                set("no_drop",1);
//mask属性标识这个物品是面具类物件，look的时候如果头上戴着面具类物件被识破会自动解除面具。
                set("mask",1);
//min_level和max_level两个属性指的是伪装复杂度限定，关联是否可以佩戴面具以及是否可以提升技能等级。
                set("min_level", 50);
                set("max_level", 100);
//add_level表示佩戴面具以后获得的伪装复杂度增益，提供除技能等级以外的伪装复杂度
                set("add_level", 15);
//max_complex表示该伪装工具能够提供的最高伪装复杂度
                set("max_complex", 150);
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
    switch(random(100)%4)
    {
    	case 0:
        owner->set_face("mask", "孙悟空", "", complex, 
          (["title":HIY"齐天大圣"NOR,
            "class":"百姓",
            "long":"一个头戴孙悟空头像面具的奇异人士。"]) );
        break;
      case 1:
        owner->set_face("mask", "唐僧", "", complex, 
          (["title":HIW"取经人"NOR,
            "class":"百姓",
            "long":"一个头戴唐僧头像面具的奇异人士。"]) );
        break;
      case 2:
        owner->set_face("mask", "猪八戒", "", complex, 
          (["title":HIM"天蓬元帅"NOR,
            "class":"百姓",
            "long":"一个头戴猪八戒头像面具的奇异人士。"]) );
        break;
      case 3:
        owner->set_face("mask", "沙和尚", "", complex, 
          (["title":HIC"卷帘大将"NOR,
            "class":"百姓",
            "long":"一个头戴沙和尚头像面具的奇异人士。"]) );
        break;
    }
//当复杂度在限定范围内的时候可以获得伪装技能的经验提升奖励。
    if ( complex > query("min_level") &&
    	   complex <= query("max_level") + query("add_level") )
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