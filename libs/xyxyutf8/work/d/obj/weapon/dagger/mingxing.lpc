// mingxing.c

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
                set_name(HIR"明心锥"NOR, ({"mingxing zui", "bishou", "dagger", "zui"}) );
                    set("long", "一件类似匕首的名贵兵器，是恐怖和死亡的象征。\n相传有位皇帝生性多疑，每当他对臣子的忠诚有\n了怀疑的时候便令人持明心锥前往，交给臣子。\n而接到明心锥者，等于被判处了死刑。\n");
	set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
		set("unit", "把");
		set("value", 50);
		set("material", "steel");
}
              init_dagger(75);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀中。\n");

// The setup() is required.

	setup();
}

void init()
{
        add_action("do_wield","wield");
}

int do_wield (string arg)
{
  object me = this_player();
  if(me->query("family/family_name")!="火系魔法教派")
{
  message_vision(HIR"明心锥"NOR+"是火系魔法教派的专用武器\n",me);
return 1;
}
}
