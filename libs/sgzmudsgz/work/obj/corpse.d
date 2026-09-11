// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CONTAINER;

string the_name;
object link;

int is_living() {
    return 1;
}

string in_room_desc() {
    return query_in_room_desc();
}

mixed ob_state()
{
    return the_name;
}

object query_link() {
    return link;
}

void mudlib_setup(string name, string long, object l)
{
    ::mudlib_setup();

    link = l;
    if ( !name )
        return;

    the_name = name;
    set_long(long || the_name + "的尸体，毫无特殊之处。");
 
    set_id("corpse", "尸体");
    set_unit("具");
    set_proper_name(the_name + "的尸体");//"' corpse");
    set_in_room_desc(the_name + "的尸体静静地躺在地上。");//" is lying here slumped on the ground.");
    set_max_capacity(VERY_LARGE);
    set_size(VERY_LARGE);
    set_preposition("on");
}

string introduce_contents()
{
    return "在"+short()+"上你看到：\n";//"On " + short() + " you see:\n";
}    
mixed indirect_get_obj_from_obj()
{
  return 1;
}
