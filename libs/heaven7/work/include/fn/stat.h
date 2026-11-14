#ifndef MUD_H
#define MUD_H

/* status stuff */

string stat_player(object arg);
void stat_monster(object arg);
void stat_container(object arg);
void stat_object(object arg);
void stat_other(object arg);
void stat_weapon(object arg);
void stat_armour(object arg);
void stat_inventory(object ob);
void ans_stat_inventory(string ans);
protected string is_valid_ac(object ob);
string is_valid_wc(object ob);
string is_valid_mon(object ob);
varargs status stat_ob_list(object *ob, int ob_index);
status next_com(string str);
status stat_info(string str);


nosave object *object_list;
nosave int command_counter;


/**************************************************************************/
/**************************************************************************/
/* status stuff */

/* general object stats */

void stat_object(object ob) {
  string stat;
  string tmp;

  stat = "";
  stat += (ob->query_name())  
       ? "Id Name: "+(string)ob->query_name()
       : "Id Name: Unknown";
  stat += (function_exists("id",ob))
       ? "\n"
       : "->No id() function\n";
  stat += (ob->short()) 
       ? "Short Name: "+(string)ob->short()+"\n"
       : "Short Name: Invisible Object\n";
  tmp = "";
  tmp  += (environment(ob))
       ? "Environment: "+file_name(environment(ob))
       : "Environment: None";
  tmp  += (environment(ob) && environment(ob)->short())
       ? "->Short Name: "+environment(ob)->short()
       : "";
  stat += extract(tmp,0,75)+"\n";
  stat += (creator(ob))
       ? "Creator: "+creator(ob)+"\n"
       : "";
  stat += (ob->query_create_room())
       ? "Create Room: "+(string)ob->query_create_room()+"\n"
       : "";
  stat += "Object Id: "+file_name(ob)+"\n";
  stat += (ob->query_info()) 
       ? "Info: "+(string)ob->query_info()+"\n"
       : "";
  stat += (ob->query_enchanted())
       ? "Enchanted: Yes\n"
       : "";
  stat += (ob->query_modified()) 
       ? "Modified: "+(string)ob->query_modified()+"\n"
       : "";
  write(stat);
}


void stat_weapon(object ob) {
  string stat;

  stat = "";
  stat += "Object Type: Weapon,  Weapon Type: ";
/*
  switch((int)ob->query_type()) {
    case 1:
      stat += "Pierce\n";
    break;
    case 2: 
      stat += "Blunt\n";
    break;
    case 3:
      stat += "Slash\n";
    break;
    case 4:
      stat += "Range\n";
    break;
    default:
      stat += "General\n";
    break;
  }
*/
  stat += ((string)ob->query_type())
       ?  (string)ob->query_type()+"\n"
       :  "Unknown Type!\n";
  stat += "Weapon Class: "+(string)ob->weapon_class()+", "+is_valid_wc(ob)+"\n";
  stat += (ob->query_value())
       ? "Value: "+(string)ob->query_value()+" coins"
       : "Value: None!";
  stat += (ob->query_weight())
       ? ",  Weight: "+(string)ob->query_weight()+"\n"
       : ",  Weight: None!\n";
  stat += "Weapon Length: "+ob->query_length()+"\n";
  stat += (ob->query_wielded())
       ? "Weapon is wielded\n"
       : "";
  write(stat);
}

void stat_armour(object ob) {
  string stat;

  stat = "";
  stat += "Object Type: Armour,  Armour Type: "+ob->query_type()+"\n";
  stat += "Armour Class: "+(string)ob->armour_class()+", "+is_valid_ac(ob)+"\n";
  stat += (ob->query_value())
       ? "Value: "+(string)ob->query_value()+" coins"
       : "Value: None!";
  stat += (ob->query_weight()) 
       ? ",  Weight: "+(string)ob->query_weight()+"\n"
       : ",  Weight: None!\n";
  stat += (ob->query_worn())
       ? "Armour is being worn\n"
       : "";
  write(stat);
}


void stat_container(object ob) {
  string stat;

  stat = "";
  stat += "Object Type: Container\n";
  stat += "Carry Wt: "+(string)ob->query_weight()+"/"+
          (string)ob->query_max_weight()+"\n";
  stat += (ob->query_value())
       ? "Value: "+(string)ob->query_value()+" coins"
       : "Value: None!";
  stat += (ob->query_weight()) 
       ? ",  Weight: "+(string)ob->query_weight()+"\n"
       : ",  Weight: None!\n";
  write(stat);
}


void stat_food(object ob) {
  string stat;

  stat = "";
  stat += "Object Type: Food\n";
  stat += "Strength "+(string)ob->query_strength()+
            ",  Heal "+(string)ob->query_heal()+"\n";
  stat += (ob->query_value())
       ? "Value: "+(string)ob->query_value()+" coins"
       : "Value: None!";
  stat += (ob->query_weight()) 
       ? ",  Weight: "+(string)ob->query_weight()+"\n"
       : ",  Weight: None!\n";
  write(stat);
}

void stat_drink(object ob) {
  string stat;

  stat = "";
  stat += (ob->query_soft_drink())
       ? "Object Type: Soft Drink\n"
       : "Object Type: Alco Drink\n";
  stat += (ob->query_full())
       ? "Full  " 
       : "Empty  "; 
  stat += "Strength "+(string)ob->query_strength()+
            ",  Heal "+(string)ob->query_heal()+"\n";
  stat += (ob->query_value())
       ? "Value: "+(string)ob->query_value()+" coins"
       : "Value: None!";
  stat += (ob->query_weight()) 
       ? ",  Weight: "+(string)ob->query_weight()+"\n"
       : ",  Weight: None!\n";
  write(stat);
}

void stat_living(object ob) {
  string stat;

  stat = ""; 
  stat += (ob->query_npc()) 
       ? "Object Type: Monster\n"
       : ((ob->query_security_level()) ? "Object Type: Wizard\n"
                                       : "Object Type: Player\n");

  stat += "Level: "+(string)ob->query_level()+
          ", Align: "+(string)ob->query_al()+
          ", Hp: "+(string)ob->query_hp()+"/"+(string)ob->query_max_hp()+
/*
          ", Sp: "+(string)ob->query_sp()+"/"+(string)ob->query_max_sp()+"\n";
*/
          "\n";
    
  stat += "Wc: "+(string)ob->query_wc()+
          ", LWc: "+(string)ob->query_left_wc()+
          ", Ac: "+(string)ob->query_ac()+
          ", Carry Wt: "+(string)ob->query_weight()+" lbs"+
          ", Guild: "+(string)ob->query_guild_string()+
          ", Race: "+(string)ob->query_race()+"\n";

  stat += "Str: "+(string)ob->query_strength()+
              "/"+(string)ob->query_max_strength()+
          "  Int: "+(string)ob->query_intelligence()+
                "/"+(string)ob->query_max_intelligence()+ 
          "  Wis: "+(string)ob->query_wisdom()+
                "/"+(string)ob->query_max_wisdom()+ 
          "  Dex: "+(string)ob->query_dexterity()+
                "/"+(string)ob->query_max_dexterity()+
          "  Con: "+(string)ob->query_constitution()+
                "/"+(string)ob->query_max_constitution()+
          "\n";


/*
  stat += "Str: "+(string)ob->query_strength()+
          ",  Dex: "+(string)ob->query_dexterity()+
          ",  Wis: "+(string)ob->query_wisdom()+
          ",  Con: "+(string)ob->query_constitution()+
          ",  Chr: "+(string)ob->query_charisma()+
          "\n";
 */

  stat += (ob->query_invis())
       ? "Invis: Yes"
       : "Invis: No";
  stat += ",  Money: "+ob->query_money()+" Coins";
  stat += (ob->query_npc()) 
       ? ",  Valid Status: "+is_valid_mon(ob)+"\n"
       : "\n"+stat_player(ob);
  write(stat);
}

string stat_player(object ob) {
  string stat;

  stat = "";
  stat += "Real Name: "+ob->query_real_name();
  stat += ",  Savings: "+ob->query_savings()+" Coins\n";
  return stat;
}

void stat_other(object ob) {
  string stat;

  stat = "";
  stat += (ob->query_value())
       ? "Value: "+(string)ob->query_value()+" coins"
       : "Value: None!";
  stat += (ob->query_weight())
       ? ",  Weight: "+(string)ob->query_weight()+"\n"
       : ",  Weight: None!\n";
  write(stat);
}


/* do a short stat on inventory */
#define INV_NUM 6     /* number of inventory items listed per page */

nosave int stat_num;
nosave object stat_ob;



void ans_stat_inventory(string ans) {
  if(ans == "n") {
    stat_num = 0;
    stat_ob = 0;
  }
  else {
    stat_num += (stat_num) ? INV_NUM : 3;
    stat_inventory(stat_ob);
  }
}


void stat_inventory(object ob) {
  int i;
  string stat;
  object *inv;

  stat_ob = ob;
  inv = all_inventory(ob);
  stat = "";

  if(sizeof(inv)){
    int block_size;

    stat += "<Inventory of "+((ob->query_name()) ? (string)ob->query_name()
                                                 : file_name(ob))+">:\n";
    block_size = (stat_num) ? INV_NUM : 3;
    for(i = stat_num; i < sizeof(inv) && i < stat_num + block_size; i++){
      stat += (inv[i]->short()) 
           ? "    Short Name: "+(string)inv[i]->short()+"->\n"
           : "    Short Name: Invisible Object->\n";
      stat += (inv[i]->query_name())
           ? "    Id Name: "+(string)inv[i]->query_name()+"->"
           : "    Id Name: Unknown Id Name->";
      stat += "Id: "+file_name(inv[i])+"\n";
      if(!living(inv[i])) {
       if(inv[i]->armour_class())
          stat += "    Status: "+is_valid_ac(inv[i])+"\n";
       if(inv[i]->weapon_class())
          stat += "    Status: "+is_valid_wc(inv[i])+"\n";
      }
      else{
        if(!inv[i]->query_npc()){
          stat += "    Level: "+inv[i]->query_level()+
                  ", Hp: "+inv[i]->query_hp();
/*
                  ", Sp: "+inv[i]->query_sp();
*/
          stat += (inv[i]->query_guild_string())
               ? ", Guild: "+inv[i]->query_guild_string()+"\n"
               : ", Guild: None\n";
          stat += (inv[i]->query_security_level())
               ? "    Player Status: Wizard"
               : "    Player Status: Player";
          stat += ", Wc: "+(string)inv[i]->query_wc();
          stat += ", LWc: "+(string)inv[i]->query_left_wc();
          stat += ", Ac: "+(string)inv[i]->query_ac();
          stat += ", Carry Wt: "+(string)inv[i]->query_weight();
          stat += ", Money: "+(string)inv[i]->query_money()+" coins\n"; 
        }
        else{
          stat += "    Status: "+is_valid_mon(inv[i])+"\n";
        }
      }
      stat += "\n";
    }
    write(stat);
    if(i < sizeof(inv)) {
      write("Continue Inventory (y/n) [y]: ");
      input_to("ans_stat_inventory");
    }    

    else {
      stat_num = 0;
      stat_ob = 0;
    }
  }
  else{
    write("<Inventory>: None.\n");
  }
}


/*** check for valid Armour Criteria ***/

protected string is_valid_ac(object ob){
  int val, ac, weight, ac_val, error;
  string *types, type;
  int *tmp, eflag;
  int aflag;
  string bad;
  mixed *ac_values;

  if(!(ob || ob->armour_class())) return 0;

/*** Legal Armour: values of 20000 & 0 indicate illegal values */

/* price[armour_class(vertical)][weight(horizontal)] */

   ac_values = 
      ({ ({   300,   200,   130,    90,   60,     0,    0,    0 }),
         ({   900,   600,   400,   260,   175,    0,    0,    0 }),
         ({ 20000,  2500,  1700,  1200,   800,  550,    0,    0 }),
         ({ 20000, 20000,  5600,  3750,  2500, 1600, 1000,    0 }),
         ({ 20000, 20000, 20000,  9000,  6000, 4000, 2600, 1700 }),
         ({ 20000, 20000, 20000, 20000, 10000, 6500, 4300, 2800 }), });

/*** Actual Armour Stats ***/

  ac = (int)ob->armour_class() - 1;
  weight = (int)ob->query_weight() - 1;
  val = (int)ob->query_value();

/*** Messages ***/

  bad = "Illegal Armour!! (";

/*** Test the armour (20% error) ***/

  if(ac < 0 || ac > 5){
    eflag = 1;
    bad += "ac: "+(ac+1);
  } 
  if(weight < 0 || weight > 7){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "W: "+(weight+1);
  } 
  if(eflag) aflag = 1;
  if(val < 1 || val > 15000){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "V: "+val;
  }
  if(!aflag){
    tmp = (int *)ac_values[ac];
    ac_val = tmp[weight];
    if(!ac_val || ac_val == 20000){
      if(eflag) bad += ", ";
      eflag = 1;
      bad += "ac/weight bad";
    }
    error = ac_val/5;
    if( val < ac_val - error || val > ac_val + error){ 
      if(eflag) bad += ", ";
      eflag = 1;
      bad += "V: "+val+"=>"+ac_val;
    }
  }

/* legal armour types */

  types = ({ "amulet","armour","boots","cloak","gloves","helm",
             "ring","shield" });
  type = (string)ob->query_type();
  if(member_array(type,types) < 0){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "type: "+type;
  }
  if(type != "armour" && ac > 1){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "Illegal ac";
  }
  if(type != "armour" && ac && !ob->query_sell_destruct()){
    if(eflag) bad += ", ";

    eflag = 1;
    bad +=  "No sell Destruct";
  }
  bad += ")";
  if(eflag) return bad;
  return "Valid Armour";
}


/*** check for valid Weapon Criteria ***/

string is_valid_wc(object ob){
  int val, wc, weight, wc_val, error;
  int *tmp, eflag;
  int aflag;
  string bad;
  mixed *wc_values;

  if(!(ob || ob->weapon_class())) return 0;

/*** Legal Weapons: values of 20000 & 0 indicate illegal values ***/

/* price[weapon_class(Vertical)][weight(horizontal)] */

   wc_values = ({
      ({    20,    16,    12,    10,    0,     0,    0,    0,    0 }),
      ({    40,    32,    25,    20,     0,    0,    0,    0,    0 }),
      ({ 20000,    80,    64,    50,    40,    0,    0,    0,    0 }),
      ({ 20000,   140,   110,    90,    70,    0,    0,    0,    0 }),
      ({ 20000,   200,   160,   130,   100,    0,    0,    0,    0 }),
      ({ 20000,   350,   280,   275,   180,    0,    0,    0,    0 }),
      ({ 20000, 20000,   500,   400,   320,  260,    0,    0,    0 }),
      ({ 20000, 20000,   800,   650,   520,  420,    0,    0,    0 }),
      ({ 20000, 20000,  1200,   960,   770,  620,    0,    0,    0 }),
      ({ 20000, 20000,  1700,  1300,  1100,  870,    0,    0,    0 }),
      ({ 20000, 20000, 20000,  2300,  1800, 1500, 1180,    0,    0 }),
      ({ 20000, 20000, 20000,  3100,  2500, 2000, 1600,    0,    0 }),
      ({ 20000, 20000, 20000,  4000,  3200, 2600, 2100,    0,    0 }),
      ({ 20000, 20000, 20000,  5000,  4000, 3300, 2600,    0,    0 }),
      ({ 20000, 20000, 20000, 20000,  6200, 4400, 3800, 3000,    0 }),
      ({ 20000, 20000, 20000, 20000,  7300, 5900, 5000, 4100,    0 }),
      ({ 20000, 20000, 20000, 20000,  8500, 7000, 6300, 5300,    0 }),
      ({ 20000, 20000, 20000, 20000, 10000, 9000, 7700, 6600,    0 }),
      ({ 20000, 20000, 20000, 20000, 20000,12000, 9600, 8200, 6700 }),
    });
    
    /*** Actual Weapon Stats ***/
  wc = (int)ob->weapon_class() - 3;
  weight = (int)ob->query_weight() - 1;
  val = (int)ob->query_value();

  /*** Messages ***/

  bad = "Illegal Weapon!! (";

/*** Test Weapon (20% error) ***/

  if(wc < 0 || wc > 18){
    eflag = 1;
    bad += "wc: "+(wc+3);
  } 
  if(weight < 0 || weight > 8){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "W: "+(weight+1);
  } 
  if(eflag) aflag = 1;
  if(val < 1 || val > 15000){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "V: "+val;
  }
  if(!aflag){
    tmp = (int *)wc_values[wc];
    wc_val = tmp[weight];
    if(!wc_val || wc_val == 20000){
      if(eflag) bad += ", ";
      eflag = 1;
      bad += "ac/weight bad";
    }
    error = wc_val/5;
    if(val < wc_val - error || val > wc_val + error){
      if(eflag) bad += ", ";
      eflag = 1;
      bad += "V: "+val+"=>"+wc_val;
    }
  }
  if(wc > 15 && !ob->query_sell_destruct()){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "No sell Destruct";
  }
  if(eflag) return bad;
  return "Valid Weapon";
}


/*** check for valid Monster Citeria ***/

string is_valid_mon(object ob){
  int lev, hp, wc, ac, tr;
  int mon_tot, tot_ac_wc;
  int error, eflag, wflag;
  string bad, warning;
  int *mon_hp, *mon_wc, *mon_ac, *mon_tr;
  if(!living(ob) || !ob->query_npc()) return 0;

/*** legal monster stats ***/

/* hit points */

    mon_hp = ({ 50,  55,  60,  70,  80,  95, 110,  130,  150,  175, 200,
               230, 260, 300, 350, 450, 600, 800, 1100, 1500, 1700 });

/* weapon class */

    mon_wc = ({ 5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
               15, 16, 17, 18, 20, 22, 24, 26, 27, 30, 30 });

/* armour class */

    mon_ac = ({ 3,  3,  4,  4,  5,  5,  6,  7,  7,  8,
                9,  9, 10, 11, 12, 13, 14, 15, 16, 17, 17 }); 

/* money */

    mon_tr = ({ 30,   60,  100,  150,  200,  250,  300,  350,  400,  700,
               900, 1200, 1400, 1700, 2000, 3000, 3500, 4000, 4600, 5000,
              5600 });

/*** warning messages ***/

  bad = "Illegal Monster!! (";
  warning = "Warning!! (";

/*** actual monster stats ***/

  lev = (int)ob->query_level() - 1;
  hp  = (int)ob->query_hp();
  wc  = (int)ob->query_wc();
  ac  = (int)ob->query_ac();
  tr  = (int)ob->query_money();

/*** lets do the tests (20% error) ***/

  if(lev < 0){
    eflag = 1;
    bad += "Level: 0";
    lev = 0;
  }
  if(lev > 20) lev = 20;

  error = mon_hp[lev]/5;
  if( mon_hp[lev] - error > hp){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "hp: "+hp+"=>"+mon_hp[lev];
  }
  if( mon_hp[lev] + error < hp){
    wflag = 1;
    warning += "hp: "+hp+"=>"+mon_hp[lev];
  }
  tot_ac_wc = wc + ac;
  mon_tot = mon_wc[lev] + mon_ac[lev];
  error = mon_tot/5;
  if(mon_tot - error > tot_ac_wc){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "ac: "+ac+"=>"+mon_ac[lev]+", wc: "+wc+"=>"+mon_wc[lev]+"  ";
  }
  if(mon_tot + error < tot_ac_wc){
    if(wflag) warning += ", ";
    wflag = 1;
    warning += "ac: "+ac+"=>"+mon_ac[lev]+", wc: "+wc+"=>"+mon_wc[lev];
  }
  if(mon_tr[lev] < tr){
    if(eflag) bad += ", ";
    eflag = 1;
    bad += "tr: "+tr+"=>"+mon_tr[lev];
  }
  bad += ")";
  warning += ")";
  if(eflag && wflag) return bad+"  "+warning;
  if(eflag) return bad;
  if(wflag) return warning;
  return "Valid Monster";
}


/* stat list */

status next_com(string str) {
  write("\n");
  if(str == "n") {
    command_counter = 0;
    object_list = ({});
    return 1;
  }
  command_counter += 1;
  stat_ob_list(object_list, command_counter);
  return 1;
}
 


status stat_ob_list(object *ob, int ob_index) {

  command_counter = ob_index;

  if(!ob[ob_index]) return 1;
  stat_object(ob[ob_index]);
  if(living(ob[ob_index])) {
    stat_living(ob[ob_index]);
  }
  else if(ob[ob_index]->query_alco_drink() 
       || ob[ob_index]->query_soft_drink()) {
    stat_drink(ob[ob_index]);
  }
  else if(ob[ob_index]->weapon_class()) {
    stat_weapon(ob[ob_index]);
  }
  else if(ob[ob_index]->armour_class()) {
    stat_armour(ob[ob_index]);
  }
  else if(ob[ob_index]->can_put_and_get()) {
    stat_container(ob[ob_index]);
  }
  else {
    stat_other(ob[ob_index]);
  }
  stat_inventory(ob[ob_index]);

  if(sizeof(ob) > 1 && command_counter + 1 < sizeof(ob)) {
    write("Next Object (y/n) [y]: ");
    input_to("next_com");
  }
  else {
    command_counter = 0;
    object_list = ({});
  }
  return 1;
}



/* status: stat an object for relevant info */

status stat_info(string str){
  object *ob;

  if(!str) {
    write("Usage: stat <object>\n\n"+
          "Notes: This shows important info contained by various objects\n"+
          "       It checks to see if the objects have valid values.\n");
    return 1;
  }
  if(!sizeof((ob = PROCESS_ARG(str)))) return 1;
  object_list = ob;
  stat_ob_list(ob,0);
  return 1;
}


/* end status */
#endif /* MUD_H */ 
