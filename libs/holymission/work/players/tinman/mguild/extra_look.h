
/* extra_look */


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
     if (environment()->query_property("monk_legend")>0) 
         res = res + "\n"+me+" is a Monk Legend";
     return res;
}





