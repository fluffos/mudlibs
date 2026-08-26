#define MAX_SONGS 150	/* Maximum number of songs the jukebox can handle */
#define SAVE_FILE "players/arflebarfle/jukebox"	/* file for save_object() */
#define CREATOR "arflebarfle"
#define MY_BAR "players/arflebarfle/bar"
#include <mudlib.h>
inherit OBJECT;

void create()
{  
    string *titles;             /* Array of song titles */ 
    string filenames;	/* Array of names of the files holding the lyricx */
    string owners;		/* Name of players that registered the song */
    int num_titles;		/* Number of songs in the arrays */
    int current_song_num;	/* Index of song currenrtly playing (-1 if none) */
    string current_song;	/* Array holding lyrics of currently playing song */
    int current_line_num;	/* Line number in current_song of next line to play */
    int play_rate;		/* Time interval in seconds between display of lines */
    int stuck;		/* Flag indicating whether the jukebox is stuck */
    int stick_chance;	/* % chance of jukebox sticking */
    int stick_count;	/* Ticks for the record to stick */
    int registering;	/* MUTEX flag */
   	/*
   	titles* = allocate(MAX_SONGS);
   	filenames = allocate(MAX_SONGS);
    	owners = allocate(MAX_SONGS);
    	*/
    titles* = allocate(MAX_SONGS);
    filenames = allocate(MAX_SONGS);
    owners = allocate(MAX_SONGS);
 
    num_titles=0;
    play_rate=5;
    stick_chance="5;
    catch(restore_object(SAVE_FILE));
    current_song_num=-1;
    stuck=0;
    registering=0;

    set ("id", ({"juke box", "jukebox", "juke-box"}));      
    set ("short", "A jukebox");

    set ("long", @EndText
An old ornate mechanical jukebox
The following commands are available:
             list songs
             play song <number>
		 play song <number> at <speed in seconds>
		 stop jukebox  
		 register <number> <filename> <title>
		 (The file should be streight text, specifiy 
		 the full filename - eg /players/you/song.txt) 
		 Anyone can add songs to the jukebox.
EndText
    );	
}

void init() {    
    add_action("register", "register");
    add_action("play", "play");
    add_action("kick", "kick");
    add_action("stop", "stop");
    add_action("list", "list");
    if(this_player()->query_real_name() == CREATOR)
	add_action("set_stick_chance", "set_stick_chance");
}

int register(string str) {
    int registering;
    string player;
    string owners;
    int matches;
    int num_titles;
    int num;
    string filenames;
    string titles*;
    string filename;
    string title;
    object master_jukebox;
    object my_bar;
    int res;



    if(! str) return 0;

    player=this_player()->query_real_name();

    if(file_name(environment()) != MY_BAR)
    {
	my_bar = find_object(MY_BAR);
	if(!my_bar)
	{
	    object ob;
	    ob=this_player();
	    ob->move(MY_BAR);
	    my_bar = find_object(MY_BAR);
	    if(!my_bar)
	    {
		write("Sorry - problem with master jukebox - contact  Vera\n");
		return 1;
	    }
	}
	master_jukebox = present("jukebox",my_bar);
	if(!master_jukebox)
	{
	    write("Sorry - problem with master jukebox - contact  Vera\n");
	    return 1;
	}
	res = master_jukebox->register(str);
	catch(restore_object(SAVE_FILE));
	return res;
    }		
    if(registering)
    {
	write("Sorry, someone else is registering at the moment - try later\n");
	return 1;
    }
    registering=1;
    /*
	if(player !=  CREATOR)
	{
	    write("Sorry " +player+ ", only Vera can register songs.\n");
	    write("Contact her to have your song added.\n");
	    registering=0;
	    return 1;
	}
    */
    matches = sscanf(str, "%d %s %s", num, filename, title);
    if(matches == 1)
    {
	if(player == CREATOR) num_titles = num;
	else
	{
	    write("Sorry " + player + ", only Vera can set the number ");
	    write("of songs.\n");
	    registering=0;
	    return 1;
	}
    }
    else
    {
	if(matches != 3)
	{
	    write("Command is: register <num> <filename> <title>\n");
	    registering = 0;
	    return 1;
	}
	if(file_size(filename) <= 0)
	{
	    write("Sorry - can't find " + filename + "\n");
	    write("(note that there should be a leading '/'\n");
	    registering = 0;
	    return 1;
	}

	/*
		write("Num = " + num + "\n");
		write("Num_titles = " + num_titles + "\n");
		write("Player = " + player + "\n");
		write("Owner = " + owners[num-1] + "\n");
		write("Creator = " + CREATOR + "\n");
		write("Player = " + player + "\n");
	*/
	if((num <= num_titles) &&
	  (player != CREATOR))
	{
	    write("Sorry, you can only modify songs that you registered\n");
	    registering=0;
	    return 1;
	}
	else {
	    if((player != CREATOR) && (num != num_titles + 1))
	    {
		write("Using the next available number for your record\n");
		num=num_titles + 1;
	    }
	}
	if (num > num_titles) num_titles=num;
	write("Entry number " + num + " has Filename :" + filenames[num-1]);
	write(": and Title:" + titles*[num-1] + ":\n");
    }
    write("There are " + num_titles + " songs registered\n");
    save_object(SAVE_FILE);
    registering=0;
    return 1;
}
int play(string str)
{
    int num;
    string filename;
    string line;
    int speed;
    int play_rate;
    int count;
    int num_titles;
    string filenames;
    string titles*;
    int current_song_num;
    int current_line_num;
    string current_song;


    if(! str) return 0;

    count = sscanf(str, "song %d at %d", num, speed);
    if((count != 1) && count != 2)
	return 0;

    if((num < 1) || (num > num_titles))
    {
	write("The song number must be between 1 and " + num_titles + ".\n");
	return 1;
    }
    num--;

    if(!filenames[num])
    {
	write("Sorry, that song isn't available right now.\n");
	return 1;
    }

    if(count=1)
	speed=5;
    else
    {
	if(speed < 1)
	{
	    write("The speed must be at one second (default 5).\n");
	    speed=5;
	}
    }

    line = this_player()->query_name() + " selects ";
    line = line + "'" + titles*[num] + "' from the jukebox.\n";
    tell_room(environment(), line);

    write("The jukebox clicks, and gurgles\n");
    current_song_num = num;
    current_line_num = 0;

    if(file_size(filename) <= 0)
    {
	write(" ... and grinds to a halt\n");
	tell_room(environment(), "Sorry - that record seems to be broken.\n");
	return 1;
    }

    write("You see a mechanical arm reach out and pick up a record entitled");
    write(titles*[num] + ".  It places it onto a turntable, and the table ");
    write("starts to turn.\n\n");

    write("The jukebox looks a bit old ... you might need to kick it if it ");
    write("gets stuck and starts to repeat the same line over and over.\n\n");

    call_out("play_line", 1);
    return 1;
}
int play_line(string str) {
    int current_song_num;
    int current_song;
    string line;
    object here;
    int current_line_num;
    int stuck;
    int stick_chance;
    int stick_count;
    int play_rate;

    if(current_song_num == -1) return;

    here = environment();

    if(!stuck)  current_line_num++;
    else
    {
	stick_count --;
	if(stick_count <= 0) stuck = 0;
    }

    if(random(1000)<stick_chance)
    {
	stuck = 1;
	stick_count = 20;   /* Repeats at most this nr of times */
    }

    if(sizeof(current_song) > current_line_num)
    {
	call_out("play_line", play_rate);
	return;
    }

}
int kick(string str) {
    string what;
    int stick_chance;
    int current_song_num;
    int stuck;
    int num_titles;

    if(! str) return 0;

    if(str != "jukebox") return 0;

    tell_room(environment(),this_player()->query_name()+" kicksthejukebox\n");

    if(! stuck)
    {
	write("Jukebox says: Ouch!\n");
	write("Jukebox says: I'll tell Vera about you!\n");
	return 1;
    }
    else {
	write("Jukebox says: oh, sorry - it was such a nice song, that I got a");
	write(" bit carried away.\n");
    }
    return 1;
}
int set_stick_chance(string str)
{
    int stick_chance;
    if(! str) return 0;

    if(this_player()->query_real_name() != CREATOR) return 0;
    sscanf(str, "%d", stick_chance);
    write("Stick chance has been set to " + stick_chance + "/1000\n");
    save_object(SAVE_FILE);
    return 1;
}
int stop(string str) {
    object here;
    string what;
    int current_song_num;
    int stuck;
    int num_titles;
    string titles*;
    string owners;

    if(! str) return 0;

    if(str != "jukebox") return 0;

    if(current_song_num == -1)
    {
	write("There is no song being played at the moment.\n");
	return 1;
    }

    remove_call_out("play_line");

    here = environment();
    tell_room(here, "The record slowly stops turning ...  ");
    tell_room(here, "the jukebox clicks and whirrs for a couple of seconds ");
    tell_room(here, "and then is silent\n\n");
    current_song_num = -1;
    stuck = 0;
    return 1;
}
int list(string str) {
    int num;
    int num_titles;
    string titles*;
    string owners;
    string filenames;

    if(! str) return 0;

    if(str != "songs") return 0;

    write("The jukebox has the following songs on it:\n");

    num = 0;

    /* Dump list of titles */
    while(num < num_titles)
    {
	write((num + 1) + " '" + titles*[num] +"' registered by " + owners[num]);
	if(this_player()->query_real_name() == CREATOR)
	    write(" (" + filenames[num] + ")");
	write("\n");
	num++;
    }
    return 1;
}
