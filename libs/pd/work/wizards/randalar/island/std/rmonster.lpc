inherit "std/monster";

// Originally written by Randalar in 2003
// Looking to port some of this over to PD
// Need to research how messaging works on 
// this game, as well as means to initiate an attack
private string *friends, *enemies;

void add_enemy(mixed e);
void add_friend(mixed f);
void add_ally(mixed a);
void remove_enemy(mixed e);
void remove_ally(mixed a);
void remove_friend(mixed f);
int is_fighting();
int member(mixed arr, mixed item);



int is_fighting()
{
#if 0 // Oops, doesn't work
    return query_current_attacker() &&
           present(query_current_attacker(), environment(this_object()));
#else
    return (query_current_attacker() &&
            present(query_current_attacker(), environment(this_object())) ? 1 : 0);
#endif
}

void add_enemy(mixed e)
{
    if (stringp(e))
        e = ({ e });
    else if (!pointerp(e))
             return;

    if (!pointerp(enemies))
        enemies = ({ });

    for (int i = 0; i < sizeof(e); i++)
         enemies += ({ lower_case(e[i]) });
}

void add_friend(mixed f)
{
    if (stringp(f))
        f = ({ f });
    else if (!pointerp(f))
             return;

    if (!pointerp(friends))
        friends = ({ });

    for (int i = 0; i < sizeof(f); i++)
        friends += ({ lower_case(f[i]) });
}

string *query_friends()
{
    if (!pointerp(friends))
        friends = ({ });

    return friends;
}

string *query_enemies()
{
    if (!pointerp(enemies))
        enemies = ({ });
    return enemies;
}

void remove_enemy(mixed e)
{
    if (stringp(e))
        e = ({ });
    else if (!pointerp(e))
             return;

    if (!enemies || !pointerp(enemies))
         enemies = ({ });

    for (int i = 0; i < sizeof(e); i++)
        if (member(enemies, lower_case(e[i])) >= 0)
            enemies -= ({ lower_case(e[i]) });
        else
            continue;
}

void remove_friend(mixed f)
{
    if (stringp(f))
        f = ({ lower_case(f) });
    else if (!pointerp(f))
             return;

    if (!friends || !pointerp(friends))
        friends = ({ });

    for (int i = 0; i < sizeof(f); i++)
        if (member(friends, f[i]) >= 0)
            friends -= ({ f[i] });
        else
            continue;
}

void add_ally(mixed a)
{
    return add_friend(a);
}

void add_foe(mixed f)
{
    return add_enemy(f);
}

void remove_foe(mixed f)
{
    return remove_enemy(f);
}

void remove_ally(mixed a)
{
    return remove_friend(a);
}

// Compatibility purposes... I'll need to eventually rewrite
// all my member() functions to member_array() functions
// --Randalar
int member(mixed arr, mixed item)
{
    return member_array(item, arr);
}

void heart_beat()
{
// Actually, first check to see if the damn thing has an environment
    if (environment(this_object()))
    {
        // First, check to see if any allies around are needing help
        if (!is_fighting() && friends && pointerp(friends))
        {
            object *whom;

            whom = all_inventory(environment(this_object()));

            for (int i = 0; i < sizeof(whom); i++)
            {
                if (member_array(whom[i]->query_name(), friends) >= 0)
                {
                    if (whom[i]->is_fighting())
                    {
                        say(query_name() + " shouts: All for one and one for all!\n");
                        kill_ob(whom[i]->query_current_attacker());
                        break;
                    }
                }
            }
        }

        // Next, check if any enemies are around.  Not much use currently
        // with the exception of monster vs monster combat that could be
        // neat in a role-playing aspect (e.g., racial enemies, orcs hate
        // dwarves and vice versa)

        if (!is_fighting() && enemies && pointerp(enemies))
        {
            object *whom;
            if (!enemies) enemies = ({ });
            whom = all_inventory(environment(this_object()));
            for (int j = 0; j < sizeof(whom); j++)
            {
                if (member_array(whom[j]->query_name(), enemies) >= 0)
                {
                    say(query_name() + " screams and attacks " +
                        query_possessive() + " mortal enemy!\n");
                    kill_ob(whom[j]);
                    break;
                }
            }
        }
    }
    ::heart_beat();
}
