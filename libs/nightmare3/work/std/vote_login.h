//    vote_login.c
//    From the Nightmare mudlib
//    Code to force people to vote on login.
//    By Kalinash 040294

int receive_objects(object ob) {
    if(!(int)VOTING_D->is_time_to_vote())
        return ::receive_objects(ob);
    if(creatorp(this_player()) || (int)this_player()->query_level() < 2)
        return ::receive_objects(ob);
    if((int)VOTING_D->query_voted((string)this_player()->query_name(), this_player()->query_class()))
        return ::receive_objects(ob);
    else
        this_player()->move_player("/domains/Praxis/"+this_player()->query_class()+"_vote");
    return ::receive_objects(ob);
}
