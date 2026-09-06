#define ROOM  "/d/archwiz/raistlin/rooms/stand1"

inherit "/std/room";
inherit "/lib/money";

#include <properties.h>
#include <attributes.h>     /* Physical attributes of livings */
#include <moving.h>
#include <secure/wizlevels.h>
#include <money.h>
#include <living.h>

object *maceaters; /* List of all MacEaters in the game */
#define MACEATER "/d/archwiz/raistlin/npc/maceater"
object *monsters;
object firstsay;

string *foodkind;
int *foodstuff;
int *foodsoak;
int *foodheal;
mixed *foodids;
string *foodlong;
string *foodshort;
int *foodvalue;
int *foodweight;

void create() {

    int i;
    string sign;

    ::create();

    SetIntLong ( 
        "You stand here in a line inside the McDonalds.\n"
        + "Because very many people visit this restaurant, "
        + "you are forced to stand in a line till it's your turn "
        + "to make your order...\n"
        + "Let's wait...\n"
        + "A big sign behind the counter shows the prices.\n");

    SetIntShort ("In a line in the McDonalds.");

    SetIntSmell("You smell the fried potatoes and the grilled ham in here.\n");
    SetIntNoise("You hear many people making their orders.\n");
    SetIndoors(1);

    AddExit("north","+archwiz/raistlin/rooms/entrance");
    sign =
    "             Mc Donalds price list:\n"
   +"BigMac:          45      Mayo/Ketchup:     3\n"
   +"Ham Royal:       47      Small pommes:    15\n"
   +"McRib:           45      Great pommes:    20\n"
   +"Hamburger:       22      Hot applepie:    18\n"
   +"Cheeseburger:    24      McSundae ice:    19\n"
   +"Fishmac:         31      McSundae cream:  12\n"
   +"Chicken  6:      42      Milkshake 0.3:   22\n"
   +"Chicken  9:      53      Milkshake 0.5:   33\n"
   +"Chicken 20:     105      Coke/Fanta 0.3:  16\n"
   +"Chef salad:      43          ''     0.4:  22\n"
   +"Mexicana salad:  43          ''     0.5:  27\n";
    AddDetail("sign", sign);
    AddReadMsg("sign", sign);

    foodkind = allocate(30);
    foodstuff = allocate(30);
    foodsoak = allocate(30);
    foodheal = allocate(30);
    foodids = allocate(30);
    foodlong = allocate(30);
    foodshort = allocate(30);
    foodvalue = allocate(30);
    foodweight = allocate(30);

    foodkind[0] = "food";
    foodvalue[0] = 45;
    foodstuff[0] = foodvalue[0]/5;
    foodsoak[0] = 0;
    foodheal[0] = foodvalue[0]/20;
    foodids[0] = ({"BigMac","bigmac","Bigmac"});
    foodlong[0] = "You see a big BigMac of McDonalds.\n";
    foodshort[0] = "A BigMac";
    foodweight[0] = 200;

    foodkind[1] = "food";
    foodvalue[1] = 47;
    foodstuff[1] = foodvalue[1]/5;
    foodsoak[1] = 0;
    foodheal[1] = foodvalue[1]/20;
    foodids[1] = ({"Ham Royal","royal"});
    foodlong[1] = "You see a Hamburger Royal with Cheese of McDonalds.\n";
    foodshort[1] = "A Hamburger Royal";
    foodweight[1] = 220;

    foodkind[2] = "food";
    foodvalue[2] = 45;
    foodstuff[2] = foodvalue[2]/5;
    foodsoak[2] = 0;
    foodheal[2] = foodvalue[2]/20;
    foodids[2] = ({"McRib","mcrib","rib"});
    foodlong[2] = "You see a McRib of McDonalds.\n";
    foodshort[2] = "A MacRib";
    foodweight[2] = 210;

    foodkind[3] = "food";
    foodvalue[3] = 22;
    foodstuff[3] = foodvalue[3]/5;
    foodsoak[3] = 0;
    foodheal[3] = foodvalue[3]/20;
    foodids[3] = ({"Hamburger","hamburger","burger"});
    foodlong[3] = "You see a small Hamburger of McDonalds.\n";
    foodshort[3] = "A small Hamburger";
    foodweight[3] = 130;

    foodkind[4] = "food";
    foodvalue[4] = 24;
    foodstuff[4] = foodvalue[4]/5;
    foodsoak[4] = 0;
    foodheal[4] = foodvalue[4]/20;
    foodids[4] = ({"Cheeseburger","cheeseburger","cheese"});
    foodlong[4] = "You see a Cheeseburger of McDonalds.\n";
    foodshort[4] = "A Cheeseburger";
    foodweight[4] = 140;

    foodkind[5] = "food";
    foodvalue[5] = 31;
    foodstuff[5] = foodvalue[5]/5;
    foodsoak[5] = 0;
    foodheal[5] = foodvalue[5]/20;
    foodids[5] = ({"Fishmac","fishmac","fish"});
    foodlong[5] = "You see a FishMac of McDonalds.\n";
    foodshort[5] = "A FishMac";
    foodweight[5] = 150;

    foodkind[6] = "food";
    foodvalue[6] = 42;
    foodstuff[6] = foodvalue[6]/5;
    foodsoak[6] = 0;
    foodheal[6] = foodvalue[6]/20;
    foodids[6] = ({"6 chicken","6 Chicken","chicken"});
    foodlong[6] = "You see a package of 6 Chicken McNuggets of McDonalds.\n";
    foodshort[6] = "6 Chicken McNuggets";
    foodweight[6] = 150;

    foodkind[7] = "food";
    foodvalue[7] = 53;
    foodstuff[7] = foodvalue[7]/5;
    foodsoak[7] = 0;
    foodheal[7] = foodvalue[7]/20;
    foodids[7] = ({"9 Chicken","9 chicken","chicken"});
    foodlong[7] = "You see a package of 9 Chicken McNuggets of McDonalds.\n";
    foodshort[7] = "9 Chicken McNuggets";
    foodweight[7] = 200;

    foodkind[8] = "food";
    foodvalue[8] = 105;
    foodstuff[8] = foodvalue[8]/5;
    foodsoak[8] = 0;
    foodheal[8] = foodvalue[8]/20;
    foodids[8] = ({"20 Chicken","20 chicken","chicken"});
    foodlong[8] = "You see a package of 20 Chicken McNuggets of McDonalds.\n";
    foodshort[8] = "20 Chicken McNuggets";
    foodweight[8] = 380;

    foodkind[9] = "food";
    foodvalue[9] = 43;
    foodstuff[9] = foodvalue[9]/5;
    foodsoak[9] = 0;
    foodheal[9] = foodvalue[9]/20;
    foodids[9] = ({"chef salad","salad"});
    foodlong[9] = "You see a Chef salad of McDonalds.\n";
    foodshort[9] = "A Chef salad";
    foodweight[9] = 210;

    foodkind[10] = "food";
    foodvalue[10] = 43;
    foodstuff[10] = foodvalue[10]/5;
    foodsoak[10] = 0;
    foodheal[10] = foodvalue[10]/20;
    foodids[10] = ({"mexicana salad","salad"});
    foodlong[10] = "You see a Mexicana salad of McDonalds.\n";
    foodshort[10] = "A Mexicana salad";
    foodweight[10] = 210;

    foodkind[11] = "food";
    foodvalue[11] = 3;
    foodstuff[11] = foodvalue[11]/5;
    foodsoak[11] = 0;
    foodheal[11] = foodvalue[11]/20;
    foodids[11] = ({"mayo","ketchup","Mayo","Ketchup"});
    foodlong[11] = "You see either a Mayo or some Ketchup of McDonalds.\n";
    foodshort[11] = "Ketchup or Mayo";
    foodweight[11] = 80;

    foodkind[12] = "food";
    foodvalue[12] = 15;
    foodstuff[12] = foodvalue[12]/5;
    foodsoak[12] = 0;
    foodheal[12] = foodvalue[12]/20;
    foodids[12] = ({"Small pommes","small pommes","pommes"});
    foodlong[12] = "You see a small pommes of McDonalds.\n";
    foodshort[12] = "A small pommes";
    foodweight[12] = 100;

    foodkind[13] = "food";
    foodvalue[13] = 20;
    foodstuff[13] = foodvalue[13]/5;
    foodsoak[13] = 0;
    foodheal[13] = foodvalue[13]/20;
    foodids[13] = ({"great pommes","Great pommes","big pommes","pommes"});
    foodlong[13] = "You see a great pommes of McDonalds.\n";
    foodshort[13] = "A great pommes";
    foodweight[13] = 140;

    foodkind[14] = "food";
    foodvalue[14] = 18;
    foodstuff[14] = foodvalue[14]/5;
    foodsoak[14] = 0;
    foodheal[14] = foodvalue[14]/20;
    foodids[14] = ({"applepie","Applepie"});
    foodlong[14] = "You see a Hot applepie of McDonalds.\n";
    foodshort[14] = "A hot applepie";
    foodweight[14] = 150;

    foodkind[15] = "food";
    foodvalue[15] = 19;
    foodstuff[15] = foodvalue[15]/5;
    foodsoak[15] = 0;
    foodheal[15] = foodvalue[15]/20;
    foodids[15] = ({"sundae","ice","mcsundae"});
    foodlong[15] = "You see a McSundae ice of McDonalds.\n";
    foodshort[15] = "A McSundae ice";
    foodweight[15] = 130;

    foodkind[16] = "food";
    foodvalue[16] = 12;
    foodstuff[16] = foodvalue[16]/5;
    foodsoak[16] = 0;
    foodheal[16] = foodvalue[16]/20;
    foodids[16] = ({"cream","mcsundae cream"});
    foodlong[16] = "You see a McSundae cream of McDonalds.\n";
    foodshort[16] = "A McSundae cream";
    foodweight[16] = 110;

    foodkind[17] = "drink";
    foodvalue[17] = 22;
    foodstuff[17] = 0;
    foodsoak[17] = foodvalue[17]/10;
    foodheal[17] = foodvalue[17]/20;
    foodids[17] = ({"shake 0.3","milkshake 0.3","shake","milkshake"});
    foodlong[17] = "You see a milkshake 0.3 of McDonalds.\n";
    foodshort[17] = "A milkshake 0.3";
    foodweight[17] = 300;

    foodkind[18] = "drink";
    foodvalue[18] = 33;
    foodstuff[18] = 0;
    foodsoak[18] = foodvalue[18]/10;
    foodheal[18] = foodvalue[18]/20;
    foodids[18] = ({"shake 0.5","milkshake 0.5","milkshake","shake"});
    foodlong[18] = "You see a milkshake 0.5 of McDonalds.\n";
    foodshort[18] = "A milkshake 0.5";
    foodweight[18] = 500;

    foodkind[19] = "drink";
    foodvalue[19] = 16;
    foodstuff[19] = 0;
    foodsoak[19] = foodvalue[19]/10;
    foodheal[19] = foodvalue[19]/20;
    foodids[19] = ({"coke 0.3","Coke 0.3","coke","Coke"});
    foodlong[19] = "You see a Coke 0.3 of McDonalds.\n";
    foodshort[19] = "A Coke 0.3";
    foodweight[19] = 300;

    foodkind[20] = "drink";
    foodvalue[20] = 22;
    foodstuff[20] = 0;
    foodsoak[20] = foodvalue[20]/10;
    foodheal[20] = foodvalue[20]/20;
    foodids[20] = ({"coke 0.4","Coke 0.4","Coke","coke"});
    foodlong[20] = "You see a Coke 0.4 of McDonalds.\n";
    foodshort[20] = "A Coke 0.4";
    foodweight[20] = 400;

    foodkind[21] = "drink";
    foodvalue[21] = 27;
    foodstuff[21] = 0;
    foodsoak[21] = foodvalue[21]/10;
    foodheal[21] = foodvalue[21]/20;
    foodids[21] = ({"coke","Coke","Coke 0.5","coke 0.5","big coke"});
    foodlong[21] = "You see a Coke 0.5 of McDonalds.\n";
    foodshort[21] = "A Coke 0.5";
    foodweight[21] = 500;

    maceaters = find_clones(MACEATER);
    monsters = ({});
    firstsay=0;

    call_out("create_maceater",30);
}

/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
*/
room_is_modified() {
    return 1;
}

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/
init() {
    ::init();
    add_action("do_examine", "examine");
    add_action("do_buy", "buy");
    add_action("do_buy", "order");
    /* added by Sique */
    return 1;
}


notify_enter(object oldenv, mixed method, mixed extra)
{
    object po;

    po=previous_object();
    if(living(po))
      monsters+=({po});




    if(firstsay!=monsters[0])
    {
	firstsay=monsters[0];
        call_out("notify_first",1);
    }

    return room::notify_enter(oldenv, method, extra);
}

notify_first()
{
    if(firstsay && firstsay->QueryIsPlayer())
        tell_object(firstsay, "\nIt's now your turn, "+capitalize(firstsay->QueryRealName())+". Order please.\n");
}

notify_leave(object dest, mixed method, mixed extra)
{
    int i;
    object po;
    po=previous_object();
    i=member(monsters, po);
    if(i>=0)
    {
	if(po->QueryIsPlayer())
            tell_object(po, "\nHave a nice day, "+capitalize(po->QueryRealName())+" and thanks for your visit.\n");

        monsters = monsters[0..i-1]+monsters[i+1..sizeof(monsters)];
    }

    return room::notify_leave(dest, method, extra);
}

create_maceater() {
    object *obj;
    object eater;

    int i,len;

    maceaters -= ({ 0 });
    
    obj=filter(all_inventory(),#'living);

    monsters = ({});
    len = sizeof(obj);

    for(i=0;i<len;i++)
        monsters += ({obj[len-i-1]});

    if (random(1000)<500 && len<10 && sizeof(maceaters) < 10) {
        eater = clone_object(MACEATER);
        eater->move(ROOM);
	maceaters += ({ eater });
        tell_room(ROOM,"A new Maceater enters the line...\n");
    }
    if (random(1000)<450 && len>0 && first()=="MacEater") {
	if(monsters[0]->QueryGoChance()==0)
	{
            tell_room(ROOM,"The maceater at the first position seems to have finally finished his buy.\n");
            i=random(21);
            monsters[0]->command_me("buy "+foodids[i][0]);
            monsters[0]->begin_move();
	}
    }

    if (len>0 && firstsay!=monsters[0]) {
        firstsay=monsters[0];
        if(firstsay)
          if(firstsay->QueryIsPlayer())
            tell_object(firstsay, "It's now your turn, "+capitalize(firstsay->QueryRealName())+". Order please.\n");
    }

    call_out("create_maceater",30);
    return 1;
}


query_monsters() { return monsters; }

query_monster(i) { return monsters[i]; }


string first() {
  if (monsters && pointerp(monsters) && monsters[0])
    if (present(monsters[0]))
        return monsters[0]->QueryName();
    return "";
}

do_examine(str) {
    if (str!="sign")
        return 0;
    write ("You just see a price list of the McDonalds...\n");
    return 1;
}

do_buy(str) {
    object food;
    int i;
    if (lower_case(first())!=lower_case(this_player()->QueryName())) {
        write ("The lady behind the counter says: 'It's not YOUR turn, man!'\n");
        return 1; }

    for (i=0;i<22;i++) {
        if (member(foodids[i], str)!=-1 ) {
           if (QuerySomeonesValue(this_player())<foodvalue[i]) {
                write ("You are not rich enough!\n");
                return 1; }
            food = clone_object("/d/archwiz/raistlin/obj/macfood");
            food->SetFoodKind(foodkind[i]);
            food->SetFoodStuff(foodstuff[i]);
            food->SetFoodSoak(foodsoak[i]);
	    food->SetFoodHeal(foodheal[i]);
            food->Set(P_IDS,foodids[i]);
            food->Set(P_LONG,foodlong[i]);
            food->Set(P_SHORT,foodshort[i]);
            food->Set(P_VALUE,foodvalue[i]);
	    food->Set(P_WEIGHT,foodweight[i]);
            if(food->move(this_player())==ME_TOO_HEAVY)
            {
                 /* destruct(food) */
                 /* For weight-adjusting */
                 food->remove();
                 /* done by Sique */
                    write("You can`t carry that much!!\n");
		    return 1;
	    }
            PayValue(this_player(),foodvalue[i]);
            write("You got " + food->QueryShort() + ".\n");
            say(this_player()->QueryName() + " got " + food->QueryShort() +
                ".\n");
            /* Communication added by Sique */
            return 1;
        }
    }
    write ("We don't serve that here!\n");
    return 1;
}
