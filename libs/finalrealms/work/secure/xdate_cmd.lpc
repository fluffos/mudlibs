/* Hamlet, Feb 1996.  -- This gets cloned to do the xdate command.  The
                         Command is so complex so integration can be
                         truly simple.
*/
object querier;
string thedata;
string host;

void res_cb(string address, string resolved, int key);
varargs void dest_me(int i);

int do_xdate(string data, object me, string extrajunk) {
  string *parts;
  int WORD = 0;
  int i;
  int tmp;

  seteuid("Root");
    
  querier = me;
  
  if(strlen(extrajunk)) {  /* they did 'finger <username>', so we can trust */
    res_cb(extrajunk,data,-200);
  }
  else { /* finger <hostname|hostip> -- don't trust it. */
    parts = explode(data,".");
  
    for(i=0;i<sizeof(parts);i++)
      if(!sscanf(parts[i],"%d",tmp))
        WORD = 1;
  
    if(!WORD) /* if resolve fails, we'll trust this */
      thedata = data;
    
    resolve(data,"res_cb");
  }
  
  return 1;
}

void res_cb(string address, string resolved, int key) {
  object xdated;
  string data;

  if(!resolved && !thedata) {
    tell_object(querier,"xdate: That seems to have been a bad address.\n");
    return;
  }

  if(resolved)
    host = "\n["+address+" ("+resolved+")]\n";
  else
    host = "\n["+thedata+"]\n";
    
  if(!xdated = clone_object("/secure/xdated")) {
    tell_object(querier,"Oops... xdated didn't want to clone.\n");
    dest_me();
    return;
  }
  
  if(resolved)
    data = resolved;
  else
    data = thedata;
    
  if(!xdated->do_xdate(data, this_object())) {
    tell_object(querier,"xdate: Error with sockets or something.  "
                   "Check the log.\n");
    dest_me();
  }
  else
    call_out("dest_me",40,1);
}

void receive_xdate_data(int tm, string datestr) {
  if(!querier) {
    dest_me();
    return;
  }
  
  tell_object(querier,host+"They said: "+datestr+"We calculated: "+
              ctime(time() + tm)+"\n");
                   
  dest_me();
}         

varargs void dest_me(int i) {
  if(i && querier)
    tell_object(querier,"** Xdate timed out for "+host[1..strlen(host)-1]);
  if(!i)
    remove_call_out("dest_me");
  
  destruct(this_object());
}
