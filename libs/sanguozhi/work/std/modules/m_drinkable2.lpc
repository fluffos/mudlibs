// this is second kind of drinkable materials
// can't re-fill
// by fire on April 4, 1999
private int num_drinks=10,max_drinks=10;
private mixed drink_action="$N端起$o咕嘟咕嘟喝了几口。\n";
private mixed last_drink_action="$N一口把$o喝完了。\n";
private int drink_val,eat_val;


string short();
string query_chinese_id();
void set_drink_val(int i) {
	drink_val=i;
}
void set_eat_val(int i) {
	eat_val=i;
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
int query_num_drinks()
{
	return num_drinks;
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
	if(num_drinks>0) {
		this_body()->add_drink(drink_val);
		this_body()->add_food(eat_val);
	}
    if (num_drinks == 1 )
        action = last_drink_action;
    else
        action = drink_action;
	if(action[<1]!='\n')
		action+="\n";
    this_body()->simple_action(action,this_object());

    num_drinks--;
    if (num_drinks<=0)	
	num_drinks=0;
	if(num_drinks==0)
		destruct(this_object());
}
 
