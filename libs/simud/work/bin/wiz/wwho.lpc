string status_string(object victim) {
  int idle = query_idle(victim);

  if (victim->query_invis())	// Invis
    return "~[120I~CDEF";

  if (victim->query_target())	// Fighting (blue)
    return "~[040F~CDEF";

  if (victim->query_dead())	// Dead (red)
    return "~[090D~CDEF";

  if (victim->query_editing())	// Editing (cyan)
    return "~[060E~CDEF";

  if (victim->query_mailing())	// Mailing (cyan)
    return "~[060M~CDEF";

  if (victim->query_creating())	// Character Creation (hicyan)
    return "~[140*~CDEF";

  return " ";
}

string name_color(object victim) {
  if (victim->query_testchar())
    return "~[030";	// brown
  if (victim->query_level() >= WIZLEVEL)
    return "~[020";	// green
  return "~[060";	// cyan
}

string idle_string(int time) {
  if (time < 60)	// under one minute, display seconds
    return (string)time+"s";
  if (time < 60*60)	// under one hour, display minutes
    return (string)(time/60)+"m";
  if (time < 60*60*9) {	// under 9 hours, display hours:minutes
    string buf = "";
    int y;
    y = time/(60*60);   // hours
    time -= y*60*60;
    buf += (string)y;
    y = time/(60);      // minutes
    time -= y*60;
    if (y > 9)
      buf += ":"+(string)y;
    else if (y > 0)
      buf += ":0"+(string)y;
    else
      buf += "h";
    return buf;
  } else                // more than 9 hours, display hours
    return (string)(time/3600)+"h";
}

string idle_color(object victim) {
  string str = idle_string(query_idle(victim));
  if ( str[<1..] == "s" )
    return "~[100";           // higreen
  if ( str[<1..] == "m" )
    return "~[110";           // yellow
  if ( str[<1..] == "h" )
    return "~[010";           // red
  return "~[090";             // hired
}

// Function used for sorting list of players by name
int name_sort (object a, object b) {
  string astr = a->query_name();
  string bstr = b->query_name();
  if (!stringp(astr))
    astr = "";
  if (!stringp(bstr))
    bstr = "";
  return astr > bstr;
}

main(string str) {
  object *plyrs;
  int i,wiz;
  string envstr, envobj;

  WIZ_CHECK

  plyrs = sort_array(users(),"name_sort");
  msg("~CTIT"+pad("Lvl",5,JUST_CENTER)+ "   Idle " +
              pad("Name",13,JUST_LEFT)+ pad("Reference",10,JUST_LEFT)+
              "Location");
  for (i = 0; i < sizeof(plyrs); i++) {
    if (!plyrs[i]->query_is_player()) {
       envstr = "logging in";
       envobj = query_ip_number(plyrs[i]);
//"null";
    } else {
       if( !environment(plyrs[i]) )
          envstr = "[Invalid]";
       else if ( get_location(environment(plyrs[i])) )
          envstr = get_location(environment(plyrs[i]));
	   else
          envstr = to_string(environment(plyrs[i]));

       if ( envstr[0..5] == "world;" )
          envstr = envstr[5..];

       envobj = object_name(environment(plyrs[i]));
    }
    msg("~CDEF"+pad(plyrs[i]->query_level(),5,JUST_RIGHT)+
        "~CDEF "+status_string(plyrs[i])+idle_color(plyrs[i])+
        pad(idle_string(query_idle(plyrs[i])),5,JUST_RIGHT)+"~CDEF "+
        name_color(plyrs[i])+pad(plyrs[i]->query_cap_name(),13,JUST_LEFT)+
        "~CDEF"+pad(object_name(plyrs[i])[11..],10,JUST_LEFT)+
        "~CCOM"+envstr+"~CDEF", 47);
    if (plyrs[i]->query_level() >= WIZLEVEL)
      wiz++;
  }
  msg("~CBRTTotal: "+(string)sizeof(plyrs)+" ("+(string)wiz+" wiz)~CDEF");
  return 1;
}
