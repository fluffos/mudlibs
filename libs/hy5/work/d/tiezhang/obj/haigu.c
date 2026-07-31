#include <ansi.h>

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
        add_action("do_move", "move");
}

void create()
{
       set_name("骸骨", ({"haigu","skeleton"}) );
       set_weight(10000);
       set_max_encumbrance(6000000);
       if( clonep() )
               set_default_object(__FILE__);
       else{
       set("unit", "具");
       set("long", "这副骸骨躺在这里已经很久了。\n");
       set("value", 0);
       set("material","wood");
       set("no_get",1);
       set("init",0);
       }
       setup();
}

int do_move(string arg)
{
        int i;
        object book;
        object fang,who;
        object me = this_player();
        who=me;
        if (!id(arg))
                return 0;
        if (this_player()->query_temp("wumu_shanshui") ) {
                if (!present("wumu yishu",me)){


 if ((int)who->query("jinyong/book5")==7 && !query("iskillok"))
        {
      	fang = load_object("/d/tiezhang/npc/qqzhang");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object("/d/tiezhang/npc/qqren");
	fang->move(environment(who));	
	fang->kill_ob(who);

     this_object()->set("iskillok",1);
     set("iskillok",1);
 message_vision(
HIY"$N轻轻地挪动骸骨，发现下面有一本书，$N正想拣起揣到怀中。\n"NOR
RED"附近突然出来二个武林高手来抢书，吓了$N一跳！\n"NOR,this_player());
return 0;
}

 if ((int)who->query("jinyong/book5")==7 && !query("iskillok"))
        {
      	fang = load_object("/d/tiezhangy/npc/qqzhang");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object("/d/tiezhangy/npc/qqren");
	fang->move(environment(who));	
	fang->kill_ob(who);

     this_object()->set("iskillok",1);
     set("iskillok",1);
 message_vision(
HIY"$N轻轻地挪动骸骨，发现下面有一本书，$N正想拣起揣到怀中。\n"NOR
RED"附近突然出来二个武林高手来抢书，吓了$N一跳！\n"NOR,this_player());
return 0;
}

 if (!who->query_temp("book581"))
        {
 message_vision(
HIY"$N轻轻地挪动骸骨，但发现骸骨里面什么也没有了。\n"NOR,this_player());
return 0;
}
 if (!who->query_temp("book582"))
        {
 message_vision(
HIY"$N轻轻地挪动骸骨，但发现骸骨里面什么也没有了。\n"NOR,this_player());
return 0;
}



                message_vision(
HIY"$N轻轻地挪动骸骨，发现下面有一本书，$N急忙拣起揣到怀中。\n"NOR
RED"那骸骨突然迎头向$N扑将下来，摔在地上，四下散开，吓了$N一跳！\n"NOR,this_player());
                book = new(__DIR__"wumu-yishu");
                book->move(me);

if ((int)who->query("jinyong/book5")==7){   	

                        		i = 900+random(2000);
		who->set("jinyong/book5",8);
		who->add("combat_exp",i+17000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		
		tell_object (who,"你赢得了"+chinese_number(i+17000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
   }

                destruct(this_object());
                return 1;
                }
                message_vision(
HIM"骸骨急道：书都拿到了还不快滚，没事把老子挪来挪去的干什么？？？\n"NOR, this_player());
                return 1;
                }
                else {
                message_vision(
HIR"$N轻轻地挪动骸骨，突然从骸骨的下面冒出一股毒气，钻进$N的鼻子中。\n"NOR, this_player());
		me->set_temp("last_damage_from", "中毒");
                me->die();
                return 1;
        }
}
