// Rust.

private int mass;

//:FUNCTION set_mass
//Change the mass of an object
void set_mass(int m)
{
   object env;

   mass = m;

   if (env = environment(this_object())) { env->update_capacity(); }
}

//:FUNCTION set_weight
//calls set_mass() for compat reasons
void set_weight(int m)
{
   mass = m;
}

//:FUNCTION query_mass
//returns the mass of an object
int query_mass()
{
   return mass;
}

//:FUNCTION query_weight
//returns the mass of an object, based on local gravity
float query_weight()
{
   int gravity;
   float weight;
   mass = this_object()->query_mass();
   weight = (mass * 2.0) / 1000.0;

   if (!environment(this_object()))
   {
      if (weight < 0.1) { weight = 0.1; }

      return weight;
   }

   // If we're sitting in a room.
   if (environment(this_object())->is_room())
   {
      if (environment(this_object())->query("gravity"))
      {
         gravity = environment(this_object())->query("gravity");
         weight = (((mass * gravity) / 10.0) * 2.0) / 1000.0;
      }

      if (weight < 0.1) { weight = 0.1; }

      return weight;
   }

   // if we are in something's inventory.
   if (environment(this_object())->is_living())
   {
      if (!environment(environment(this_object()))) { return weight; }

      if (environment(environment(this_object()))->is_room())
      {
         if (environment(environment(this_object()))->query("gravity"))
         {
            gravity = environment(environment(this_object()))->query("gravity");
            weight = (((mass * gravity) / 10.0) * 2.0) / 1000.0;
         }
      }

      if (weight < 0.1) { weight = 0.1; }

      return weight;
   }

   // we're in a bag, or box, pack, etc
   if (!environment(this_object())->is_living() && environment(this_object())->is_container())
   {
      if (!environment(environment(this_object())))
      {
         if (weight < 0.1) { weight = 0.1; }

         return weight;
      }

      if (environment(environment(this_object()))->is_living())
      {
         if (!environment(environment(environment(this_object()))))
         {
            if (weight < 0.1) { weight = 0.1; }

            return weight;
         }

         if (environment(environment(environment(this_object())))->is_room())
         {
            if (environment(environment(environment(this_object())))->query("gravity"))
            {
               gravity = environment(environment(environment(this_object())))->query("gravity");
               weight = (((mass * gravity) / 10.0) * 2.0) / 1000.0;
            }
         }

         if (weight < 0.1) { weight = 0.1; }

         return weight;
      }

      if (environment(environment(this_object()))->is_room())
      {
         if (environment(environment(this_object()))->query("gravity"))
         {
            gravity = environment(environment(this_object()))->query("gravity");
            weight = (((mass * gravity) / 10.0) * 2.0) / 1000.0;
         }
      }

      if (weight < 0.1) { weight = 0.1; }

      return weight;
   }

   if (weight < 0.1) { weight = 0.1; }

   return weight;
}