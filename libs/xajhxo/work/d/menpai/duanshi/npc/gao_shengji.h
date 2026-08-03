//这是高升泰对要求升级的反应
int change_dengji()
{
    object me, ob, here, obj, npc;
    int score, num, i;
    
    me = this_player();
    ob = this_object();
    here = environment(ob);
    
    score = me->query("class_score/镇南王府");
    
    if( me->query("class")!="duanshi" )
    {
        command("say “取笑了，您怎么会在王府升什么级呢？”");
        return 1;
    }        
    if( me->query("title")!=RED"镇南王府卫士"NOR
     && me->query("title")!=MAG"镇南王府卫士"NOR
     && me->query("title")!=YEL"镇南王府卫士"NOR
     && me->query("title")!="大理国武官")
    {
        command("say “你的级别不够，升级应该找管家丁的段管事。”");
        return 1;
    }        
    if((me->query("title")==RED"镇南王府卫士"NOR && score<1600)
    || (me->query("title")==MAG"镇南王府卫士"NOR && score<2400)
    || (me->query("title")==YEL"镇南王府卫士"NOR && score<3500))
    {
        command("say “只有对王爷赤胆忠心的卫士才能得到最快的提升，你看自己做得够么？”");
        return 1;
    }        
    if( here->query("short") != "小客厅")
    {
        command("say “唔，这个么……你在小客厅等我吧！”");
        return 1;
    }   
    
    if( me->query("title")=="大理国武官" )
    {
        command("say “现在你我已经同殿称臣，不能再升了。”");
        return 1;
    }        

    command("say “卫士的升级和家丁的不同，要比试真功夫的，刀剑无眼，可能会有性命之忧。”");
    command("say “你真的已经做好准备(ok)了吗？”");
    me->set_temp("pending/ask_ok", 1);
    return 1;
}

int say_ok()
{
    object me, ob, here, obj, npc;
    int score, num, i;
    
    me = this_player();
    ob = this_object();
    here = environment(ob);
    
    score = me->query("class_score/镇南王府");

    if(!me->query_temp("pending/ask_ok")) return 0;
    me->delete_temp("pending/ask_ok");
    me->set_temp("pending/is_testing", 1);
    
    if(me->query("title")==RED"镇南王府卫士"NOR && score>=1600) num = 3;
}   
