/* questtool.c
 * used by the admtool
 * Shaydz - 02 Apr '00
 */

#include <colors.h>
inherit COMMAND_BASE;

private mapping return_mapping = ([ ]);
private string main_menu_template = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s
  
  [1]  Create a New Quest                      %s

  [2]  Change quests level                     %s
  [3]  Change quests reward xp                 %s
  [4]  Change quests player title              %s
  [5]  Change quests player story              %s
  [6]  Change quests status                    %s
  
  [7]  Remove an Old Quest                     %s

  [8]  List the Current Registered Quests      %s

END;

private string main_prompt = "Enter your command [1-8], or [Q] to quit: ";
private string main_prompt2 = "Enter your command [1-8], [B] to go back, or [Q] to quit: ";

private string story, title;
private int level, xp;

// Function prototypes
mixed cmd(string args);
private void get_command(string str);
private void modify_level();
private void modify_level2(string str);
private void modify_level3(string str, string quest);
private void modify_xp();
private void modify_xp2(string str);
private void modify_xp3(string str, string quest);
private void modify_title();
private void modify_title2(string str);
private void modify_title3(string str, string quest);
private void modify_story();
private void modify_story2(string str);
private void modify_story3(string str, string quest);
private void modify_status();
private void modify_status2(string str);
private void del_quest1();
private void del_quest2(string str);
private void del_quest3(string str, string quest);
private void new_quest();
private void set_level1(string str);
private void set_xp(string str);
private void set_story1(string str);
private void set_title1(string str);
private void add_quest1(string str);
private void list_quests();


private void display_menu() {
    string title, s1, s2, s3, s4, s5, s6, s7, s8;

    title = sprintf("%s%|72s%s", YELLOW, mud_name()+" Quest Control Tool v1.6", RESET);

    s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = RED+"Unavailable"+RESET;

    if (lordp(TP)) {
        s1 = s7 = s8 = GREEN+"Available"+RESET;
    }
    if(adminp(TP)){
        s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = GREEN+"Available"+RESET;
    }  
    tell_object(TP, sprintf(main_menu_template, title, BOLD, RESET, s1, s2, s3, s4, s5, s6, s7, s8));
} /*display_menu()*/

private void modify_level() {
    tell_object(TP, "Enter the name of the quest to modify the level on: ");
    input_to((: modify_level2 :));
}  /*modify_level()*/

private void modify_level2(string str) {
    string *quests;

    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    quests = (mixed *)QUEST_H->query_quest_names();
    if (member_array(str, quests) == -1) {
        tell_object(TP, "That quest could not be found.\n");
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    tell_object(TP, "Enter new level of quest "+str+" (current level: "
                    +QUEST_H->query_quest_level(str)+"):");
    input_to((: modify_level3($1, $(str)) :));
} /*modify_level2()*/

private void modify_level3(string str, string quest) {
    int i;
    
    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    sscanf(str, "%d", level);
    
    if(level<1){
       tell_object(TP, "Level not changed, has to be a positive number.");
       tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
       input_to((: get_command :));
    }
    i = QUEST_H->set_quest_level(quest,level);
    if(i)   
       tell_object(TP, "Quest "+quest+" level set to "+level+".\n");
    else
       tell_object(TP, "Unable to change level for "+quest+".\n");
           
    tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
    input_to((: get_command :));

} /*modify_level3()*/

private void modify_xp() {
    tell_object(TP, "Enter the name of the quest to modify the xp reward on: ");
    input_to((: modify_xp2 :));
}  /*modify_xp()*/

private void modify_xp2(string str) {
    string *quests;

    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    quests = (mixed *)QUEST_H->query_quest_names();
    if (member_array(str, quests) == -1) {
        tell_object(TP, "That quest could not be found.\n");
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    tell_object(TP, "Enter new xp reward of quest "+str+" (current xp reward: "
                    +QUEST_H->query_quest_xp(str)+"):");
    input_to((: modify_xp3($1, $(str)) :));
} /*modify_xp2()*/

private void modify_xp3(string str, string quest) {
    int i;
    
    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    sscanf(str, "%d", xp);
    
    if(xp<1){
       tell_object(TP, "Xp reward not changed, has to be a positive number.");
       tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
       input_to((: get_command :));
    }
    i = QUEST_H->set_quest_xp(quest,xp);
    if(i)   
       tell_object(TP, "Quest "+quest+" xp set to "+xp+".\n");
    else
       tell_object(TP, "Unable to change xp reward for "+quest+".\n");
           
    tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
    input_to((: get_command :));

} /*modify_xp3()*/

private void modify_title() {
    tell_object(TP, "Enter the name of the quest to modify the players title on: ");
    input_to((: modify_title2 :));
}  /*modify_title()*/

private void modify_title2(string str) {
    string *quests;

    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    quests = (mixed *)QUEST_H->query_quest_names();
    if (member_array(str, quests) == -1) {
        tell_object(TP, "That quest could not be found.\n");
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    tell_object(TP, "Enter new title of quest "+str+" (current title: "
                    +QUEST_H->query_quest_title(str)+"):");
    input_to((: modify_title3($1, $(str)) :));
} /*modify_title2()*/

private void modify_title3(string str, string quest) {
    int i;
    
    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    i = QUEST_H->set_quest_title(quest,str);
    if(i)   
       tell_object(TP, "Quest "+quest+" title set to "+str+".\n");
    else
       tell_object(TP, "Unable to change title for "+quest+".\n");
           
    tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
    input_to((: get_command :));

} /* modify_title3()*/

private void modify_story() {
    tell_object(TP, "Enter the name of the quest to modify the story on: ");
    input_to((: modify_story2 :));
}  /* modify_story()*/

private void modify_story2(string str) {
    string *quests;

    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    quests = (mixed *)QUEST_H->query_quest_names();
    if (member_array(str, quests) == -1) {
        tell_object(TP, "That quest could not be found.\n");
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    tell_object(TP, "Enter new story of quest "+str+" (current story: "
                    +QUEST_H->query_quest_story(str)+"):");
    input_to((: modify_story3($1, $(str)) :));
} /* modify_story2()*/

private void modify_story3(string str, string quest) {
    int i;
    
    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    i = QUEST_H->set_quest_story(quest,str);
    if(i)   
       tell_object(TP, "Quest "+quest+" story to "+str+".\n");
    else
       tell_object(TP, "Unable to change story for "+quest+".\n");
           
    tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
    input_to((: get_command :));

} /*modify_story3()*/

private void modify_status() {
    tell_object(TP, "Enter the name of the quest to change the status on: ");
    input_to((: modify_status2 :));
}  /* modify_status()*/

private void modify_status2(string str) {
    string *quests;
    int i;

    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    quests = (mixed *)QUEST_H->query_quest_names();
    if (member_array(str, quests) == -1) {
        tell_object(TP, "That quest could not be found.\n");
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    i = QUEST_H->change_quest_status(str);
    tell_object(TP, "Quest "+str+" status changed to: "+(i?"active":"inactive")+".\n");
           
    tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
    input_to((: get_command :));

} /*modify_staus2()*/

private void del_quest1() {
    tell_object(TP, "Enter the name of the quest to remove: ");
    input_to((: del_quest2 :));
}  /*del_quest()*/

private void del_quest2(string str) {
    string *quests;

    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    quests = (mixed *)QUEST_H->query_quest_names();
    if (member_array(str, quests) == -1) {
        tell_object(TP, "That quest could not be found.\n");
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    tell_object(TP, "WARNING: You should not remove other peoples quests.\n"+
      "Are you sure you want to remove the quest "+str+" (Y/N): ");
    input_to((: del_quest3($1, $(str)) :));
} /*del_quest2()*/

private void del_quest3(string str, string quest) {

    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    str = lower_case(str);
    if (str == "y" || str == "yes") {
        if (QUEST_H->delete_quest(quest))
            tell_object(TP, GREEN+"\nThe quest "+quest+" was successfully removed.\n\n"+RESET);
        else
            tell_object(TP, BOLD+RED+"\nFailed to remove quest "+quest+".\n\n"+RESET);
    }else{
        tell_object(TP, BOLD+RED+"\nQuest wasn't removed.\n\n"+RESET);
    }
    tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
    input_to((: get_command :));
} /*del_quest3()*/

private void new_quest() {
    level = title = story = 0;
    tell_object(TP, "Enter the quests difficulty level: ");
    input_to((: set_level1 :));
}  /*new_quest()*/

private void set_level1(string str) {
    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    sscanf(str, "%d", level);
    tell_object(TP, "Quests difficulty level set to "+level+".\n");
    tell_object(TP, "Enter the quests xp reward: ");
    input_to((: set_xp :));
} /*set_level1()*/

private void set_xp(string str) {
    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    sscanf(str, "%d", xp);
    tell_object(TP, "Quests xp reward set to "+xp+".\n");
    tell_object(TP, "Enter the quests player title: ");
    input_to((: set_title1 :));
} /*set_level1()*/


private void set_title1(string str) {
    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    title = str;
    tell_object(TP, "Quests player title set to "+title+".\n");
    tell_object(TP, "Enter the quests story (description): ");
    input_to((: set_story1 :));
} /*set_title1()*/

private void set_story1(string str) {
    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }

    story = str;
    tell_object(TP, "Quest story set to "+story+".\n");
    tell_object(TP, "Enter the name of the NEW quest: ");
    input_to((: add_quest1 :));
} /*set_story1()*/


private void add_quest1(string str) {
    if (!str || str == "") {
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        return;
    }
    if (!level) {
        tell_object(TP, "You must set the quests Level first.\n");
        input_to((: get_command :));
        return;
    }
    if (!xp) {
        tell_object(TP, "You must set the quests xp first.\n");
        input_to((: get_command :));
        return;
    }
    if (!story) {
        tell_object(TP, "You must set the quests Story first.\n");
        input_to((: get_command :));
        return;
    }
    if (!title) {
        tell_object(TP, "You must set the quests Player Title first.\n");
        input_to((: get_command :));
        return;
    }  
    if (QUEST_H->add_quest(str, level, xp, title, story)) {
        tell_object(TP, GREEN+"Quest "+str+" added successfully.\n"+RESET);
        level = story = title = 0;
    } else {
        tell_object(TP, BOLD+RED+"Failed to register quest.\n"+RESET);
    }

    tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
    input_to((: get_command :));
} /*add_quest1()*/

private void list_quests() {
    string list;
    mixed *names;
    int i;

    list = "These are the Quests "+mud_name()+" has:\n\n";
    names = (mixed *)QUEST_H->query_quest_names();
    for (i=0; i<sizeof(names); i++) {
        list += "Quest "+(i+1)+"  \""+names[i]+"\", status "+
        (QUEST_H->query_quest_status(names[i])?"active":"inactive")+
        "\n        level:"+(int)QUEST_H->query_quest_level(names[i])+
        "  xp_reward: "+(int)QUEST_H->query_quest_xp(names[i])+
        "\n       title: "+(string)QUEST_H->query_quest_title(names[i])+
        "\n        story: "+(string)QUEST_H->query_quest_story(names[i])+"\n";
        if (i<sizeof(names)-1)
            list += "\n";
    }

    if (sizeof(names))
        TP->more_string(list, "Quest List", 1);
    else
        tell_object(TP, BOLD+RED+"\nThere are currently no quests registered.\n"+RESET);
    tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
    input_to((: get_command :));  
} /*list_quests()*/

private void get_command(string str) {
    if (!str) {
        display_menu();
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
    }

    switch(str) {
    case "1":
        new_quest();
        break;
    case "2":
        if(!adminp(TP)){
            tell_object(TP, BOLD+RED+"You are not authorised to use that option.\n"+RESET);
            input_to((: get_command :));  
            break;
        }
        modify_level();
        break;
    case "3":
        if(!adminp(TP)){
            tell_object(TP, BOLD+RED+"You are not authorised to use that option.\n"+RESET);
            input_to((: get_command :));  
            break;
        }
        modify_xp();
        break;
    case "4":
        if(!adminp(TP)){
            tell_object(TP, BOLD+RED+"You are not authorised to use that option.\n"+RESET);
            input_to((: get_command :));  
            break;
        }
        modify_title();
        break;
    case "5":
        if(!adminp(TP)){
            tell_object(TP, BOLD+RED+"You are not authorised to use that option.\n"+RESET);
            input_to((: get_command :));  
            break;
        }
        modify_story();
        break;
    case "6":
        modify_status();
        break;
    case "7":
        if(!adminp(TP)){
            tell_object(TP, BOLD+RED+"You are not authorised to use that option.\n"+RESET);
            input_to((: get_command :));  
            break;
        }
        del_quest1();
        break;
    case "8":
        list_quests();
        break;
    case "B": case "b":
      if (!return_mapping[TP]) {
        display_menu();
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        break;
      }
      if (return_mapping[TP]) {
        return_mapping[TP]->cmd("");
        map_delete(return_mapping, TP);
      }
      break;
    case "Q": case "q":
      break;
    default:
        display_menu();
        tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
        input_to((: get_command :));
        break;
    }
} /*get_command()*/

mixed cmd(string arg) {

    if (file_name(previous_object()) == "/secure/cmds/creator/admtools")
      return_mapping[TP] = previous_object();

    /* Initialise the global variables */
    level = 0;
    story = 0;
    title = 0;

    seteuid(geteuid(TP));
    display_menu();
    tell_object(TP, undefinedp(return_mapping[TP]) ? main_prompt : main_prompt2);
    input_to((: get_command :));
    return 1;
} /*cmd()*/

