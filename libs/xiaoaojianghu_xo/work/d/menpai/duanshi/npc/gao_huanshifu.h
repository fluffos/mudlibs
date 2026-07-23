//这是对玩家要求换师傅的时候高升泰的反应
int change_master()
{
    object me, ob, here, obj;
    int num;
    
    me = this_player();
    ob = this_object();
    here = environment(ob);
    
    if( me->query("class") != "duanshi" )
    {
        command("say “您取笑了，您和本王府没有什么关系啊？！”");
        return 1;
    }        
    if( here->query("short") != "小客厅" )
    {
        command("say “嗯，我知道了，你先在小客厅等我吧！”");
        return 1;
    }        
    if( me->query("title") == RED"镇南王府卫士"NOR )
    {
        command("say “你身份不够，只能向卫护们学功夫，不要好高骛远！”");
        return 1;
    }        
    if(( me->query("title") == MAG"镇南王府卫士"NOR )
    && (( me->query("family/master_id") == "hua hegen" )
     || ( me->query("family/master_id") == "fan hua" )
     || ( me->query("family/master_id") == "ba tianshi" )))
    {     
        command("say “你身份不够，只能向大理三公学功夫，不要好高骛远！”");
        return 1;
    }        
    if(( me->query("title") == YEL"镇南王府卫士"NOR )
    && ( me->query("family/master_id") == "gao shengtai" ))
    {
        command("say “你身份不够，只能向为师我学功夫，不要好高骛远！”");
        return 1;
    }        
    if( me->query_temp("marks/段/拿到令牌2") )
    {
        command("say “你不是拿了我的令牌了么？怎么又来了？！”");
        return 1;
    }        
    if( me->query("title") == MAG"镇南王府卫士"NOR )
    {
        if( me->query("class_score/镇南王府")<2000 )
        {
            command("say “你目前的表现不够忠心耿耿，所以不能学习更高深的武功！”");
            return 1;
        }            
        command( "nod" );
        command( "say “好吧，你可以凭我的令牌向大理三公学习武功。”");
        obj = new(__DIR__"obj/lingpai");
        obj->move(me);
        me->set_temp("marks/段/拿到令牌2", 1);
        message_vision("$N交给$n一块令牌。\n",this_object(), me);
    }
    if( me->query("title") == YEL"镇南王府卫士"NOR )
    {
        if( me->query("class_score/镇南王府")<3000 )
        {
            command("say “你目前的表现不够忠心耿耿，所以不能学习更高深的武功！”");
            return 1;
        }            
        command( "nod" );
        command( "say “好吧，你可以向我学习武功了！”" );
        me->set("family/master_id", "gao shengtai" );
        me->set("family/master_name", "高升泰" );
        LOG_D->do_log(me, "你获得了高升泰对你的赏识，终于同意亲自教你高深的武功了。");        
        message_vision( @LONG
$N想要收$n为弟子。

$n决定拜$N为师。

$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」

LONG, ob, me);
        tell_object( me, "恭喜您成为镇南王府"+ob->query("name")+"的弟子。\n");          
        me->save();
    }        
    if( me->query("title") == "大理国武官" )
    {
        if( me->query("class_score/镇南王府")<4500 )
        {
            command("say “你目前的表现不够忠心耿耿，所以不能学习更高深的武功！”"); 
            return 1;
        }
        if( me->query("class_score/镇南王府")<( 6000 - me->query("kar")*25 ) )
        {
            if ( !me->query("marks/段/can_ask_key") )
            {
                num = (random(9)+1)*10000
                    + (random(9)+1)*1000
                    + (random(9)+1)*100
                    + (random(9)+1)*10
                    + (random(9)+1)*1;
                command( "nod" );
                command( "say “嗯，你现在这个样子也不容易，王爷说啦，你现在可以到内书房看书。”" );
                command( "say “你进入内书房的口令是："
                 + CHINESE_D->chinese_number( num/10000 ) 
                 + CHINESE_D->chinese_number( num/1000-num/10000*10 ) 
                 + CHINESE_D->chinese_number( num/100-num/1000*10 ) 
                 + CHINESE_D->chinese_number( num/10-num/100*10 ) 
                 + CHINESE_D->chinese_number( num-num/10*10 ) + " 。”" );
                LOG_D->do_log(me, "你获得了王爷的信任，可以进入内书房学习武功了。");        
                me->set("marks/段/can_ask_key", num);
                me->save();
            }
            else
                command( "say “你现在还是凭口令到书房多念点书吧。”");
        }            
    }        
//嘿嘿，先写这么多，估计能坚持到“十一”了
//对于“大理武官”怎么处理先扔这儿
//反正要见老段要至少10000的忠诚度才能够
    return 1;
}
        
int ask_key()
{
    object me = this_player();
    int num;
    if( !num = me->query("marks/段/can_ask_key") )
        return 0;
    command("say “真是糊涂，这么重要的东西也能忘记！”");
    command("say “再告诉你一次，口令是： "
     + CHINESE_D->chinese_number( num/10000 ) 
     + CHINESE_D->chinese_number( num/1000-num/10000*10 ) 
     + CHINESE_D->chinese_number( num/100-num/1000*10 ) 
     + CHINESE_D->chinese_number( num/10-num/100*10 ) 
     + CHINESE_D->chinese_number( num-num/10*10 ) + " 。”" );
    return 1;
}


