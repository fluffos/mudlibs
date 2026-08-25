mixed list;

#define CUT if (sizeof(list)>10)\
               list=list[0..9]

void create() {
  if (file_size("/save/tt_save.o")<0)
    list=({});
  else
    restore_object("/save/tt_save");
  seteuid("Root");
}

void update_list(mixed info) {
  int i,honk;
  object ob;
  string me;

  if (this_player()->query_app_creator())
    return;
  if (this_player()->query_property_exists("guest"))
    return;

  for (i=0;i<sizeof(list);i++)
    if (info[0]==list[i][0])
      list=delete(list,i,1);

  for (i=0;i<sizeof(list);i++)
    if (info[1]>list[i][1])
      break;



  list=insert(list,info,i);
  CUT;
  save_object("/save/tt_save");
}

string query_list() {
  int i;
  string ret;

  ret="";
  for (i=0;i<sizeof(list);i++) {
    ret+= (i+1) + ") " + list[i][0];
    if (list[i][2])
      ret+=", " + list[i][2];
    ret+="\n";
  }
  return ret;
}
