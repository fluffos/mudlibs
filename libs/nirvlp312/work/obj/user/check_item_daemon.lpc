/* check_item_daemon
 *
 * Keeps track of items recommended by players for update
 * flagged items are added to a list wizards can view
 * wizards can also flag an item as updated once it has
 * been.
 * Flagging an item that has already been updated notifies
 * the player.
 */
 
#define SAVE_FILE "obj/play/CHECK_ITEM"
 
string *filenames,*submitters,*recommendations,*updaters;

reset() {
  if(!filenames) {
    filenames=({});
    submitters=({});
    recommendations=({});
    updaters=({});
    restore_object(SAVE_FILE);
  }
}

check_item(string filename) {
  int num;
  num=member_array(filename,filenames);
  if(num==-1)
    return 0;
  else
    if(updaters[num])
      return "updated";
    else
      return "submitted";
}

add_item(string filename,string submitter,string recommendation) {
  filenames+=({filename});
  submitters+=({submitter});
  recommendations+=({recommendation});
  updaters+=({0});
  save_object(SAVE_FILE);
  return 1;
}

delete_item(string filename) {
  int num;
  num=member_array(filename,filenames);
  if(num==-1)
    return 0;
  filenames[num]="aaaaaaaaaaaabbbbbbbbbbbbccccccccccccc";
  submitters[num]="aaaaaaaaaaaabbbbbbbbbbbbccccccccccccc";
  recommendations[num]="aaaaaaaaaaaabbbbbbbbbbbbccccccccccccc";
  updaters[num]="aaaaaaaaaaaabbbbbbbbbbbbccccccccccccc";
  filenames-=({"aaaaaaaaaaaabbbbbbbbbbbbccccccccccccc"});
  submitters-=({"aaaaaaaaaaaabbbbbbbbbbbbccccccccccccc"});
  recommendations-=({"aaaaaaaaaaaabbbbbbbbbbbbccccccccccccc"});
  updaters-=({"aaaaaaaaaaaabbbbbbbbbbbbccccccccccccc"});
  save_object(SAVE_FILE);
  return 1;
}

get_not_updated() {
  string *result;
  int s;
  s=sizeof(filenames);
  result=({});
  while(s--)
    if(!updaters[s])
      result+=({
        "filename:     "+filenames[s]+"\n"+
        "submitted by: "+submitters[s]+"\n"+
        "recommended:  "+recommendations[s]+"\n"});
  return result;
}

get_updated() {
  string *result;
  int s;
  s=sizeof(filenames);
  result=({});
  while(s--)
    if(updaters[s])
      result+=({
        "filename:     "+filenames[s]+"\n"+
        "submitted by: "+submitters[s]+"\n"+
        "recommended:  "+recommendations[s]+"\n"+
        "updated by:   "+updaters[s]+"\n"});
  return result;
}

mark_updated(filename,updater) {
  int num;
  num=member_array(filename,filenames);
  if(num!=-1) {
    updaters[num]=updater;
    save_object(SAVE_FILE);
    return 1;
  }
  return 0;
}