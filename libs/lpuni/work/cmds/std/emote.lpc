//Simple emote command

//Tacitus @ LPUniversity
//02-APR-05
//General Command

//Last edited on October 8th, 2005 by Tacitus
//Last edited on June 19th, 2006 by Parthenon


#define TP this_player()
#define TPQN this_player()->query_name()
#define TPQCN capitalize(this_player()->query_name())


/********* GLOBALS ***************/
string *list_of_names_in_emote;
mixed *targeted_users;


/********* PROTOTYPES ***********/
void parse_living(string arg);
int get_users_targeted();
void print_emotes_to_targets(string arg, object *targets_to_print_to);
object *get_targets_to_print_to();


int main(string arg)
{
    object *targets_to_print_to;

    if (!arg)
    return notify_fail("Syntax: emote <message>\n");

    list_of_names_in_emote = ({});
    targeted_users = ({});
    targets_to_print_to = ({});

    if(strsrch(arg, "$") != -1)
    parse_living(arg);

    targets_to_print_to = get_targets_to_print_to();

    if(list_of_names_in_emote)
    if(!get_users_targeted())
        return 0;

    if(targets_to_print_to)
    {
    print_emotes_to_targets(arg, targets_to_print_to);
    return 1;
    }// END IF

    write("You emote: " + capitalize(this_player()->query_name()) + " " +
      arg + "\n");
    say (capitalize(this_player()->query_name()) + " " + arg + "\n");
    return 1;
}

string help()
{
    return(HIW + " SYNTAX:" + NOR + " emote <string>\n\n" +
      "This command allows you to do custom emotes. Example, if you\n" +
      "type 'emote smiles serenely' then the others in the room will\n" +
      "see '" + TPQCN + " smiles serenly.' You can also use people's names\n" +
      "who are present in the room. If you type 'emote smiles serenely\n" +
      "at $parthenon' and Parthenon is present, then Parthenon will see\n" +
      "'" + TPQCN + " smiles serenly at you.' and the room will see\n'" +
      TPQCN + " smiles serenely at Parthenon.' You may also use the\n" +
      "possessive form of the person's name like '$parthenon's' and\n" +
      "Parthenon will see 'your'.\n\n" +
      HIW + "See also: " + NOR + "say\n");
}


/********* FUNC IMPLEMENTATION ***********/
void parse_living(string arg)
{
    int i, j;
    string tmp, curr_item;
    string *tmp_array;

    tmp_array = explode(arg, " ");

    for(i = 0; i < sizeof(tmp_array); i++)
    {
    curr_item = tmp_array[i];

    if(curr_item[0] == '$')
    {

        for(j = sizeof(curr_item)-1; j > 0; j--)
        {
        if((curr_item[j] >= 65 && curr_item[j] <= 90) ||
          (curr_item[j] >= 97 && curr_item[j] <= 122))
        {
            tmp = curr_item[1..j];
            if(!list_of_names_in_emote)
            list_of_names_in_emote = ({ capitalize(tmp) });
            else
            list_of_names_in_emote += ({ capitalize(tmp) });

            break;
        }// END IF
        }// END FOR
    }// END IF
    }// NED FOR

    return;
}

int get_users_targeted()
{
    mixed *user_list_and_possessive = ({});
    object tmp;
    int i;

    for(i = 0; i < sizeof(list_of_names_in_emote); i++)
    {
    if(list_of_names_in_emote[i][<2..<1] == "'s")
    {
        tmp = present(lower_case(list_of_names_in_emote[i][0..<3]), environment(this_player()));

        if(!tmp)
        return notify_fail(capitalize(list_of_names_in_emote[i][0..<3]) + " is not present!\n");

        user_list_and_possessive += ({ tmp, 1 });
    }// END IF
    else if(list_of_names_in_emote[i][<2..<1] == "s'")
    {
        tmp = present(lower_case(list_of_names_in_emote[i][0..<2]), environment(this_player()));

        if(!tmp)
        return notify_fail(capitalize(list_of_names_in_emote[i][0..<2]) + " is not present!\n");

        user_list_and_possessive += ({tmp, 1 });
    }// END ELSE IF
    else
    {
        tmp = present(lower_case(list_of_names_in_emote[i]), environment(this_player()));         

        if(!tmp)
        return notify_fail(capitalize(list_of_names_in_emote[i]) + " is not present!\n");

        user_list_and_possessive += ({ tmp, 0 });
    }// END ELSE
    }// END FOR

    targeted_users = user_list_and_possessive;

    return 1;
}

void print_emotes_to_targets(string arg, object *targets_to_print_to)
{
    int i;
    string tmp_emote, tmp_name, tmp_emote2;
    string curr_target_name;
    object curr_target;
    object *exclude_list;

    arg = replace_string(arg, "$", "");
    tmp_emote = arg;

    for(i = 0; i < sizeof(targets_to_print_to); i++)
    {
    if(targets_to_print_to[i] == 0)
        targets_to_print_to -= ({ targets_to_print_to[i] });
    }// END FOR

    for(i = 0; i < sizeof(list_of_names_in_emote); i++)
    {
    tmp_name = list_of_names_in_emote[i];
    if(strsrch(tmp_emote, lower_case(list_of_names_in_emote[i])) != -1)
        tmp_emote = replace_string(tmp_emote, lower_case(list_of_names_in_emote[i]), tmp_name);
    }// END FOR

    tmp_emote2 = tmp_emote;

    if(tmp_emote2[<1..<1] != "." && tmp_emote2[<1..<1] != "!" && tmp_emote2[<1..<1] != "?")
    tmp_emote2 += ".";

    write("You emote: " + TPQCN + " " + tmp_emote2 + "\n");


    for(i = 0; i < sizeof(targets_to_print_to); i++)
    {
    tmp_emote2 = tmp_emote;
    curr_target = targets_to_print_to[i];
    curr_target_name = capitalize(curr_target->query_name());

    if(targeted_users[i+1] == 1 && curr_target_name[<1] == 's')
        tmp_emote2 = replace_string(tmp_emote2, curr_target_name + "'", "your");
    else if(targeted_users[i+1] == 1)
        tmp_emote2 = replace_string(tmp_emote2, curr_target_name + "'s", "your");
    else
        tmp_emote2 = replace_string(tmp_emote2, curr_target_name, "you");

    if((strsrch(tmp_emote2, TPQCN + "'s") != -1) || (strsrch(tmp_emote2, TPQCN + "'") != -1))
    {
        tmp_emote2 = replace_string(tmp_emote2, TPQCN + "'s", "his/her");
        tmp_emote2 = replace_string(tmp_emote2, TPQCN + "'", "his/her");
    }// END IF

    if(strsrch(tmp_emote2, TPQCN) != -1)
        tmp_emote2 = replace_string(tmp_emote2, TPQCN, "he/she");

    if(tmp_emote2[<1..<1] != "." && tmp_emote2[<1..<1] != "!" && tmp_emote2[<1..<1] != "?")
        tmp_emote2 += ".";

    tell_object(curr_target, TPQCN + " " + tmp_emote2 + "\n");
    }// END FOR


    tmp_emote2 = tmp_emote;

    if(tmp_emote2[<1..<1] != "." && tmp_emote2[<1..<1] != "!" && tmp_emote2[<1..<1] != "?")
    tmp_emote += ".";

    exclude_list = targets_to_print_to + ({ TP });

    tell_room(environment(TP), TPQCN + " " + tmp_emote + "\n", exclude_list);

    return;
}

object *get_targets_to_print_to()
{
    int i;
    object *tmp_array = ({});

    for(i = 0; i < sizeof(list_of_names_in_emote); i++)
    {
    if(member_array(find_living(lower_case(list_of_names_in_emote[i])), tmp_array) == -1)
        tmp_array += ({ find_living(lower_case(list_of_names_in_emote[i])) });
    }// END FOR

    tmp_array -= ({ TP });

    return tmp_array;
}

