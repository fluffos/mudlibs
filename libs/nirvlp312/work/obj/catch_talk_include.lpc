string talk_match, talk_func, talk_ob_str, talk_type;
string talk_hold_func, talk_hold_type;
object talk_hold_ob;
int catch_nr;
int talk_done;


/*
 * The talk_funcction to call.
 */
set_type(t) {
   start_up_talk();
    talk_hold_type = t;
}

/*
 * The string to talk_match.
 */
set_match(str) {
   start_up_talk();
    if(catch_nr >= sizeof(talk_ob_str)) return; /* by verte */
    talk_ob_str[catch_nr] = talk_hold_ob;
    talk_match[catch_nr] = str;
    talk_func[catch_nr] = talk_hold_func;
    talk_type[catch_nr] = talk_hold_type;
    catch_nr+=1;
}

/*
 * The talk_function to call.
 */
set_function(f) {
    start_up_talk();
    talk_hold_func = f;
}

/*
 * The object to call.
 */
set_object(ob) {	
     start_up_talk();
    talk_hold_ob = ob;
}

test_match(str) {
    string who,str1;
    int i;
    i=0;
    while(i < catch_nr) {
       if(talk_match[i] !="BLANK") {

    if(sscanf(str,"%s " + talk_type[i] + talk_match[i] + " %s\n",who,str1) == 2 ||
       sscanf(str,"%s " + talk_type[i] + talk_match[i] + "\n",who) == 1 ||
       sscanf(str,"%s " + talk_type[i] + talk_match[i] + "%s\n",who,str1) == 2 ||
       sscanf(str,"%s " + talk_type[i] + " " + talk_match[i] + "\n",who) == 1 ||
       sscanf(str,"%s " + talk_type[i] + " " + talk_match[i] + " %s\n",who,str1) == 2)
    {
/* next line by Verte [7.19.01] */
            if(talk_ob_str[i] && talk_func[i])
	    return call_other(talk_ob_str[i], talk_func[i], str);
    } 
    }
    i+=1;
    }
	return 0;
}

remove_match(str) {
    int i;
    while(i < catch_nr) {
    if (str == talk_match) {
        talk_match[i] ="BLANK";
        return 1;
    }
   i+=1;
   }
    return this_object();
}

start_up_talk(){
  if(!talk_done){
     talk_func=allocate(30);
     talk_match=allocate(30);
     talk_type=allocate(30);
     talk_ob_str=allocate(30);
     talk_done=1;
     }
  return 1;
}

list_arrays(){
   int i;
   while(i<catch_nr) {
     write(i+" "+talk_func[i]+" "+talk_match[i]+" "+talk_type[i]+" ");
     write(talk_ob_str[i]); write("\n");
     i+=1;
   }
   return 1;
}
