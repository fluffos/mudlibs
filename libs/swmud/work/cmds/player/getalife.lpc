inherit CMD;

private void main(string arg)
{
   object body = find_body(arg);
   int time = time();
   float possible;
   float total;

   if (wizardp(this_body()) && body) { body = find_body(arg); }
   else { body = this_body(); }

   possible = time - body->query_character_birthday();
   total = body->query_total_connected_time() + (time - LAST_LOGIN_D->query_last(body->query_userid())[0]);

   if (body == this_body())
   {
      outf("You have been here %.1f%% of your life since creating this character.\n",
         (total * 100) / possible);
   }
   else
   {
      outf("%s has been here for %.1f%% of character time.\n",
         capitalize(arg), (total * 100) / possible);
   }
}