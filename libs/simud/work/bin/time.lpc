int main() {
  string weather;
  msg("Walraven's time is "+"/daemon/time"->query_time_of_day() + " on " + "/daemon/time"->query_date());
  msg("Current server time is "+ctime(time())+".");
  if( environment(this_player()) && environment(environment(this_player())) )
     weather = environment(environment(this_player()))->query_weather_desc();
  if( weather ) msg("Weather: " + weather);
  return 1;
}
