#define PATH this_player() -> query_path()



object *PROCESS_ARG_OB(mixed *ob_list, object *ob);





string plural_to_single(string plural) {

  string word, end;

  int len;

            

if(!plural) return "";

  len = strlen(plural); 

  /* sscanf() sucks...it wouldn't work *sob*  

  * it has problems with things like "%ss", - Zil */

if(len > 3) { 

  end = extract(plural,(len - 3),(len - 1));

  word = extract(plural,0,(len - 4));

  if(end == "ies") return word + "y";  /* babies -> baby */

   if(end == "ses") {

    if(word[strlen(word)-1] == 's')   

     return word + "s";               /* glasses -> glass */

     else 

     return word + "se";              /* fuses -> fuse */

    }

  }

  if(len > 2) {

   end = extract(plural,(len - 2),(len - 1));

   word = extract(plural,0,(len - 1));

   if(end == "ii") return word + "us";  /* you never know ;) */ 

    if(plural[len-1] == 's')

     return extract(plural,0,(len - 2));

   }

   return plural;

}

        

string make_path(string file) {

  string *path_split, tmp;

  string tmp1, tmp2;

  int i, len;

  string current_path;

  string name;

  name = this_player() -> query_name();

  name = lower_case(name);

  current_path = PATH;

  

if(!file || file == "") return "/"+current_path;

 if(file == "~") return WIZARD_DIR +""+ name;

 if(sscanf(file,"~/%s",file)) {

   file = WIZARD_DIR +""+ file;

}

 if(sscanf(file,"~%s",file)) {

   file = WIZARD_DIR +""+ name +"/"+ file;

}

  if(file[0] != '/') {

    if(current_path == "") {

      file = "/"+file;

    }

  else {

    file = "/" + current_path + "/" + file;

  }

}

  while(sscanf(file, "%s//%s", tmp1, tmp2)) file = tmp1 + "/" + tmp2;

  return file;

}

        

nosave varargs object *FIND_OBJECT(string str, object who){

  string tmp1, tmp2;

  int i, j;

  object *ob;

  string current_path;

            

if(!str){ 

  write("No Argument to FIND_OBJECT!\n");

    return ({});

}

  ob = ({});

  if(str == "users") {

    ob = allocate(sizeof(users()));

    ob = users();

    if(who) {    /* eg. users in room */

     ob = filter_array(ob,"present_filter",this_object(),who);

    } 

}  

  if(!sizeof(ob)) ob = allocate(1);

  if(!who) who = this_player();

            

  if(str == "me") ob[0] = this_player();

   else if(str == "env") ob[0] = environment(who);

    else if(str == "room") ob[0] = environment(who);

     else if(str == "all") {

     ob = allocate(sizeof(all_inventory(who)));

     ob = all_inventory(who);

     if(!sizeof(ob)) ob = allocate(1);

    }

    else if(sscanf(str, "all %s", tmp1)) {      /* eg. all swords */

     ob = filter_array(all_inventory(who), "plural_filter", this_object(), tmp1);

     if(!sizeof(ob)) ob = allocate(1);

    }

    else if(sscanf(str, "%d %s", j, tmp1)) {    /* eg. 3 swords */

     ob = filter_array(all_inventory(who), "plural_filter", this_object(), tmp1);

     if(j <= sizeof(ob)) {

     ob = ob[0..(j-1)];

    }

    if(!sizeof(ob)) ob = allocate(1);

   }

   else if(sscanf(str,"who%d",i) == 1) {

   if(i < 1 || i > sizeof(users()) - 2) {

   write("Who "+i+" is out of who number bounds.\n");

    return ({});

   } 

   ob[0] = users()[i-1];

  }

  if(!ob[0]) ob[0] = present(str, who);

  if(!ob[0] && environment(who)) ob[0] = present(str, environment(who));

  if(!ob[0]) ob[0] = find_object(str);

  if(!ob[0]) ob[0] = find_living(str);

  if(!ob[0]) {

   ob = find_all_living(plural_to_single(str));

   if(!sizeof(ob)) ob = allocate(1);

  }

  if(!ob[0]) ob[0] = find_living("ghost of " + str);

   if(!ob[0]) {

    if(!sscanf(str,"%s %s", tmp1, tmp2)) {

     str = make_path(str);

     sscanf(str,"/%s", str);

     sscanf(str,"%s.lpc",str);

     if(file_size("/"+ str +".lpc") > 0) {

      if(catch(call_other(str,"???"))) {

       write("Error in loading: "+str+"\n");

       return ({});

     }

     ob[0] = find_object(str);

    }

  }

}

  if(!ob[0]) return ({});

  return ob;

}

        



nosave object *PROCESS_ARG(string arg){

  string tmp1, tmp2;

  mixed *ob_list; 

  string *contents, list, content_list;

  mixed *ob;

  int i;

            

if(!arg) return ({});

  ob_list = explode(arg," in ");

  list = implode(ob_list," of ");

  ob_list = explode(list," of ");

  if(!ob_list) ob_list = ({ arg, });

  for(i = 0; i < sizeof(ob_list); i++) {

  content_list = ob_list[i];

  while(sscanf(content_list,"%s, %s", tmp1, tmp2)) {

  content_list = tmp1 + "," + tmp2;

}

if(content_list[strlen(content_list)-1] != ',') content_list += ",";

  contents = explode(content_list,",");

  ob_list[i] = contents;

}

  ob = PROCESS_ARG_OB(ob_list,({ 0,})); 

  if(!sizeof(ob)) {

    write("Error: Cannot find '"+arg+"'\n");

}

  return ob;

}

        

object *PROCESS_ARG_OB(mixed *ob_list, object *ob) {

  int i, size, j;

  object *new_ob, *obj;

  string *list;

  

  new_ob = ({});

  list = ob_list[sizeof(ob_list)-1];

  for(i = (size=sizeof(ob)) - 1; i >= 0; i--) {

    for(j = 0; j < sizeof(list); j++) {

      obj = FIND_OBJECT(list[j], ob[i]);

      if(sizeof(obj)) {

        new_ob = new_ob + obj;

      }

    }

  }

  if(!sizeof(new_ob)) return ({});

  if(sizeof(ob_list) > 2) {  

    return PROCESS_ARG_OB(ob_list[0..(sizeof(ob_list)-2)],new_ob);

  } 

    else if(sizeof(ob_list) == 2) {

      return PROCESS_ARG_OB(({ ob_list[0], }), new_ob);

  }

  return new_ob;

}

        

string string_results(mixed arg) {

  string str;

  string tmp;

  string result;

  int i;

  mixed *indices;

            

  result = "";

  if(pointerp(arg)) {

    result += "({";

    for(i = 0; i < sizeof(arg); i++) {

    if(!i) result += " ";

    result += string_results(arg[i]) +", ";

  }

    result += "})";

            }



    else if(mapp(arg)) {

      str = "([\n";

      indices = keys(arg);

      for(i = 0; i < sizeof(indices); i++) {

        str += "  "+ string_results(indices[i]) +": "+

        string_results(arg[indices[i]]) +",\n";

      }

      result = str +"])";

    }

   else if(objectp(arg)) {

     result = file_name(arg);

   }

   else if(stringp(arg)) {

     str = arg;

     result = "";

     while(sscanf(str,"%s\n%s", tmp, str)) {

       if(arg != tmp +"\n"+ str) result += "\n";

       result += tmp +"\\n";

     }

     result = "\""+ result + str +"\"";

   }

   else if(intp(arg)) {

     result = arg +"";

   }

   return result;

}

        

        

void show_results(mixed arg) {

  write(((pointerp(arg)) ? "[ARRAY]\n"

        :(objectp(arg))  ? "[OBJECT]\n"

        :(intp(arg))     ? "[INT]\n"

        :(stringp(arg))  ? "[STRING]\n"

        :(floatp(arg))   ? "[FLOAT]\n"

        :(mapp(arg))  ? "[MAPPING]\n"

        : "[UNKNOWN TYPE]\n"));

            write(string_results(arg) +"\n");

}



