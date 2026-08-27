// emoted.c
// Daemon designed to handle emotes in every way.
// Lol   10/17/95
// Tim   11/6/95  fixed so this_player() is excluded from room message

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

private string *emote_verbs, *emote_statement;

// The proceding routine will load the verbs and their generic
//  outputs.

void create() {
  string *temp = explode(read_file("/obj/daemon/emote.list"), "\n");
  int i;
  emote_verbs = allocate(sizeof(temp)+1);
  emote_statement = allocate(sizeof(temp)+1);
  for(i=0; i<sizeof(temp); i++) {
    sscanf(temp[i], "%s:%s", emote_verbs[i+1], emote_statement[i+1]);
  }
}

int emote_parse(string str) {
  string verb, this_emote, room_emote, other_tmp, tmp, me, this_tmp;
  object ob, *exclude_ob;
  int other, k;
  string *word=explode(str," ");
  string *exclude_list, *other_emote;
  int i=sizeof(word);
  int j=sizeof(word);
  me=this_player()->query_name();
  exclude_ob = ({});
  exclude_list = ({" "});
  other_emote = ({" "});
  this_emote="You ";
  room_emote=capitalize(this_player()->query_name()) + " ";
  for(i=0; i<j; i++) {
  tmp=word[i];
  other_tmp = word[i];
  if(tmp[<1] == 's') {
    verb="es"; }
    else { verb="s"; }
    if(member_array(tmp, emote_verbs) > 0 && !(i)) {
      if(j==1) {
//  This section looks for a generic emote (i.e. <smile>) //
//  and returns the emote.
    this_emote += word[i] + " " + emote_statement[member_array(word[i],emote_verbs )];
    room_emote += word[i] + verb + " " + emote_statement[member_array(word[i],emote_verbs)];
      } else {
        this_emote += word[i];
        room_emote += word[i]+verb;
      }

    } else {
    if(!i) {
        this_emote += word[i];
        room_emote += word[i]+verb;
      }
      else {
//  Here's where it gets a little tricky.  This routine will attempt
//  to create a "smart" emote mode (changing the output) to the player
//  and the room.  Don't worry about gender, we'll get to that later.
      tmp=word[i];
      this_tmp=word[i];
      if(tmp=="my") { tmp="his"; this_tmp="your"; }
       if(word[i]=="myself") {
         tmp="himself";
         this_tmp="yourself";
       }
//  This routine will determine if an emote was designated for 
//  another living() or is word[i] is in the room
  if(ob=present(word[i],environment(this_player())) ) {
    if(living(ob)) {
      this_tmp = capitalize(this_tmp);
      tmp = capitalize(tmp);
    }
    if(interactive(ob)) {
      other_tmp = "";
    if(member_array(ob->query_name(), exclude_list) == -1) {
      other +=1;
  exclude_list += ({ob->query_name()});
    exclude_ob += ({ob});
      other_emote = allocate(other+1);
      other_emote[other] = room_emote + "you";
    } else {
    other_emote[member_array(ob->query_name(), exclude_list)] = "you";
    }
  }
    }
      this_emote +=this_tmp;
      room_emote +=tmp;
      }
    }
  if(i<j-1) {
       this_emote += " ";
       room_emote += " ";
      }
      if(other) {
        for(k=1; k<=other; k++) {
        other_emote[k] += other_tmp;
        if(i < j-1) {
          other_emote[k] += " ";
        }
        }
     }
}

  this_emote = replace_string(this_emote,"\n", "");
  room_emote = replace_string(room_emote, "\n", "");
  tell_object(this_player(),this_emote+".\n");
  tell_room(environment(this_player()), room_emote+".\n",
      exclude_ob + ({ this_player() }));
  for(i=1; i<=other; i++) {
    ob=present(exclude_list[i],environment(this_player()));
    tell_object(ob, other_emote[i]+".\n");
  }
  return 1;
}

int emote_search(string verb, string tmp_emote) {
  int pass;
  if(member_array(verb, emote_verbs) >0) {
    EMOTE_D->emote_parse(tmp_emote);
    pass = 1;
  }
  return pass;
}
