#include <ansi.h>
inherit NPC;
string *name=({"鲤鱼","草鱼","鲶鱼","金鱼","鳊鱼","鲢鱼"});
void create()
{     
	set_name(YEL+name[random(sizeof(name))]+NOR, ({ "fish","yu" }) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一条生长在池塘中的野鱼。\n");
	
	set("str", 23);
	set("dex", 36);

	set("limbs", ({ "头部", "身体","尾巴" }) );
	set("verbs", ({ "bite"}) );

	set("chat_chance", 6);
	set("chat_msg", ({
		this_object()->name()+"悠闲得从你面前游过。\n",
		this_object()->name()+"摇了摇尾巴,从嘴里吐出一串气泡。\n",
           }));		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}
