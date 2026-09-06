int main() {
  string weather;
  if( environment(this_player()) && environment(environment(this_player())) )
     weather = environment(environment(this_player()))->query_weather_desc();
  if( weather ) msg(weather);
  else msg("There is no weather here.");
  return 1;
}
