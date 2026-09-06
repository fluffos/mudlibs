/*  
*
*   Basic Storage facility for Storage area use.
*
*/

#include "../rooms/priest_room.h"



#define MAX_AT_ONCE 5
#define MAX_LISTED  40
#define MAX_ITEMS   45

string ROOM;
int    min_value;  /* "The cheap item is thrown away" */

void
create_room(){
    set_short("Storage room");
    set_long("A very simple storage room. There's shelves from floor to the \
ceiling filling all walls except the south wall, where there is a door.");
    set(PREVENT_TELEPORT);
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(NO_CLEANUP);
    set_light_level(LT_LIGHTS);
    this_object()->create_storage();
}

int query_min_value() { return min_value; }
void set_min_value(int v) { if (v < 500) min_value = v; }

int accept_object(object ob){

    return 1;
}


#define SPACES "                                "
int list_item(string item) {
    object ob,ob_next;
    int    count,len,old_len,list_type;
    string str,tmp;
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

	if(living(ob) || ob->id("door")) continue;
	if(((int)ob->query_value() < min_value)) {
	    destruct(ob);
	} else {
	    /*** list items ***/
	    if(++count>MAX_LISTED) break;
	    /* can't use switch because of continue command */
	    if(    (list_type==1 && (!ob->id(item)))
	      || (list_type==2 && (!ob->is_armour()))
	      || (list_type==3 && (!ob->is_weapon())) )
		continue;

	    if(first) {
		write("Num\tItem                          Num\tItem\n");
		first = 0;
	    }
	    len = sizeof(str = (string)ob->short());
	    if(old_len && len>34) {write("\n");old_len=0;}
	    write( SPACES[(old_len ? old_len : 35)..((count<10) ? 36 : 35 )]
	      + count
	      + "\t"
	      + str );
	    if(old_len || len>33){
		write("\n");
		old_len = 0;
	    } else
		old_len = len;
	}
    }
    if(old_len) write("\n");
    if(first) notify_fail("No such items in storage.\n");
    return !first;
}


int borrow_item(string item) {
    object ob;
    string str;
    int    i;

    if(!item) {
	notify_fail("Borrow <item>\n");
	return 0;
    }

    if(sscanf(item,"%d%s",i,str)==2 && str=="" && i>0 && i<=MAX_LISTED) {
	ob = first_inventory();
	while(ob) {
	    if((!ob->id("door")) && !living(ob)) i--;
	    if(i==0) break;
	    ob = next_inventory(ob);
	}
	if(i!=0) ob = 0;
    }
    if((!ob && !(ob=present(item))) || living(ob) || ob->id("door")) {
	notify_fail("No such item in storage.\n");
	return 0;
    }
    i = (int)ob->query_weight();
    if(!this_player()->add_weight(i)) {
	this_player()->tell_me("You can't carry that much.");
	return 1;
    }
    this_player()->tell_me("Ok.");
    if((ob->query_value())>=500){
	write_file(SHOPLOG,this_player()->query_real_name()+" borrowed \
 "+ob->query_name()+" worth: "+ob->query_value()+".  "+ctime(time())+".\n");
    }

    move_object(ob, this_player());
    return 1;
}


int donate_items_in_list(object *item_list) {
    mixed  *store_list;
    object ob;
    string desc, lender;
    int    i, count, size;
    size=sizeof(item_list);
    for(i = 0; i < size; ++i) {

	/* Avoid too long evaluation */
	if (count >= MAX_AT_ONCE) {
	    this_player()->tell_me("You are leaving a lot of stuff! I need a break.");
	    break;
	}

	ob = item_list[i];
	if(!(accept_object(ob)) || !(desc=(string)ob->short())
	  || ob->drop() || !ob)
	    continue;
	if(!count++) {
	    lender = (string)this_player()->query_name();
	}

	this_player()->tell_me("You donate: "+desc+".");

	if(!store_list) { /* collect shorts from all items */
	    int i2;
	    store_list = all_inventory();
	    i2=sizeof(store_list);
	    while(i2--)
		store_list[i2] = (string)store_list[i2]->short();
	}
	if(member(store_list, desc)<-1){
	    /* destruct automatically updates the weight */
	    destruct(ob);
	} else {
	    string *longname;
	    environment(ob)->add_weight(-((int)ob->query_weight()));
	    if((ob->query_value())>=500){
		write_file(SHOPLOG,this_player()->query_real_name()+" donated a\
 "+ob->query_name()+" worth: "+ob->query_value()+".  "+ctime(time())+".\n");
	    }
	    longname=explode(desc,"#");
	    if(member(longname, "HOB")<0){
		CASH_D->from_shop(((int)(ob->query_value())*2)/9+1);
		ob->set_short(ob->short()+" #HOB#");
		desc=(string)ob->short();
	    }
	    move_object(ob,this_object());
	    store_list += ({ desc });
	}
    }

    if(count) {
	store_list = all_inventory();
	size=sizeof(store_list);
	for(i=MAX_ITEMS; i<size; ++i)
	    destruct(store_list[i]);
    } else {
	notify_fail("I'm not interested in "
	  +((sizeof(item_list)==1) ? "it" : "them")
	  +".\n");
    }
    return count;
}


int donate_item(string item) {
    object *item_list;
    object env,ob;
    string str;

    if(!item) {
	notify_fail("Donate <item(s)>\n");
	return 0;
    }

    env = this_player();
    if(sscanf(item,"%s from %s",item,str)==2) {
	if(!(env = present(str,env))) {
	    notify_fail("You don't have any "+str+".\n");
	    return 0;
	}
	if(!env->can_put_and_get()) {
	    notify_fail("You can't take anything from that.\n");
	    return 0; } }

    /** Sell what... **/
    if(item=="all") {
	item_list = all_inventory(env);
	if(!sizeof(item_list)) {
	    notify_fail("Nothing to donate" + (str ? (" in "+str) : "") +".\n");
	    return 0;
	}
    } else {
	if(!(ob=present(item,env))) {
	    notify_fail("You don't have any " + item
	      +(str ? (" in "+str) : "")
	      +".\n");
	    return 0;
	}
	if((ob->query_wc())&&(ob->query_wielded())){
	    notify_fail("Your still using "+item+"!\n");
	    return 0;
	}
	if((ob->query_ac())&&(ob->query_worn())){
	    notify_fail("Your still wearing "+item+"!\n");
	    return 0;
	}

	item_list = ({ ob });
    }

    return donate_items_in_list(item_list);
}

#ifdef LOG_STEALS
void
init_room() {
    if(query_once_interactive(this_player()) &&
      !this_player()->query_coder_level()) {
	write_file(STEAL_LOG, sprintf("%s %s %s\n",
	    object_name(),
	    this_player()->query_real_name(), ctime(time())));
    }
}
#endif
