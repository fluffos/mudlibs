inherit "/std/object";
#define PLANT_HANDLER "/obj/handlers/plant"

string plant;

void set_plant(string s)
{
   plant = s;
}

void set_germ(int n)
{
   call_out("germinate", n, n);
}

void germinate(int n)
{
   object newplant;

   if (PLANT_HANDLER->query_population(plant) >= plant->query_max()) {
      call_out("germinate", n, n);
      return;
   }
   newplant = clone_object(plant);
   newplant->move(environment());
   this_object()->dest_me();
}
