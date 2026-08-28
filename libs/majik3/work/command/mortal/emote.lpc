int
main (string str)
{
    if (!str)
    {
	write ("usage: emote <text>\n");
	return 1;
    }

    if(THIS->query_security()||!interactive(THIS))
	message("emote",capitalize(this_player ()->query_name ()) + " " + str + "^c0\n",all_inventory(environment(THIS)),THIS);
    else
	message("emote","* " + capitalize(THIS->query_name ()) + " " + str + "^c0\n",all_inventory(environment(THIS)), THIS);

    message ("emote","You emote: "+capitalize(this_player()->query_name())+" " + str +"\n",THIS);
    return 1;
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "emote <emote text>";
}

query_example ()
{
  return "emote thinks that this help page sucks";
}

query_help ()
{
  return "This command writes to players in the same room with you "
       + "the <emote text> prefixed by your name.";
}

query_see_also ()
{
  return "tell(1), say(1), shout(1), whisper(1)";
}

query_position ()
{
  return POS_RESTING;

}
