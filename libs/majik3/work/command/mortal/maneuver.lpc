/****
****    Command                                 use
***     Descriptions                            uses skills
**      Coder                                   Aluna
*/



int main(string args)
{
    string man;
    if(!args)
    {
	message("0",THIS->list_skills("maneuver"),THIS);
	write("\nYour current maneuver is: "+
	  replace_string(THIS->query_maneuver(),"_"," ")+".\n");
	return 1;
    }
    args=replace_string(args," ","_");
    man=THIS->set_maneuver(args);
    write("Your maneuver is: "+
      replace_string(man,"_"," ")+".\n");
    THIS->update_wielded_weapon();
    return 1;
}

query_author ()
{
  return "aluna";
}

query_synopsis ()
{
  return "maneuver [maneuver]";
}

query_example ()
{
  return "maneuver basic strike";
}

query_help ()
{
  return "Using this command you can display the available maneuvers "
       + "for you and change the maneuver to maneuver you wish to use "
       + "in the battle. Some maneuvers are better for some monsters "
       + "and some are worser.";
}

query_position ()
{
  return POS_RESTING;
}

