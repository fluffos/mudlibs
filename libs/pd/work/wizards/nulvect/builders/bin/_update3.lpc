#include <std.h>
#include <rooms.h>
#include <security.h>
#include <move.h>

inherit DAEMON;

void do_deep_update(string file);
int do_update(string file, int deep);
int do_update_room(string file, int deep);

int cmd_update3(string str) {
  object ob;
  string file, path;
  string *files;
  int i, deep;


  if(!str) {

    if(!(ob=environment(this_player())))
      return notify_fail("No environment!\n");

    file = file_name(ob);
    message("Nsystem", "Update environment ("+file+"): ", this_player());

    do_update(file,0);
    return 1;
  }

  if (sscanf(str, "-a %s", file) == 1) {
    message("Nsystem", "Updating all files directly/indirectly related to "+file+".",
      this_player());
    deep=1;
  }
  else {
    file=str;
    deep=0;
  }

  if (!file)
    return notify_fail("No file specified.\n");
  
  path = (string)this_player()->get_path();

  if (file == "*") {
    files = get_dir(path+"/*");
    files -= ({".",".."});
    i = sizeof(files);
    while (i--)
      do_update(path+"/"+files[i],0);
  }
  else {
    file=resolv_path(path, file);
    if (deep)
      do_deep_update(file);
    else
      do_update(file,0);
  }

  return 1;  

}

void do_deep_update(string file) {
  int i;
  object ob;
  string *deep;
  
  if (!(ob=find_object(file))) {
    message("system","Couldn't update "+file,this_player());
    return;
  }

  deep=({ file }) + deep_inherit_list(ob);
  i=sizeof(deep);

  while (i--)
    if (do_update(deep[i],1) == 0)
      return;
    
}

int do_update(string file, int deep) {
  string error;
  int master_flag;
  object ob;
  
  ob=find_object(file);

  if (ob) {

    if (ob->is_room())
      return do_update_room(file, deep);
      
    if (ob == master())
      master_flag=1;

    error=catch(ob->remove());
    if (error) {
      message("system", file+": error in remove()", this_player());
      if (deep) return 0;
    }
    
    if (ob) {
      seteuid(getuid(previous_object()));
      destruct(ob);
      if (!master_flag)
        seteuid(UID_SYSTEM);
    }

  }

  if (!find_object(file)) {

    file_size(file);

    message("system", file+": "+
      ((error=catch(call_other(file,"???"))) ? error : "updated and loaded."),
      this_player());

    if (master_flag)
      seteuid(UID_SYSTEM);

    return 1;

  }
  else {
    message("system", file+": couldn't destruct", this_player());
    return 0;
  }
}


int do_update_room(string file, int deep) {
  int env_flag, i, m;
  object *inv;
  object ob;
  
  ob=find_object(file);

  if (ob == environment(this_player()))
    env_flag=1;

  inv=all_inventory(ob);
  for (i=0; i<sizeof(inv); i++)
    if (inv[i]->is_player())
      inv[i]->move(ROOM_VOID);

  seteuid(getuid(previous_object()));
  destruct(ob);
  seteuid(UID_SYSTEM);

  if (env_flag) {

    m=this_player()->move(file);
    for (i=0; i<sizeof(inv); i++)
      if (inv[i])
        inv[i]->move(environment(this_player()));

    if (m != MOVE_OK) {
      message("system", "Error in loading file.", this_player());
      if (deep) return 0;
    }

  }
  
  return 1;
}


