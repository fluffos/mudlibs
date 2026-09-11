// Updated by stefan on 10 Jan 1997 by dan and fire
/* Do not remove the headers from this file! see /USAGE for more info. */
/*
** go.c
**
*/
#include <mudlib.h>
inherit VERB_OB;
int need_to_be_alive() {
    return 0;
}
int need_to_see() {
    return 0;
}
//###should be s
//###should be shared somehow with drive.c
string * normal_dirs = ({  "up", "down", "north", "south", "east",
"west", "northwest", "northeast", "southwest", "southeast" ,"bedroom"});
void do_go_wrd_obj(string prep, object ob) 
{
    ob->go(prep);
}
// This is one of the most heinous functions in this lib. Sorry.
mixed can_go_str(string str) 
{
    int is_normal = (member_array(str, normal_dirs) != -1);
    mixed value;
    object env = this_body()->query_room();
    object env_another = environment(this_body());
    if (is_chinese(str)) 
    {
             str = DIRECTION_D->to_english(str);
    }
   if(env->is_vehicle()) env = environment(env);
// Be careful what errors you return here since "go " + str is tried for
// all input
    if (is_normal) 
    {
        mixed ret = 0;
        if( function_exists( "can_go_" + str, env ))
        {
            ret = call_other( env, "can_go_" + str );
           if( ret == 1 ) return 1;
           return ret;
        }
    }
    value = env->query_exit_value(str, is_normal);
    if (stringp(value) && value[0] == '#')
      {
        string other_value;
        if(environment(env) && env->can_travel() && (other_value = 
           env->query_final_exit_value(str,is_normal)))
          {
            if(stringp(other_value) && other_value[0] != '#')
              {
                return default_checks();
              }
            else
              {
                if(stringp(other_value))
                  return other_value[1..];
                else
                  return default_checks();
              }
          }
        return value[1..];
      }
    if (value)
     {
	string fn;
	object o_rom;
	fn=env->query_exit_value(str);
	if(!stringp(fn)) return "似乎不太可能朝那个方向走。\n";

	o_rom=load_object(fn);
	if(!objectp(o_rom)) return "似乎不太可能朝那个方向走。\n";

           if(env_another->is_horse() && o_rom->is_indoors()) 
          return "你必须下马才能进去。\n";

		   if(env_another->is_troop()) {
				value=default_checks();
				if(stringp(value)) return value;
				return WARAI_D->check_move(env_another,env->query_exit_value(str));
		   }
		return default_checks(); 

	}
        
    if( is_normal )
    {   
        return "似乎不太可能朝那个方向走。\n";
    }

}
void do_go_str(string str) 
{
    if (is_chinese(str)) 
    {
             str = DIRECTION_D->to_english(str);
    }
    this_body()->do_go_somewhere(str);
        if(random(6)==1) {
//                this_body()->start_busy(1,"你正忙着赶路呢。");
	}
}
mixed * query_verb_info()
{
    return ({ ({ "STR" }), ({ "leave" }), ({ "down OBJ",
 "up OBJ", "around OBJ:v", "to OBJ:v", "over OBJ", "on OBJ", "into OBJ", "in OBJ", "STR" }) });
    /*
    ** exit 1 -> go 1
    ** exit down OBJ -> go down OBJ
    ** exit up OBJ -> go up OBJ
    ** exit around OBJ -> go around OBJ
    ** exit to OBJ -> go to OBJ
    ** exit over OBJ -> go over OBJ
    ** exit on OBJ -> go on OBJ
    ** exit into OBJ -> go into OBJ
    ** exit in OBJ -> go in OBJ
    */
}
