/*
** healcalc.c
** Original by Fred - 2009
** Updated by Rumplemintz - 2014
*/

#include <ansi.h>

string choice;                                     /* What we chose in the main
                                                      menu */
int hp, sp, charges, soak, stuff, intox, rhp, rsp; /* Things we set */
int amt;                                           /* Amount we set the
                                                     'things' to */

/* Prototypes */
void mainmenu();
int get_heal_cost(int arg);
int calculate_cost();

int id(string str) {
  return str == "heal_calculator" || str == "heal_calc";
}

void reset(int arg) {
  if(arg) return;
  /* Reset all the variables to 0 */
  hp = sp = charges = soak = stuff = intox = rhp = rsp = 0;
}

int main() {    /* Called from 'healcalc' command */
  reset(0);     /* Reset the variables */
  mainmenu();   /* Call the menu */
}

void mainmenu() {
  write("\n\t\tHeal Cost Calculator (c) Fred 2009\n\n");
  write("\t[1] Set HP Amount per charge: (" + (hp ? hp : 0 ) + ")\n");
  write("\t[2] Set SP amount per charge: (" + (sp ? sp : 0) + ")\n");
  write("\t[3] Set number of charges: (" + (charges ? charges : 0) + ")\n");
  write("\t[4] Set soak amount per charge: (" + (soak ? soak : 0) + ")\n");
  write("\t[5] Set stuff amount per charge: (" + (stuff ? stuff : 0) + ")\n");
  write("\t[6] Set intox amount per charge: (" + (intox ? intox : 0) + ")\n");
  write("\t[7] Set random HP's per charge: (" + (rhp ? rhp : 0) + ")\n");
  write("\t[8] Set random SP's per charge: (" + (rsp ? rsp : 0) + ")\n\n");
  write("\t[r] Reset all values to 0\n");
  write("\t[c] Calculate the heal cost\n");
  write("\t[x] Exit\n\n");
  write("\t[1,2,3,4,5,6,7,8,r,c,x] ");
  input_to("get_choice1");
}

int dest_me() {
  destruct(this_object());
  return 1;
}

int set_it(string str) {
  if (!str) {
    mainmenu();
    return 1;
  }
  if (!intp(str))
#ifdef __LDMUD__
  {
    amt = to_int(str);
  }
#else
    sscanf(str, "%d", amt);
#endif

  if (amt < 0) {
    notify_fail("Value must be an integer > 0!\n");
    return 0;
  }
  switch(choice) {
  case "hp": hp = amt; break;
  case "sp": sp = amt; break;
  case "charges": charges = amt; break;
  case "soak"   : soak = amt; break;
  case "stuff"  : stuff = amt; break;
  case "intox"  : intox = amt; break;
  case "rhp"    : rhp = amt; break;
  case "rsp"    : rsp = amt; break;
  }
  mainmenu();
  return 1;
}

int get_amount(string str) {
  write("\tEnter the number of ");
  switch(str) {
  case "1": write("Hit Points per charge: "); choice = "hp"; break;
  case "2": write("Spell Points per charge: "); choice = "sp"; break;
  case "3": write("Charges: "); choice = "charges"; break;
  case "4": write("Soak per charge: "); choice = "soak"; break;
  case "5": write("Stuff per charge: "); choice = "stuff"; break;
  case "6": write("Intox per charge: "); choice = "intox"; break;
  case "7": write("Random HP's per charge: "); choice = "rhp"; break;
  case "8": write("Random SP's per charge: "); choice = "rsp"; break;
  }
  input_to("set_it");
  return 1;
}
  
int get_choice1(string str) {

  switch(str) {
  case "r":
    main();
    return 1;
    break;
  case "c":
    calculate_cost();
    return 1;
    break;
  case "x":
    dest_me();
    return 1;
    break;
  case "1":
  case "2":
  case "3":
  case "4":
  case "5":
  case "6":
  case "7":
  case "8":
    get_amount(str);
    return 1;
    break;
  default:
    mainmenu();
    return 1;
    break;
  }
  return 0; /* Should not happen */
}

int calculate_cost() {
  int healamt, rhealamt, toxamt, costlvl;
  int v, w, x, y, z;

  healamt = rhealamt = toxamt = costlvl = x = y = z = w = v = 0;

  if(hp == sp)
    healamt = (hp * charges);
  
  if(hp != sp) {
    if(!hp)
      healamt = (((sp * charges) * 2) / 3);
    if(!sp)
      healamt = (((hp * charges) * 2) / 3);
  }  

  if(rhp || rsp) {
    if(rhp == rsp)
      costlvl = healamt + ((((rhp + rsp) / 2) * charges) / 2);
    if(rhp != rsp) {
      if(!rsp)
        costlvl = healamt + ((rhp / 2) * charges); 
      if(!rhp)
        costlvl = healamt + ((rsp / 2) * charges);
    }
  }
 
  rhealamt = (rhp + rsp) / 2;

  toxamt = (((soak + stuff + intox) * charges) * 100);

  if(costlvl == 0 && healamt == 0) {
    mainmenu();
    write("\n\n\tMore information is needed to properly calculate the cost.\n");
    return 1;
  }

  if(costlvl)
    z = toxamt / costlvl;
  else
    z = toxamt / healamt;

  x = get_heal_cost(z);
  w = healamt * x;

  if(rhp || rsp)
    v = (((rhealamt * 2) * x) / 3);
  
  y = w + v;

  mainmenu();
  write("\n\n\tThe cost for this heal would be: "+y+" coins.\n");
  return 1;
}

int get_heal_cost(int arg) {
  int cost;

  switch(arg) {
    case 40..1000: cost = 8;   break;
    case 35..39:   cost = 10;  break;     
    case 31..34:   cost = 11;  break;
    case 28..30:   cost = 12;  break;
    case 26..27:   cost = 13;  break;
    case 24..25:   cost = 14;  break;
    case 22..23:   cost = 15;  break;
    case 20..21:   cost = 16;  break;
    case 18..19:   cost = 17;  break;
    case 16..17:   cost = 18;  break;
    case 14..15:   cost = 20;  break;
    case 12..13:   cost = 22;  break;
    case 8..11:    cost = 30;  break;
    case 0..7:     cost = 40;  break;
  }
  return cost;
}
