#define EPITAPH "/obj/user/tomb/epitaph"

inherit "/obj/treasure";

string epitaph;
string PlayerName;
string tombstone;
string time_of_death;

status get() { return 0; }

void reset(status arg){
  set_no_clean(1);
  ::reset(arg);
  if(arg) return;
  set_id("tombstone");
  set_alias("gravestone");
}

status id(string str){
  return ::id(str) || str=="stone";
}

void init() {
  ::init();
  add_action("cmd_read", "read");
}

void setPlayerName(string str)
{

  time_of_death=ctime();
  PlayerName=str;
}

void long(string str){

  if(!epitaph)
    epitaph=(string)EPITAPH->query_epitaph();

  if(!tombstone)
  tombstone="\n\
Here lies: "+PlayerName+"\n\
Died:      "+time_of_death+"\n\
\""+epitaph+"\"\n";

  write(tombstone+"\n");
}

int cmd_read(string str){
  if(id(str)){
    write(long(str));
    return 1;
  }
}

string short() {
  if(!PlayerName) setPlayerName("Nobody");
  return "A tombstone ["+PlayerName+"]";
}

query_save_flag() { return 1; } /* Not savable */
