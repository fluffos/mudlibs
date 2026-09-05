nomask mixed valid_write(string arg,object c) {
  string str, who,tmpa,tmpb,tmpc, file, temp;
  string tpa,tpb, fname;
  int tempb;
  object prev_caller;
  string bbbttttj;
  string heh, heh2;
  mixed result;

  /* Allow wizards to change the central wlog, if wlog calls it */
/*
if (find_player("earwax") && this_player() && (prev_caller = previous_object()))
tell_object(find_player("earwax"), HIR+"VALIDWRITE TEST: "+NORM+(string)this_player()->query_real_name()+" ... "+arg+" ... "+file_name(prev_caller)+"\n");
write("THIS HIT\n");
*/
  if (level >= CREATE && arg == "/log/WR/WORK_REPORT"
  && previous_object() && file_name(previous_object()) == "bin/wiz/_wlog")
  {
    return ("log/WR/WORK_REPORT");
  }

/* ghetto fix. don't know why this makes things happy -Bp */
/*
  if(level > CREATE)
  bbbttttj = creator(caller());
*/
  
  if (!arg) return 0;
  prev_caller = caller();
/*
  fname = (c ? file_name(c) : 0);
*/
  if (caller()!=myself || !c) c=caller();
  if (c!=this_object() && !in_editor(this_object()))

/*
  if (fname &&
   (  fname[0..3] == "room" 
  ||  fname[0..2] == "obj"
  ||  fname[0..2] == "bin"
  ||  fname[0..2] == "sys"
  ||  fname[0..5] == "secure"
  ||  fname[0..6] == "daemons"
  ||  fname[0..5] == "closed"))
    c = this_object();
*/
  if (extract(file_name(c),0,3)=="room" ||
      extract(file_name(c),0,2)=="obj" ||
      extract(file_name(c),0,2)=="bin" ||
      extract(file_name(c),0,5)=="secure" ||
      extract(file_name(c),0,2)=="lib" ||
      extract(file_name(c),0,2)=="sys" ||
      extract(file_name(c),0,6)=="daemons" ||
      /* Added next 4 lines - Rumplemintz - 08/12/2011 */
      extract(file_name(c),0,5)=="kernel" ||
      extract(file_name(c),0,5)=="global" ||
      extract(file_name(c),0,4)=="basic" ||
      extract(file_name(c),0,6)=="complex" ||
      extract(file_name(c),0,5)=="closed")
    c=this_object();
  if (in_editor(this_object())) c=this_object();
  if(inact && !inacttwo) {
    if((int)get_handshake(handshake) != inact) {
      return 0;
    }
    if (sscanf(arg, "/pfiles/%s.o", who) == 1) {
      if(who == extract(name,0,0)+"/"+name) 
        return "pfiles/"+extract(name,0,0)+"/"+name+".o";
      return 0;
    }
  write("past-pfile-name-check");
    if (sscanf(arg, "/players/%s.o", who) == 1) {
      if(who == name) return "players/"+name+".o";
      if (sscanf(arg, "/players/inactive_saved/%s.o", who) == 1) {
        if(who == name) return "players/inactive_saved/"+name+".o";
        return 0;
      }
      return 0;
    }
    if (sscanf(arg, "/players/inactive_saved/%s.o", who) == 1) {
      if(who == name) return "players/inactive_saved/"+name+".o";
      return 0;
    }
    return 0;
  }
  if(sscanf(arg,"/bin/soul/%s",who) && prev_caller && basename(prev_caller) == "/bin/soul/editor") return "bin/soul/"+who;
  if(sscanf(arg, "/doc/helpdir/%s",who)) return "doc/helpdir/"+who;
  if(sscanf(arg, "/pfiles/notes/%s",who)) return "pfiles/notes/"+who;
  if (extract(arg,0,8)=="/Driver32") {
    if(sscanf(arg, "%splayers%s", tmpa, tmpb) !=2 ) {
      return 0; 
    } else {
      tmpa = 0;
      sscanf(tmpb, "/%s/", tmpa);
      if(!tmpa) sscanf(tmpb, "/%s", tmpa);
      if(tmpa == name) return extract(arg,1,strlen(arg));
      return 0; 
    }
  }
  str = arg;
  if (str == "~" || str == "~/") 
    str = "/players/" + name;
  else if (sscanf(str,"~/%s",temp) == 1)
    str = "/players/" + name + "/" + temp;
  else if (sscanf(str,"~%s",temp) == 1)
    str = "/players/" + temp;
  else if (str[0] != '/')
    str = pwd + str;
  if(sscanf(str, "/doc/helpdir/%s",who) && name == "star") return "doc/helpdir/"+who;
  if (sscanf(str, "%s//%s", temp)) return 0;
  if (sscanf(str, "//%s", temp)) return 0;
  if (sscanf(str, "/.%s", temp)) return 0;
  if (sscanf(str, "%s/.%s", temp, temp)) return 0;
  if (sscanf(str, "/players/%s/%s", who, file) == 2) {
    if(level < ELDER && level > 20)
      if(sscanf(str,"%s"+name+"%s",tpa,tpb) != 2)
        if(sscanf(file_name(c),"players/"+who+"/%s",temp)!=1) {
          string a, b;
          string vvverb;
          vvverb = query_verb();
          if(vvverb == "mv" || vvverb == "cp" || vvverb == "ed" ||vvverb=="rm")
       if(level < 1000)
       log_file("ED_OTHER",name+" ["+vvverb+"] "+str+" "+ctime(time())+"\n");
     }
    if(!ok_edit) ok_edit="none#";
    if ((who == ok_edit || sscanf(ok_edit, "%s"+who+"%s", tmpa,tmpb)==2 || 
        who == name || level >= ED_OTHERS) && c==this_object()) {
      if(sscanf(ok_edit,"%s"+who+"/%s#%s",tmpa,tmpb,tmpc)==3){ 
        if(sscanf(str,"%s"+tmpb+"%s",tmpa,tmpc)==2)
          return "players/" + who + "/" + file;
        else 
          return 0;
        }
        if(who!="tar_castles" || who!="inactive_saved" || who!="pre_reno" || 
           level >= ELDER)
	  return "players/" + who + "/" + file;
    }
    if (sscanf(file_name(c),"players/"+who+"/%s",temp)==1)
      return "players/" + who + "/" + file;
    return 0;
  }
  if(sscanf(str,"/players/%s.o",file) == 1)
    if(level >= ELDER || (prev_caller &&
       file_name(prev_caller)=="obj/simul_efun"))
      return "players/"+file+".o";
  if (sscanf(str,"/open/%s", file) == 1) {
    string vverb;
    vverb = query_verb();
    if(vverb == "mv" || vverb == "cp" || vverb == "ed" || vverb == "rm")
      log_file("ED_OTHER",name+" ["+vverb+"] "+str+" "+ctime(time())+"\n");
    return "open/" + file;
  }
  if (sscanf(str, "/log/WR/%s_%s", who,file) == 2)
    if (who == name || level >= ED_LOG)
      return "log/WR/" + who + "_" + file;
  if(sscanf(str, "/log/user/%s", who) &&
      ((prev_caller && basename(prev_caller)[0..8] == "/obj/user") ||
      (level >= ED_LOG)))
    return "log/user/"+who;
  if(sscanf(str, "/doc/%s",file) && level >= ELDER) return "doc/"+file;
  if(sscanf(str, "/pa/log/%s", who) == 1) {
        if((prev_caller && (basename(prev_caller)=="/obj/soul" || basename(prev_caller)=="/closed/wiz_soul")) || level >= SENIOR)
    {
    return "pa/log/"+who;
    }
  }
  if(sscanf(str, "/pa/admin/%s", who) == 1) {
    if(level < SENIOR) return 0;
  }
  if(sscanf(str, "/pa/%s", who) == 1) {
    if(who=="log/Snoop.txt")
      if(query_verb()=="snoop") return "pa/"+who;
    else if(level >= SENIOR || "/pa/admin/pa-daemon"->query_name(name))
   {
      return "pa/"+who;
  }
  }
  if (sscanf(str, "/log/SQLDATA/%s.%s", who,file) == 2)
    if (who == name || level >= ED_LOG)
      return "log/SQLDATA/" + who + "." + file;
  if(sscanf(str, "/ideas/sugg_old/%s", file) == 1)
    return "ideas/sugg_old/" + file;
  if(sscanf(str, "/ideas/%s", file) == 1)
    return "ideas/" + file;
  if (c!=this_object())
    return 0;
  if (sscanf(str, "/log/%s.%s", who,file) == 2)
    if (who == name || (capitalize(who) != who &&
	level >= ED_OTHERS) || level >= ED_LOG)
      return "log/" + who + "." + file;

  if (sscanf(str, "/log/%s", who) == 1) {
    if (who == name ||  (capitalize(who) != who &&
        level >= ED_OTHERS) || level >= ED_LOG)
      return "log/" + who;
    if(who == ok_edit || sscanf(ok_edit, "%s"+who+"#%s", tmpa,tmpb)==2 ||
       sscanf(ok_edit, who+"%s", tmpa)) 
     return "log/" + who;
  }

  if ((sscanf(str, "/obj/%s", file) == 1) && level >= EDIT_STANDARD)
    return "obj/" + file;
  if((sscanf(str, "/room/housing/%s",file) == 1) && prev_caller &&
      (file_name(prev_caller)[0..11]=="room/housing"))
    return "room/housing/"+file;
  if ((sscanf(str, "/room/%s", file) == 1) && level >= EDIT_STANDARD)
    return "room/" + file;
    if ((sscanf(str, "/post_dir/%s", file) == 1) && level >= ELDER)
        return "post_dir/" + file;
    if ((sscanf(str, "/closed/%s", file) == 1) && level >= ELDER)
	return "closed/" + file;    
    if ((sscanf(str, "/daemons/%s", file) == 1) && level >= ELDER)
      return "daemons/"+file;
    /* Added next 4 if's - Rumplemintz - 08/12/2011 */
    if ((sscanf(str, "/kernel/%s", file) == 1) && level >= ELDER)
      return "kernel/"+file;
    if ((sscanf(str, "/global/%s", file) == 1) && level >= ELDER)
      return "global/"+file;
    if ((sscanf(str, "/basic/%s", file) == 1) && level >= ELDER)
      return "basic/"+file;
    if ((sscanf(str, "/complex/%s", file) == 1) && level >= ELDER)
      return "complex/"+file;
    if ((sscanf(str, "/banish/%s", file) == 1) && level >= ELDER)
       return "banish/" + file;
    if ((sscanf(str, "/secure/%s", file) == 1) && level >= ELDER)
      return "secure/" + file;
    if ((sscanf(str, "/sys/%s", file) == 1) && level >= ELDER)
      return "sys/"+file;
    if ((sscanf(str, "/bin/%s", file) == 1) && level >= ELDER)
        return "bin/" + file;
    if(sscanf(str,"/pfiles/%s",file))
      if(level >= ELDER || (prev_caller &&
#ifdef __LDMUD__ /* Rumplemintz */
                            (file_name(prev_caller) == "obj/simul_efun_new" ||
                             file_name(prev_caller) == "obj/simul_efun")))
#else
                            file_name(prev_caller) == "obj/simul_efun"))
#endif
         return "pfiles/" + file;
    if ((sscanf(str, "/%s", file) == 1) && level >= ELDER)
      if (file && (sscanf(file, "%s/%s", str, str)!=2) && level >= ELDER)
	return file;
    if (level >= ALL_POWER) {
	sscanf(str,"/%s",file);
	return file;
    }
    return 0;
}

nomask string valid_read(string arg) {
    string str, who,tmpa,tmpb, file, temp,tmp;
    object c, prev_caller;
    int tempb;

    /*
     * Because argument lists are passed unevaluated, by the time caller()
     * gets executed, the real caller() will be valid_read, not whoever

     * actually called us.  Thus, we get caller() before calling valid_write.
     */
    c = caller();
    if (c!=this_object() && !in_editor(this_object()))
    if (extract(file_name(c),0,3)=="room" ||
        extract(file_name(c),0,2)=="obj" ||
        extract(file_name(c),0,2)=="bin" ||
        extract(file_name(c),0,7)=="post_dir" ||
      extract(file_name(c),0,5)=="closed")
	c=this_object();
if (level < ELDER)
if (sscanf(arg, "%ssecure%s", temp, tmp) == 2) return 0;


#ifndef __LDMUD__  /* Rumplemintz */
    if(sscanf(arg, "%sacces%s", temp,tmp) == 2) return arg[1..-1];
#else
    if(sscanf(arg, "%sacces%s", temp,tmp) == 2) return arg[1..<1];
#endif
    file = valid_write(arg,c);
    if (file)
	return file;

    str = arg;
    if (str == "~" || str == "~/") 
	str = "/players/" + name;
    else if (sscanf(str,"~/%s",temp) == 1)
	str = "/players/" + name + "/" + temp;
    else if (sscanf(str,"~%s",temp) == 1)
	str = "/players/" + temp;
    else if (str[0] != '/')
	str = pwd + str;
    if (sscanf(str, "//%s", temp)) return 0;
    if (sscanf(str, "%s//%s", temp, temp)) return 0;
    if (sscanf(str, "/.%s",  temp)) return 0;
    if (sscanf(str, "%s/.%s", temp) > 1) return 0;
    if (sscanf(str, "%star_castles%s", temp) > 1) return 0;
    if(sscanf(str, "/players/%s/PLAN", who) == 1) return "players/" + who + "/PLAN";
    if (sscanf(str, "/players/%s/closed/%s", who, file) == 2) {
  if (who == name || level >= 100)
    {
       return "players/"+who+"/closed/"+file;
          }
  return 0;
  }
    if (sscanf(str, "/players/inactive_saved/%s.o", who) == 1) {
  if (((who == name || level >= SENIOR) && c==this_object()) || (prev_caller && (prev_caller == find_object("/obj/simul_efun"))))
	    return "players/inactive_saved/" + who + ".o";
	return 0;
    }
   if (sscanf(str, "/players/guilds/%s",who) == 1) {
      if(level >= ITEM_OVER && c==this_object())
         return "players/guilds/" + who;
      if (who[0..4] == "necro"
      ||  who[0..5] == "fallen"
      ||  who[0..5] == "healer")
         if (name == "rumplemintz")
#ifndef __LDMUD__ /* Rumplemintz */
           return str[1..-1];
#else
           return str[1..<1];
#endif
      return 0;
   }
    if (sscanf(str, "/players/%s/%s", who, file) == 2) {
    if(!ok_edit) ok_edit="none#";
	if ((who == ok_edit || sscanf(ok_edit, "%s"+who+"%s", tmpa,tmpb)==2 || who == name || level >= READ_OTHERS) && c==this_object())
    {
	    return "players/" + who + "/" + file;
    }
	return 0;
    }
    if (sscanf(str, "/players/%s.o", who) == 1) {
  if (((who == name || level >= SENIOR) && c==this_object()) || (prev_caller && (prev_caller == find_object("/obj/simul_efun"))))
	    return "players/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/pfiles/%s.o", who) == 1) {
  if (((who == name[0..0]+"/"+name || level >= SENIOR) && c==this_object()) || (prev_caller && (prev_caller == find_object("/obj/simul_efun"))))
	    return "pfiles/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/post_dir/%s"+".o", who) == 1 || sscanf(str, "post_dir/%s"+".o", who) == 1) {
	if ((who == name || level >= ELDER) && c==this_object())
	    return "/post_dir"+"/" + who + ".o";
	return 0;
    }
    if (sscanf(str, "/pa/%s", file) == 1) {
        if(str=="/pa/admin/pa-list.txt") return "pa/admin/pa-list.txt";
        if (level >= SENIOR || "/pa/admin/pa-daemon"->query_name(name)) return "pa/"+file;
        return 0;
      }
    if (sscanf(str, "/closed/%s", file) == 1) {
	if (level >= ELDER && c==this_object())
	    return "/closed/"+file;
	return 0;
    }
    if (sscanf(str, "/%s", file) == 1)
	return file;

    write("Bad file name.\n");
    return 0;		/* Should not happen */
}

