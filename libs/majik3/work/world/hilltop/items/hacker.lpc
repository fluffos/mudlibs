inherit ITEM;

string answer;

string *questions;
int i=0, yes, no, que, score;
string owned;


get ()
{
    return 1;
}

create_item ()
{
    set_name (({ "test", "scroll" }));
    set_long (
      "This scroll obviously contains infamous hacker test. You can "
      + "fill it by typing \"fill\". After you've done with it you can "
      + "\"rip\" it to pieces.\n");
    set_dimensions (1, 1, 20);
    set_weight (2);
    set_hp (1);
    set_max_hp (1);
    set_material ("paper");
}

short ()
{
    if (!owned)
	return "a long scroll labeled \"hacker test\"";
    else
	return owned+"'s long scroll labeled \"hacker test\"";
}

init ()
{
    add_action ("do_fill", "fill");
    add_action ("do_rip", "rip");
}

do_rip ()
{
    write ("You rip it to small pieces.\n");
    tell_room (environment(), capitalize(THIS->query_name()) + " rips "
      + short() + " to small pieces.\n", ({ THIS }));
    destruct (THOB);
    return 1;
}

do_fill ()
{
    if (owned && THIS->query_name() != owned)
    {
	write ("You should not mess "+owned+"'s test.\n");
	return 1;
    }

    if (!i)
	tell_room (environment(), capitalize(THIS->query_name()) + " " +
	  "begins answering questions in a hacker test.\n");
    else
	tell_room (environment(), capitalize(THIS->query_name()) + " " +
	  "continues answering questions in a hacker test.\n");

    questions = explode(read_file ("/data/purity/hacker.1"), "\n");

    owned = THIS->query_name();

    if (i)
	write ("You continue answering questions in the hacker test.\n\n");
    else
	write ("You begin answering questions in the hacker test.\n\n");

    do_answer ();
    return 1;
}

do_end ()
{
    score = no*100/que;
    printf ("You answered "+yes+" times yes and "+no+" times no which makes\n"+
      "your score to be: "+score+" %% == 0x%03X\n\n", no);
    cat ("/data/purity/hacker.2");
    write_file ("/data/purity/hacker.3", THIS->query_name() + " " + no + "\n");
    tell_room (environment(), capitalize(THIS->query_name()) + " " +
      "finishes a hacker test with total score of "+no+" ("+score+" %) points.\n");
    return 1;
}

do_answer ()
{
    i++;
    if (i >= sizeof(questions)) {
	do_end ();
	return 1;
    }
    if (answer == "q")
    {
	answer = "";
	return 1;
    }

    if (questions[i][0] == '[')
    {
	message ("topic", "\n^c1" + questions[i][2..strlen(questions[i])-2] +"^c0\n\n", THIS);
	do_answer();
    }
    else
    {
	write (questions[i][2..strlen(questions[i])-2] + "\n(y/n/q): ");
	que++;
	input_to ("do_answer_input");
	return 1;
    }
    return 1;
}

do_answer_input (string str)
{
    answer = str;
    if (answer == "y")
    {
	yes++;
    }
    else if (answer == "q")
    {
    }
    else
    {
	no++;
    }
    do_answer ();
    return 1;
}
