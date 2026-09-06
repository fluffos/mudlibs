string *query_daemons() {
   return ({
      "/daemon/cryo",
      "/daemon/idle",
      "/daemon/hunger"
   });
}


void activate()
{
   foreach(string daemon : query_daemons() ) {
      catch(load_object(daemon));
   }
}

void deactivate()
{
   foreach(string daemon : query_daemons() ) {
      object obj;

      obj = find_object(daemon) && catch(
         destruct(obj)
      );
   }
}

void create()
{
   activate();
}

void destructor(object ob)
{
   deactivate();
}
