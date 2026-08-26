inherit "/std/effect_shadow";


int test_for_effect( object thing ) {
   return member_array( "/std/effects/other/party-hat",
      (string *)thing->query_wear_effects() ) != -1;
}

void taken_off(object what, string eff)
{
  if (eff != "/std/effects/other/party-hat")
    player->taken_off(what, eff);
  else {
    remove_this_effect();
  }
}

