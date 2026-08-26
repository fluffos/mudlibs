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
    if( this_player()->query_class() == "little_sea" 
        || this_player()->query_class() == "thief_sea" 
        || this_player()->query_class() == "big_sea" 
        || this_player()->query_class() == "reward_sea" 
        || this_player()->query_class() == "money_sea"
        || this_player()->query_class() == "king_sea" ) {

        switch(random(4)) {
            case 0: msg = ""HIR"$N"HIR"一見到$n立刻上前攻擊：「海賊來襲！全力跟$n拼了！」"NOR"\n\n"; break;
            case 1: msg = ""HIR"$N"HIR"一見到$n大喊著：「是海賊！全體動員！」"NOR"\n\n"; break;
            case 2: msg = ""HIR"$N"HIR"發現$n馬上喊道：「這裡是海軍領地！可惡的海賊別想逃走！」"NOR"\n\n"; break;
            case 3: msg = ""HIR"$N"HIR"一見到$n立刻上前攻擊：「貫徹正義之名！」"NOR"\n\n"; break;
        }
        message_vision(msg, this_object(), this_player());
        this_object()->kill_ob(this_player());
        if( function_exists("accept_kill", this_player()) && !this_player()->is_killing(this_object()) && this_player()->accept_kill(this_object()) ) return;
        if( ! this_player()->is_killing(this_object()) ) this_player()->kill_ob(this_object());
    }
}
