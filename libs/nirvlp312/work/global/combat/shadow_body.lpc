object player;

void
set_shadowing(object pl)
{
  player = pl;
  shadow(player,1);
}

object
query_body()
{
  return player->query_body();
}

string
get_hit_location(int from)
{
  object b;
  if (b = query_body())
    return b->get_hit_location(from);
}

mapping
query_hit_locations(int from)
{
  object b;
  if (b = query_body())
    return b->query_hit_locations(from);
}

varargs int
wield_weapon(object weapon,mixed where)
{
  object b;
  if (b = query_body())
    return b->wield_weapon(weapon,where);
}

remove_weapon(object weapon)
{
  object b;
  if (b = query_body())
    return b->remove_weapon(weapon);
}

int
wear_garment(object garment)
{
  object b;
  if (b = query_body())
    return b->wear_garment(garment);
}

int
remove_garment(object garment)
{
  object b;
  if (b = query_body())
    return b->remove_garment(garment);
}

void
receive_attack_event(mapping e, string t, int p)
{
  object b;
  if (t != "attack" || !(b = query_body()))
    return;
  b->receive_attack_event(e,t,p);
}

#if 0  // temporarily disabled because of monster::query_race()
string 
query_race()
{
  object b;
  if (b = query_body())
    return b->query_race();
}
#endif

string *
query_wielded(object weapon)
{
  object b;
  if (b = query_body())
    return b->query_wielded(weapon);
}

varargs string *
query_worn(object garment)
{
  object b;
  if (b = query_body())
    return b->query_worn(garment);
}

varargs mixed
query_weapons(mixed hands)
{
  object b;
  if (b = query_body())
    return b->query_weapons(hands);
}

varargs mixed
query_armours(mixed where)
{
  object b;
  if (b = query_body())
    return b->query_armours(where);
}

status
query_bodypart(string part)
{
  object b;
  if (b = query_body())
    return b->query_bodypart(part);
}

varargs mixed *
query_resources(mixed weapon_or_bodypart)
{
  object b;
  if (b = query_body())
    return b->query_resources(weapon_or_bodypart);
}

void
schedule_action(mapping last_action)
{
  object b;
  if (b = query_body())
    return b->schedule_action(last_action);
}

int
damage_bodypart(string bodypart,int how_much)
{
  object b;
  if (b = query_body())
    return b->damage_bodypart(bodypart,how_much);
}

int
heal_bodypart(string bodypart,int how_much)
{
  object b;
  if (b = query_body())
    return b->heal_bodypart(bodypart,how_much);
}
