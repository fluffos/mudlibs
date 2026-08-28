/****
****    Command                                 use
***     Descriptions                            uses skills
**      Coder                                   Aluna
*/



int main(string args)
{
    string chant, target;
    int tmp;

    if (!args)
    {
	notify_fail("Usage: divine 'name1-name2-name3-[nameN]' [target]\n");
	return 0;
    }
 
    emote ("$n {concentrate} on a spell.", THIS, 0, ENV(THIS));

    tmp=sscanf(args,"'%s' %s",chant, target);
    if(tmp)
	THIS->begin_true_name(chant, target);
    else
	tmp=sscanf(args,"'%s'",chant);
    if(tmp)
	THIS->begin_true_name(chant,target);
    else
	THIS->begin_true_name(args);
    return 1;
}

query_author ()
{
  return "aluna";
}

query_synopsis ()
{
  return "divine <'name1-name2-name3-[nameN]'> [target]";
}

query_help ()
{
  return "Using this command you can use the powers of truenames. " 
       + "The command is meant only for truly skilled mages.";
}

query_example ()
{
  return "divine 'ooqnaa-yzait-efori' namhas";
}

query_position ()
{
  return POS_STANDING;
}

