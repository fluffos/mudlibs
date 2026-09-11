// Updated by stefan on 10 Jan 1997 modified by fire on Jan 7 1998
/* Do not remove the headers from this file! see /USAGE for more info. */
private int num_eats;
private int eat_val=20,drink_val=0;
private mixed eat_action;
private mixed last_eat_action;
string short();

int query_num_eats()
{
	return num_eats;
}
//:FUNCTION set_eat_action
//set_eat_action(string) causes 'string' to be printed when someone
//eats this object.  set_eat_action(function) causes the function
//to be called instead.
void set_eat_action(mixed action) {
    eat_action = action;
}
//:FUNCTION set_eat_val
//set_eat_val(int i) set the food increase for each bite
//default is 20
void set_eat_val(int i)
{
	eat_val=i;
}
void set_drink_val(int i) {
	drink_val=i;
}
//:FUNCTION set_last_eat_action
//Just like set_eat_action, but only is used for the last eat
void set_last_eat_action(mixed action) {
    last_eat_action = action;
}
//:FUNCTION set_num_eats
//num_eats is the number of eats left before the object is empty.
void set_num_eats(int num) {
    num_eats = num;
}
mixed direct_bite_obj() {
    return 1;
}
void eat_it() {
    mixed action;
    this_body()->add_food(eat_val);
	this_body()->add_drink(drink_val);
    if (num_eats == 1 && last_eat_action)
        action = last_eat_action;
    else
        action = eat_action;
    if (stringp(action))
        this_body()->simple_action(action,this_object());
    else
        evaluate(action);
        
    num_eats--;
    if(num_eats<=0)
        destruct(this_object());
}
