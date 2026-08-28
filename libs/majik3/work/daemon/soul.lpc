// file name   : /daemon/soul.c
// description : soul daemon
// coder       : harum

#include <soul.h>
string *soul_cache, *adverb_cache, *body_part_cache, soul_list, adverb_list;
int res =0;

create () {
   if (!soul_cache)
     soul_cache = explode(read_file(SOULS), "\n");
   if (!adverb_cache)
     adverb_cache = explode(read_file(ADVERBS), "\n");
   if (!body_part_cache)
     body_part_cache = explode(read_file(BODY_PARTS), "\n");
   if (!soul_list)
     soul_list = get_souls();
   if (!adverb_list)
     adverb_list = get_adverbs();

}

int is_soul(string soul){
   string soul_name;
   int i;
   for (i=0; i<sizeof(soul_cache); i++){
      soul_name = explode(soul_cache[i], "::")[0];
      if (soul_name == soul) return 1;
   }
   return 0;
}

string get_souls(){
   string soul_name, ret = "", *souls = ({ });
   int i;
   for (i=0; i<sizeof(soul_cache); i++){
      soul_name = explode(soul_cache[i], "::")[0];
      souls += ({ soul_name });
   }
   if (!sizeof(souls)) return "";
   else {
      souls = sort_array(souls, "sort_souls", this_object());
      ret += sprintf("%s\n\n", "A complete list of all available feeling commands:");
      ret += sprintf("%#-78s\n", implode(souls, "\n")); 
      ret += "\nTotal number of feelings: "+sizeof(soul_cache)+"\n";
   }
   return ret;
}

string get_adverbs(){
   string ret = "", *adverbs = ({ });
   int i;
   for (i=0; i<sizeof(adverb_cache); i++){
      adverbs += ({ adverb_cache[i] }); 
   }
   if (!sizeof(adverbs)) return "";
   else {
      adverbs = sort_array(adverbs, "sort_souls", this_object());
      ret += sprintf("%s\n\n", "A complete list of all available adverbs:");
      ret += sprintf("%#-78s\n", implode(adverbs, "\n"));
      ret += "\nTotal number of adverbs: "+sizeof(adverb_cache)+"\n";
   }
   return ret;
}

string query_souls () {
   return soul_list;
}

string query_adverbs () {
   return adverb_list;
}


int sort_souls(string str, string str2){
   return strcmp(str, str2);
}

string find_adverb(string check) {
   int i, j, Count = 0;
   int size;
   
   if (check == "") return 0;
   for (i=0; i<sizeof(adverb_cache); i++){
      size = strlen(check);
      if (strlen(adverb_cache[i]) < size)
        size = strlen(adverb_cache[i]);
      for (j=0; j<size; j++){
         if (check[j..j] == adverb_cache[i][j..j])
           Count++;
         else break;
      }
      if (Count == strlen(check))
        return adverb_cache[i];
      Count = 0;
   }
   return 0;
}

string find_body_part(string check) {
   int i;   
   if (check == "") 
     return 0;
   for (i=0; i<sizeof(body_part_cache); i++) {
      if (check == body_part_cache[i])
        return check;
   }
   return 0;
}   

string get_soul_string(string soul){
   
   string soul_name;
   int i;
   for (i=0; i<sizeof(soul_cache); i++)
     {
        soul_name = explode(soul_cache[i], "::")[0];
        if (soul_name == soul)
          return explode(soul_cache[i], "::")[1];
     }
   return "";
}




string get_me_string(string me) {
   string str1, str2 ,str3;
   while (sscanf(me, "%s{%s}%s", str1, str2, str3) == 3)
     me = str1 + str2 + str3;
   return me;
}

string get_target_string(string target) {
   string str1, str2, str3;
   while (sscanf(target, "%s{%s}%s", str1, str2, str3) == 3) {
      if (str2 == "hum")
        target = str1 + "hums" + str3;
      else
        target = str1 + pluralize(str2) + str3; 
   }
   return target;
}

int test_living (string str) {
   if (!present(str))
       return 0;
   if (!living(present(str)))
     return 0;
   return 1;
}
       




execute_soul(string soul, string who, string where, string how) {
   string text, def, who_argument, extra; 
   string me, target, others;
   object ob;
   int i;

   res = 0;
   
   
   text = get_soul_string(soul);
   
   extra = "";
   def = "";
   
   sscanf(text, "%*s<%s:%s>%*s", extra, def);
   
   
   if (test_living(who) || who == "") {
      if (where != "") {
         if (def != "")
           text = replace_string(text, def, "");     
         text = replace_string(text, "WHERE", where);
            
      }
      
      else {
         where = def;
            if (extra != "")
           text = replace_string(text, extra, "");
      }
   }
   
   else {
      if (def != "")
        text = replace_string(text, def, "");
      if (extra != "")
        text = replace_string(text, extra, "");
   }
   
   extra = "";
   def = "";
   
   sscanf(text, "%*s(%s|%s|%s)%*s" , extra, def, who_argument);
   if (who != "") {
      if (def != "" && def != "$")
        text = replace_string(text, def, "");
   
   }
   
   else  {
      
      if (def == "$") { 
         notify_fail(capitalize(soul)+ " who?\n");
         res = 0;
         return; 
      }
      else if (def == "THIS$")
        who = THIS->query_name();
      else text = replace_string(text, extra, "");
   
   }
   
   
  
   def = "";
   extra ="";
   sscanf(text, "%*s[%s/%s]%*s", extra, def);
   if (how != "" && how) {
      text = replace_string(text, def, "");
      text = replace_string(text, "HOW", how);
   }
   else {
      text = replace_string(text, extra, "");
      if (def !="")
        text = replace_string(text, def, def);
      
   }
      
   
  
   
   if (who_argument)
     text = replace_string(text, who_argument, "");
   text = replace_string(text, "(", "");
   text = replace_string(text, ")", "");
   text = replace_string(text, "<", "");
   text = replace_string(text, ">", "");
   text = replace_string(text, "[", "");
   text = replace_string(text, "]", "");
   text = replace_string(text, "|", "");
   text = replace_string(text, "/", "");
   text = replace_string(text, ":", "");
   text = replace_string(text, "THIS$", "");
   text = replace_string(text, "$", "");
   
   if (who !="") {
      	ob = present(who);
      
	if (present(who, THIS))
		{
		if (ob->query_wielded())
			text = replace_string(text,"WHO","WHO #N {are} wielding");
		else if (ob->query_weared())   
			text = replace_string(text,"WHO","WHO #N {are} wearing");

      		else text = replace_string(text,"WHO","WHO #N {are} carrying");
		}

//      who = present(who)->query_name();
   }

   me = get_me_string(text);
   target = get_target_string(text);
   others = target;
   
   
   
   if (who != "") {
//      ob = present(who);
      
      if (ob == THIS) { 
         
         if ((who_argument == "s$" && where != "") || who_argument == "S$")
           {
              me = replace_string(me, "WHO", "your");
              target = replace_string(target, "WHO", THIS->query_possessive());
              others = replace_string(others, "WHO", THIS->query_possessive());
           }
         else {
            me = replace_string(me, "WHO", "yourself");
            target = replace_string(target, "WHO", THIS->query_objective() + "self");
            others = replace_string(others, "WHO", THIS->query_objective() + "self");
         }
      }
      else if (living(ob) && ((who_argument == "s$" && where != "") || who_argument == "S$"))
        {
              me = replace_string(me, "WHO", ob->query_maybe_cap_name(THIS) +"'s");
              others = replace_string(others, "WHO", "$v's");
           target = replace_string(target, "WHO", "your");
        }
      else {
            me = replace_string(me, "WHO", ob->query_maybe_cap_name(THIS));
            others = replace_string(others, "WHO", "$v"); 
         target = replace_string(target, "WHO", "you");
   }
   }

   me = replace_string(me, "#N", "you");
   target = replace_string(target, "#N", THIS->query_pronoun());
   others = replace_string(others, "#N", THIS->query_pronoun());
   
   me = replace_string(me, "#P", "your");
   target = replace_string(target, "#P", THIS->query_possessive());
   others = replace_string(others, "#P", THIS->query_possessive());
   
   me = replace_string(me, "#O", "you");
   target = replace_string(target, "#O", THIS->query_objective());
   others = replace_string(others, "#O", THIS->query_objective());
   
   me = me + "\n";
   target = target +"\n";
   


	
		
	message("feeling", "You "+ me, THIS);
	
	if (ob && ob != THIS) 
		
		message("feeling", THIS->query_maybe_cap_name(ob) +" "+ target,ob);
		
	act(THIS,"$n "+ others, ob, ob);
		
	
	
  
   

   res = 1;
   return 1;
}

parse_soul (string arg) {
   int i, j, *integer_list;
   string *args;
   
   
   if (!arg || arg == "")
     return ;
   arg = lower_case(arg);
   args = explode(arg, " ");
   

   integer_list = ({ 1,2,3,4,5,6,7,8,9,10 }); 
  
if (sizeof(args)>2){
  for (i=2 ; i< sizeof(args) ; i++) 
   {   
	
        if (member_array(to_int(args[i]), integer_list) != -1)
        	{ 
		args[i-1] = args[i-1] + " " + args[i];
		
		
		for (j = i ; j < sizeof(args)-1 ; j ++) 
		   {
			args[i] = args [j+1];
		   }
		args[sizeof(args)-1] = ""; 
		args -= ({ args[sizeof(args)-1] });
		break;  
		} 
   }
}



 if (sizeof(args) == 1)
     execute_soul(args[0],"","","");
   
   else if (sizeof(args) == 2) {
      
      if (present(args[1]))
        execute_soul(args[0], args[1], "", "");
      else if (find_body_part(args[1]))
        execute_soul(args[0], "", args[1], "");
      else if (find_adverb(args[1]))
        execute_soul(args[0], "", "", find_adverb(args[1]));
      else {
         notify_fail(capitalize(args[0]) +" who?\n");
         
         return 0;
      }
      }
   else if (sizeof(args) == 3) {
      if (present(args[1])) {
         if (find_body_part(args[2]))
           execute_soul(args[0], args[1] , args[2], "");
         else if (find_adverb(args[2]))
           execute_soul(args[0], args[1], "", find_adverb(args[2]));
         else {
            notify_fail(capitalize(args[0]) +" "+ args[1] +" who?\n");
            return 0;
         }
      }
      else if (find_adverb(args[1]) && present(args[2])) 
        execute_soul(args[0], args[2], "", find_adverb(args[1]));
      else if (find_body_part(args[1]) && find_adverb(args[2]))
        execute_soul(args[0], "", args[1], find_adverb(args[2]));
      else {
         notify_fail(capitalize(args[0]) +" who?\n");
         return 0;
      }
   }
   else if (sizeof(args) == 4){
      if (present(args[1])) {
         if (find_body_part(args[2]) && find_adverb(args[3]))
           execute_soul(args[0], args[1], args[2], find_adverb(args[3]));
         else if (find_adverb(args[2]) && find_body_part(args[3]))
           execute_soul(args[0], args[1], args[3], find_adverb(args[2]));
         else {
            notify_fail(capitalize(args[0]) + " who?\n");
            return 0;
         }
      }
      else {
         notify_fail(capitalize(args[0]) + " who?\n");
         return 0;
      }
      
      
   }
   else {
         notify_fail(capitalize(args[0]) + " who?\n");
         return 0;  
	}

    if (!res) 
     return 0;
   
   return 1;
}
