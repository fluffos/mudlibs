/* Code to be inherited by any object that raises stats!

   Written by Chronos.
*/

int raise_stat() {
  string stat;
  int mod, duh;
  if (this_object()->query("stat_invoked")) return 0;
  stat = this_object()->query("raise_stat");
  if (!stat) return -1;
  if (!userp(environment())) return -1;
  mod = this_object()->query("modifier");  
  duh = environment()->query("stat/"+stat);
  environment()->set("stat/"+stat,mod+duh);
  if (stat=="strength") environment()->fix_volcap();
  environment()->check_stats();
  this_object()->set("stat_invoked", 1);
  return 1;
}

int lower_stat() {
  string stat;
  int mod, duh;
  if (!this_object()->query("stat_invoked")) return 0;
  stat = this_object()->query("raise_stat");
  if (!stat) return -1;
  if (!userp(environment())) return -1;
  duh = environment()->query("stat/"+stat);
  mod = this_object()->query("modifier");
  environment()->set("stat/"+stat, duh - mod);
  if (stat=="strength") environment()->fix_volcap();
  environment()->check_stats();
  this_object()->delete("stat_invoked");
  return 1;
}
