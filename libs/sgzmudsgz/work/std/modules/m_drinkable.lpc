// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// modified by fire on Jan 7 1998 m_drinkable.c
private int num_drinks=10,max_drinks=10;
private mixed drink_action;
private mixed last_drink_action;
private mixed finish_drink_action;
private string con;

string short();
string query_chinese_id();
void set_con(string p_con)
{
	con=p_con;
}
string query_con()
{
	return con;
}
void set_finish_drink_action( mixed action)
{
	finish_drink_action=action;
}
void set_drink_action(mixed action) {
    drink_action = action;
}
void set_last_drink_action(mixed action) {
    last_drink_action = action;
}
//:FUNCTION set_num_drinks
//num_drinks is the number of drinks left before the object is gone.
void set_num_drinks(int num) {
    num_drinks = num;
}
void set_max_drinks(int num)
{
	max_drinks=num;
	num_drinks=num;
}
mixed direct_drink_obj() {
//    if (!num_drinks)
//       return short() + "喝光了。\n";
    return 1;
}
void drink_it() {
    mixed action;
	if(num_drinks>0)
		this_body()->add_drink(15);
    if (num_drinks == 1 && last_drink_action)
        action = last_drink_action;
    else if (num_drinks <= 0)
        action = finish_drink_action;
    else
        action = drink_action;
    if (stringp(action))
        write(action);
    else
        evaluate(action);
    num_drinks--;
    if (num_drinks<=0)	
	num_drinks=0;
}
 
mixed direct_fill_obj()
{
   return 1;
}
void fill_with(object with)
{
   if(num_drinks)
		this_body()->simple_action("$N将"+con+"从"+query_chinese_id()+"里倒掉。\n");
   this_body()->simple_action("$N将"+query_chinese_id()+"装满了清水。\n");
   con="清水";
   num_drinks=max_drinks;
}