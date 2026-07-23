//weihu.h 四大卫护的公共部分
//By lala on July 17, 1997

void init()
{
        object ob=this_object();
        object me=this_player();
    
    if ( me->query_condition("kill_dali") 
        && ob->can_act() )
    {
        remove_call_out("kill_him");
        call_out("kill_him", 1, me);
    }
    else
    {
        if ( ob->can_act() 
            && !ob->is_fighting() )     
            {
                remove_call_out("greeting");
                call_out("greeting", 5, me);
            }   
    }
}

void kill_him( object me)
{
    message_vision( "$N对着$n大喝一声：“杀人放火的强盗，快快受死吧！！！” \n", this_object(), me );
    kill_ob(me);
}

void greeting( object me)
{
        if(!me || environment(me)!=environment() ) return;
        if( can_act() )
        {            
                message_vision(chat_msg[random(sizeof(chat_msg))], me);
                if ( !is_fighting() )  call_out("greeting",25,me);
        }
}                           

int accept_object( object me, object obj)
{
        if ( ( obj->query("id")!="tuijian xin" )
        &&(obj->query("id")!="ling pai") )
        {
                command("say “多谢美意，不过这东西对我好象没有什么用。”");
                return 0;
        }
        if ( obj->query("id")=="tuijian xin" )
        {
                message_vision("$N看了$n一眼，说：“给我的？”拆开信读了起来。\n",
                                this_object(), me);
                remove_call_out("do_recruit1");
                call_out("do_recruit1", 3, me, obj);
                return 1;
        }
        if ( obj->query("id")=="ling pai" )
        {
                message_vision("$N看了看$n，说：“原来是侯爷引荐来的。”\n",
                                this_object(), obj);
                remove_call_out("do_recruit2");
                call_out("do_recruit2", 1, me, obj);
                return 1;
        }
}

int do_recruit1( object me, object obj )
{
        object ob=this_object();
        destruct( obj );
        if ( !me->query_temp("can_apprentice/段") )
        {
                message_vision("$N奇怪地看着$n：“这封信上怎么没有说是推荐的你啊？奇怪……”\n",
                                ob, me);
        }
        else
        {       
        if ( me->query("class_score/镇南王府")<( 1100-me->query("kar")*5 ) )
        {
            command("shake "+ me->query("id"));
            command("say “虽然段管事这么大力推荐，但是从你的表现上很难看出你足够忠诚。”");
            command("say “所以我现在不能让你担任卫士。你还是回去好好从家丁做起吧。”");
        }
        else
        {
                command("nod "+ me->query("id") );
                command("say 好吧，既然段管事这么一力推荐，你以后就跟我学功夫罢。");
                message_vision( @LONG
$N想要收$n为弟子。

$n决定拜$N为师。

$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」

LONG, ob, me);
            tell_object( me, "恭喜您成为镇南王府"+ob->query("name")+"的弟子。\n");              
                command("chat " + me->query("name") +"成为"RED"镇南王府卫士"CYN"！\n");
                    me->set("family/master_id", ob->query("id"));
                    me->set("family/master_name", ob->query("name"));
                me->set("title", RED"镇南王府卫士"NOR);
                me->save();
                    LOG_D->do_log(me, "你得到段无畏的推荐，获准向" + ob->query("name")
                                + "学习进一步的武功。\n成为一名"RED"镇南王府卫士"NOR"。");      
        }
        }
        return 1;
}

int do_recruit2( object me, object obj )
{
        object ob=this_object();
        destruct( obj );
        if ( !me->query_temp("marks/段/拿到令牌") )
        {
                message_vision("$N奇怪地看着$n：“这令牌上怎么没有你的名字啊？奇怪……”\n",
                                ob, me);
        }
        else
        {       
                command("nod "+ me->query("id") );
        command("say 好吧，既然侯爷有令，你以后就跟我学功夫罢。");
        message_vision( @LONG
$N想要收$n为弟子。

$n决定拜$N为师。

$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」

LONG, ob, me);
        tell_object( me, "恭喜您成为镇南王府"+ob->query("name")+"的弟子。\n");          
            me->set("family/master_id", ob->query("id"));
            me->set("family/master_name", ob->query("name"));
                me->set("title", RED"镇南王府卫士"NOR);
        me->save();
            LOG_D->do_log(me, "你得到鄯阐侯高升泰的赏识，获准向" + ob->query("name")
                        + "学习进一步的武功。\n成为一名"RED"镇南王府卫士"NOR"。");      
                command("chat " + me->query("name") +"成为"RED"镇南王府卫士"CYN"！\n");
        }
        return 1;
}

int refuse_killing()
{
    int i;
    object *inv, who;

        who=this_player();
    who->apply_condition("kill_dali", 250);
    inv = all_inventory( environment(this_object()) );
    for(i = 1; i < sizeof(inv); i++)
    {
        if ( !userp( inv[i] )
            &&  inv[i] != this_object() 
            && inv[i]->query("class")=="duanshi"
            && inv[i] != who )
            inv[i]->kill_ob(who);
    }
    return 0;
}

