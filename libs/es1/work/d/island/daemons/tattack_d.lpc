
object *members = ({});

void add_member()
{
     members += ({ previous_object() });
}

void remove_member()
{
    members -= ({ previous_object() });
}

void add_huntee(object who)
{
    members -= ({0});
    members->pseudo_hunt(previous_object(), who);
}

object *query_army()
{
    return members;
}
