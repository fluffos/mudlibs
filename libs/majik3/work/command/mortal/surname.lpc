/*
   File: surname.c
   Description: Set thy surname!
   Creator: Dranil
*/
#include <message.h>

int
main(string str)
{
    if (!str)
    {
        p_line ("Give an argument to be set as thy name\n");
        return 1;
    }

    if(strlen (str) > 15)
    {
    p_line ("Too long surname. Maxium surname is 15 chars\n");
    return 1;
    }    

    if (strsrch(str,"^") != -1) {
        p_line ("Colors not allowed in surname!");
        return 1;
    }

    if (THIS->query("surname") && !THIS->query_security()) {
        p_line ("You have a surname already!");
    return 1;
    }

    THIS->set("surname", str);
    p_line ("You are now known as: "+THIS->short()+"\n");
    return 1;
}

query_author()
{
  return"dranil";
}

query_help()
{
  return "Sets <str> as a surname for you.";
}

query_see_also()
{
  return "title(1)";
}
query_position()
{
  return POS_RESTING;
}

