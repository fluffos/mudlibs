/*
 * Integrated the board-utility into /bin/shell, Carador, Mar-96
 * The variables are now extern_data in the player and no longer
 * savefiles in Arkon's directory.
 *
 * Board Utility V2.5 by Arkon@Tubmud
 *
 * V2.1 : restore()/save(), check in travel()
 * V2.2 : check in unlist() and add()
 * V2.3 : use the new board server not loading all the boards (Ugh)
 * V2.4 : check if travel destination exists
 * V2.5 : cleaned everything up and added loading of board destinations
 *        when travelling which might not be loaded yet due to reboot
 *        (Chameloid, 3-Jan-97)
 * V2.6 : added destination check for 'board travel next' upon loading
 *        (Chameloid, 7-Feb-97)
 */

#pragma strong_types

#include <kernel.h>
#include <server.h>

// For compatibility
#define SAVEDIR "/players/arkon/save/boardutil/"  

inherit ACCESS;
inherit "basic/create";

string *boards=({});      // sorted boards (topics)
string *org_boards=({});  // copy of original list (board server)
string *removed=({});     // removed topics

int last_check;

int index(string elem,string* str_arr) {
  int i,index;
  index=-1;
  for (i=0;i<sizeof(str_arr);i++)
    if (elem==str_arr[i])
      index=i;
  return index;
}

void restore() {
  object tp;
  string name;
  tp=this_player();
  name=tp->query_real_name ();
  if (last_check=tp->query_extern_data("board_util","last_check"))
    removed=tp->query_extern_data("board_util","removed")||({});
  else  // for compatibility
    unguarded(1,#'restore_object,SAVEDIR+name);
}

void save() {
  object tp;
  tp=this_player();
  tp->set_extern_data("board_util","last_check",last_check);
  tp->set_extern_data("board_util","removed",removed);
  unguarded(1,#'rm,SAVEDIR+this_player()->query_real_name()+".o");
}

int sth_has_changed() {
  int i,flag;
  string *boards_copy;
  boards_copy=SE_BOARDS->query_boards();
  if (sizeof(org_boards)!=sizeof(boards_copy)) // something has changed
    return 1;
  for (i=0;i<sizeof(org_boards);i++)
    if (org_boards[i]!=boards_copy[i])
      flag=1;
  return flag; // If flag==1, a new board has been loaded.
}

void update_board_list() {
  org_boards=SE_BOARDS->query_boards();
  boards=sort_array(org_boards,#'>);
  if (this_player())
    write("Updating board lists...\n");
}

void create() {
  update_board_list();
}

int list(string str) {
  int i,complete,last_write;
  string res;
  restore();
  res="";
  if (str && (sscanf(str,"%s c",str)==1 || sscanf(str,"%s complete",str)==1))
    complete=1;
  if (str=="all" || str=="new") {
    if (sth_has_changed())
      update_board_list();
    for (i=0;i<sizeof(boards);i++) {
      last_write=SE_BOARDS->query_last_write(boards[i]);
      if ((str=="all" || last_write>last_check) && 
          (complete || index(boards[i],removed)<0)) {
        res+=sprintf("%2d: %:-47s - %s\n",i,capitalize(boards[i]),
                     (last_write>last_check?ctime(last_write):"nothing new"));
      }
    }
    res+=("Last reset of check-time was "+ctime(last_check)+".\n");
    this_player()->view_text(res,"board utility");
    this_player()->start_view();
    this_player()->remove_extern_data("board_util","next_board");
    return 1;
  }
  if (str=="removed") {
    int which;
    if (sth_has_changed())
      update_board_list();
    for (i=0;i<sizeof(removed);i++)
      res+=sprintf("%2d: %-57s - %s\n",i,capitalize(removed [i]),
                   ((which=index(removed[i],boards))>=0?"loaded as no."+
                    which:"not loaded"));
    if (!sizeof(removed))
      res+=("There are no removed boards!\n");
    this_player()->view_text(res,"board utility");
    this_player()->start_view();
    return 1;
  }
  notify_fail("Board list what?\n");
  return 0;
}

int travel(string str) {
  int no;
  string dest;
  int next_board;
  restore();
  next_board=this_player()->query_extern_data("board_util","next_board");
  if (str && sscanf(str,"%d",no)==1) {
    if (sth_has_changed())
      update_board_list();
    if (no<sizeof(boards)) {
      dest=SE_BOARDS->query_environment(boards[no]);
      catch(load_object(dest)); // Chameloid, 3-Jan-97
      if (find_object(dest))
        this_player()->move_living("X",dest);
      else
        write("Sorry, but "+dest+" doesn't exist, move is canceled.\n");
      this_player()->set_extern_data("board_util","next_board",no+1);
      return 1;
    }
    notify_fail("There aren't that many boards!\n");
    return 0;
  }
  if (str=="next" || str=="n") {
    if (sth_has_changed())
      update_board_list();
    while (next_board<sizeof(boards) &&
           (SE_BOARDS->query_last_write(boards[next_board])<=last_check ||
            index(boards[next_board],removed)>=0))
      next_board++;
    if (next_board<sizeof (boards)) {

      // added destination check, Chameloid, 7-Feb-97

      dest=SE_BOARDS->query_environment(boards[next_board]);
      catch(load_object(dest));
      if (find_object(dest))
        this_player()->move_living("X",dest);
      else
        write("Sorry, but "+dest+" doesn't exist, move is canceled.\n"
              "Type 'board travel next' for next board.\n");

      next_board++;
    }
    else
      write("That were all boards. Use 'board list new' to set next_board "
            "to 0!\n");
    this_player()->set_extern_data("board_util","next_board",next_board);
    return 1;
  }
  notify_fail("Board travel to a specific <number> or to <next> board?\n");
  return 0;
}

int reset_time(string str) {
  restore();
  if (str=="reset") {
    restore();
    last_check=time();
    write("Ok.\n");
    save();
    return 1;
  }
  notify_fail("'board time reset' or what?\n");
  return 0;
}

status remove(string str) {
  int no;
  restore();
  if (str && (str=="0" || (no=(int)str || sscanf(str,"board %d",no)==1))) {
    if (no<sizeof(boards)) {
      restore();
      removed-=({boards[no]});
      removed+=({boards[no]});
      write("Removed '"+capitalize(boards[no])+"'.\n");
      save();
      return 1;
    }
    notify_fail("There aren't that many loaded boards!\n");
    return 0;
  }   
  notify_fail("'board remove <no.>' or what?\n");
  return 0;
}

status add(string str) {
  int no;
  restore();
  if (str && (str=="0" || (no=(int)str || sscanf(str,"board %d",no)==1))) {
    if (no<sizeof(removed)) {
      write("Added '"+capitalize(removed[no])+"'.\n");
      removed-=({removed [no]});
      save();
      return 1;
    }
    notify_fail("There aren't that many removed boards!\n");
    return 0;
  }
  notify_fail("'board add <no.> or what?\n");
  return 0;
}

status board(string str) {
  string *wo,rest;
  if (str) {
    wo=explode(str," ");
    rest=implode(wo[1..]," ");
    switch (wo[0]) {
    case "list": 
      return list(rest);
    case "travel":
      return travel(rest);
    case "time":
      return reset_time(rest);
    case "remove": // fall through
    case "unlist":
      return remove(rest);
    case "add":
      return add(rest);
    }
  }
  notify_fail("\
This is the board utility. It has the following commands:\n\n\
'board list all [c[omplete]]': list all boards\n\
                               ('c' (or 'complete') means that removed\n\
                                boards are also listed)\n\
'board list new [c[omplete]]': as above except that only boards with changes\n\
                               are listed\n\
'board list removed'         : list all removed boards\n\n\
'board travel <no.>'         : move user to board listed as <no.>\n\
'board travel n[ext]'        : move user to next board with new notes\n\
                               (removed boards are not considered)\n\n\
'board time reset'           : store NOW as time of last check\n\n\
'board remove <no.>'         : remove a board for consideration\n\
'board add <no.>'            : add a board listed with <no.> when typing\n\
                               'board list removed'\n");
  return 0;
}

