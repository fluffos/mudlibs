// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <playerflags.h>
#define DEF_LEN 20
inherit M_ANSI;

private nosave string remote_desc;
private string * room_state = ({});
private mapping room_state_extra_longs = ([]);
private nosave int this_look_is_forced;

nosave private mapping default_nb =
(["northwest":"┏━━━━━━━━━",
 "north": "━━━━━━━━━━",
 "northeast": "━━━━━━━━━┓",
 "west": "┃        ",
 "east": "        ┃",
 "southwest": "┗━━━━━━━━━",
 "south": "━━━━━━━━━━",
 "southeast":  "━━━━━━━━━┛",
 "upp" : "                            ",
 "downp" : "                            ",
 "enterp" : "                            ",
 "outp" : "                            ",
]);

nosave private string pd="━━━━━━━━━━";
nosave private string pds="                    ";
nosave private string bl=
"┃                                                        ┃";

int query_light();
string short();
string show_exits();
string get_base_long();
string get_base_longr();
string get_extra_long();
string query_exit_value(string dir);
string default_base_long();


string * get_room_state_info()
{
  return copy(room_state);
}

string get_state_specific_long()
{
  string retval = "";
  mixed s;

  foreach(string state in room_state)
    {
      if(s = room_state_extra_longs[state])
        retval += evaluate(s)+"\n";
    }
  if(retval == "")
    return "\n";
  return retval;
}

int query_state(string state) {
    return member_array(state + "_on", room_state) != -1;
}

void set_room_state(string state)
{
  room_state -= ({state+"_off",state+"_on"});
  room_state += ({state+"_on"});
}

void clear_room_state(string state)
{
  room_state -= ({state+"_on",state+"_off"});
  room_state += ({state+"_off"});
}

void set_state_description(string state, mixed desc)
{
  if((strlen(state) < 4) || ((state[<3..] != "_on")
                             && (state[<4..] != "_off")))
    {
      error("State description must be state + _on or _off\n");
    }
  if(state[<3] == '_')
    {
      if((member_array(state, room_state) == -1) &&
         (member_array(state[0..<4]+"_off",room_state) == -1))
        clear_room_state(state[0..<4]);
    }
  else
    {
      if((member_array(state, room_state) == -1) &&
         (member_array(state[0..<5]+"_on",room_state) == -1))
        clear_room_state(state[0..<5]);
    }
  room_state_extra_longs[state] = desc;
}

//:FUNCTION show_objects
//Return a string describing the objects in the room
varargs string show_objects(object except)
{
    object *obs;
    string user_show;
    string obj_show;
    string str;
    int n;
    object link;

    obs = filter(all_inventory() - ({ this_body() }), 
                 (: $1->is_visible() :));
    if(except)
      {
        obs -= ({except});
      }

    n = sizeof(obs);
    user_show = "";
    obj_show = "";

    while (n--) {
        if ((obs[n]->is_living())||(obs[n]->is_troop())){
          if((link = obs[n]->query_link()) && userp(link))
            {
              user_show += obs[n]->in_room_desc() + "\n";
              continue;
            }
          str = obs[n]->in_room_desc();
          if(strlen(str)) 
            {
              if(0) //  if (except) modified by fire
                {
                  str += sprintf(//" (outside %s)"
                                 " (在%s外面)", except->short());
                }
              obj_show += str + "\n";
            }
        } else {

		  if(obs[n]->sg_obj())
		  {
			  obj_show+=obs[n]->query_in_room_desc();
			  continue;
		  }
            
			if (!duplicatep(obs[n])) {
                if ((str = obs[n]->show_in_room()) && strlen(str)) {
                  if(0) // if(except) modified by fire
                {
                  str += sprintf(//" (outside %s)"
                                 " (在%s外面)", except->short());
                }
                    obj_show += str + "\n";
                }
                if (obs[n]->inventory_visible())
                    obj_show += obs[n]->show_contents();
            }
        }
    }
    if(except) // We're inside an object
      obj_show += except->inventory_recurse(0,this_body());

    if (user_show != "") obj_show += "\n"+user_show;
//    return wrap(obj_show);
    return obj_show;
}

private int dont_show_long()
{
  return !this_look_is_forced && this_body()->test_flag(F_BRIEF);
}


string long()
{
#ifdef OBVIOUS_EXITS_BOTTOM
    return sprintf(//"%s%s%sObvious Exits: %s\nYou also see:\n%s",
                   "%s%s%s明显的出口是：%s\n你还可以看到：\n%s",     
                   (dont_show_long() ? "" : get_base_long()[0..<2]),
                   get_state_specific_long(),
                   get_extra_long(),
                   show_exits(),
                   show_objects());
#else
    return sprintf("%s%s%s%s",
                   (dont_show_long() ? "" : get_base_longr()[0..<2]),
                   get_state_specific_long(),
                   get_extra_long(),
                   show_objects());
#endif
}

//:FUNCTION long_without_object
//This is used by things like furniture, so the furniture can use the
//same long as the room, but not see itself in the description.
string long_without_object(object o)
{
#ifdef OBVIOUS_EXITS_BOTTOM
    return sprintf(//"%s%sObvious Exits: %s\n%s",
                   "%s%s明显的出口是：%s\n%s",     
                   get_base_long()[0..<2],
                   get_state_specific_long(),
                   get_extra_long(),
                   show_exits(),
                   show_objects(o));
#else
    return sprintf("%s%s%s%s",
                   get_base_long()[0..<2],
                   get_state_specific_long(),
                   get_extra_long(),
                   show_objects(o));
#endif
}

//:FUNCTION do_looking
//print out the description of the current room
void do_looking(int forced_look)
{
    // This probably shouldn't be done in a global variable,
    // instead it should be passed to long(), but long does
    // not take args anywhere else...
    this_look_is_forced = forced_look;

    if ( wizardp(this_body()) &&
        this_body()->query_shell_ob() &&
         this_body()->query_shell_ob()->get_variable("show_loc") )
    {
        printf("[%s]\n", file_name(this_object()));
    }

    if ( query_light() < 1 )
    {
        //write("Someplace dark\nIt is dark here.\n");
        write("地方很暗，这里漆黑一片。\n");
#ifdef ZORKMUD
        //write("You might get eaten by a grue.\n");
        write("你可要小心别吓趴下喽...\n");
#endif
    }
    else
    {
#ifdef OBVIOUS_EXITS
        write(short()+"%^ROOM_EXIT%^ [出口："+show_exits()+"]%^RESET%^\n");
//        printf(//"%s [exits: %s]\n"
//               "%s%%^ROOM_EXIT%%^ [出口：%s]%%^RESET%%^\n", short(), show_exits());
        
#else
        printf("%s\n", short());
#endif

        write(long()); //write(wrap(long()));
    }
}




//### I think this should be torched :-)
// I don't.
// This should be overloaded if you want to be able to give different
// descs from different rooms
// Hmm, I know who made each of these comments.  Who else does? :-)
// I do =)
// Your mom.
void remote_look(object o)
{
    if ( remote_desc )
    {
        printf("%s\n", remote_desc);
    }
    else
    {
        //printf("You can't seem to make out anything.\n");
        printf("你使劲挣大双眼，可什么也瞧不见...\n");
    }
}

void set_remote_desc(string s)
{
    remote_desc = s;
}


string get_base_longr()
{
	string ret;
 	ret=get_base_long();
	if(sizeof(ret)<28) ret=default_base_long();
	
		return ret;
}


mixed query_nb_short(string dir)
{
	string ret;
	object o;
	ret=query_exit_value(dir);
	if(!ret) return default_nb[dir];
	o=load_object(ret);
	if(!objectp(o)) return default_nb[dir];
	ret=" "+o->short()+" ";
	if(colour_strlen(ret)%2) ret+=" ";
	return ret;
}

string exp_string(string inp,string dir)
{
	int cur_len;
	int lef,rig;
	cur_len=colour_strlen(inp);
	if(cur_len>=DEF_LEN) return inp;
	switch(dir)
	{
	case "sw":
	case "nw":
		return inp+pd[0..(DEF_LEN-cur_len-1)];
	case "s":
	case "n":
		lef=(DEF_LEN-cur_len)/2;
		rig=lef;
		if(lef%2)
		{ lef--;rig++;}
		return pd[0..(lef-1)]+inp+pd[0..(rig-1)];
	case "se":
	case "ne":
		return pd[0..(DEF_LEN-cur_len-1)]+inp;
	case "w":
		return inp+pds[0..(DEF_LEN-cur_len-1)];
	case "e":
		return pds[0..(DEF_LEN-cur_len-1)]+inp;
	case "c":
		lef=(DEF_LEN-cur_len)/2;
		rig=lef;
		if(lef%2)
		{ lef--;rig++;}
		return pds[0..(lef-1)]+inp+pds[0..(rig-1)];
	}
}
string get_spe_dir(string dir) {
	string ret;
	ret=query_nb_short(dir);
	if(!sizeof(ret)) ret=default_nb[dir+"p"];
		return COLOR_D->center_string(ret,28);
	return ret;
}
string default_base_long()
{
	string nw,n,ne;
	string w,c,e;
	string sw,s,se;

	string ot,en,up,dw;

	nw=query_nb_short("northwest");
	n=query_nb_short("north");
	ne=query_nb_short("northeast");

	sw=query_nb_short("southwest");
	s=query_nb_short("south");
	se=query_nb_short("southeast");

	w=query_nb_short("west");
	c=" "+short()+" ";
	if(colour_strlen(c)%2) c+=" ";
	e=query_nb_short("east");
	
	nw=exp_string(nw,"nw");
	n=exp_string(n,"n");
	ne=exp_string(ne,"ne");

	sw=exp_string(sw,"sw");
	s=exp_string(s,"s");
	se=exp_string(se,"se");

	w=exp_string(w,"w");
	c=exp_string(c,"c");
	e=exp_string(e,"e");

	up="┃"+get_spe_dir("up");
	dw="┃"+get_spe_dir("down");

	en=get_spe_dir("enter")+"┃";
	ot=get_spe_dir("out")+"┃";

	return "\n"+nw+n+ne+"\n"+up+ot+"\n"+w+c+e+"\n"+dw+en+"\n"+sw+s+se+"\n\n";

}

