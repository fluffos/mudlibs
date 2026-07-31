// biao.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("镖银", ({ "biao yin", "biao","yin" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "箱");
                set("long", "这是一箱林总镖头托你运送的镖银。\n");
        }
}

void init()
{
        add_action("do_give", "give");
        add_action("do_put", "put");
	add_action("do_guard", "guard");
        remove_call_out("attract_robber");
        call_out("attract_robber", 1);

        if(query("target") ) {
                remove_call_out("set_target");
                call_out("set_target", 4, query("target"));
                delete("target");               //add 4 seconds' delay, can't be so fast
        }
}

void set_target(string target)
{
        set("target", target);
}

int do_give(string arg)
{
        object me,ob,silver, home;
        string obj,target,msg;
        int i;

        if(!arg || sscanf(arg,"%s to %s",obj,target)!=2 )
                if(sscanf(arg,"%s %s", target, obj) !=2 )       
                        return 0;

        if(!id(obj) )   return 0;

        me = this_player();

        if(!ob=present(target,environment(me)) ) {
                tell_object(me,"你想要把镖银交给谁？\n");
                return 1;
        }
        if(ob->query("id")!=query("target") ) {
                tell_object(me,"你不能把这样东西给这个人。\n");
                return 1;
        }
        if(ob->query_temp("unconcious") ) {
                tell_object(me,ob->query("name")+"已经无法收下这样东西了。\n");
                return 1;
        }
/*
        if(!home = find_object(ob->query("startroom")) )
                home = load_object(ob->query("startroom"));

        if(ob->query("id") != "kong kong-er" 
        && base_name(environment(ob)) != ob->query("startroom") ) {
                tell_object(me, ob->query("name")+"说道：你还是到"+home->query("short")+"来找我吧。\n");
                return 1;
        }
*/
        message_vision("$N拿出一箱镖银交给了"+ob->query("name")+"。\n",me);
        if((time()-me->query("biao_start"))>me->query("biao_time") ) {
                message_vision("$N很生气地对$n说道：这么点儿事都办不好，真没用！\n",
                        ob,me);
                tell_object(me,"你没有及时把镖银送到"+ob->query("name")+"的手中，你的任务失败了！\n");
                me->set("biao_failed",1);
        }
        else {
                i=query("amount")/100;
                tell_object(me,"恭喜你成功地将镖银送到了"+ob->query("name")+"的手中。\n");

                message_vision(CYN"$N对$n笑道：好！这里是一成红利，你拿去吧。\n"NOR,ob,me);
                msg=sprintf("$N拿出%s两银子交给$n。\n",chinese_number(i));
                if(!silver=present("silver",me) ) {
                        silver=new("/clone/money/silver");
                        silver->move(me);
                        silver->set_amount(i);
                }
                else    silver->add_amount(i);
                message_vision(msg,ob,me);

                i=1+random(me->query("kar") ) * 8;
                tell_object(me,sprintf(WHT"你获得了%s点战斗修为！\n"NOR,chinese_number(i*3/2)) );
                me->add("combat_exp",i*2);
                i=2+random(me->query("kar") ) * 8;
                tell_object(me,sprintf(WHT"你获得了%s点潜能！\n"NOR,chinese_number(i)) );
                me->apply_condition("zzz_busy",6);
                me->add("potential",i*2);
                me->start_busy(6);
                me->delete("biao_start");
                me->delete("biao_time");
        }

        me->receive_damage("qi", random(10) + 20);
        me->receive_damage("jing", random(10) + 20);

        destruct(this_object());

        return 1;
}

void attract_robber()
{
        object ob, robber, room1, room2;
        int i;
	ob = this_player();
        if(!userp(ob = environment(this_object())) )    return;

        room2 = environment(ob);

        if(room1 != room2 && room2->query("outdoors") 
//                && random(ob->query("kar")) < 1) {
                ) {
/*
                if(ob->query("combat_exp") < 2000 )
                        i = 1+ random(3);
                if(ob->query("combat_exp") < 10000 )
                        i = 4+ random(3);
                if(ob->query("combat_exp") < 80000 )
                        i = 7+ random(3);
                if(ob->query("combat_exp") >= 80000 )
                        i = 10+ random(3);
*/
//    if( !environment(ob)->query("no_fight") )
//{
                robber = new(__DIR__"robber");
                robber->set_leader(this_player());
                robber->move(room2);
                this_player()->start_busy(3);
                robber->set_leader(this_player());
		robber->kill_ob(this_player());
//}
                room1 = room2;
                return;
        }

        remove_call_out("attract_robber");
        call_out("attract_robber", 1);
}

int do_put(string arg)
{
        string biao, bag;

        if(!arg)        return 0;

        if(sscanf(arg, "%s in %s", biao, bag) != 2)     return 0;

        if(present(biao, this_player()) || biao == "all" ) {
                tell_object(this_player(), "你要把镖银放到哪里？\n");
                return 1;
        }

        return 0;
}
int do_guard(string arg)
{
        write(this_player()->query("name")+"，你现在不能用guard！\n");
        return 1;
}