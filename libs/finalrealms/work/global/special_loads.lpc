/*
 * Wonderflug 1996.
 * This handles birthdays, and other crap like that, that doesn't belong
 * in the auto loader, yet, for some unexplicable reason, was in the auto 
 * loader.
 */

void birthday_gifts() 
{

  if( !sizeof( find_match("birthday card", this_object()) ) )
    if( this_object()->query_is_birthday_today() )
      if( !catch(call_other("/obj/b_day/card", "??") ) &&
          !catch(call_other("/obj/b_day/demon", "??") ) ) 
      {
        call_out("card_arrives", 5);
      }

} /* birthday_gifts() */

int query_special_day(string type) 
{
  string s1, s2, month;
  int day;

  sscanf(ctime(time()), "%s %s %d %s", s1, month, day, s2);
  switch (type) 
  {
    case "cabbage day" :
      if (month == "Feb" && day == 17)
        return 1;
      return 0;
    case "test day" :
      if (month == "Feb" && day == 16)
        return 1;
      return 0;
  }
  return 0;
} /* query_day_special() */

void card_arrives() 
{
  object card;

  card = clone_object("/obj/b_day/card");
  if ( !card )
  {
    write("You would've received a birthday card just now, however "
      "we seem to be out of stock.\n");
    return ;
  }

  tell_room(environment(this_object()), 
    "You hear a rumbling in the distance. "
    "Then, suddenly, a malformed goblin wizzes past you, "
    "frantically pedalling a fire-engine red tricycle!\n");

  write("You feel something thrust into your hand by a greener, "
    "wartier one.\n");

  if ( card->move(this_object()) )
  {
    write("However you couldn't quite keep a hold on it, and you drop "
      "it on the ground.\n");
    card->move( environment(this_object()) );
  }
} /* card_arrives() */
