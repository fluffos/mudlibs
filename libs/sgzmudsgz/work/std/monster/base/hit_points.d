// modified by fire on March 1998  hit_points.c
// Updated by stefan on 10 Jan 1997 
/* Do not remove the headers from this file! see /USAGE for more info. */
// Keeps track of hit points, for combat systems that use them
void die();
private int hp = 1;
private int max_hp = 1;
private static int hp_time = time();
private int heal_rate = 60;
void set_heal_rate(int x) {
    heal_rate = x;
}
void set_max_hp(int x) {
}
void set_hp(int x) {
}
private void reduce_hp(int x) {
}
private void increase_hp(int x) {
}
void reincarnate() {
}
int query_hp() {
    return hp;
}
void heal_us(int amt) {
    query_hp(); // healing since last checked
    if( hp <= 0 ) return;
    increase_hp(amt);
}
void hurt_us(int amt) {
    int p_tmp;
    p_tmp=this_object()->query_cur_hp();
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
int query_max_hp() {
    return max_hp;
}
int query_ghost() {
    return 0;
}
