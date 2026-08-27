/* Hamlet, Feb 1996.  -- This gets cloned to do the xfinger command.  The
                         Command is now more complex so integration can be
                         truly simple (not that it'll ever be integrated).
*/
object querier;
string thedata;
string host;
string user;

void res_cb(string address, string resolved, int key);
varargs void dest_me(int i);

int do_xfinger(string data, object me, string extrajunk) {
  string *parts, *trash;
  int WORD = 0;
  int i;
  int tmp;

  seteuid("Root");
    
  querier = me;
  
  trash = explode(data,"@");
  
  if(sizeof(trash) == 1)
    user = "";
  else if(sizeof(trash) == 2)
    user = trash[0];
  else
    return 0;

  if(strlen(extrajunk)) {  /* they did 'finger <username>', so we can trust */
    res_cb(extrajunk,trash[sizeof(trash)-1],-200);
  }
  else { /* finger <hostname|hostip> -- don't trust it. */
    parts = explode(trash[sizeof(trash)-1],".");
  
    for(i=0;i<sizeof(parts);i++)
      if(!sscanf(parts[i],"%d",tmp))
        WORD = 1;
  
    if(!WORD) /* if resolve fails, we'll trust this */
      thedata = trash[sizeof(trash)-1];
    
    resolve(trash[sizeof(trash)-1],"res_cb");
  }
  
  return 1;
}

void res_cb(string address, string resolved, int key) {
  object xfingerd;
  string data;

  if(!resolved && !thedata) {
    tell_object(querier,"xfinger: That seems to have been a bad address.\n");
    return;
  }

  if(strlen(user) && (user != "/W ")) {
    if(user[0..2] != "/W ")
      host = "\n["+user+"@";
    else
      host = "\n["+user[3..strlen(user)-1]+"@";
  }
  else
    host = "\n[";
    
  if(resolved)
    host += address+" ("+resolved+")]\n";
  else
    host += thedata+"]\n";
    
  if(!xfingerd = clone_object("/secure/xfingerd")) {
    tell_object(querier,"Oops... xfingerd didn't want to clone.\n");
    dest_me();
    return;
  }
  
  if(resolved)
    data = user + "@" + resolved;
  else
    data = user + "@" + thedata;
    
  if(!xfingerd->do_xfinger(data, this_object())) {
    tell_object(querier,"xfinger: Error with sockets or something.  "
                   "Check the log.\n");
    dest_me();
  }
  else
    call_out("dest_me",40,1);
}

void receive_xfinger_data(string response) {
  if(!querier) {
    dest_me();
    return;
  }
  
  tell_object(querier,host+response+"\n");
                   
  dest_me();
}         

varargs void dest_me(int i) {
  if(i && querier)
    tell_object(querier,"** Xfinger timed out for "+host[1..strlen(host)-1]);
  if(!i)
    remove_call_out("dest_me");
  
  destruct(this_object());
}
