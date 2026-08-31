inherit "room/room";
#define COMS 104 
#define SOULROOM "/tools/exsoul/soulroom"

string commands, verbs;
int usage, wusage;

reset(arg) {
int i;
	
    if (arg) return;
	commands=allocate(COMS);
	verbs=allocate(COMS);
	usage=allocate(COMS);
	wusage=allocate(COMS);
	commands=({ "admire",
		  "apologize",
		  "applaud",
		  "bang",
		  "blush",
		  "bounce",
		  "bow",
		  "burp",
		  "cackle",
		  "chuckle",
		  "clap",
		  "cheer",
		  "comfort",
		  "complain",
		  "cough",
		  "cry",
		  "cuddle",
		  "curse",
		  "curtsey",
		  "excuse",
		  "dance",
		  "fail",
		  "fart",
		  "fear",
		  "finger",
		  "flip",
		  "fondle",
		  "french",
		  "destroy",
		  "frown",
		  "gasp",
		  "giggle",
		  "glare",
		  "grin",
		  "groan",
		  "grope",
		  "growl",
		  "hiccup",
		  "hug",
		  "ignore",
		  "kick",
		  "kiss",
		  "knee",
		  "laugh",
		  "lick",
		  "look",
		  "love",
		  "me",
		  "mercy",
		  "moan",
		  "nibble",
		  "no",
		  "nod",
		  "nose",
		  "pale",
		  "pat",
		  "point",
		  "poke",
		  "pout",
		  "puke",
		  "praise",
		  "protest",
		  "pshout",
		  "purr",
		  "puzzle",
		  "relax",
		  "roll",
		  "ruffle",
		  "scratch",
		  "scream",
		  "shake",
		  "shame",
		  "shiver",
		  "shrug",
		  "sigh",
		  "sing",
		  "slap",
		  "smile",
		  "smirk",
		  "snap",
		  "sneeze",
		  "snicker",
		  "sniff",
		  "snore",
		  "snuggle",
		  "sob",
		  "spit",
		  "squeeze",
		  "stare",
		  "strut",
		  "sulk",
		  "sweat",
		  "thank",
		  "throat",
		  "tickle",
		  "tongue",
		  "twiddle",
		  "wait",
		  "wave",
		  "whistle",
		  "wiggle",
		  "wink",
		  "wshout",
		  "yawn",
	});
	for (i=0; i<(COMS-1); i++) {
		verbs[i]=commands[i];
	}

    set_light(1);
    short_desc = "room of thousand souls";
    no_castle_flag = 0;
    long_desc = 
        "You have entered the room of the thousand souls. The air is buzzing from\n"
        + "a strange sound, like the sound of a giantic dynamo. You can feel the \n"
        + "presence of a thousand of souls in this room, though there is nothing to \n"
        + "be seen. The room seems to have no end, you can see no walls.\n";
    dest_dir = 
        ({
        "SOULROOM", "everywhere",
        "SOULROOM", "nowhere",
        });
}

query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}
room_is_modified() {
    return 1;
}

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

disp_verbs() {
int i;
	write("Verbs available:\n\n");
	for (i=0; (i<=((COMS)/6)); i++) {
		if (verbs[i])
        write(extract(verbs[i] + "         ", 0, 9) + "   ");
		if (verbs[i+17])
		write(extract(verbs[i+17] + "         ", 0, 9) + "   ");
		if (verbs[i+34])
        write(extract(verbs[i+34] + "         ", 0, 9) + "   ");
		if (verbs[i+51])
        write(extract(verbs[i+51] + "         ", 0, 9) + "   ");
		if (verbs[i+68])
        write(extract(verbs[i+68] + "         ", 0, 9) + "   ");
		if ((i+85<COMS) && (verbs[i+85]))
        write(extract(verbs[i+85] + "         ", 0, 9) + "   ");
		write("\n");
	}
	return 1;
}


add_usage(verb) {
int index;
	index=member_array(verb, commands);
	if ((index<0) || (index>COMS)) return 0;
	usage[index]++;
	return 1;
}

add_wusage(verb) {
int index;
	index=member_array(verb, commands);
	if ((index<0) || (index>COMS)) return 0;
	wusage[index]++;
	return 1;
}

display_usage(page) {
string hcom;
int i, k, hus, hwus, sum, wsum;
	for (i=0; i<(sizeof(commands)-1); i++) {
		sum+=usage[i]; wsum+=wusage[i];
	}
	for (i=0; i<(sizeof(commands)-1); i++) {
		for (k=i+1; k<sizeof(commands); k++) {
			if (usage[i]<usage[k]) {
				hus=usage[i]; hwus=wusage[i]; hcom=commands[i];
				usage[i]=usage[k]; wusage[i]=wusage[k]; commands[i]=commands[k];
				usage[k]=hus; wusage[k]=hwus; commands[k]=hcom;
			}
		}
	}	/* sort the usage */

	write("Verbs	  Usage [a:all w:wizards]\n");
	for (i=0; i<20; i++) {
		write(extract(commands[i] + "_________", 0, 8) );
		write("_a:"); tab((usage[i]));
		write("_w:"); tab((wusage[i]));
		write("  ");
		write(extract(commands[i+20] + "_________", 0, 8) );
		write("_a:"); tab((usage[i+20]));
		write("_w:"); tab((wusage[i+20]));
		write("  ");
		write(extract(commands[i+40] + "_________", 0, 8) );
		write("_a:"); tab((usage[i+40]));
		write("_w:"); tab((wusage[i+40]));
		write("\n");
	}
	write("Total_____a:" + (sum));
	write("_w:" + wsum + "\n");
	return 1;
}

disp_only() {
int i, k, hus, hwus, sum, wsum;
        for (i=0; i<(sizeof(commands)-1); i++) {
                sum+=usage[i]; wsum+=wusage[i];
        }

        write("Verbs      Usage [a:all w:wizards]\n");
        for (i=0; i<20; i++) {
                write(extract(commands[i] + "_________", 0, 8) );
                write("_a:"); tab((usage[i]));
                write("_w:"); tab((wusage[i]));
                write("  ");
                write(extract(commands[i+20] + "_________", 0, 8) );
                write("_a:"); tab((usage[i+20]));
                write("_w:"); tab((wusage[i+20]));
                write("  ");
                write(extract(commands[i+40] + "_________", 0, 8) );
                write("_a:"); tab((usage[i+40]));
                write("_w:"); tab((wusage[i+40]));
                write("\n");
        }
        write("Total_____a:" + (sum));
        write("_w:" + wsum + "\n");
        return 1;
}

tab(c) {

	if (c<10) { write(c + "____" ); return; }
	if (c<100) { write(c + "___" ); return; }
	if (c<1000) { write(c + "__" ); return; }
	if (c<10000) { write(c + "_" ); return; }
	write(c); return;
}


sort_only() {
string hcom;
int i, k, hus, hwus, sum, wsum;
        for (i=0; i<(sizeof(commands)-1); i++) {
                sum+=usage[i]; wsum+=wusage[i];
        }
        for (i=0; i<(sizeof(commands)-1); i++) {
                for (k=i+1; k<sizeof(commands); k++) {
                        if (usage[i]<usage[k]) {
                                hus=usage[i]; hwus=wusage[i]; hcom=commands[i];
                                usage[i]=usage[k]; wusage[i]=wusage[k]; commands[i]=commands[k];
                                usage[k]=hus; wusage[k]=hwus; commands[k]=hcom;
                        }
                }
        }       /* sort the usage */

}

query_commands()  { return( commands ); }

