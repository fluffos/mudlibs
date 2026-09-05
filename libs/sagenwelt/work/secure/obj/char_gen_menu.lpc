/// @file char_gen_menu.c
/// @brief menu driven character generation/extension
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2016-02-02

#include <std_paths.h>
#include <race_d.h>

inherit M_MENU;

private MENU        main_menu;

private mapping     races;
private MENU        race_menu;
private MENU_ITEM   race_selected;

private mapping     genders;
private MENU        gender_menu;
private MENU_ITEM   gender_selected;

private mapping     player_info;
private function    call_back;      // call back function to be called after
                                    // all information is gathered

// once we've gathered everything we inform our caller and terminate
private void finished(void)
{
    evaluate(call_back, player_info);
    quit_menu_application();
}

// check if choosen race allows given gender
private int check_race(string gender)
{
    string race;

    if((race = player_info[MI_PI_RACE]) == "")  // no choosen race
        return TRUE;                            // => all genders allowed
    else if(member_array(gender, races[race][]))                // gender allowed
        return TRUE;
    return FALSE;                               // everything else forbidden
}

// check if choosen gender allows given race
private int check_gender(string race)
{
    string gender;

    if(!(gender = player_info[MI_PI_GENDER]))   // no choosen gender
        return TRUE;                            // => all races allowed
    else if(genders[gender][race])              // race allowed
        return TRUE;
    return FALSE;                               // everything else forbidden
}

// check if everything is gathered, if so we allow finished to be called
private int check_finished(void)
{
    if(                                     // we need:
       player_info[MI_PI_NAME]   == ""  ||  // a name
       player_info[MI_PI_PWD]    == ""  ||  // a password
       player_info[MI_PI_RACE]   == ""  ||  // a race
       player_info[MI_PI_GENDER] == ""      // the gender
      )
        return FALSE;                       // still missing something
    return TRUE;
}

// someone choose to logout during character generation....
private void logout(void)
{
    find_object(MUD_INFO_D)->unregister(TO, player_info[MI_PI_NAME]);
    environment()->quit();
    quit_menu_application();
}

private void help(string arg)
{
    string msg;

    switch(arg)
    {
        case "top":
            msg =
@END_HELP
For a new player it is mandatory to choose a race, a gender, a name and a password. Neither an email address, nor a web page is
necessary, although it is recommended to supply at least the email address!

If an email address is supplied and registered (the automatically send register email is answered) this email may be used to
either login, the password is still needed, or to reset a forgotten password. Without an email address a character with a
forgotten password is most likely lost!

The choosen race implies the base character values like strength, wisdom and so on, but also gives some perks, either positive
like the ability to see in the dark or negative like fear of open plains.  While most races have the 'normal' genders of
female/male some races might restricted to either one or might have a complete other set of genders available. As such as soon as
one chooses either a race or some gender the available choices for the other one will be restricted!  To circumvent any problems
with those choices it is recommended to visit the sub menus in the given order.

As soon as all mandatory choices are made the character may be finished. This last step in the character generation gives the
opportunity to slightly change both the base character values as well as the perks to individualize the character. Thereafter
neither race, gender or name may be changed anymore, while the character values and perks may be still changed through either
normal character development (most likely permanently) or the help of e.g. some spells or the participation in a adventurer group
(most likely temporary).

Either of password, email address and web page are available for change for as long as the character exists!
END_HELP ;
            break;
        case "race":
            msg =
@END_HELP
Here you might choose between any available race.

ATTENTION:
By choosing some gender before coming here said choice might be limited!

To get an overview of the capabilities of one race or another just choose it from the menu.
Depending on the given choices you might later either choose another race to change your selection or choose the same race a
second time to completely undo your choice.
END_HELP ;
            break;
        case "gender":
            msg =
@END_HELP
Depending on the choosen race, if any, you will be given a choice of available genders.

Furthermore depending on the given choices you might later either choose another gender to change your selection or choose the
same gender a second time to completely undo your choice.
END_HELP ;
            break;
        default:
            msg = "Huh??? Something is definitly wrong here... Somehow I don't know anything about <" + arg + ">...";
            break;
    }
    write(msg);
}

private void choose_race(string arg)
{
    if(player_info[MI_PI_RACE] == arg)
    {
        player_info[MI_PI_RACE] = "";
        set_menu_item_description(race_selected, "Selected: -");
    }
    else
    {
        player_info[MI_PI_RACE] = arg;
        set_menu_item_description(race_selected, "Selected: " + player_info[MI_PI_RACE]);
        write(races[arg][RD_RACE_INFO]);
    }
}

private void choose_gender(string arg)
{
    if(player_info[MI_PI_GENDER] == arg)
    {
        player_info[MI_PI_GENDER] = "";
        set_menu_item_description(gender_selected, "Selected: -")
    }
    else
    {
        player_info[MI_PI_GENDER] = arg;
        set_menu_item_description(gender_selected, "Selected: " + player_info[MI_PI_GENDER])
    }
}

private void create(void)
{
    int       idx;
    MENU_ITEM sep = new_seperator("");
    MENU_ITEM top = new_menu_item("Back", (: main_menu :), "b");

    init_eids();

    player_info = ([
            MI_PI_NAME  : = "",
            MI_PI_PWD   : = "",
            MI_PI_RACE  : = "",
            MI_PI_GENDER: = ""
            ]);

    main_menu    = new_menu(MUD_NAME + " CHARACTER GENEARATION");

    // main menu
    add_menu_item(main_menu, sep);
    add_menu_item(main_menu, new_seperator("Mandatory:"));
    add_menu_item(main_menu, new_menu_item("Race selection",   race_menu,         "r"));
    add_menu_item(main_menu, new_menu_item("Gender selection", gender_menu,       "g"));
    add_menu_item(main_menu, new_menu_item("Name selection",   (: name_menu :),   "n"));
    add_menu_item(main_menu, new_menu_item("Password",         (: password :),    "p"));
    add_menu_item(main_menu, sep);
    add_menu_item(main_menu, new_seperator("Optional:"));
    add_menu_item(main_menu, new_menu_item("eMail address",    (: email :),       "e"));
    add_menu_item(main_menu, new_menu_item("Web page",         (: homepage :),    "w"));
    add_menu_item(main_menu, sep);
    add_menu_item(main_menu, new_menu_item("Help",             (: help, "top" :), "h", 1));
    add_menu_item(main_menu, new_menu_item("Finished",         (: finished :),    "f", 0, (: check_finished :)));
    add_menu_item(main_menu, new_menu_item("Logout",           (: logout :),      "q"));

    // race selection menu
    race_menu    = new_menu("Race selection");
    add_menu_item(race_menu, sep);
    races = (mapping)RACES_D->get_races_map();
    idx   = 1;
    foreach(string entry in sort_array(keys(races), 1))
        add_menu_item(race_menu, new_menu_item(capitalize(entry), (: choose_race, entry :), idx++, 1, (: check_gender, entry :)));
    add_menu_item(race_menu, sep);
    add_menu_item(race_menu, race_selected = new_seperator("Selected: -"));
    add_menu_item(race_menu, new_menu_item("Help", (: help, "race" :), "h", 1));
    add_menu_item(race_menu, top);

    // gender selection menu
    gender_menu  = new_menu("Gender selection");
    add_menu_item(gender_menu, sep);
    gender = (mapping)RACES_D->get_gender_map();
    idx    = 1;
    foreach(string entry in sort_array(keys(gender), 1))
        add_menu_item(gender_menu, new_menu_item(capitalize(entry), (: choose_gender, entry :), idx++, 0, (: check_race, entry :)));
    add_menu_item(gender_menu, sep);
    add_menu_item(gender_menu, gender_selected = new_seperator("Selected: -"));
    add_menu_item(gender_menu, new_menu_item("Help", (: help, "gender" :), "h", 1));
    add_menu_item(gender_menu, top);
}

public void start_menu(mapping p_info, function cb)
{
    player_info = p_info;
    call_back   = cb;
    init_menu_application(main_menu);
}

// event handler
public void event_destruct(void)
{
    if(origin() != ORIGIN_EFUN)
        return;
    // someone destructed us :(
    write("\nSorry, but someone is playing around with the login process...\nPlease try again in a few minutes...\n");
    logout();
    destruct();
}

public void event_shutdown(void)
{
    if(origin() != ORIGIN_EFUN)
        return;
    destruct();
}
