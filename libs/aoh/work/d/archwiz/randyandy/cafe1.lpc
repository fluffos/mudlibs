/* This is the Soul Food Cafe! */
/* the guitar is needed for the collector quest! */
inherit "std/pub";

int flag;

void create() {
	::create();
	SetIntShort("The Soul Food Cafe");
	SetIntLong(
"You are standing inside the famous Soul Food Cafe.\n"+
"There are various drinks and foods available. To see what you "+
"can order, just type 'read menu'.\n"+
"There is an exit to the east.\n");
	AddRoomCmd("order","order");
        AddExit("east","./plaza");
        AddDrink("beer",3,2,2,0);
        AddDrink("coke",0,-1,6,0);
        AddDrink("sprite",10,0,10,0);
        AddDrink("whiskey",20,19,23,0);
        AddDrink("vodka",15,20,17,0);
        AddDrink("rum",35,30,29,0);
        AddDrink("coffee",0,-4,4,50);
        AddDrink("expresso",0,-7,2,130);
        AddFood("chips",5,5,0);
        AddFood("toast",8,8,0);
        AddFood("sausage",9,9,0);
        AddFood("steak",20,15,0);
        AddFood("chicken",30,20,0);
        flag=2; /* Matt can be called 2 times until he runs out of guitars */
}
        
        
order(str) {
	if (str == "4 chicken and a coke" || str == "four chicken and a coke") {
                AddItem("/d/archwiz/randyandy/mon/matt",1);
	        // BEGONE log_file("randyandy/randyandy.blues", ctime(time())+" "+this_player()->QueryName()+" calls Matt 'Guitar' Murphy.\n");
	        write("Matt 'Guitar' Murphy arrives.\n");
	        write("Matt 'Guitar' Murphy says: You must have met the Blues Brothers!\n");
	        if (flag>0) {
		       write("Matt 'Guitar' Murphy says: Take my guitar and become happy!\n");
                       AddItem("/d/archwiz/randyandy/obj/guitar",1);
	               write("Matt Murphy lays a guitar on the floor.\n");
	               // BEGONE log_file("randyandy/randyandy.blues", ctime(time())+" ... and recieves a guitar.\n");
	               flag=flag-1;
                       return 1;
                } else { 
                       write("Matt 'Guitar' Murphy says: Unfortunately you are not the first today.\nMatt 'Guitar' Murphy says: I have no guitar left for you.\n");
                       return 1;
                       }
	      } else {
                     ::_porder(str);
		     return 1;
		     }
}
