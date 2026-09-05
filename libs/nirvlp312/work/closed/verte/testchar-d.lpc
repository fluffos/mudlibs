#include "/obj/play/paths.h"
#include "/obj/user/dt_stamp.h"

private string *testChars;
private string *wizChars;

void reset(status arg)
{
  if(arg)
    return;
  testChars = ({});
  wizChars  = ({});
  write("RESTORING testChar data.\n");
  restore_object("pfiles/misc/testchar_d");
}

status query_prevent_shadow()
{
  return 1;
}

string * query_test_chars()
{
  return testChars;
}

string * query_wiz_chars()
{
  return wizChars;
}

string query_test_char(string nm)
{
  int x;
  if((x=member_array(nm,testChars)) == -1)
    return 0;
  else
    return wizChars[x];
}

status add_test_char(string nm)
{
  object targ;
  int    x;
  string myNm;
  
  if(!(targ = find_player(nm)))
    return (notify_fail(capitalize(nm)+" is not logged on!\n"), 0);
  if(myNm = query_test_char(nm))
    return (notify_fail(
capitalize(nm)+" is already a test character.\n"+
capitalize(nm)+" belongs to "+capitalize(myNm)+".\n"), 0);
  if(query_ip_number(targ) != query_ip_number(this_player()))
    return (notify_fail("\
For the initial registration, your prospective test character\n\
must be active from the computer you are using right now.\n"), 0);
  if((x = member_array(
    (myNm=(string)this_player()->query_real_name()),
     wizChars)) > -1)
  {
    string *tmp, *ttmp;
    int    sz;
    if(x)
    {
      tmp  = wizChars[0..x] + ({ myNm });
      ttmp = testChars[0..x] + ({ nm });
    }
    else
    {
      tmp = ({wizChars[0]})+ ({ myNm });
      ttmp = testChars[0..x] + ({ nm });
    }
    if((sz=sizeof(wizChars) > 1) && (x < sz-1))
    {
      if(x+1 == sz-1)
      {
        tmp += ({wizChars[x+1]});
        ttmp += ({testChars[x+1]});
      }
      else
      {
        tmp += wizChars[x+1..sz];
        ttmp += testChars[x+1..sz];
      }
    }
  }
  else
  {
    wizChars += ({ myNm });
    testChars += ({ nm });
  }
  log_file("TESTCHARS",
    "["+DT+"] "+capitalize(myNm)+" : "+nm+"\n");
  testChars = ({ }); wizChars = ({ });
  write("SAVING testChar data.\n");
  save_object("pfiles/misc/testchar_d");
  return 1;
} 
