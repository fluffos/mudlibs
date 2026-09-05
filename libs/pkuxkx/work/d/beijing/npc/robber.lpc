// robber for dart
//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
#include <random_name.h>
#include "npc_setup.h"
void create()
{
    set_name(get_rndname(), ({"robber", }));
    set("nickname", get_rndnick());
    set("age", 10 + random(50));
	set("chat_chance", 100);
        set("vendetta/authority", 1);
        set("no_use/qiankun-danuoyi",1);

        setup();
}
void destroying(object me)
{
        destruct(me);
        return;
}
int checking(object me, object ob)
{
        if (me->is_fighting())
        {
                call_out("checking",1, me, ob);
                return 1;
        }

        if (!me->is_fighting() && objectp(ob) && living(ob) && objectp(present(ob->query("id"), environment())) )
        {
        	      me->kill_ob(ob);
                call_out("checking",1, me, ob);
                return 1;
        }
        
        if ( (!objectp(ob) || !present(ob->query("id"), environment()) || !living(ob)) && present("qiu che",environment()) )
        {
                command("grin");
                command("jie qiu che");
                message_vision("$N推着囚车呼啸而去。\n", me);
                call_out("destroying",1,me);
                return 1;
        }
        if (!objectp(ob) || !present(ob->query("id"), environment()))
          {
              message_vision("$N悻悻的说：“算你跑的快！”\n",me);
              command("sigh");
              command("jie qiu che");
              message_vision("$N身行几起几纵消失在暗处\n",me);
              call_out("destroying",1,me);
              return 1;

          }
        if ( present(ob->query("id"), environment()) && !living(ob) && present("qiu che",environment()) )
           {
                command("grin");
                command("jie qiu che");
                message_vision("$N推着囚车呼啸而去。\n", me);
                call_out("destroying",1,me);
                return 1;
        }
}

void unconcious()
{
	die();
}

void die()
{
	object me;
	if (objectp(me = this_object()->get_damage_origin_object()) && me->query("jianzhan/in_dart"))
		me->add("combat_exp", 50 + random(50));
	message_vision(CYN"\n$N叫道：点子扎手，扯呼！\n\n$N个起纵遁入暗里不见了。\n\n"NOR,this_object());
	destruct(this_object());
}
