/* Copyright 1994 - Tim Hollebeek
 *
 * Permission is granted to copy and use this code elsewhere, provided
 * that all code derived from this code retain this header and credit
 * the author (Tim Hollebeek) for the source, that all improvements
 * to this code be communicated to the above mentioned author for possible
 * inclusion in this code, that all derived works are made publicly
 * available to whoever wants them, and no profit is made off of this
 * code or any other derived works or any other package or system this
 * is used in without express written permission of the author.
 */
/*
 *  General news daemon, by Beek
 *  Oct 10, 1994
 *
 * Interface:
 *
 * id NEWS_D->post(group, subject, message)
 * id NEWS_D->followup(group, id, message)
 * message NEWS_D->get_message(group, id)
 * id array NEWS_D->get_messages(group, filter)
 * id array NEWS_D->get_thread(group, thread)
 * NEWS_D->get_groups()
 *
 * Converted to work on TMI-2 mudlibs by Mobydick@TMI-2, 12-12-94.
 * Mobydick has notified Beek of changes to this object per the
 * above license. If you make any changes of your own, please do
 * the same.
 */

#include <newsreader.h>
#include <commands.h>

void archive_posts();

private mapping data = ([]);

create() {
  string tmp;

  if (clonep()) destruct(this_object());
  seteuid(getuid()) ;
  restore_object(SAVE_FILE);
  archive_posts();
}

void
save_me() {
    save_object(SAVE_FILE) ;
}

private int get_new_id(string group) {
    return data[group]["next_id"]++;
}

int
post(string group, string subject, string message) {
  int post_id;
  mapping map = allocate_mapping(5);

  if (!data[group]) return 0;
// If this post is originating locally, increment the counter for this group.
// if (base_name(previous_object())==NEWS_OBJ) local_posts[group]++ ;
  post_id = get_new_id(group);
  map["TIME"] = time();
  map["THREAD"] = post_id;
  map["SUBJECT"] = subject;
  map["MESSAGE"] = message;
  map["POSTER"] = this_player()->query("cap_name") ;
  data[group][post_id] = map;
  save_me();
  return post_id;
}

void
add_group(string group) {
  string fn = file_name(previous_object());
  
   if (fn != CMD_NEWSADM) return ;

  data[group] = (["next_id":1]);
  save_me();
}

void
remove_group(string group) {
  string fn = file_name(previous_object());

   if (fn != CMD_NEWSADM) return ;
  map_delete(data, group);
  save_me();
}
int
followup(string group, int id, string message) {
  int post_id;
  int tmp;
  mapping map = allocate_mapping(6);
  string subject;

  if (!data[group]) return 0;
  if (!data[group][id]) return 0;
  post_id = get_new_id(group);
  subject = ">" + data[group][id]["SUBJECT"];

  /* the original article is the thread id */
  while (tmp = data[group][id]["FOLLOW"])
    id = tmp;
  map["TIME"] = time();
  map["THREAD"] = id;
  map["SUBJECT"] = subject;
  map["MESSAGE"] = message;
  map["POSTER"] = this_player()->query("cap_name") ;
  data[group][post_id] = map;
  save_me();
  return post_id;
}

mapping
get_message(string group, int id) {
  /* sigh */
  /* Beek sighs because the copy() call is expensive but necessary. */
  return copy(data[group][id]);
}

mapping temp_kludge3;
function temp_kludge4;

int *
get_messages(string group, function filter) {
    int *ret;

    ret = keys(data[group]) - ({ "next_id" });
    if (!filter) filter = (: 1 :);
    temp_kludge3 = data[group];
    temp_kludge4 = filter;
    ret = filter_array(ret, (: evaluate(temp_kludge4, $1, temp_kludge3[$1]) :) );
    return sort_array(ret, 1);
}

private int temp_kludge;
private mapping temp_kludge2;

int *
get_thread(string group, int thread) {
  temp_kludge = thread;
  temp_kludge2 = data[group];
  return filter_array(keys(data[group]), (: $1 != "next_id" && temp_kludge2[$1]["THREAD"] == temp_kludge :));
}

string *
get_groups() {
  return sort_array(keys(data), 1);
}

private void
archive_post(string group, int id) {
    string file = sprintf("%s/%s", ARCHIVE_DIR, group);
    string msg = sprintf("---\nposter: %s\nsubject: %s\ndate: %s\n%s\n\n", data[group][id]["POSTER"], data[group][id]["SUBJECT"], ctime(data[group][id]["TIME"]), data[group][id]["MESSAGE"]);
    write_file(file,msg) ;
    map_delete(data[group], id);
}


void
archive_posts() {
    string *groups;
    int *ids;
    int i,j,ni,nj;
    mapping group;
    int archive_time = time() - ARCHIVE_DAYS * 24 * 60 * 60;

    groups = keys(data);
    ni = sizeof(groups);
    
    for (i=0; i<ni; i++) {
        group = data[groups[i]];
        ids = keys(group) - ({ "next_id" });
        nj = sizeof(ids);

        for (j=0; j<nj; j++) {
            if (group[ids[j]]["TIME"] < archive_time)
                archive_post(groups[i], ids[j]);
        }
    }
}

// Local additions begin here.

int query_group (string group) {
    if (member_array(group,keys(data))==-1) return 0 ;
    return 1 ;
}

// test only

int query_id (string group) {
    write(identify(data[group]["next_id"])+"\n") ;
}
