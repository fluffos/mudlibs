// 定义杀手检查，自己消失的时间
#define A_TIME 20

void init()
{       
        remove_call_out("do_check");
        call_out("do_check", 0);
        remove_call_out("do_wait");
        call_out("do_wait",A_TIME);
        
}

void do_check()
{
        object me = this_object();
        object ob;

        if (! living(me) || me->is_fighting() ) {
                remove_call_out("do_check");
                call_out("do_check",0); 
        }
        else {
        if( !ob = present("ren zhi",environment(me))) {
                remove_call_out("do_check");
                call_out("do_check",0);
        }
        else {
                if (! environment()->query("no_fight") ) {
                        message_vision("$N对着$n大喝一声：你这"+RANK_D->query_rude(ob)+"，拿命来！\n",me,ob);
                        command("kill "+ob->query("id"));
                        ob -> add("combat_num",1);
                }
                else {
                        me->set_leader(ob);
                        remove_call_out("do_wait");
                        call_out("do_wait",10*A_TIME);
                }
        }
        }

}

void do_wait()
{
        object ob;
        object me = this_object();

        if (me->is_fighting() || !living(me) ) {
                remove_call_out("do_wait");
                call_out("do_wait",A_TIME);
        }
        else {
                if (ob = present("corpse",environment(me)) 
                        && ob->query("victim_name") == "人质" ) {
                        message_vision("$N狂笑道：人质既死，我可以回去交差了。\n一阵烟雾过后，$N的身影神秘地消失了。\n",this_object());
                        destruct(me);
                }
                else {
                        message_vision("$N自言自语地说道：看来人质不会从这里来了，我还是回去吧。\n$N满面无奈地向远处走了开去。\n",this_object());
                        destruct(me);
                }
        }
}

void killed_enemy(object victim)
{
        object me = this_object();

        if (victim->query("id") == "ren zhi") {
                message_vision("$N仰天狂笑一声：哈哈，终于得手了！说罢，几个起落，身形消失在远处的屋檐角。\n",me);
                destruct(me);
        }
}

