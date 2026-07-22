int family_quest(object me)
{ 
    return OLD_QUEST_D->give_oldquest(me, this_object());
}

int have_family_quest(object me)
{
    return OLD_QUEST_D->have_oldquest(me, this_object());
}

void done_family_quest(object me)
{
    OLD_QUEST_D->done_oldquest(me, this_object());
}

void cancel_family_quest(object me)
{
    return OLD_QUEST_D->cancel_oldquest(me, this_object());
}

