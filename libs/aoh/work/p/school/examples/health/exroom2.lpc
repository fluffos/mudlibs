/* This is a normal test pub. Most pubs should be built in this way. */
inherit "/room/pub";

varargs void create() {
	pub::create();
	SetIntShort("a test pub");
	SetIntLong(
"This is an example pub (/d/archwiz/common/health/exroom2.c). You cannot emote "+
"here.\n"+
"You may order food and beverages for instant consuming by typing 'buy [thing]'. "+
"It is possible to buy something for a friend by entering 'buy [thing] for "+
"[friend]'. If you want to be especially gratious, type 'buy [thing] for all'.\n" +
"For menu, just type 'read menu'.\n"+
"For a more complicated example, see /p/school/examples/health/exroom3.c.");
	AddDrink("Guinness",0,2,20,0);
	/* like the firebreather in /room/pub2.c */
	AddDrink("firebreather",12,25,2,0);
	AddDrink("Altbier",0,1,20,0);
	AddFood(({"portion of fish and chips","fish and chips"}),5,20,0);
	AddFood("Big Mac",-5,10,0,"Arrgh, this tastes awful!");
	AddExit("west","/p/school/examples/health/exroom1");
}
