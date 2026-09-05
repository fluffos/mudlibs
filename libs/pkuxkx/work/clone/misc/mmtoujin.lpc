#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "蒙面头巾", ({ "mengmian toujin", "toujin" }) );
        set("long", "这是能够遮住你的面貌的蒙面头巾。\n");

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("material", "silk");
                set("armor_prop/armor", 1);
                set("value", 3000);
                set("no_store",1);
                set("no_put",1);
                set("no_drop",1);
//mask属性标识这个物品是面具类物件，look的时候如果头上戴着面具类物件被识破会自动解除面具。
                set("mask",1);
                set("max_level", 50);
                set("add_level", 25);
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
  	
  if ( !DISGUISE_D->valid_disguise(this_object(), owner) ) 
  {
  	tell_object(owner,"你伪装技能不足，无法装备"+name()+"。\n");
  	return 0;
  }
  
  if ( ::wear() ) 
  {
  	if ( owner->is_mask() )
  		mask=owner->check_mask(0);
  	if ( !mask || 
  		   mask["mask"]!="mask" ) 
  	{
      complex=DISGUISE_D->query_complex(this_object(), owner);
      owner->set_face("mask", "蒙面人", "mengmian ren", complex, 
          (["title":HIR"金牌杀手"NOR,
            "class":"baixing",
            "long":"一个头戴蒙面头巾目露凶光的杀手。"]) );
      DISGUISE_D->improve_disguise(0, complex, owner);
      return 1;
    }
    else 
    {
    	tell_object(owner,"你已经佩戴了面具，无法再带上"+name()+"。\n");
    	return 0;
    }
  }
  else
  	return 0;
}

int unequip()
{
	object owner;
	mapping mask;

  if( (owner = environment())->is_character() &&
  	  owner->is_mask() )
	{
 		mask=owner->check_mask(0);
 		if ( mask["mask"]=="mask" )
      owner->uncover_mask();
  }
  
  if ( query("equipped") )
  	call_out("destroying",1,this_object());

	return ::unequip();
}

void destroying(object obj)
{
	destruct(obj);
}