void init()
{
    string msg;

    if( this_object() == this_player() ) return;

    // 若 this_player() 看不見這個人物，則不引發戰鬥。
    if( ! this_object()->visible(this_player()) ) return;

    // 區域設定
    if( environment()->is_area() && !area_environment(this_object(), this_player()) ) return;

    // 若雙方正互相仇視中，開始戰鬥。
    if( this_player()->is_killing(query("id")) ) {
        COMBAT_D->auto_fight(this_player(), this_object(), "hatred");
        return;
    }
    if( is_killing(this_player()->query("id")) )
    {
        COMBAT_D->auto_fight(this_object(), this_player(), "hatred");
        return;
    }
    // 遇到海賊職業的就主動攻擊
    if( this_player()->query_class() == "work_sea" 
        || this_player()->query_class() == "soldier_sea" 
        || this_player()->query_class() == "officer_sea" 
        || this_player()->query_class() == "guard_sea" 
        || this_player()->query_class() == "general_sea"
        || this_player()->query_class() == "admiral_sea" ) {

        switch(random(4)) {
            case 0: msg = ""HIR"$N"HIR"一見到$n立刻咆哮著：「海軍殺來啦！」"NOR"\n\n"; break;
            case 1: msg = ""HIR"$N"HIR"拿起戰刀備戰：「殺殺殺！」"NOR"\n\n"; break;
            case 2: msg = ""HIR"$N"HIR"大聲喊著：「前方有海軍來襲！大家注意！」"NOR"\n\n"; break;
            case 3: msg = ""HIR"$N"HIR"大吼：「別讓那熊樣的海軍走狗跑啦！」"NOR"\n\n"; break;
        }
        message_vision(msg, this_object(), this_player());
        this_object()->kill_ob(this_player());
        if( function_exists("accept_kill", this_player()) && !this_player()->is_killing(this_object()) && this_player()->accept_kill(this_object()) ) return;
        if( ! this_player()->is_killing(this_object()) ) this_player()->kill_ob(this_object());
    }
}
