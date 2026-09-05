#define ACTIVE_PLAYERS(x)    "pfiles/"+x[0..0]+"/"
#define INACTIVE_PLAYERS(x)  "players/inactive_saved/"
#define BANISHED_PLAYERS(x)  "banish/"
#define WIZARDS(x)           "players/"

#define RO(x,y) (restore_object(x+y))

status security_check()
{
  return (this_player() && environment(this_player()) && 
          this_player()->query_real_name());
}

status dvalid_active_player(string nm)
{
  if(!security_check()) return 0;
  return RO(ACTIVE_PLAYERS(nm), nm) > 0;
}

status dvalid_wizard(string nm)
{
  if(!security_check()) return 0;
  return RO(WIZARDS(nm), nm) > 0;
}

status dvalid_banished_player(string nm)
{
  if(!security_check()) return 0;
  return RO(BANISHED_PLAYERS(nm), nm) > 0;

}

status dvalid_inactive_player(string nm)
{
  if(!security_check()) return 0;
  return RO(INACTIVE_PLAYERS(nm), nm) > 0;
}

int dvalid_player(string nm)
{
  if(dvalid_banished_player(nm)) return 4;
  else if(dvalid_inactive_player(nm)) return 3;
  else if(dvalid_wizard(nm)) return 2;
  else if(dvalid_active_player(nm)) return 1;
}   

int query_prevent_shadow() { return 1; }
