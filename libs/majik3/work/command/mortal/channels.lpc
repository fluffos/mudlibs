/****
****    Command                                 channels        
***     Description                             Shows available channels
**      Coder                                   Dazzt
*/


int main()
{
    object chan_d = find_object(CHANNEL_D);
    string *channels;
    string s;
    int i;

    channels = chan_d->query_valid_channels();
    message("standard", "Available channels:\n\n", THIS);
    for (i = 0; i < sizeof(channels); i++)
    {
	if (THIS->query_security() < chan_d->query_channel_level(channels[i]))
	    continue;
	s = sprintf("  %10s : ", channels[i]);
	if (THIS->query_channel(channels[i]))
	    s += "on";
	else
	    s += "off"; 
	message("standard", s + "\n", THIS);
    }
    return 1;
}

query_author ()
{
  return "dazzt";
}

query_help ()
{
  return "Shows you the current channels that are available to you "
       + "and how you have them toggled. Valid toggles are on and "
       + "off. If on you will see messages that are ut on those "
       + "channels and if off you won't.";
}
