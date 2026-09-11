// modified by fire on March 5 death.c
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
void remove();
string query_name();
string query_chinese_id();
private string corpse_long;
private string corpse_filename = CORPSE;
void set_corpse_long(string str) {
    corpse_long = str;
}
void set_corpse_filename(string str) {
    corpse_filename = str;
}
//:FUNCTION drop_corpse
//replace us with a corpse
void drop_corpse() {
    object corpse = new(corpse_filename, query_chinese_id(), corpse_long);
    all_inventory()->move(corpse);
    corpse->move(environment());
    remove();
}
void die() 
{
    drop_corpse(); // subtle pun
}
