
int query_own_titles()
{
    int lev;

    lev = this_player()->query_level();

    if (this_player()->query_gender() == 1)
    {
         if (this_player()->query_legend_level())
             this_player()->set_pretitle("Outer World Ruler");
         else if (lev < 6)
             this_player()->set_pretitle("Brother");
         else
             this_player()->set_pretitle("Monk");
    }
    else 
    {
         if (this_player()->query_legend_level())
         {
             if (this_player()->query_gender()==2)
                 this_player()->set_pretitle("Outer World Ruless");
         }
         else if (lev < 6)
             this_player()->set_pretitle("Sister");
         else
         {
          if (this_player()->query_gender()==2)
             this_player()->set_pretitle("Nun");
          else
             this_player()->set_pretitle("Nunk");
        }
    }
   return 1;
}
