
mixed hit_player(int dam,int kind,mixed elem)
{
      if (this_player()->query_property("hunted_by_orcs")==-1)
           this_player()->add_property("hunted_by_orcs",1);
     
      return ::hit_player(dam,kind,elem);
}

int chk_attack(object food)
{
    string race;

    race = food->query_race();

    if (!interactive(food))
        return 0;
    else if ((race=="orc" || race=="giant" || race=="troll") 
         && food->query_property("hunted_by_orcs")==-1)
       return 0;
  return 1;
}

     
