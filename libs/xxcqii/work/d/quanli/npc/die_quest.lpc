
/* void init()
{
 add_action("clone_tar","shouzhang");
 }
 
*/
 int clone_tar()
 {
 	object tar;
        if(this_player()->query_temp("qljob") == 1)
        {
 	tar = new("/d/xiangyang/npc/"+this_object()->query("id"));
   	tar->move(environment(this_object()));
   	return 1;
       }
 }
  
void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) && killer->query_temp("qljob")== 2 ) {
                killer->set_temp("qljob",4);
                killer->apply_condition("jyfail",0);
        }
	::die();
}
