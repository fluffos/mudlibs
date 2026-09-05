//tongxinjie-f 同心结雌

#include <ansi.h>
#include <armor.h> 

inherit NECK;
#include "tongxinjie.h"

void create() 
{ 
        set_name(HIR"同心结（雌）"NOR, ({ "tongxin jie", "necklace"}) ); 
        set_weight(50); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "根"); 
                set("long", "这是中国古老而寓意深长的花结，取“永结同心”(tongxin)之意。\n"); 
                set("value", 10000); 
                set("material", "cloth"); 
                set("armor_prop/armor", 50);
                set("armor_prop/dodge", 50);
              }
        get_user_list(); 
        setup(); 
}

//只有女性可以佩戴
int wear()
{
	object owner;
	
  if (!environment()) return 0;
  if( !(owner = environment())->is_character() ) return 0;

  if(owner->query("gender")!="女性") 
  	return notify_fail("这根雌结只有女性才可以佩戴。\n");
  else
  	::wear();
}