void powerup();
void full_me();
int do_none();
void powerup()
{
        object me = this_object();
        CHANNEL_D->do_channel(this_object(), "bd", "sneer", 1);
        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("neili",2*me->query("max_neili"));
        me->set("jingli",2*me->query("max_jingli"));
        me->clear_condition();
        return;
}

void full_me()
{
        object me = this_object();
        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("neili",2*me->query("max_neili"));
        me->set("jingli",2*me->query("max_jingli"));
        me->clear_condition();
        message_vision("$N对著"+me->query("name")+"喝道：「老匹夫！今日不是你死就是我活！」\n",this_player());

        me->kill_ob(this_player());
        return;
}
