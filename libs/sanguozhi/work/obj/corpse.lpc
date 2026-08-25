// Updated by fire on April 05, 1998
// Updated by tset on 03 Mar 1998
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
 
inherit CONTAINER;
string the_name;
object link;
 
int is_living() {
    return 1;
}
 
string in_room_desc() 
{
    return query_in_room_desc();
}
    
mixed ob_state()
{
    return the_name;
}
     
object query_link() 
{
    return link;
}
void mudlib_setup(string name, string long, object l)
{
    ::mudlib_setup(); 
    link = l;
    if ( !name ) {
        name = "无名";
    }
    the_name = name;
    set_long(long || the_name + "的尸体，毫无特殊之处。");
    set_id("corpse", "尸体");
    set_unit("具");
    set_proper_name(the_name + "的尸体");
    set_in_room_desc(the_name + "的尸体(corpse)");
    set_max_capacity(VERY_LARGE);
    set_size(VERY_LARGE);
    set_preposition("on");
    if( clonep(this_object()) ) call_out("decay", 120, 1);
}
 
string introduce_contents()
{
    return "在"+query_chinese_id()+"上你看到：\n";
}   
mixed indirect_get_obj_from_obj(object ob1,object ob2)
{
  return 1;
}    
void decay(int phase)
{
    switch(phase) {
        case 1:
          tell_environment(this_object(),
                the_name+"的尸体开始腐烂了，发出一股难闻的恶臭。\n" );
          set_id("corpse", "腐烂的尸体");
          set_long(
"这具尸体显然已经躺在这里有一段时间了，正散发著一股腐尸的味道。\n");
          set_in_room_desc("一具腐烂的尸体。\n");
          call_out("decay", 120, phase + 1);
          break;
       case 2:
          tell_environment(this_object(),
                query_chinese_id()+"被风吹乾了，变成一具骸骨。\n" );
          set_id("skeleton", "一具枯乾的骸骨");
          set_long("这副骸骨已经躺在这里很久了。\n");
          set_in_room_desc("一具枯乾的骸骨。\n");
          call_out("decay", 60, phase + 1);
          break;
       case 3:
          tell_environment(this_object(),
                "一阵风吹过，把"+query_chinese_id()+"化成骨灰吹散了。\n" );
          if( environment() ) {
              object *inv;
              int i;
    
              inv = all_inventory(this_object());
              for(i=0; i<sizeof(inv); i++)
                   inv[i]->move(environment());
          }
          destruct(this_object());
          break;
    }
}
mixed is_corpse()
{
	return 1;
}
