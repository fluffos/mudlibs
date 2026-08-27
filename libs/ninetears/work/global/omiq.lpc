/* Hamlet -- October 1995.
   This is called by various things that behave differently during 
   omiqs and/or flag games.  Don't change the functions just the #defines
   below.  It is not necessary to set OMIQ to true to set FLAG to true.
*/

#define OMIQ 0
#define FLAG 0

int omiq_in_progress() {  return (OMIQ || FLAG);  }

int flag_in_progress() {  return FLAG;  }

int is_playing_flag(object ob) {
  string team;

  if(catch(team = "/d/omiq/flag/master_control"->query_property(ob, "flagteam")))
    return 0;

  if(!team || !stringp(team))
    return 0;

  if((team == "observer") || (team == "admin"))
    return 0;

  return 1;
}

void clear_playertmp() {
  string *tmp;
  string f;

  if(explode(file_name(previous_object()), "#")[0] ==
     "/d/omiq/flag/master_control")
  {
    seteuid("Root");
    tmp = get_dir("/save/playertmp/");
    foreach(f in tmp)
      rm("/save/playertmp/"+f);
    seteuid(0);
  }
}
