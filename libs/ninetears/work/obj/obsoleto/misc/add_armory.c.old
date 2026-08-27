#include "weapon.h"
#include "armory.h"
inherit "/std/object";

#define CHECK if (!str || str == "") {\
                write("Aborted.\n");\
                do_next(); \
                return 1;\
              }

int do_next();
int edit_array();

int in_add,
    up_to,
    weapon;
string add_id,
       array_name,
       kind;
string thing_name, end_command;
mixed *data_array,
      tmp,
      *desc_array;

void setup() {
  reset_drop();
  set_name("adder");
  set_short("armory adder");
  add_adjective("armory");
  set_main_plural("armory adders");
  add_plural("adders");
  set_weight(40);
}

void setup_array()
{
  desc_array = ({
"What name do you want your "+kind+" to be called in the armory?\n"+
"Id : ", "get_id", 0,
"What name do you want to give your "+kind+" (NB: used the tables) ?\n"+
"Name : ", "get_name", 0,
"Please add any aliases you want.  Return on a blank line to end.\n"+
"Alias : ", "get_alias", "edit_alias",
"Please add any plurals you want.  Return on a blank line to end.\n"+
"Plural : ", "get_plural", "edit_plural",
"Please add any adjectives you want for your "+kind+".\n"+
"Adjective : ", "get_adjective", "edit_adjective",
"What is the short description of the "+kind+" ?\n"+
"Short : ", "get_short", 0,
"Just press return on the next line.  Input to it is ignored.\n"+
"What is the long description of the object (Entering ed)?\n",
"get_long", 0,
});
} /* setup_array */

void init() {
::init();
add_action("add", "add");
add_action("edit", "edit");
}

int add(string str) 
{
  kind = str;
  if (str != "weapon" && str != "armor") 
  {
     notify_fail("Usage: add <armor|weapon>\n");
     return 0;
  }
  setup_array();
  weapon = (str == "weapon");
  if(weapon)
     data_array = allocate(WEAP_A_SIZE + 1);
  else
     data_array = allocate(ARM_A_SIZE + 1);
  in_add = 1;
  up_to = -1;
/* I put the new improved method of handling it in here. */
  do_next();
  return 1;
}

int edit(string str) 
{
  if (str != "weapon" && str != "armor") 
  {
     notify_fail("Usage: edit <armor|weapon>\n");
     return 0;
  }
  weapon = (str == "weapon");
  write("What id of "+str+" do you wish to edit ? ");
  input_to("get_id");
  in_add = 0;
  data_array = 0;
  return 1;
}

int print_menu() {
string menu;
menu =  "a : Id\nb : Object Name\nc : Name\nd : Alias\ne : Plural\n"+
  "f : Adjective\ng : Short\nh : Long\n";
printf("%#*-s\n", this_player()->query_cols(), menu+"Quit\nSave\nMenu\n");
}

int do_next() 
{
  up_to ++;
  if (!data_array)
    if (in_add) 
    {
      write("Serious error.\n");
      return 1;
    } 
  else 
  {
      if (weapon)
        data_array = (mixed *)ARMORY->query_weapon(add_id);
      else
        data_array = (mixed *)ARMORY->query_armor(add_id);
      if (!data_array) 
      {
        write("Invalid armor/weapon name "+add_id+"\n");
        return 1;
      }
  }
  
  if (up_to >= sizeof(data_array))
      in_add = 0;
  if (!in_add) 
  {
    print_menu();
    write("Selection : ");
    input_to("do_choice");
    return 1;
  }
  if (!pointerp(desc_array[up_to*3])) 
  {
    if (data_array[up_to])
       printf("Is currently set to : %O\n", data_array[up_to]);
    write(desc_array[up_to*3]);
    input_to(desc_array[up_to*3+1]);
    return 1;
  } 
  
  else 
  {
    if (data_array[up_to])
       printf("Is currently set to : %O\n", data_array[up_to]);
    write(desc_array[up_to*3][weapon]);
    input_to(desc_array[up_to*3+1][weapon]);
    return 1;
  }
}

int do_choice(string str) {
  int i;

  str = lower_case(str);
  if (str == "menu") {
    print_menu();
    write("Selection : ");
    input_to("do_choice");
    return 1;
  }
  if (str == "quit") {
    write("Quitting.\n");
    return 1;
  }
  if (str == "save") {
    write("Saving.\n");
    if (weapon)
      ARMORY->add_weapon(add_id, data_array);
    else
      ARMORY->add_armor(add_id, data_array);
    return 1;
  }
  if (str[0] < 'a' || str[0] > 'n') {
    write("Invalid choice, try agian. (Menu to redraw menu)\n");
    write("Selection : ");
    input_to("do_choice");
    return 1;
  }
  i = str[0] - 'a';
  if (pointerp(desc_array[i*3])) {
    if (data_array[i])
      printf("Is currently set to : %O\n", data_array[i]);
    write(desc_array[i*3][weapon]);
    if (!desc_array[i*3+2][weapon])
      input_to(desc_array[i*3+1][weapon]);
    else
      call_other(this_object(), desc_array[i*3+2][weapon]);
  } else {
    if (data_array[i])
      printf("Is currently set to : %O\n", data_array[i]);
    write(desc_array[i*3]);
    if (!desc_array[i*3+2])
      input_to(desc_array[i*3+1]);
    else
      call_other(this_object(), desc_array[i*3+2]);
  }
  return 1;
}

int get_id(string str) {
  CHECK
  add_id = str;
  do_next();
  return 1;
}

int get_name(string str) {
  int *data;
  CHECK
  if(weapon)
  {
   if(!(data = "/table/weapon_table"->lookup_weapon_data(str)))
   {
    write("Illegal name "+str+" for your weapon.  Fatal error, aborting.\n");
    return 0;
   }  
  }
  else
   if(!(data = "/table/armor_table"->lookup_armor_data(str)))
   {
    write("Illegal name "+str+" for your armor. Fatal error, aborting.\n");
    return 0;
   }
  data_array[W_NAME] = str;
  do_next();
  return 1;
}


int get_short(string str) {
  CHECK
  data_array[W_SHORT] = str;
  do_next();
  return 1;
}

int get_long() {
  if (!data_array[W_LONG])
    data_array[W_LONG] = "";
  seteuid("tmp");
  rm("/tmp/long-"+this_player()->query_name());
  write_file("/tmp/long-"+this_player()->query_name(),
               sprintf("%-=*s", this_player()->query_cols(), data_array[W_LONG]));
  ed("/tmp/long-"+this_player()->query_name(), "end_long");
  return 1;
}

int end_long() {

  data_array[W_LONG] = read_file("/tmp/long-"+this_player()->query_name());
  data_array[W_LONG] = implode(explode(data_array[W_LONG],"\n")," ")+"\n";
  rm("/tmp/long-"+this_player()->query_name());
  seteuid("Room");
  do_next();
  return 1;
}

int get_alias(string str) {
  if (!tmp)
    tmp = ({ });
  if (!str || str == "") {
    data_array[W_ALIAS] = tmp;
    tmp = 0;
    do_next();
    return 1;
  }
  tmp += ({ str });
  write("Alias "+(sizeof(tmp)+1)+" : ");
  input_to("get_alias");
  return 1;
}

int edit_alias(string str) {
  thing_name = "aliases";
  end_command = "end_aliases";
  tmp = data_array[W_ALIAS];
  edit_array();
  return 1;
}

int end_aliases() {
  if (tmp)
    data_array[W_ALIAS] = tmp;
  tmp = 0;
  do_next();
  return 1;
}

int get_plural(string str) {
  if (!tmp)
    tmp = ({ });
  if (!str || str == "") {
    data_array[W_PLURALS] = tmp;
    tmp = 0;
    do_next();
    return 1;
  }
  tmp += ({ str });
  write("Plural "+(sizeof(tmp)+1)+" : ");
  input_to("get_plural");
  return 1;
}

int edit_plural(string str) {
  thing_name = "aliases";
  end_command = "end_plural";
  tmp = data_array[W_PLURALS];
  edit_array();
  return 1;
}

int end_plural() {
  if (tmp)
    data_array[W_PLURALS] = tmp;
  tmp = 0;
  do_next();
  return 1;
}

int get_adjective(string str) {
  if (!tmp)
    tmp = ({ });
  if (!str || str == "") {
    data_array[W_ADJ] = tmp;
    tmp = 0;
    do_next();
    return 1;
  }
  tmp += ({ str });
  write("Adjective "+(sizeof(tmp)+1)+" : ");
  input_to("get_adjective");
  return 1;
}

int edit_adjective(string str) {
  thing_name = "aliases";
  end_command = "end_adjectives";
  tmp = data_array[W_ADJ];
  edit_array();
  return 1;
}

int end_adjectives() {
  if (tmp)
    data_array[W_ADJ] = tmp;
  tmp = 0;
  do_next();
  return 1;
}

mixed get_val(string str) {
  int fixed, rand, die;

  if (sscanf(str, "%d+%dd%d", fixed, rand, die) == 3)
    return ({ fixed, rand, die });
  if (sscanf(str, "%d+%d", fixed, rand) == 2)
    if (rand)
      return ({ fixed, rand });
    else
      return ({ fixed });
  sscanf(str, "%d", rand);
  return rand;
}

int edit_array() {
  int i;

  for (i=0;i<sizeof(tmp);i++)
    printf("%2d %s\n", i, tmp[i]);
  write("Do you want to (A)dd, (R)emove, (C)hange, (Q)uit or (S)ave ? ");
  input_to("get_thingy");
  return 1;
}

int do_add_thing() {
  write("What "+thing_name+" do you wish to add ? ");
  input_to("get_add_thing");
  return 1;
}

int get_add_thing(string str) {
  if (!str || str == "")
    return edit_array();
  tmp += ({ str });
  write("Ok added "+str+" to "+thing_name+" list.\n");
  do_add_thing();
  return 1;
}

int do_remove_thing() {
  write("Which "+thing_name+" do you wish to remove (number or string) ? ");
  input_to("get_remove_thing");
  return 1;
}

int get_remove_thing(string str) {
  int i;

  if (!str || str == "")
    return edit_array();
  if (sscanf(str, "%d", i) == 1)
    if (i>=0 && i<sizeof(tmp)) {
      write("Removeing "+tmp[i]+"\n");
      tmp = delete(tmp,i,1);
    } else
      write("Invalid array index. (PS this in not a LPC error)\n");
  else
    if ((i=member_array(str,tmp)) == -1)
      write(str+" not a member of "+thing_name+" list.\n");
    else {
      write("Removeing "+tmp[i]+"\n");
      tmp = delete(tmp, i, 1);
    }
  do_remove_thing();
  return 1;
}

int do_change_thing() {
  write("Which "+thing_name+" do you wish to change ? ");
  input_to("get_change_thing1");
  return 1;
}

int i;
int get_change_thing1(string str) {
  if (!str || str == "")
    return edit_array();
  if (sscanf(str, "%d", i) == 1)
    if (i>=0 && i < sizeof(tmp)) {
      write("Ok changeing "+tmp[i]+" what do you want to change it too ? ");
      input_to("get_change_thing2");
      return 1;
    } else
      write("Invalid Index, (Frog?)\n");
  else
    if ((i=member_array(str, tmp)) == -1)
      write(str+" is not a member of "+thing_name+" list.\n");
    else {
      write("Ok changeing "+tmp[i]+" what do you want to change it too ? ");
      input_to("get_change_thing2");
      return 1;
    }
  do_change_thing();
  return 1;
}

int get_change_thing2(string str) {
  if (!str || str == "")
    return do_change_thing();
  write("Ok changed "+tmp[i]+" to "+str+".\n");
  tmp[i] = str;
  do_change_thing();
  i = 0;
  return 1;
}

int get_thingy(string str) {
  str = lower_case(str);
  if (str != "")
    switch(str[0]) {
      case 'a' :
        do_add_thing();
        return 1;
      case 'r' :
        do_remove_thing();
        return 1;
     case 'c' :
       do_change_thing();
       return 1;
     case 'q' :
       tmp = 0;
       call_other(this_object(), end_command);
       return 1;
    case 's' :
      call_other(this_object(), end_command);
      return 1;
   }
  write("Ivalid selection\n");
  edit_array();
  return 1;
}
