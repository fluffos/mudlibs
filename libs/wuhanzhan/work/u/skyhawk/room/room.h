void init() 
{
        object me = this_object();

 if (!wizardp(this_player()) && this_player()->query_condition("no_pk_time"))
   {
    this_player()->move("/d/city/dangpu");
   }
  }
