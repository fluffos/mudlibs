#define INCUBATE_TIME 200

void init_curse(object target)
{
    target->add_timed_property("COLD_CURSE_INCUBATE",1,INCUBATE_TIME);
}

void curse_end(object target)
{
    tell_object(target,"Ah much better. Your nose clears up, "
      "the headache disappears and "
      "you feel much better!\n");
    tell_room(environment(target),target->query_cap_name()+" looks a bit healthier.\n",
      ({target}));
}



void player_start(object target)
{
    // Nope, nothing happens here. Shadows would get setup here though.
}

void player_quit(object target)
{
    // Nope, nothing happening here either. Desting of shadows would go here though.
}

void curse_heart_beat(object target)
{

    if((target->query_time_remaining("COLD_CURSE_INCUBATE") < 40) &&
      (target->query_property("COLD_CURSE_INCUBATE")))
    {
        tell_object(target,"\nAll of a sudden you feel dizzy, your nose itch "
          "and your head starts aching.\n");
        tell_room(environment(target),target->query_cap_name()+" suddenly doesn't look "
          "too well.\n",({target}));
    }
    tell_object(target,"You sneeze violently.\n");
    tell_object(environment(target),target->query_cap_name()+
      " sneezes violently.\n",({target}));
}


int prevent_remove(object target, object remover)
{
    object *stuff;
    int i;

    stuff = all_inventory(remover);
    for(i=0;i<sizeof(stuff);i++)
    {
        if(stuff[i]->query_property("cold_remedy"))
            return 0;
    }
    return 1;
}  
