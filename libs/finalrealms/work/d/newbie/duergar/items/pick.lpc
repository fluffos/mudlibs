inherit "/obj/weapon";

int query_hands_needed() { return 2; }
void setup() {
	set_base_weapon("pick");
	set_name("pick");
	set_short("pick");
   add_alias("skiepick");
	set_long("This is a pick.\n");
	set_main_plural("picks");
}

int set_in_use(int i)
{

  if(i==1)    {
       this_object()->add_static_property("PICKUSED",1);
     }
     else if(i==0)
         this_object()->remove_static_property("PICKUSED");
  return ::set_in_use(i);
}
