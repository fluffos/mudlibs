// modified by fire on March 1998  hit_points.c
// Updated by stefan on 10 Jan 1997 
/* Do not remove the headers from this file! see /USAGE for more info. */
// Keeps track of hit points, for combat systems that use them
void hurt_us(int amt) {
    int p_tmp;
    p_tmp=this_object()->query_cur_hp();
	amt+=random(3); // increase the damage speed
    this_object()->set_cur_hp(p_tmp-amt);
    if(p_tmp<amt)
	    this_object()->set_cur_hp(-1);
    
    if(random(5)==0)  // 1/5 chance to get cur_max_hp reduced
    {
	p_tmp=this_object()->query_cur_max_hp();
	this_object()->set_cur_max_hp(p_tmp-amt);
    if(p_tmp<amt)
		    this_object()->set_cur_max_hp(0);
    }
}
int query_ghost() {
    return 0;
}
