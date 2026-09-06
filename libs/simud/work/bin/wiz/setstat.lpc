int main(string arg) {
   string stat;
   int val;
   object victim = this_player();

   if (!arg) {
      msg("syntax: setstat stat value");
      return 1;
   }

   sscanf(arg,"%s %d",stat,val);
   if (!member(victim->query_stats(), stat)) {
      msg("No such stat ~CBRT"+stat+"~CDEF.");
      return 1;
   }
   if (val > 20 || val < 1) {
      msg("Must give a value between 1 and 20");
      return 1;
   }

   victim->set_stat(stat,val);
   msg(victim->query_cap_name()+"'s "+stat+" set to "+val+".");
   return 1;
}
