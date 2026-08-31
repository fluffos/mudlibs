
/* Coded by Tinman 4-05-99 */
/* Initial Copy by Whisky */

string extra_look()
{
    string me;
    string poss;
    string res;


    me = capitalize(environment()->query_real_name());
    poss = environment()->query_possessive();

    res = (
    me+"'s beautiful body is athletic and well built.\n"+
  "On "+poss+" arm you see the symbol of a 'golden Dragon'");
    if (environment()->blink_shad())
    {
         res = res + "\n"+capitalize(poss)+" suntanned body seems"+
               " to vibrate slightly";
     }
     switch(present("monksoul",environment())->query_g_status()) {
	case 0: res = res + "\n"+me+" is a Member of the Monk Guild";
	break;
	case 1: res = res + "\n"+me+" is a Protector of the Monk Guild";
	break;
	case 2: res = res + "\n"+me+" is a Master of the Monk Guild";
	break;
	case 3: res = res + "\n"+me+" is an Assistant Guild Master of the Monk Guild";
	break;
	case 4: res = res + "\n"+me+" is a Guild Master of the Monk Guild";
	break;
       default: res = res + "\n"+me+" is a Member of the Monk Guild";
	break;
	}
	return res;
}

