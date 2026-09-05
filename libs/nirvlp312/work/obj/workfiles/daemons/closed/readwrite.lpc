#include <security.h>
  
nomask string check_write(string arg, object c, object this_ob, int inact, int ghs, object caller) {
  string str, who,tmpa,tmpb,tmpc, file, temp;
  string tpa,tpb;
  int tempb;
  object prev_caller, myself;
  string name, pwd, ok_edit;
  int level;
				     
  if (!arg) return 0;
  name = (string)this_ob->query_real_name();
  level = (int)this_ob->query_level();
  prev_caller = caller;
  myself = this_ob;
  pwd = (string)this_ob->query_pwd();
  
  if (caller !=myself || !c) c=caller;
  if (c!=this_ob && !in_editor(this_ob))

    if (extract(file_name(c),0,3)=="room" ||
        extract(file_name(c),0,2)=="obj" ||
        extract(file_name(c),0,2)=="bin" ||
        extract(file_name(c),0,5)=="closed")
      c=this_ob;

  if (in_editor(this_ob)) c=this_ob;
  if(inact) {
    tell_object(this_ob, "inact");
    if(ghs != inact) {
      return 0;
    }
    if (sscanf(arg, "/pfiles/%s.o", who) == 1) {
      if(who == extract(name,0,0)+"/"+name) 
        return "pfiles/"+extract(name,0,0)+"/"+name+".o";
      return 0;
    }
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
      return 0; } else {
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
    ok_edit = (string)this_ob->query_ok_edit();
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
    if(level >= ELDER || (prev_caller && file_name(prev_caller)=="obj/simul_efun"))
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
  if (c!=this_ob)
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
  if((sscanf(str, "/room/housing/%s",file) == 1) && prev_caller && (file_name(prev_caller)[0..11]=="room/housing"))
    return "room/housing/"+file;
  if ((sscanf(str, "/room/%s", file) == 1) && level >= EDIT_STANDARD)
    return "room/" + file;
    if ((sscanf(str, "/post_dir/%s", file) == 1) && level >= ELDER)
        return "post_dir/" + file;
    if ((sscanf(str, "/closed/%s", file) == 1) && level >= ELDER)
	return "closed/" + file;    
    if ((sscanf(str, "/banish/%s", file) == 1) && level >= ELDER)
       return "banish/" + file;
    if ((sscanf(str, "/bin/%s", file) == 1) && level >= ELDER)
        return "bin/" + file;
    if(sscanf(str,"/pfiles/%s",file))
      if(level >= ELDER || (prev_caller && file_name(prev_caller) == "obj/simul_efun"))
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
