int main(string str)
{
    object tp = this_player();
    object here = environment(tp);

    write("You fumble about in your pockets and find a snowball.\n");
    tell_room(here, capitalize(tp->query_name()) + " fumbles about in some pockets and finds a snowball.\n", ({ tp }));

    call_out("throw_snowball", 2, here, tp);
    return 1;
}

void throw_snowball(object here, object tp)
{
    object *u = users();
    int u_sz = sizeof(u);

    tell_object(tp, "You take a step back, aim and launch the snowball.\n");
    tell_room(here, capitalize(tp->query_name()) + " takes a step back, aims and launches the snowball.\n", ({ tp }));

    call_out("snowball_hit", 5, u[random(u_sz)]);

    return;
}

void snowball_hit(object vict)
{
    object here = environment(vict);

    tell_object(vict, "A large snowball appears out of the sky and hits you on the back of the head.\n");
    tell_room(here, "A large snowball appears out of the sky and hits " + capitalize(vict->query_name()) + " on the back of the head.\n", ({ vict }));

    return;
}

string help()
{
     return(HIW + " SYNTAX: " + NOR + "snowball [victim]\n"
     "Go back to your childhood and throw snowballs at the players.\n");
}
