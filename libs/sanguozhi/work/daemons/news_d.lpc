/* Do not remove the headers from this file! see /USAGE for more info. */

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
 * id array NEWS_D->get_messages(group)
 * id array NEWS_D->get_thread(group, thread)
 * NEWS_D->get_groups()
 * varargs id NEWS_D->system_post(group, subject, message, poster)  (poster optional)
 *
 *
 * 941224, Deathblade: GUElib conversion
 * 950707, Rust: added system_post on July 7, 1995
 * 950724, Rust: added the restrict_group() interface on July 24, 1995.
 * ??????, Beek: modified the system to be automatic based on group prefixes.
 * 950811, Deathblade: converted to classes. added remove_post().
 * 9606xx, Ohara: added move_post() and reply_post.
 * 970312, Stefan: added post restriction feature.
 * 20020811, Emperor: add query_news(string s) and get_player_group(string player, string group).
 */

#include <mudlib.h>
#include <security.h>
#include <commands.h>
#include <classes.h>

inherit M_ACCESS;

inherit CLASS_NEWSMSG;

#define SAVE_FILE "/data/news/news_d"
#define RECENT_FILE "/data/news/recent"

#define ARCHIVE_DIR "/data/news/archive"

void archive_posts();
nomask string * get_groups();

private mapping data = ([]);
private mapping last_id = ([]);

private mapping recent_changes = ([]);
private int new_format;

// No info on a group means never archive.
private mapping archive_info = ([ ]);

nomask mixed remove_nation_post(string n_id) ;

private mapping restrictions = 
([
  "wiz" : (: wizardp :),
  "admin" : (: adminp :)
]);

private mapping post_restrictions =
([
  "announce" : (: adminp :)
]);

#define is_group(x) (member_array(x,get_groups()) != -1)

//Emperor add.用于查询news_d object中的某些变量。//
mixed query_news(string s){
	if (s=="data") return data;
	if (s=="last_id") return last_id;
	if (s=="archive_info") return archive_info;
	return "no message.";
}

nomask void save_me()
{
    unguarded(1, (: save_object, SAVE_FILE :));
//    foreach (string key in keys(recent_changes))
//        recent_changes[key] = ([]);
//    save_recent();
}

nomask void save_recent() {
	save_me();
//    unguarded(1, (: rm, RECENT_FILE :));
//    unguarded(1, (: write_file, RECENT_FILE, save_variable(recent_changes) :));
}

/*
** Set the archive time on a group.
*/
nomask void set_archive_time(string group, int numDays)
{
    if (!check_previous_privilege(1))
    {
        error("权限不足");
    }
    if (!is_group(group))
    {
        error("没有这个新闻组");
    }
    if(!intp(numDays))
    {
        error("天数不是整数");
    }
    if(numDays < 0)
    {
        error("天数为负数");
    }
    if(!numDays) 
    {
        /* Never expire */
        map_delete(archive_info, group);
    }
    else
    {
        archive_info[group] = numDays;
    }
    save_me();
}





/*
** Convert the storage format from (old-style) mappings to classes
*/
private nomask void convert_news()
{
    string group;
    mapping contents;

    foreach ( group, contents in data )
    {
        mixed id;
        mapping post;

        foreach ( id, post in contents )
        {
            class news_msg msg;

            if ( id == "next_id" )
                continue;

#define MSG_TIME        1
#define MSG_THREAD      2
#define MSG_SUBJECT     3
#define MSG_MESSAGE     4
#define MSG_POSTER      5

            msg = new(class news_msg,
                      time : post[MSG_TIME],
                      thread_id : post[MSG_THREAD],
                      subject : post[MSG_SUBJECT],
                      poster : post[MSG_POSTER],
                      body : post[MSG_MESSAGE]);
            msg->userid         = lower_case(msg->poster);

            contents[id] = msg;
        }
    }

    new_format = 1;
    save_me();
}

void clear_recent() {
    recent_changes = 0;
}

nomask void create()
{
    string rec;
    
    set_privilege(1);
    if ( clonep(this_object()) )
    {
        destruct(this_object());
        return;
    }

    restore_object(SAVE_FILE, 1);

//    if (rec = read_file(RECENT_FILE))
//        recent_changes = restore_variable(rec);
//    else
//        recent_changes = 0;

//    if ( !new_format )
//        convert_news();
//    if (!recent_changes) {
//        recent_changes = ([]);
//        foreach (string key in keys(data))
//            recent_changes[key] = ([]);
//    } else {
//        foreach (string key, mixed value in recent_changes) {
//            if (value == "#removed#") {
//                map_delete(data, key);
//                map_delete(recent_changes, key);	// bug fixed by stefan
//            } else {
//                /* possible for new groups */
//                if (!data[key]) data[key] = ([]);
//                foreach (string key2 in keys(value)) {
//                    data[key][key2] = value[key2];
//                }
//                recent_changes[key] = ([]);
//            }
//        }
//    }
    foreach (string key, mixed value in data) {
        if (mapp(value)) {
            foreach (string key2, class news_msg msg in value) {
                if (classp(msg) && !msg->body)
                    map_delete(value, key2);
            }
        }
    }
    save_me();
    archive_posts();
}

public nomask int post_permitted(object user, string group)
{
    int index = member_array('.', group);
    string prefix = (index>0) ? group[0..index - 1] : group;
    
    function f = post_restrictions[prefix];
    if (!f) return 1;
    return evaluate(f, user);
}
                
private nomask int get_new_id(string group)
{
/*    int id = data[group]["next_id"]++;

    recent_changes[group]["next_id"] = data[group]["next_id"];
    
    return id;
*/
	if(!last_id[group])
		last_id[group]=10000;
	return last_id[group]++;
}

private nomask void notify_users(string group, class news_msg msg)
{
    CHANNEL_D->deliver_channel("news",
      sprintf("%s: %s [%s]",
        group,
        msg->subject[0..39],
        msg->poster));
}

nomask int post(string group, string subject, string message)
{
    int post_id;
    class news_msg msg;

    if (!data[group]) return 0;
    if (!post_permitted(this_user(), group)) return 0;
    post_id = get_new_id(group);
    msg = new(class news_msg,
              time : time(),
              thread_id : post_id,
              subject : subject,
	      poster : this_body()->short()+"("+this_user()->query_userid()+")",
              userid : this_user()->query_userid(),
              body : message);
//    msg->poster          = capitalize( msg->userid );

    data[group][post_id] = msg;
//    recent_changes[group][post_id] = msg;
    save_recent();

    notify_users(group, msg);

    return post_id;
}

varargs nomask int system_post(string group,
  string subject,
  string message,
  string poster)
{
    int post_id;
    class news_msg msg;

//### need to think on this. I don't think we want to require priv 1
//### ... especially since even *this* object doesn't have that.  And
//### just checking the previous object is a no-no.
    //    if ( get_privilege(previous_object()) != 1 )
    //  return 0;
    if ( !data[group] )
        return 0;
    post_id = get_new_id(group);
    msg = new(class news_msg,
              time : time(),
              thread_id : post_id,
              subject : subject);
    if ( poster )
    {
        msg->poster = poster;
        msg->userid = base_name(previous_object());
    }
    else if ( this_body() )
    {
        msg->userid = this_user()->query_userid();
        msg->poster = capitalize( msg->userid );
    }
    else if ( this_user() )
    {
        msg->userid = this_user()->query_userid();
        msg->poster = capitalize( msg->userid);
    }
    else
    {
        msg->poster = msg->userid = mud_name();
    }
    msg->body           = message;

    data[group][post_id] = msg;
//    recent_changes[group][post_id] = msg;
    save_recent();

    notify_users(group, msg);

    return post_id;
}

varargs nomask void add_group(string group)
{
    string fn;

    fn = base_name(previous_object());
    if (fn != ADMTOOL) return;

    data[group] = (["next_id":1]);
//    recent_changes[group] = (["next_id":1]);
    save_recent();
}

nomask void remove_group(string group)
{
    string fn;

    fn = base_name(previous_object());
    if (fn != ADMTOOL) return;

    map_delete(data, group);
//    recent_changes[group] = "#removed#";
    save_recent();
}

nomask int followup(string group, int id, string message)
{
    string subject;
    int post_id;
    class news_msg msg;

    if (!data[group]) return 0;
    if (!post_permitted(this_user(), group)) return 0;
    if (!data[group][id]) return 0;
    post_id = get_new_id(group);
    subject = ">" + ((class news_msg)data[group][id])->subject;

    id = ((class news_msg)data[group][id])->thread_id;

    msg = new(class news_msg,
              time : time(),
              thread_id : id, /* link to original thread_id */
              subject : subject,
              userid : this_user()->query_userid(),
              body : message);
    msg->poster       = capitalize( msg->userid );

    data[group][post_id] = msg;
//    recent_changes[group][post_id] = msg;
    save_recent();

    notify_users(group, msg);

    return post_id;
}
nomask int get_message_time(string group,int id) {
    class news_msg msg;

    if ( !data[group] )
        return 0;

    msg = data[group][id];
    if ( !msg )
        return 0;

    return msg->time;

}
nomask class news_msg get_message(string group, int id)
{
    class news_msg msg;

    if ( !data[group] )
        return 0;

    msg = data[group][id];
    if ( !msg )
        return 0;

    /* sigh */
    //### oops... can't do this yet... leave this unsafe for now
    //    return copy(msg);
    return msg;
}

nomask void remove_post(string group, int id)
{
    class news_msg msg;

    if ( !data[group] )
        return;
    
    msg = data[group][id];
    if ( !msg || !msg->body )
        return;

	if ((this_user() && !adminp(this_user()) && msg->userid != this_user()->query_userid()) &&
        (msg->userid != base_name(previous_object()))
		&& (group!=("nation."+this_user()->query_userid()))) // king can remove nation post
    {
        error("试图非法删除留言\n");
    }

    msg->body = 0;
//    recent_changes[group][id] = msg;
    save_recent();
}

nomask int * get_messages(string group)
{
    if (!data[group]) return ({});
    return keys(data[group]) - ({ "next_id" });
}

nomask int * get_thread(string group, int thread)
{
    return filter_array(keys(data[group]),
      (: $1 != "next_id" &&
        ((class news_msg)data[$(group)][$1])->thread_id
        == $(thread) :) );
}

nomask string * get_groups()
{
    string * ret;

    // filter before sorting; the func is typically pretty cheap, and
    // and calling them all is O(n).  Sorting the list first is more
    // expensive
    ret = filter(keys(data), function(string group)
      {
          // this will be "" if there is no '.'
          string prefix = group[0..member_array('.', group) - 1];
          function f = restrictions[prefix];
          if (!f) return 1;
          return evaluate(f, this_user());
      }
    );
    return sort_array(ret, 1);
}

nomask int get_group_last_id(string group)
{
	if(!last_id[group]) return 10000;
	return last_id[group]-1;
}

nomask void dump_to_file(string group, string fname)
{
    mapping contents = data[group];
    int id;

    foreach ( id in sort_array(keys(contents) - ({ "next_id" }), 1) )
    {
        class news_msg msg = contents[id];

        if ( !msg->body )
            continue;

        write_file(fname,
          sprintf("---\n作者: %s\n题目: %s\n日期: %s\n\n%s\n",
            msg->poster, msg->subject,
            intp(msg->time) ? ctime(msg->time) : msg->time,
            msg->body));
    }
}

private nomask void archive_post(string group, int id)
{
    class news_msg msg = data[group][id];

    unguarded(1, (: write_file, 
        sprintf("%s/%s", ARCHIVE_DIR, group),
        sprintf("---\n作者: %s\n题目: %s\n日期: %s\n%s\n\n",
          msg->poster, msg->subject,
          intp(msg->time) ? ctime(msg->time) : msg->time,
          msg->body)
      :) );

    /* This doesn't give w/ the newsreader. */
#if 0
    map_delete(data[group], id);
#else
    /* Do this instead. */
    remove_post(group, id);
#endif
}

private nomask int filter_removed(string group, int elem) {
    class news_msg msg = NEWS_D->get_message(group, elem);
    
    if (!msg || !msg->body)
        return 0;
    return 1;
}

private int compare_time(string group,int id1,int id2) {
	if(get_message_time(group,id1)>get_message_time(group,id2)) return -1;
	return 1;
}
nomask void archive_group(string group){

	mixed * ids;
    class news_msg msg;
	int i;
	ids=filter_array(NEWS_D->get_messages(group), (: filter_removed,group :));
	ids-=({"next_id"});
	if(sizeof(ids)<200) return;
	ids=sort_array(ids,(:compare_time($(group),$1,$2):));
	for(i=200;i<sizeof(ids);i++) {
//		tell_user("fire",sprintf("group %s id %d\n",group,ids[i]));
        archive_post(group, ids[i]);
	}


}
nomask void archive_posts()
{
    int archive_days;
    int archive_time;
    string group;
    mapping contents;

    foreach ( group, contents in data )
    {
		archive_group(group);


    }
}

nomask mixed remove_nation_post(string n_id) {
        mixed id;
	string group;
	mapping contents;
        class news_msg msg;

	group="nation."+n_id;
	if(COUNTRY_D->nation_exist(n_id)) return n_id+"还没有亡国。\n";

	contents=data[group];
	if(!mapp(contents)) return "don't have group of "+group+" .\n";

        foreach ( id, msg in contents )
        {
            if ( id == "next_id" )
                continue;
           archive_post(group, id);
        }
	
    	map_delete(data, group);
//    	recent_changes[group] = "#removed#";
    	save_recent();
	return 1;
}
// Blame --OH. for this code :)

nomask void move_post( string curr_group, int curr_id, string to_group )
{
    class  news_msg msg;
    int new_id;

    msg = copy( data[curr_group][curr_id]);
    if( !adminp(this_user()) && msg->userid != this_user()->query_userid())
    {
        write( "你不能转移不属于你的留言。\n\n");
        return;
    }
    if( curr_group == to_group )
    {
        write( "同一新闻组，留言没有转移。\n");
        return;
    }
    new_id = get_new_id(to_group);
    msg->body = "(转载自" + curr_group + ")\n" + msg->body;
    data[to_group][new_id] = msg;
//    recent_changes[to_group][new_id] = msg;
    remove_post( curr_group, curr_id );
    write( "留言转移完毕。\n");
    save_recent();
}

void remove() {
    save_me();
}

varargs nomask void add_nation_group(string group)
{
    if(data[group]) return;
    if(group[0..6]!="nation.") return;
    data[group] = (["next_id":1]);
//    recent_changes[group] = (["next_id":1]);
    archive_info[group]=90; // try 100 first
    save_me();
//    save_recent();
}
nomask void post_to_email(string destination,string subject,string message)
{
unguarded(1,(:call_other,"/secure/daemons/smtp_d","send_mail",destination,subject,message:));
}
varargs nomask void add_city_group(string group)
{
    if(data[group]) return;
    if(group[0..4]!="city.") return;
    data[group] = (["next_id":1]);
//    recent_changes[group] = (["next_id":1]);
    archive_info[group]=90; // try 100 first
    save_me();
//    save_recent();
}


// Emperor add.查询某个玩家在某个group里的所有贴子
mixed get_player_posts(string player, string group){
	int *thread;
	mixed id;
	mapping contents;
	class news_msg msg;
	if(!data[group]) return "no group: " + group;
	thread = ({});//get_messages(group);
	contents=data[group];
	foreach ( id, msg in contents ){
		if ( id == "next_id" ) continue;
		if ( msg->userid == player ) thread += ({id});
	}
	return thread;//filter_array(thread,(:contents[$1]->userid==$(player):));
}

// Emperor add.查询某个玩家在所有group里的所有贴子
mixed get_player_groups(string player){
	string *g;
	mapping player_groups = ([]);
	g = get_groups();
	foreach(string group in g){
		mixed posts;
		posts = get_player_posts(player, group);
		if(!arrayp(posts)) continue;
		if(!sizeof(posts)) continue;
		player_groups[group] = posts;
	}
	return player_groups;
}

string delete_player_posts(string player, string group){
	mixed posts;
	posts = get_player_posts(player, group);
//	if(!arrayp(posts)) return;
	if(!sizeof(posts)) return "为空。";
	foreach(int id in posts){
		remove_post(group, id);
	}
	return "玩家"+player+"在Group:"+group + "里所有留言删除完毕。";
}

string get_player_all_posts(string player, string group){
    class news_msg msg; 
	mixed posts;
	string s = "";
    
	posts = get_player_posts(player, group);
	if(!sizeof(posts)) return "为空。";
	foreach(int id in posts){
		msg = data[group][id];
		s += sprintf("-------------\n作者: %s\n题目: %s\n日期: %s\n%s\n",
          msg->poster, msg->subject,
          intp(msg->time) ? ctime(msg->time) : msg->time,
          msg->body);
	}
	return s;
}
