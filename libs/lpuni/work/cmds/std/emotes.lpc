//emotes command

//Parthenon @ LPUniversity
//28-JUN-06
//General Command

//Last edited on June 28th, 2006 by Parthenon

string *singled_emotes = ({});

void fix_array(string *arr);
void print_emotes(string *emotes);

int main(string arg)
{
    string *emotes;

    emotes = ({});
    emotes = SOUL_D->query_emotes();

    if(!emotes)
    return notify_fail("Error [emotes]: There are no emotes available\n");

    singled_emotes = ({});
    fix_array(emotes);

    write(HIW + "\nAvailable emotes:\n" + NOR);

    //for(i = 0; i < sizeof(singled_emotes); i++)
    //    write(singled_emotes[i]+"\n");

    print_emotes(singled_emotes);

    return 1;
}

void print_emotes(string *emotes)
{
    int i, num_full_rows, num_extras, index;
    int new_line = 0, row_count = 0, column_count = 0;
    int *indexes_printed = ({});
    int tmp = 1, need_to_add;
    string *all_emotes = SOUL_D->query_emotes();

    num_full_rows = sizeof(emotes) / 4;
    num_extras = sizeof(emotes) % 4;

    if(num_extras)
    need_to_add = 1;

    for(i = 0; i < sizeof(emotes); i++)
    {
    if(new_line >= 4)
    {
        write("\n");
        new_line = 0;
        row_count++;
        column_count = 0;
    }

    if(sizeof(indexes_printed) >= 4)
    {
        index = indexes_printed[column_count]+row_count;

        if(index > sizeof(emotes) - 1)
        continue;

        if((member_array(emotes[index]+"/t", all_emotes) != -1) && (member_array(emotes[index], all_emotes) != -1))
        printf("%%^BOLD%%^%%^GREEN%%^%-15s%%^RESET%%^", emotes[index]);
        else if((member_array(emotes[index], all_emotes) != -1))
        printf("%%^BOLD%%^%%^CYAN%%^%-15s%%^RESET%%^", emotes[index]);
        else
        printf("%%^BOLD%%^%%^BLUE%%^%-15s%%^RESET%%^", emotes[index]);
    }
    else
    {
        if(i == 0)
        index = 0;
        else
        {
        if(need_to_add)
        {
            if(num_extras)
            {
            index = row_count * column_count + num_full_rows * column_count + tmp;
            num_extras--;
            tmp++;
            }
            else
            index = row_count * column_count + num_full_rows * column_count + tmp;
        }
        else
            index = row_count * column_count + num_full_rows * column_count;
        }

        if((member_array(emotes[index]+"/t", all_emotes) != -1) && (member_array(emotes[index], all_emotes) != -1))
        printf("%%^BOLD%%^%%^GREEN%%^%-15s%%^RESET%%^", emotes[index]);
        else if((member_array(emotes[index], all_emotes) != -1))
        printf("%%^BOLD%%^%%^CYAN%%^%-15s%%^RESET%%^", emotes[index]);
        else
        printf("%%^BOLD%%^%%^BLUE%%^%-15s%%^RESET%%^", emotes[index]);

        indexes_printed += ({ (index) });
    }

    new_line++;
    column_count++;
    }

    write("\n\n" + HIC + "*Cyan* " + NOR + "untargeted only.\n");
    write(HIB + "*Blue* " + NOR + "targeted only.\n\n");
}


int alphabetize(string arg1, string arg2)
{
    return strcmp(arg1, arg2);
}

void fix_array(string *arr)
{
    int i;

    for(i = 0; i < sizeof(arr); i++)
    {
    if(arr[i][<2..<1] == "/t")
        arr[i] = arr[i][0..<3];

    if(member_array(arr[i], singled_emotes) == -1)
        singled_emotes += ({ arr[i] });
    }

    singled_emotes = sort_array(singled_emotes, "alphabetize");
}

string help()
{
    return(HIW + " SYNTAX: " + NOR + "emotes\n\n" +
      "This command allows you to see all of the emotes available for you\n"+
      "to use.\n\n"+
      HIW + "See also: " + NOR + "emote\n");
}

