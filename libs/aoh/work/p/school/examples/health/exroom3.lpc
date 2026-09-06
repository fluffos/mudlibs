/*
 * This pub has the following features:
 * 1. Special prices for wizards and (V)AWs. By changing the discount
 *    function in an appropriate way, it should be no problem to extend this
 *    to race or guild members (or whatever).
 * 2. Entry to the Restaurant in the Middle of Nowhere.
 * 3. Arrays in the use of AddDrink
 * The pub doesn't feature any food, though...
 */
inherit "/room/pub";

#define RESTAURANT "/room/restroom"

varargs void create() {
	pub::create();
	SetIntShort("a test pub");
	SetIntLong(
"This is an example pub (/p/school/examples/health/exroom3.c). You cannot emote "
"here. You may order beverages for instant consuming by typing 'buy [thing]'. Food "
"is not served here because wizards feed on alcohol only (you did NOT know "
"that?). It is possible to buy something for a friend by entering 'buy [thing] for "
"[friend]'. If you want to be especially gratious, type 'buy [thing] for all'. "
"For menu, just type 'read menu'.\n"
"This pub has the following features:\n"
"1. Wizards have to pay 200 percent of the prices, (V)AWs 50 percent.\n"
"2. An entry to the Restaurant in the Middle of Nowhere is to the south.\n"
"3. The Pangalactic Gargle Blaster can be identified as 'Gargle Blaster' and\n"
"   'Blaster', too.\n");
	AddDrink("Coke",0,0,40,0);
	AddDrink("Guinness",0,2,20,0);
	AddDrink("Clausthaler",2,0,20,0);
	AddDrink("Einbecker",1,1,20,0);
	AddDrink("wizard brew",0,23,20,0);
	AddDrink(({"Pangalactic Gargle Blaster","Gargle Blaster","Blaster"}),202,0,1,0);
	SetDiscountFunc("do_discount");
	SetMenuStr("Wizards have to pay 200, (V)AWs 50 percent.\n");
	AddExit("east","/p/school/examples/health/exroom1");
	AddExit("south",RESTAURANT);
}

/*
 * This is an extreme example. In general, prices should not be modified
 * by more than 20% (approved by the (V)AWs of Health).
 */
int do_discount(int val) {
    int    level;

    level = query_user_level(this_player());
    if (level == 0)
	return val;
    else if (level < 40)
	return (val*2);
    else
	return (val/2);
}
