// Tracked shadow - Radix 1996
object hunted;
string name;
int time;

start(object ob)
{
   hunted = ob;
   name = (string)hunted->query_short();
   shadow(ob,1);
}

void destruct_tracked_shadow() { destruct(this_object()); }

int query_being_tracked() { return(1); }

void set_time_factor(int i) { time = i; }

varargs mixed move_player(string dir, string dest, mixed message,
                          object follower, mixed enter)
{
   if(!hunted || !hunted->query_timed_property("being_tracked"))
      call_out("destruct_tracked_shadow",0);
   if(environment(hunted))
   {
      environment(hunted)->add_timed_property("track_"+name,dir,time);
      environment(hunted)->add_timed_property("no_clean_up",1,time);
   }
   return hunted->move_player(dir,dest,message,follower,enter);
}
really_quit()
{
   if(hunted && environment(hunted))
   {
      environment(hunted)->add_timed_property("track_"+name,"nowhere",300);
      environment(hunted)->add_timed_property("no_clean_up",1,300);
   }
   return hunted->really_quit();
}
