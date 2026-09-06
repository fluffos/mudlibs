// 29-Aug-96 / Graah: Doesn't accept crap any more.
//		      However, it DOES accept poisoned things and thief
//		      stuff such as lockpicks.
#include <room.h>

#define MAX_AT_ONCE 5
#define MAX_LISTED  100
#define MAX_ITEMS   45
#define	me		this_player()
#define LOG_DIR "/guilds/thieves/"

/*
To be defined in inheriting file:
*/

object *poi;

void
create_room()
{
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);
    set(NO_CLEANUP);
    set_short("Store room");
    set_long("Store room!");
}

/* Accept everything by default - redefine if needed. //Graah */
int accept_object(object ob, string desc)
{
    // value for accepting items used to be 300  --K
    if (!ob->query_thief_item() &&
      (int)ob->query_value() < 0)
    {
	if (!poi)
	    poi = (object *)"/guilds/thieves/poison_d"->query_poisoned_things(1);
	if (member(poi, ob) == -1)
	{
	    this_player()->tell_me(desc + "? Don't donate such crap here!");
	    return 0;
	}
    }

    return 1;
}

int
list_item(string item)
{
    object ob,ob_next;
    int    count,len,old_len,list_type,val;
    string str, tmp, text;
    status first,test;

    /* preprocess items variable */
    if(item && item != "all") {
	list_type = 1;
	if(item=="armours") list_type = 2; else
	if(item=="weapons") list_type = 3; else
	if((len=sizeof(item)) && item[len-1]=='s') item = item[0..len-2];
    }

    first = 1;
    ob_next = first_inventory();

    while(ob_next) {
	ob = ob_next;
	ob_next = next_inventory(ob);

	/*** list items ***/
	if(++count>MAX_LISTED) break;
	/* can't use switch because of continue command */
	if(    (list_type==1 && (!ob->id(item)))
	  || (list_type==2 && (!ob->is_armour()))
	  || (list_type==3 && (!ob->is_weapon())) )
	    continue;

	if(first) {
	    text = "Num\tItem\t\t\tNum\tItem";
	    first = 0;
	}
	len = sizeof(str = (string)ob->short());
	if (!old_len) {
	    text = sprintf("%s\n%d\t%-24s",
	      text, count, str
	    );
	    if (len > 24) old_len = 0;
	    else old_len = len;
	} else {
	    text = sprintf("%s%d\t%-24s",
	      text, count, str
	    );
	    old_len = 0;
	}
    }
    me->tell_me(text);

    if(first){
	me->tell_me("Thief-mage says: Sorry, I don't have any of those.");
	return 1;
    }
    return !first;
}

int
borrow_item(string item)
{
    object ob;
    string str;
    int i, value;

    if(!item) {
	me->tell_me("Thief-mage tells you: Perhaps you should borrow <item>.");
	return 1;
    }

    if(sscanf(item,"%d%s",i,str)==2 && str=="" && i>0 && i<=MAX_LISTED) {
	object *list;
	list = all_inventory();
	if(sizeof(list)>=i) ob = list[i-1];
    }
    if(!ob && !(ob=present(item))) {
	me->tell_me("Thief-mage says: Sorry, I'm out of that item.");
	return 1;
    }
    i = (int)ob->query_weight();
    if(!this_player()->add_weight(i)) {
	me->tell_me("Thief-mage tells you: \
You don't seem to be able to carry that much.\n");
	return 1;
    }
    move_object(ob, this_player());
    me->tell_me("Thief-mage says: Here is the item you requested. ");
    environment(me)->tell_here(sprintf("%s borrows %s.",
	(string) this_player()->query_name(),
	(string) ob->short()), me);
    write_file(LOG_DIR+"EQ_LOG", capitalize(this_player()->query_real_name())
      +" borrowed "+ob->query_short()+" from the Guild at "+ctime(time())+"\n");
    return 1;
}

/*
  Destructs the items over MAX_ITEMS count in store.
  Returns how many items was donated.
*/
varargs int
donate_items_in_list(object *item_list,object from_what)
{
    mixed  *store_list;
    object ob;
    string desc, donateer;
    int i, value, count;
    object *keeped;

    if (interactive(me) && (keeped = (object *) me->query_keep_items())
      && sizeof(keeped)) {
	i = sizeof(item_list);
	item_list -= keeped;
	if ((count = sizeof(item_list)) < i) {
	    if (!count) {
		me->tell_me(
		  "[All items you specified are the ones you've specified to be keeped!]");
		return 1;
	    }
	    else me->tell_me(sprintf(
		    "[Keeping %d items othewise donated]", i - count));
	}
    }

    poi = 0;

    for(i = count = 0; i < sizeof(item_list); ++i) {

	/* Avoid too long evaluation */
	if (count >= MAX_AT_ONCE) {
	    me->tell_me("Thief-mage says: Hey, You are donating a lot of \
stuff! Let's slow down a bit.");
	    break;
	}

	ob = item_list[i];
	if(!(desc = (string)ob->short())
	  || ob->drop() || !ob)
	    continue;
	if (!accept_object(ob, desc)) continue;
	if(!count++) {
	    donateer = (string)this_player()->query_name();
	}

	environment(me)->tell_here(donateer+" donates "+desc+".",me);
	me->tell_me("You donate "+desc+" to the Guild. ");
	write_file(LOG_DIR+"EQ_LOG", capitalize(
	    this_player()->query_real_name())+" donated "+
	  ob->query_short()+" to the Guild at "+ctime(time())+". \n");

	if(!store_list) { /* collect shorts from all items */
	    int i2;
	    store_list = all_inventory();
	    i2=sizeof(store_list);
	    while(i2--)
		store_list[i2] = (string)store_list[i2]->short();
	}
	environment(ob)->add_weight(-((int)ob->query_weight()));
	move_object(ob,this_object());
	store_list += ({ desc });
    }
    if (from_what)
	from_what->recount_weight();

    notify_fail("You didn't donate anything.\n");
    return count;
}

int
donate_item(string item)
{
    object *item_list;
    object env,ob;
    string str;

    if(!item) {
	me->tell_me("Thief-mage says: Are you trying to donate <item(s)>?");
	return 1;
    }

    /** Donate from... **/
    env = this_player();
    if(sscanf(item,"%s from %s",item,str)==2) {
	if(!(env = present(str,env))) {
	    me->tell_me("Thief-mage frowns and says: \
You don't have any "+str+".");
	    return 1;
	}
	if(!env->can_put_and_get()) {
	    me->tell_me("Thief-mage says: I can't get anything from that.");
	    return 1; } }

    /** Donate what... **/
    if(item=="all") {
	item_list = all_inventory(env);
	if(!sizeof(item_list)) {
	    me->tell_me("Thief-mage scratches his head: \
There seems to be nothing to donate" + (str ? (" in "+str) : "") +".");
	    return 1;
	}
    } else {
	if(!(ob = present(item, env))) {
	    me->tell_me(
	      "Thief-mage says: You don't have any " + item
	      +(str ? (" in "+str) : "")
	      +".");
	    return 1;
	}
	// Let's check if this was an item player wanted to keep!
	if (this_player()->query_keep_items(ob)) {
	    me->tell_me(sprintf("Won't donate the %s as you have specified\
 it to be kept from donating!", (string) ob->query_name()));
	    return 1;
	}
	item_list = ({ ob });
    }

    return donate_items_in_list(item_list,env);
}
