/*
mchat.c
Master Chat object
Handles dynamic allocation of strings for chat channels.
Original concept by Mythos
rewritten by Feldegast for the soul.
*/

#define ESC ""
#define RED ESC+"[31m"       
#define BLU ESC+"[34m"
#define BOLD ESC+"[1m"          
#define NORM ESC+"[2;37;0m"     
#define TITLE BOLD+"<"+NORM+RED+chan+NORM+BOLD+"> "+NORM

mapping channel;

void reset(int arg) {
  if(arg) return;
  channel=([ ]);
}

query_members(str) {
  string *k,*members;
  members=channel[str];
  k=keys(channel);
  if(member_array(str,k) == -1) 
    return 0;
  return channel[str];
}

chat(chan,str) {
  object *members, dude;
  string msg,temp;  
  int i;

  members=channel[chan];
  if(!members) {
    write("There's nobody on that channel.\n");
  }
  msg=capitalize(this_player()->query_real_name())+" ";

  if(str == "history") return (write(("/obj/user/chistory"->query_history("Chat Channel " + chan)+"\n")), 1);
  if(sscanf(str,":%s",temp)==1) {
    msg += temp; 
  }
  else {
    msg += "chats: " + str;
  }
  msg = TITLE +
        implode(explode(format(msg, 70 - (strlen(chan)+2)), "\n"),
                "\n" + pad("", strlen(chan)+2));
  msg += "\n";
  "/obj/user/chistory"->add_history("Chat Channel " + chan, msg);
  for(i=0; i < sizeof(members); i++)
    if(members[i])
      tell_object(members[i],msg);
    else {
      members-=({ members[i] });
      channel[chan]=members;
      i--;
    }

}

chat_who(str) {
  object *members;
  object dude;
  int i;
  members=channel[str];  
  write(""+
  "name\t\tgender\t\tlevel\t\tstatus\n"+RED+
  "_________________________________________________________\n\n"+NORM);

  for(i=0; i < sizeof(members); i++) {
    dude=members[i];
    if(dude) {
      write(pad(capitalize(dude->query_real_name()),15));
      write("\t"+dude->query_gender()+"\t\t");
      write(dude->query_level()+"\t\t");
      if(dude->query_attack()) 
         write(BLU+"C"+NORM);
      if(dude->is_ghost()) 
         write(BOLD+"D"+NORM);
      if(!dude->query_interactive()) 
         write("dc");
      else if(query_idle(dude) > 100) 
         write("I");
      write("\n");
    }
  }
  write("\n"+RED+
  "_________________________________________________________\n"+
  " Status:<i> idle,<C> combat,<D> dead,<dc> discon   chat:"+str+"\n"+NORM);

}

    
createchat(str) {
  object *chans;
  chans=keys(channel);
  if(member_array(str,chans)!=-1)
    return -1;
  if(strlen(str) > 5)
    return -2;
  channel[str]=({ this_player() });
  return 1;
}

addmem(chan,targ) {
  object *members;
  members=channel[chan];
  if(member_array(targ,members) != -1)
    return 0;
  members+=({ this_player() });
  channel[chan]=members;
  return 1;
}

purge(chan) {
  string *mkeys;
  object *members;
  int i,ind;

  mkeys=keys(channel);
  members=allocate(sizeof(mkeys));
  /* Deconstruct the mapping */
  for(i=0; i < sizeof(mkeys); i++) {
    members[i]=channel[mkeys[i]];
  }
  channel=([ ]);

  ind=member_array(chan,mkeys);
  if(ind==-1) return;

  /* Remove the key */
  mkeys-=({ mkeys[ind] });
  members-=({ members[ind] });


  /* Reconstruct the mapping */
  for(i=0; i < sizeof(mkeys); i++) {
    channel[mkeys[i]]=members[i];
  }

}

removemem(chan,targ) {
  object *members;
  members=channel[chan];
  if(member_array(targ,members) == -1)
    return 0;
  members-=({ targ });
  if(sizeof(members) == 0)
    purge(chan);
  else
    channel[chan]=members;
  return 1;
}

