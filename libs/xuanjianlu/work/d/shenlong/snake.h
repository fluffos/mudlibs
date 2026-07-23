

#include <ansi.h>

void init()
{
        object me = this_player();

        if( interactive(me) 
        &&  !objectp(present("xionghuang", me))
        &&  !objectp(present("snake", this_object()))) {
                remove_call_out("showup"); 
		call_out("showup", 0 );
	}
}

void showup()
{

        int level = 0, exp, ob_exp;
        object ob = this_player(),snake;
        exp = ob->query("combat_exp");
        snake = new("/d/shenlong/npc/snake");
        snake->set("combat_exp", exp/3*2 );
	 snake->set("max_qi", ob->query("max_qi")*3/2);
	 snake->set("qi", ob->query("max_qi")*3/2);
	 snake->set("eff_qi", ob->query("max_qi")*3/2);
	 snake->set("max_jing", ob->query("max_jing")*3/2);
	 snake->set("eff_jing", ob->query("max_jing")*3/2);
	 snake->set("jing", ob->query("max_jing")*3/2);
	 snake->set("max_jingli", ob->query("max_jingli")*3/2);
	 snake->set("eff_jingli", ob->query("max_jingli")*3/2);
	 snake->set("jingli", ob->query("max_jingli")*3/2);
        snake->move(environment(ob));
        message("vision", HIB"「唰」的一声！一条" +  snake->query("name") + "不知道从哪棵树上窜了出来！\n" NOR, this_object());
        remove_call_out("disappear");
        call_out("disappear", 1 + random(2), snake);
}

void disappear(object snake)
{
        if( !objectp(snake) ) 
                return;

        if( !living(snake) || snake->is_fighting() || snake->is_busy() ) {
                call_out("disappear", 10 + random(10), snake);
                return;
        }

        message_vision("只见$N飞快地钻入雪中逃走了。\n", snake);
        destruct(snake);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "神龙教") 
        && objectp(present("snake", environment(me))) ) {
                
           return notify_fail("雪太深，你双脚无法移动。”。\n");
        }        
        return ::valid_leave(me, dir);
}

