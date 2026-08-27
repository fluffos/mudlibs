// Radix : August 1997
// Cracking down on illegal xp add_action's

void valid_adjust_xp(object prev, object this, int i)
{
   if(i < 1) return;
   if(prev->query_creator() && this->query_creator())
      return;
   if(real_filename(prev)[0..3] == "/std")
      return;
   if(!prev->query_npc() && !prev->is_player())
   {
      secure_log_file("xp", sprintf("%O - %s - %d - %s\n",
         prev,
         this->query_name(),
         i,
         this_player()->query_name()));
   }
   return;
}
