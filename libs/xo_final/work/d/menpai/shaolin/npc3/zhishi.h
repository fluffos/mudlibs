/* zhishi.h
 * created by hydra 19980514
 * 少林各堂院知事都include的文件 
 * change_master( object )          换师傅用的函数， 
 * lose_bihua( object )             比划失败后的函数，给一封信 
 * give_letter( object )            给ppl一封推荐信，去闯罗汉阵 
 */

void give_letter( object ppl )
{
    object letter,me;
    string lon;
    me = this_object();
    letter = new( __DIR__"obj/letter" );
    lon = "                    "RED"推荐信"NOR"        \n\n";
    lon += "    推荐"+ppl->query("family/belong")+HIB"弟子"NOR;
    lon += ppl->query("name")+"("+ppl->query("id")+")";
    lon += "前来进行升级比武。\n\n";
    lon += "                "+me->query("title")+"  "+me->query("name");
    letter -> set("long",lon);
    letter -> move( ppl );
    ppl -> set_temp("hydra/shaolin/can_chuang",1);
    tell_object( ppl,me->query("name")+"给你一封推荐信。\n");
}

string change_master( object ppl )
{
    string master_id,belong;
    object this;
    this = this_object();
    ppl = this_player();
    belong = this->query("family/belong");
    if( ppl -> query("family/family_name") != "少林派" )
        return 0;
    if( ppl -> query("family/belong") != belong  )
    {
        command( "? "+ppl->query("id") );
        return "你不是我"+belong+"弟子啊？";
    }
    if( ppl->query("class_score/少林派") < 1600 )
        return "你还是不要急着升级，还是多为少林做些事情吧！";
    
    if( ppl->query_temp("hydra/shaolin/defeat_master") )
    {
        command ("say 好，你打败了你的师傅。");
        give_letter(ppl);
        ppl -> delete_temp("hydra/shaolin/defeat_master") ;
        return "你凭这封信去找罗汉堂的玄生师叔祖吧！";
    }
    
    if( (master_id=ppl->query("family/master_id")) == query("id") )
    {  
        ppl->set_temp("hydra/shaolin/fight_master",master_id);
        return "你先跟为师的比划一下再做决定。";
    }
    else
    {
        ppl->set_temp("hydra/shaolin/fight_master",master_id);
        return "你先回去跟你的师傅比划一下再做决定。";
    }
}

int lose_bihua( object ppl )
{
    if( ppl->query_temp("hydra/shaolin/fight_master") == query("id"))
    {
        command( "smile "+ppl->query("id"));
        command( "say 好徒儿，有出息！");
        ppl ->delete_temp("hydra/shaolin/fight_master");          
        give_letter( ppl );
        command( "say 你凭这封信去找罗汉堂的玄生师叔祖吧！");        
    }
    return 1;
}

