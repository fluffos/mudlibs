inherit ROOM;

string *eyetype = ({ "", "adorable", "beautiful", "dashing",
                     "penetrating" });

string *eyes = ({ "green", "deep green", "light green", "dark green",
                  "emerald green", "blue", "deep blue", "light blue",
                  "dark blue", "icy blue", "brown", "deep brown",
                  "light brown", "dark brown", "hazen brown", "grey",
                  "light grey", "amber", "purple" });

string *hairlength = ({ "very short", "short", "shoulder long", "long",
                        "very long" });

string *hairtype = ({ "straight", "slightly wavy", "wavy",
                      "slightly curly", "curly", "tangled" });

string *haircolor = ({ "brown", "hazel brown", "light brown",
                       "deep brown", "black", "blonde", "golden blonde",
                       "rich blonde", "red", "dark red", "fiery red" });

create_room ()
{
    set_light (1);
    set_no_explore (1);
    set_no_monster (1);
    set_no_wrap (1);

    set_short ("Race selection room");
    set_long (wrap (
      "You are standing in a race selection room where you need to "
    + "select a race for your new character. Please select your race "
    + "carefully because in the future getting reincarnation to a new "
    + "race might be very hard to get. Also remember the race affects "
    + "*many* things in your life in this world, example the starting "
    + "location is configured by the race you get.\n")
    + "\nAvailable commands are:\n"
    + "   races              - displays all available races\n"
    + "   info <race>        - gives you a long description of a race\n"
    + "   select <race>      - selects the race\n");
}

init_room ()
{
    add_action ("do_races", "races");
    add_action ("do_info", "info");
    add_action ("do_select", "select");
}

do_races ()
{
    this_player()->more_file("/data/race/racelist");
    return 1;
}

do_info (string str)
{
  string info;

  if (!str)
    {
      notify_fail ("Usage: info <race>\n");
      return 0;
    }

  if (file_size ("/data/race/"+str) > 0)
    {
      write ("-- "+upper_case(str)+" "+repeat_string("-", 74-strlen(str))+"\n\n");
      info = read_file ("/data/race/"+str);
      info = replace_string (info, "\n", " ");
      info = replace_string (info, "\r", "");
      write ("   " + wrap(info, 70, 3) + "\n\n");
      write (repeat_string("-", 78) + "\n");
    }
    else
    write (wrap("You selected race ("+str+") which does not exist. " +
           "Type \"races\" to see what races you can select.\n"));
    return 1;
}

do_select (string str)
{
    THIS->set_str (0);
    THIS->set_con (0);
    THIS->set_stu (0);
    THIS->set_siz (0);
    THIS->set_int (0);
    THIS->set_pow (0);
    THIS->set_wis (0);
    THIS->set_dex (0);
    THIS->set_agi (0);
    THIS->set_cha (0);
    THIS->set_alx (0);
    THIS->set_aly (0);

    THIS->set_random_hp (0);
    THIS->set_random_sp (0);
    THIS->set_random_ep (0);

    if (str == "ayura")
    {
     THIS->set_str (60);
     THIS->set_dex (40);
     THIS->set_agi (55);
     THIS->set_con (65);
     THIS->set_stu (65);
     THIS->set_siz (40 + random(10));
     THIS->set_int (45);
     THIS->set_pow (60);
     THIS->set_wis (75);
     THIS->set_cha (45);

     THIS->set("alx", 250);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024 * to_int((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70);

     THIS->set("race", "human");
     THIS->set("subrace", "ayura");

     THIS->set("max_age", (60*24*28*8)*90/3*5);
     THIS->set("age", (60*24*28*8)*17/3*5);

     write ("You are now one of the human tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "innohu")
    {
     THIS->set_str (65);
     THIS->set_dex (60);
     THIS->set_agi (60);
     THIS->set_con (85);
     THIS->set_stu (75);
     THIS->set_siz (50 + random(10));
     THIS->set_int (50);
     THIS->set_pow (65);
     THIS->set_wis (65);
     THIS->set_cha (40);

     THIS->set("alx", 0);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (to_int(((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70)*1024);

     THIS->set("max_age", (60*24*28*8)*90/3*5);
     THIS->set("age", (60*24*28*8)*17/3*5);

     THIS->set("race", "human");
     THIS->set("subrace", "innohu");

     write ("You are now one of the human tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "moraki")
    {
     THIS->set_str (85);
     THIS->set_dex (60);
     THIS->set_agi (65);
     THIS->set_con (75);
     THIS->set_stu (85);
     THIS->set_siz (50 + random(10));
     THIS->set_int (35);
     THIS->set_pow (50);
     THIS->set_wis (45);
     THIS->set_cha (45);

     THIS->set("alx", 250);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (to_int(((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70)*1024);

     THIS->set("max_age", (60*24*28*8)*60/3*5);
     THIS->set("age", (60*24*28*8)*16/3*5);

     THIS->set("race", "human");
     THIS->set("subrace", "moraki");

     write ("You are now one of the human tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "shaolu")
    {
     THIS->set_str (65);
     THIS->set_dex (70);
     THIS->set_agi (75);
     THIS->set_con (55);
     THIS->set_stu (55);
     THIS->set_siz (45 + random(10));
     THIS->set_int (50);
     THIS->set_pow (55);
     THIS->set_wis (60);
     THIS->set_cha (45);

     THIS->set("alx", -250);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*80/3*5);
     THIS->set("age", (60*24*28*8)*17/3*5);

     THIS->set("race", "human");
     THIS->set("subrace", "shaolu");

     write ("You are now one of the human tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "thari")
    {
     THIS->set_str (50);
     THIS->set_dex (50);
     THIS->set_agi (50);
     THIS->set_con (50);
     THIS->set_stu (50);
     THIS->set_siz (45 + random(10));
     THIS->set_int (50);
     THIS->set_pow (50);
     THIS->set_wis (50);
     THIS->set_cha (50);

     THIS->set("alx", 0);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str())* THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*150/3*5);
     THIS->set("age", (60*24*28*8)*18/3*5);

     THIS->set("race", "human");
     THIS->set("subrace", "thari");
 
     write ("You are now one of the human tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "yangir")
    {
     THIS->set_str (50);
     THIS->set_dex (55);
     THIS->set_agi (65);
     THIS->set_con (55);
     THIS->set_stu (55);
     THIS->set_siz (40 + random(10));
     THIS->set_int (55);
     THIS->set_pow (70);
     THIS->set_wis (60);
     THIS->set_cha (50);

     THIS->set("alx", 0);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*140/3*5);
     THIS->set("age", (60*24*28*8)*29/3*5);

     THIS->set("race", "human");
     THIS->set("subrace", "yangir");

     write ("You are now one of the human tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "yamar")
    {
     THIS->set_str (30);
     THIS->set_dex (60);
     THIS->set_agi (55);
     THIS->set_con (35);
     THIS->set_stu (30);
     THIS->set_siz (35 + random(10));
     THIS->set_int (95);
     THIS->set_pow (80);
     THIS->set_wis (70);
     THIS->set_cha (70);

     THIS->set("alx", 0);
     THIS->set("aly", 0);

     THIS->set_height (to_int(((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3)+30);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*190/3*5);
     THIS->set("age", (60*24*28*8)*39/3*5);

     THIS->set("race", "half-elf");
     THIS->set("subrace", "yamar");

     write ("You are now one of the half-elven tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "tilan")
    {
     THIS->set_str (60);
     THIS->set_dex (60);
     THIS->set_agi (60);
     THIS->set_con (60);
     THIS->set_stu (60);
     THIS->set_siz (50 + random(10));
     THIS->set_int (60);
     THIS->set_pow (60);
     THIS->set_wis (60);
     THIS->set_cha (60);

     THIS->set("alx", -250);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*150/3*5);
     THIS->set("age", (60*24*28*8)*19/3*5);

     THIS->set("race", "half-elf");
     THIS->set("subrace", "yamar");

     write ("You are now one of the half-elven tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "tanir")
    {
     THIS->set_str (50);
     THIS->set_dex (65);
     THIS->set_agi (70);
     THIS->set_con (50);
     THIS->set_stu (45);
     THIS->set_siz (45 + random(5));
     THIS->set_int (65);
     THIS->set_pow (65);
     THIS->set_wis (65);
     THIS->set_cha (65);

     THIS->set("alx", 0);
     THIS->set("aly", 0);

     THIS->set_height (to_int(((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3)+30);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*280/3*5);
     THIS->set("age", (60*24*28*8)*59/3*5);

     THIS->set("race", "elf");
     THIS->set("subrace", "tanir");

     write ("You are now one of the elven tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/welf/rooms/"+TIME_D->query_season());
    }
    else if (str == "dyanir")
    {
     THIS->set_str (50);
     THIS->set_dex (55);
     THIS->set_agi (65);
     THIS->set_con (45);
     THIS->set_stu (45);
     THIS->set_siz (45 + random(10));
     THIS->set_int (70);
     THIS->set_pow (85);
     THIS->set_wis (85);
     THIS->set_cha (70);

     THIS->set("alx", -750);
     THIS->set("aly", 0);

     THIS->set_height (to_int(((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3)+30);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*310/3*5);
     THIS->set("age", (60*24*28*8)*64/3*5);

     THIS->set("race", "elf");
     THIS->set("subrace", "dyanir");

     write ("You are now one of the elven tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "aindar")
    {
     THIS->set_str (65);
     THIS->set_dex (80);
     THIS->set_agi (80);
     THIS->set_con (65);
     THIS->set_stu (60);
     THIS->set_siz (45 + random(10));
     THIS->set_int (65);
     THIS->set_pow (50);
     THIS->set_wis (45);
     THIS->set_cha (70);

     THIS->set("alx", 501);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str())* THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*400/3*5);
     THIS->set("age", (60*24*28*8)*85/3*5);

     THIS->set("race", "elf");
     THIS->set("subrace", "aindar");

     write ("You are now one of the elven tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "lindor")
    {
     THIS->set_str (40);
     THIS->set_dex (60);
     THIS->set_agi (50);
     THIS->set_con (45);
     THIS->set_stu (40);
     THIS->set_siz (45 + random(10));
     THIS->set_int (95);
     THIS->set_pow (90);
     THIS->set_wis (75);
     THIS->set_cha (75);

     THIS->set("alx", 750);
     THIS->set("aly", 0);

     THIS->set_height (to_int(((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3)+40);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*465/3*5);
     THIS->set("age", (60*24*28*8)*98/3*5);

     THIS->set("race", "elf");
     THIS->set("subrace", "lindor");

     write ("You are now one of the elven tribe known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "faun")
    {
     THIS->set_str (70);
     THIS->set_dex (60);
     THIS->set_agi (75);
     THIS->set_con (70);
     THIS->set_stu (75);
     THIS->set_siz (45 + random(10));
     THIS->set_int (60);
     THIS->set_pow (65);
     THIS->set_wis (60);
     THIS->set_cha (75);

     THIS->set("alx", 0);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*123/3*5);
     THIS->set("age", (60*24*28*8)*17/3*5);

     THIS->set("race", "faun");
     THIS->set("subrace", 0);

     write ("You are now one of the mystic race known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "troll")
    {
     THIS->set_str (100);
     THIS->set_dex (40);
     THIS->set_agi (40);
     THIS->set_con (80);
     THIS->set_stu (90);
     THIS->set_siz (60 + random(20));
     THIS->set_int (40);
     THIS->set_pow (50);
     THIS->set_wis (40);
     THIS->set_cha (10);

     THIS->set("alx", -750);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int(((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70)+20);

     THIS->set("max_age", (60*24*28*8)*55/3*5);
     THIS->set("age", (60*24*28*8)*11/3*5);

     THIS->set("race", "troll");
     THIS->set("subrace", 0);

     write ("You are now one of the dark race known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "orc")
    {
     THIS->set_str (75);
     THIS->set_dex (60);
     THIS->set_agi (65);
     THIS->set_con (75);
     THIS->set_stu (75);
     THIS->set_siz (45 + random(10));
     THIS->set_int (40);
     THIS->set_pow (55);
     THIS->set_wis (60);
     THIS->set_cha (20);

     THIS->set("alx", -750);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int(THIS->query_stu() + THIS->query_str() * THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*67/3*5);
     THIS->set("age", (60*24*28*8)*14/3*5);

     THIS->set("race", "orc");
     THIS->set("subrace", 0);

     write ("You are now one of the dark race known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }

    else if (str == "dwarf")
    {
     THIS->set_str (65);
     THIS->set_dex (65);
     THIS->set_agi (70);
     THIS->set_con (95);
     THIS->set_stu (100);
     THIS->set_siz (25 + random(10));
     THIS->set_int (45);
     THIS->set_pow (60);
     THIS->set_wis (55);
     THIS->set_cha (45);

     THIS->set("alx", 750);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str())* THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*220/3*5);
     THIS->set("age", (60*24*28*8)*47/3*5);

     THIS->set("race", "dwarf");
     THIS->set("subrace", 0);

     write ("You are now one of the dwarven race known as The "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }

    else if (str == "gnome")

    {

     THIS->set_str (45);
     THIS->set_dex (75);
     THIS->set_agi (55);
     THIS->set_con (55);
     THIS->set_stu (45);
     THIS->set_siz (25 + random(10));
     THIS->set_int (80);
     THIS->set_pow (65);
     THIS->set_wis (65);
     THIS->set_cha (60);

     THIS->set("alx", 500);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int((THIS->query_stu() + THIS->query_str())* THIS->query_siz())/70);

     THIS->set("max_age", (60*24*28*8)*375/3*5);
     THIS->set("age", (60*24*28*8)*79/3*5);

     THIS->set("race", "gnome");
     THIS->set("subrace", 0);

     write ("You are now one of the dwarven race known as "+capitalize(str)+".\n");
     THIS->move_player ("/world/hilltop/rooms/room1");
    }
    else if (str == "halfling")
    {
     THIS->set_str (45);
     THIS->set_dex (95);
     THIS->set_agi (80);
     THIS->set_con (60);
     THIS->set_stu (55);
     THIS->set_siz (25 + random(10));
     THIS->set_int (45);
     THIS->set_pow (40);
     THIS->set_wis (65);
     THIS->set_cha (55);

     THIS->set("alx", 501);
     THIS->set("aly", 0);

     THIS->set_height (to_int((THIS->query_siz() * 7) + (THIS->query_str() * 3))/3);
     THIS->set_weight (1024*to_int(((THIS->query_stu() + THIS->query_str()) * THIS->query_siz())/70)+20);

     THIS->set("max_age", (60*24*28*8)*87/3*5);
     THIS->set("age", (60*24*28*8)*18/3*5);

     THIS->set("race", "halfling");
     THIS->set("subrace", 0);

write ("You are now one of the dwarven race known as "+capitalize(str)+".\n");

     THIS->move_player ("/world/hilltop/rooms/room1");

     }

    else

    {

     write (wrap("You selected race ("+str+") which does not exist. \n" +
            "Type 'races' to see what races you can select.\n"));

    }

    write ("\n\nYou are born male "+capitalize(str)+" "+THIS->query_race()+" You have "+eyetype[random(sizeof(eyetype))]+" "+eyes[random(sizeof(eyes))]+" and "+hairlength[random(sizeof(hairlength))]+" "+hairtype[random(sizeof(hairtype))]+" "+haircolor[random(sizeof(haircolor))]"+ hair.\n");

    THIS->set_random_hp (95 + random(10));
    THIS->set_random_sp (95 + random(10));
    THIS->set_random_ep (95 + random(10));

    THIS->set_hp (to_int((THIS->query_random_hp() * ((THIS->query_con()*2.75) + (THIS->query_stu() * 5) + (THIS->query_str() * 2)+(THIS->query_pow() * 2) + ((THIS->query_height() /15)*(THIS->query_weight()/1024/30))))/100));
    THIS->set_max_hp (THIS->query_hp());

    THIS->set_sp (to_int((THIS->query_random_sp() * ((THIS->query_pow() * 4) + (THIS->query_wis() * 3) + (THIS->query_int() * 3) + THIS->query_con()))/100));
    THIS->set_max_sp (THIS->query_sp());

    THIS->set_ep (to_int((THIS->query_random_ep() * ((THIS->query_con() * 3) + (THIS->query_str() * 2) + (THIS->query_pow() * 2) + THIS->query_agi() + THIS->query_stu())))/100);
    THIS->set_max_ep (THIS->query_ep());

    THIS->set_hunger_base (5000);
    THIS->set_thirst_base (5000);

    return 1;
}
