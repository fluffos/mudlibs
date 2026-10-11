// MingJiao.h for all npc of mingjiao
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

void greeting(object me, object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if ( ob->query("party/party_name") == HIG "明教" NOR ){
        if ( ob->query("family/generation") > me->query("family/generation"))
                message_vision("$N对$n躬身行礼，说道："+me->query("title")+me->query("name")
                        +"，参见"+ob->query("party")["rank"]+ob->query("name")+"！\n", me, ob );
        }

}
