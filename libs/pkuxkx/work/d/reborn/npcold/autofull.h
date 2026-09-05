void powerup();
void full_me();
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
        return;
}

/*
void start_busy(mixed new_busy, mixed new_interrupt)
{
        if(intp(new_busy) && new_busy > 10)

                ::start_busy(8+random(3));
}
*/
