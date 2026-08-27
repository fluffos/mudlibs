inherit "/obj/monster";
nosave object myfriend;
void set_friend(object friend) 
{
    myfriend = friend;
}

void event_fight_in_progress(object ob1,object ob2)
{
    if(ob1 && ob1 != myfriend)
	::attack_by(ob1);
    if(ob2 && ob2 != myfriend)
	::attack_by(ob2);
}
void attack_by(object ob)
{
    if(ob == myfriend)
    {
	tell_room(environment(this_object()),"The "+this_object()->query_cap_name()+" sighs and returns to the grave.\n");
	call_out("dest_me",0);
    }
    ::attack_by(ob);
}
void attack_ob(object ob)
{
    if(ob == myfriend) return;
    ::attack_ob(ob);
}


