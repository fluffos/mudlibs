// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Goto - Nevyn@Woodstock, @GUE

#include <mudlib.h>
#include <move.h>
#include <security.h>

inherit CMD;

private void main( string arg)
{
    int rt;
    string *msgs;
    object prev,env;
    object o,*obs;
   string p_tmp;

    prev = environment(this_body());

    
    if(!arg) {
	write("goto <somebody>\ngoto <somewhere>\n");
	return;
    }
    o=get_object(arg);
    if(!objectp(o))
       o=CHAR_D->find_char(arg);
    if(!objectp(o)){
       obs = objects( (: $1->id($(arg)) :));
       if(sizeof(obs)) o=obs[0];
    }

    if(!objectp(o)) {
         write("can't find that obj\n");
	return;
    }


    if (environment(o)) o= environment(o);

    rt = this_body()->move(o);
    env = environment(this_body());

    if (rt == MOVE_OK)
    { 
        if (prev==env)
        { out("你猛地抽了一下筋。\n");
            return;
        }
        msgs = this_body()->get_player_message("mleave");
        tell_from_inside(prev, msgs[1]);
        msgs = this_body()->get_player_message("menter");
        tell_from_inside(env, msgs[1], 0, ({ this_body() }));
        this_body()->force_look();
    }
    else           // failure messages
        switch(rt)
    {
    case MOVE_NO_DEST: out("错误：没有目的地。\n"); break;
    case MOVE_NOT_RELEASED: out(
          "错误：你被困在这里了。\n"); break;
    case MOVE_NOT_ALLOWED: out(
          "错误：你要去的地方不接纳你。\n"); 
    }
}

