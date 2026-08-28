/*
 * MAJIK Online wizardhood application form
 * 
 * Coded by Dazzt
 * 
 * */

#include <security.h>

inherit ITEM;

int filled;
string filler;

string *main_1_strs = ({
  "Real name",
  "Street Address",
  "Postal Address",
  "Country",
  "Date of birth",
  "Your computer and operating system(s)",
  "Your E-Mail address",
  "Your homepage URL (if one)",
  "The name you wish to be called in MAJIK"
});

string *main_2_strs = ({
  "Do you know how to use UNIX shell?",
  "Why do you want to become a coder?",
  "Have you ever coded in a mud?",
  "What experience do you have from programming and LPC?",
  "Why should we have you as a coder?"
});

string *main_3_strs = ({
  "How much information about the game can you as coder give to mortal?",
  "Mortal tells you 'FUCK YOU!'. May you zap/dest/kill the mortal?",
  "Mortal one kills mortal two, who whines to you. Can you to zap the mortal one?",
  "Mortal is trapped in a bug room, and he can't get out. What can you do?",
  "May you ask levels from greater gods when you think you have earned them?",
  "Mortal is testing your area. How can you help the mortal?"
});

string *main_4_strs = ({
  "Write a description for 'a wedding chapel'",
  "Write a description for 'the jade battle axe of Kiy'",
  "Write a description for 'the helm of the winds'",
  "Write a description 'a mantis warrior, searching for prey'"
});

string *main_1_answers = allocate(sizeof(main_1_strs));
string *main_2_answers = allocate(sizeof(main_2_strs));
string *main_3_answers = allocate(sizeof(main_3_strs));
string *main_4_answers = allocate(sizeof(main_4_strs));

string sponsor;

set_answer1(string s, int idx) { main_1_answers[idx] = s; }
set_answer2(string s, int idx) { main_2_answers[idx] = s; }
set_answer3(string s, int idx) { main_3_answers[idx] = s; }
set_answer4(string s, int idx) { main_4_answers[idx] = s; }


init()
{
	add_action("info", "info");
    add_action("do_fill", "fill");
    add_action("do_rip", "rip");
    add_action("do_send", "send");
}

create_item()
{
    set_name(({"application", "form" }));
    set_short("Immortality application form");

    set_dimensions(5, 30, 10);
    set_weight(100);
    set_hp(10000);
    set_max_hp(10000);
    filled = 0;
}

string long()
{
    string str;

    str = "This form is made from some mysterious material, which emanates godly" +
    " power. It has something written to it. You can get 'info'rmation about wizardhood " +
		" and after that you can 'fill' it out. If you change your mind, you can" +
    " 'rip' the form into pieces. After you have filled this form you can 'send' it to" +
    " gods.\n";
    if (!filled)
	str += "It's empty.\n";
    else
	str += "It has been filled.\n";

    return str;
}

info()
{
    "/command/immortal/more"->main("/doc/misc/immortality.txt");
}

do_exit()
{
    write("\nApplication saved.\n");
    filled = 1;
    filler = THIS->query_name();
}

string temp;
string fun;
int idx;

string get_string(string s)
{
    call_other(THOB, "set_answer" + temp, s, idx);
    call_other(THOB, fun);
}

int line;
string tmpstr;

string get_lines(string s)
{
    if (s != ".")
    {
	tmpstr += s + "\n";
	line++;
	write("\n" + line + "> ");
	input_to("get_lines");
    }
    else
    {
	call_other(THOB, "set_answer" + temp, tmpstr, idx);
	call_other(THOB, fun);
    }
}

main_1_input(string args)
{
    int i;

    fun = "main_1";
    temp = "1";

    if (sscanf(args, "%d", i) == 1)
    {
	if (i > 0 && i < (sizeof(main_1_strs) + 1))
	{
	    idx = i - 1;
	    write("\n" + main_1_strs[i - 1] + " > ");
	    input_to("get_string");
	}
    }
    else
    {
	if (args == "q" || args == "Q")
	    mainmenu();
	else
	{
	    write("Your choice: [1-9/Q] > ");
	    input_to("main_1_input");
	}
    }
}

main_2_input(string args)
{
    int i;

    fun = "main_2";
    temp = "2";

    if (sscanf(args, "%d", i) == 1)
    {
	if (i > 0 && i < (sizeof(main_2_strs) + 1))
	{
	    idx = i - 1;
	    write("\n" + main_2_strs[i - 1] + " > ");
	    input_to("get_string");
	}
    }
    else
    {
	if (args == "q" || args == "Q")
	    mainmenu();
	else
	{
	    write("Your choice: [1-" + (sizeof(main_2_strs) + 1) + "/Q] > ");
	    input_to("main_2_input");
	}
    }
}

main_3_input(string args)
{
    int i;

    fun = "main_3";
    temp = "3";

    if (sscanf(args, "%d", i) == 1)
    {
	if (i > 0 && i < (sizeof(main_3_strs) + 1))
	{
	    idx = i - 1;
	    write("\n" + main_3_strs[i - 1] + " (type '.' when done)\n");
	    write("1> ");
	    line = 1;
	    tmpstr = "";
	    input_to("get_lines");
	}
    }
    else
    {
	if (args == "q" || args == "Q")
	    mainmenu();
	else
	{
	    write("Your choice: [1-" + (sizeof(main_3_strs) + 1) + "/Q] > ");
	    input_to("main_3_input");
	}
    }
}
main_4_input(string args)
{
    int i;

    fun = "main_4";
    temp = "4";

    if (sscanf(args, "%d", i) == 1)
    {
	if (i > 0 && i < (sizeof(main_4_strs) + 1))
	{
	    idx = i - 1;
	    write("\n" + main_4_strs[i - 1] + " (type '.' when done)\n");
	    write("1> ");
	    line = 1;
	    tmpstr = "";
	    input_to("get_lines");
	}
    }
    else
    {
	if (args == "q" || args == "Q")
	    mainmenu();
	else
	{
	    write("Your choice: [1-" + (sizeof(main_4_strs) + 1) + "/Q] > ");
	    input_to("main_4_input");
	}
    }
}


main_1()
{
    int i;
    write("Personal information --- \n" + 
      "\n");

    for (i = 0; i < sizeof(main_1_strs); i++)
	write("    " + (i + 1) + ". " + main_1_strs[i] + "\n");
    write("    " + "Q. Back to main menu\n");
    input_to("main_1_input");
    write("Your choice: [1-" + (sizeof(main_1_strs) + 1) + "/Q] > ");
}

main_2()
{
    int i; 
    write("Your knowledge of coding --- \n" + 
      "\n");

    for (i = 0; i < sizeof(main_2_strs); i++)
	write("    " + (i + 1) + ". " + main_2_strs[i] + "\n");
    write("    " + "Q. Back to main menu\n");
    input_to("main_2_input");
    write("Your choice: [1-" + (sizeof(main_2_strs) + 1) + "/Q] > ");
}

main_3()
{
    int i;
    write("Being a Wizard --- \n" + 
      "\n");

    for (i = 0; i < sizeof(main_3_strs); i++)
	write("    " + (i + 1) + ". " + main_3_strs[i] + "\n");
    write("    " + "Q. Back to main menu\n");
    input_to("main_3_input");
    write("Your choice: [1-" + (sizeof(main_3_strs) + 1) + "/Q] > ");
}

main_4()
{
    int i;
    write("Creative tasks --- \n" + 
      "\n");

    for (i = 0; i < sizeof(main_4_strs); i++)
	write("    " + (i + 1) + ". " + main_4_strs[i] + "\n");
    write("    " + "Q. Back to main menu\n");
    input_to("main_4_input");
    write("Your choice: [1-" + (sizeof(main_4_strs) + 1) + "/Q] > ");
}

sponsor_q(string args)
{
    sponsor = lower_case(args);
    mainmenu();
}

mainmenu_input(string args)
{
    switch(args)
    {
    case "1" : main_1();
	break;
    case "2" : main_2();
	break;
    case "3" : main_3();
	break;
    case "4" : main_4();
	break;
    case "5" : write("In this murpe, all new 'wizards' should have a sponsor who will teach basics for you. " +
          "Only demigods and higher can sponsor new wizards. " +
	  "You need to have a sponsor before you can become a wizard.\n");
	write("Your sponsor > ");
	input_to("sponsor_q");
	break;
    case "q" :
    case "Q" : do_exit();
	break;
    default: write("Available commands are 1-6 and Q.\n");
	write("Your choice [1-6/Q] > ");
	input_to("mainmenu_input");
	break;
    }
}

mainmenu()
{
    write("MAJIK Wizardhood Application Form 1.0 \n"+
      "\n" +
      "Main menu -- \n\n"+
      "    1. Personal information\n" +
      "    2. Your knowledge of coding\n" +
      "    3. Being a Wizard\n" +
      "    4. Some creative tasks for your 'enjoyment'\n" +
      "    5. Sponsor\n" +
      "\n" +
      "    Q. Exit and save\n" +
      "\n" +
      "Your choice [1-5/Q] > ");
    input_to("mainmenu_input");
}

send_form()
{
    string file;
    string msg;
	string *rep, tmp;
    int i;

    file = "MAJIK Automagic Wizardhood Application v1.0\n" +
    "\n" +
    "\n" +
    "This is an automatically generated application, which is filled by\n" +
    "mortals and then sent to both namhas and mortals sponsor.\n" +
    "\n" +
    "\n" +
    "This application was filled by " + capitalize(filler) + ".\n" +
    "He is sponsored by " + capitalize(sponsor) + ".\n" +
    "\n" +
    "\n";
    for (i = 0; i < sizeof(main_1_strs); i++)
	file += main_1_strs[i] + ": " + main_1_answers[i] + "\n";
    file += "\n";
    for (i = 0; i < sizeof(main_2_strs); i++)
	file += main_2_strs[i] + ": " + main_2_answers[i] + "\n";
    file += "\n";

    for (i = 0; i < sizeof(main_3_strs); i++)
	file += main_3_strs[i] + "\n " + main_3_answers[i] + "\n\n";
    file += "\n";

    for (i = 0; i < sizeof(main_4_strs); i++)
	file += main_4_strs[i] + "\n " + main_4_answers[i] + "\n\n";
    file += "\n";

    write(".");
    write_file("/data/application/wizapp." + filler, file, 1);

    msg ="You have received a new immortality application from ^c1" + capitalize(filler) + "^c0.\n" +
    " He is sponsored by ^c1" + capitalize(sponsor) + "^c0.\n" +
    " Application can be found from /data/application/wizapp." + filler + "\n";
	
	if (find_player(sponsor))
		message("standard", msg, find_player(sponsor));
	
	tmp = read_file("/home/" + sponsor + "/" + sponsor + ".rep");
	if (tmp)
		rep = explode(tmp, "\n");
	else
		rep = ({ "" });
	
	rm("/home/" + sponsor + "/" + sponsor + ".rep");
	
	if (sizeof(rep) > 20)
		write_file("/home/" + sponsor + "/" + sponsor + ".rep", implode(rep[<19..], "\n"));
	else
		write_file("/home/" + sponsor + "/" + sponsor + ".rep", implode(rep, "\n"));
	
	write_file("/home/" + sponsor + "/" + sponsor + ".rep", msg + "\n\n");
}



do_fill(string args)
{
    if (args == "form" || args == "application")
    {
	message("environment", capitalize(THIS->query_name()) + " starts filling the wizardhood application.\n", environment(THIS), THIS);
	message("environment", "You start filling the wizardhood application.\n", THIS);

	mainmenu();
	return 1;
    }
    return 0;
}

do_send(string args)
{
    string *file, sec, tmp;
    string filename;
    int i;

    if (!sponsor)
    {
	notify_fail("But you haven't set your sponsor!\n");
	return 0;
    }
    for (i = 0; i < sizeof(main_1_strs); i++)
    {
	if (!main_1_answers[i])
	{
            notify_fail("But you haven't answered all of the questions yet!\n"
            + "The first missing was: Category 1, Question " +(i+1)+"\n");
	    return 0;
	}
    }
    for (i = 0; i < sizeof(main_2_strs); i++)
    {
	if (!main_2_answers[i])
	{
            notify_fail("But you haven't answered all of the questions yet!\n"
            + "The first missing was: Category 2, Question " +(i+1)+"\n");
	    return 0;
	}
    }
    for (i = 0; i < sizeof(main_3_strs); i++)
    {
	if (!main_3_answers[i])
	{
            notify_fail("But you haven't answered all of the questions yet!\n"
            + "The first missing was: Category 3, Question " +(i+1)+"\n");
	    return 0;
	}
    }
    for (i = 0; i < sizeof(main_4_strs); i++)
    {
	if (!main_4_answers[i])
	{
            notify_fail("But you haven't answered all of the questions yet!\n"
            + "The first missing was: Category 4, Question " +(i+1)+"\n");
	    return 0;
	}
    }

    filename = "/data/player/" + sponsor[0..0] + "/" + sponsor + ".o";
    if (file_size(filename) < 0)
    {
	notify_fail("There's no player named " + sponsor + " who could sponsor you.\n");
	return 0;
    }

    file = explode(read_file(filename), "\n");
    for (i = 0; i < sizeof(file); i++)
    {
	if (sscanf(file[i], "%s %d", sec, tmp) == 2)
	{
	    if (sec == "security")
		break;
	}
    }
    if (tmp < SEC4)
    {
	notify_fail("But " + capitalize(sponsor) + " isn't powerful enough to sponsor you!\n");
	return 0;
    }
    message("standard", "Holy light descends from the sky and falls upon the application." +
      " The application starts to glow and slowly flies into the sky!\n", THIS);
    send_form();

    return 1;
}

do_rip(string args)
{
    message("misc", "You rip the application into small pieces.\n", THIS);
    destruct(THOB);
    return 1;
}



