//	/std/living/follow.c
//	from the Nightmare mudlib
//	code for allowing people to follow
//	created by Descartes of Borg 15 february 1993

static private string allowed_to_follow;
static private object *followers;
static private object following;

object *query_followers() { return followers; }
object query_following() { return following; }

void set_following(object f) { following = f; }

int set_followers(object *f) {
    int i;

    if(!f) return 0;
    if(member_array( this_object(), f ) != -1 ) return 0;
    if(following && member_array(following, f) != -1) return 0;
    followers = f;
    for(i=0; i<sizeof(f); i++) {
	if(!f[i]) followers -= ({ f[i] });
	else f[i]->set_following(this_object());
    }
    return 1;
}

int add_follower(object f) {
    if( f == this_object() ) return 0;
    if(followers)
    if( member_array(f, followers) != -1 ) return 0;
    if(!followers) {
	followers = ({ f });
	f->set_following(this_object());
	return 1;
    }
    f->set_following(this_object());
    followers = followers + ({ f });
    return 1;
}

void remove_follower(object ob) {
    if(followers && member_array(ob, followers) == -1) 
	return;
    followers -= ({ ob });
    ob->set_following(0);
}

void clear_followers() {
    int i;

    if(!followers) return;
    for(i=0; i<sizeof(followers); i++) 
	if(followers[i]) followers[i]->set_following(0);
    followers = ({});
}

void move_followers(object prev) {
    object *tmp;
    int i;

    tmp = ({});
    for(i=0; i<sizeof(followers); i++) {
        if(!objectp(followers[i])) continue;
	if(!environment(followers[i])) continue;
	if(environment(followers[i]) != prev) {
	    tell_object(this_object(), "You have lost "+followers[i]->query_cap_name()+".\n");
	    tell_object(followers[i],
		this_object()->query_cap_name()+" has ditched you.\n");
	    followers[i]->set_following(0);
	}
	else {
	    if( followers[i]->follow(base_name(environment(this_object()))))
		tmp += ({ followers[i] });
	}
    }
    followers = tmp;
}

void follow_allow(string str) { allowed_to_follow = str; }

int can_follow(string str) { return str == allowed_to_follow; }

int follow(string exit) {
    string cmd;
    string nil;
    if(!environment(this_object())) return 0;
    if (exit[0]!='/') exit = "/"+exit;
    if (sscanf(exit, "%s.c",  nil)==1) exit=nil;
    cmd = (string)environment(this_object())->query_direction(exit);
    if (cmd=="/d/nopk/standard/void")
      if((cmd = (string)environment(this_object())->query_direction(exit+".c")) == "/d/nopk/standard/void")
      return 0;
    command(cmd);
    return 1;
}
