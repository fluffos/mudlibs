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
 * NEWS_D->remove_post(group, id)
 * message NEWS_D->get_message(group, id)
 * id array NEWS_D->get_messages(group, filter)
 * id array NEWS_D->get_thread(group, thread)
 * NEWS_D->get_groups()
 * id array NEWS_D->query_removed(group, id array)
 *
 * Internews interface stuff:
 * NEWS_D->remote_post(group, poster, subject, message)
 * NEWS_D->query_export_list(xxx)
 */
#include "/secure/include/daemons.h"

#define SAVE_FILE "/save/news/news"
#define ARCHIVE_DAYS 14
#define ARCHIVE_DIR "/save/news/archive"

void archive_posts();

private mapping data = ([]);

create() {
    string tmp;

    if (clonep()) destruct(this_object());

    restore_object(SAVE_FILE);
    archive_posts();
}

void
save_me() {
    unguarded( (: save_object, SAVE_FILE :) );
}

private int get_new_id(string group) {
    return data[group]["next_id"]++;
}

int
post(string group, string subject, string message) {
    int post_id;
    mapping map = allocate_mapping(5);

    if (!data[group]) return 0;
    post_id = get_new_id(group);
    map["TIME"] = time();
    map["THREAD"] = post_id;
    map["SUBJECT"] = subject;
    map["MESSAGE"] = message;
    map["POSTER"] = this_player()->GetCapName();
    data[group][post_id] = map;
    save_me();
    return post_id;
}

int
remote_post(string group, string poster, string subject, string message) {
    mapping map = allocate_mapping(5);
    int post_id;

    return -1;
    if (!data[group]) return 0;
    post_id = get_new_id(group);
    map["TIME"] = time();
    map["THREAD"] = post_id;
    map["SUBJECT"] = subject;
    map["MESSAGE"] = message;
    map["POSTER"] = poster;
    map["REMOTE"] = 1;
    data[group][post_id] = map;
    save_me();
    return post_id;
}

void

add_group(string group) {
    string fn = file_name(previous_object());

    if (fn != "/secure/cmds/adm/newsadm") return;

    data[group] = (["next_id":1]);
    save_me();
}

void
remove_group(string group) {
    string fn = file_name(previous_object());

    if (fn != "/secure/cmds/adm/_newsadm") return;
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
    map["POSTER"] = this_player()->GetCapName();
    data[group][post_id] = map;
    save_me();
    return post_id;
}

mapping
get_message(string group, int id) {
    /* sigh */
    return copy(data[group][id]);
}

int
remove_post(string group, int id) {
    if (this_player()->GetCapName() != data[group][id]["POSTER"] && !archp(this_player())) return 0;
    data[group][id]["MESSAGE"] = "***REMOVED***\n";
    data[group][id]["REMOVED"] = 1;
    return 1;
}

int *
get_messages(string group, function filter) {
    int *ret;

    ret = keys(data[group]) - ({ "next_id" });
    if (!filter) filter = (: 1 :);
    ret = filter_array(ret, (: evaluate($(filter), $1, $(data[group])[$1]) :) );
    return sort_array(ret, 1);
}

int *
query_removed(string group, int *ids) {
    return filter_array(ids, (: $(data[group])[$1]["REMOVED"] :) );
}

int *
get_thread(string group, int thread) {
    return filter_array(keys(data[group]), (: $1 != "next_id" 
		       && $(data[group])[$1]["THREAD"] == $(thread) :));
}

string *
get_groups() {
    return sort_array(keys(data), 1);
}

private void
archive_post(string group, int id) {
    string file = sprintf("%s/%s", ARCHIVE_DIR, group);
    string msg = sprintf("---\nposter: %s\nsubject: %s\ndate: %s\n%s\n\n", data[group][id]["POSTER"], data[group][id]["SUBJECT"], ctime(data[group][id]["TIME"]), data[group][id]["MESSAGE"]);
    unguarded( (: write_file, file, msg :) );
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
