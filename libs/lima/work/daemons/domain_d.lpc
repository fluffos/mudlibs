/*
** domain_d.c -- Controls spawns in the domains
**
** This daemon manages area spawns and makes sure that the number of mobs
** in a certain domain is under control.
**
** Tsath 2019-10-14
** Tsath 2020-01-30 (Renamed and expanded)
*/

inherit M_DAEMON_DATA;
#define PRIV_NEEDED "Mudlib:daemons"

private
mapping spawn_control = ([]);
private
mapping currency = (["std":"gold"]);

void add_spawn_control(string domain, string basename, int max)
{
   if (!check_privilege(PRIV_NEEDED))
      error("illegal attempt to add a spawn control\n");

   spawn_control[basename] = (["max":max, "domain":domain]);
   save_me();
}

void remove_spawn_control(string basename)
{
   map_delete(spawn_control, basename);
   save_me();
}

void set_currency(string domain, string coin)
{
   if (!check_privilege(PRIV_NEEDED))
      error("illegal attempt to add currency for " + domain + "\n");

   currency[domain] = coin;
   save_me();
}

void remove_currency(string domain)
{
   map_delete(currency, domain);
   save_me();
}

string query_currency(string domain)
{
   string body_d = this_body() ? file_domain(environment(this_body())) : "std";
   if (domain)
      return currency[domain] || currency["std"];

   return currency[body_d] || currency["std"];
}

mapping query_currencies()
{
   return currency;
}

void print_currencies()
{
   write(sprintf("<bld>%15.15s %15.15s<res>\n", "Domain", "Currency"));
   foreach (string domain, string cur in currency)
   {
      write(sprintf("%15.15s %15.15s\n", domain, cur));
   }
}

private
string mob_name(string basename)
{
   return explode(basename, "/")[ < 1];
}

int spawn_allowed(string basename)
{
   // The class is instance #1, the following are alive objects.
   int instances = 1;
   int spawn;
   // We are not under supervision, spawn away!
   if (!mapp(spawn_control[basename]))
      return 1;
   // We do not have a max, spawn away!
   if (!intp(spawn_control[basename]["max"]))
      return 1;

   // Expensive call, so doing this as late as possible.
   instances = sizeof(filter_array(objects(), ( : base_name($1) == $(basename) :))) - 1;
   instances = instances < 0 ? 0 : instances;

   spawn = (instances >= spawn_control[basename]["max"] ? 0 : 1);
   if (spawn)
      CHANNEL_D->deliver_channel("domains", "[" + capitalize(spawn_control[basename]["domain"]) + "]: " + "Allowed " +
                                                mob_name(basename) + " (" + (instances + 1) + "/" +
                                                spawn_control[basename]["max"] + ")");
   /*
       (spawn ?
       "domain_d allowed "+mob_name(basename)+" ("+instances+"/"+spawn_control[basename]["max"]+")" :
       "domain_d rejected "+mob_name(basename)+" ("+instances+"/"+spawn_control[basename]["max"]+")" ));
       */

   return spawn;
}

mapping query_spawn_controls()
{
   return spawn_control;
}

create()
{
   ::create();
}

void clean_up()
{
   destruct();
}

void stat_me()
{
   print_currencies();
}