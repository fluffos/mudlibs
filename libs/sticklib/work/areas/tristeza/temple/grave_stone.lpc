#include <treasure.h>
#include <areas.h>

string random_sympathy();
string random_how();

string dead;
int lines;


void
create_treasure()
{
    set_id(({ "stone", "gravestone", "grave stone" }));
    set_short("A big gravestone");
    restore_object(AREA_TRISTEZA+"temple/gravestone");
}

long() 
{
    if (!this_player()) return;
    if (dead) this_player()->tell_me(dead);
    else
	this_player()->tell_me("There is nothing engraved on the stone.");
    environment()->tell_here(this_player()->query_name()
      +" looks at the gravestone.",this_player());
}

status get() { return 0; }

init_treasure() 
{
    add_action("read","read");
}

status
read(string str) 
{
    if (!id(str)) return 0;
    long();
    return 1;
}

void
log_dead(string victim, string killer) 
{
    string dummy,temp;
    int a,b;
    /* Format:
			   "Our beloved Victim
		      was brutally killed by Killer"

    */
    if(!victim || victim=="Guest") return;
    if(!killer) killer = "someone";
    if(!dead) dead = "";
    temp=sprintf("%|*s",79,random_sympathy()+" "+victim+"#");
    /* sprintf() uses some UGLY and  S L O W  control-chars which we take away */
    sscanf(temp,"%s#%s",temp,dummy);
    temp+="\n";
    temp+=sprintf("%|*s",79,random_how()+" "+killer+"#");
    sscanf(temp,"%s#%s",temp,dummy);
    temp+="\n\n";
    dead+=temp;
    lines+=3;
    if(lines>21) {
	lines-=3;
	sscanf(dead,"%s\n\n%s",dummy,dead);
    }
    save_object(AREA_TRISTEZA+"temple/gravestone");
}

string
random_sympathy() 
{
    return ({"Our beloved","Highly honored","Noble-minded","Pure hearted",
      "Beloved","Esteemed","Exceedingly esteemed","Honorable","Brave",
      "Respectable","Greatly admired","Admirable",
      "Throughout immaculate","Famous","Celebrated","Always friendly",
      "Friendly","Lovingly remembered","Tenderly remembered",
      "Affectionately recalled","Skilled","Non-Plastic",
      "Prestigious","Glorious","Illustrious","Valiant",
      "Courageous","Heroic","Steadfast","Virtuous",
    })[random(29)];
}

string
random_how() 
{
    return ({"was brutally killed by","got an appointment with Death from",
      "was slain by","bit the dust in front of","was killed by",
      "was departed from our existence by","was called to Death by",
      "stopped breathing in the presence of","died in combat by",
      "got killed by","met Death with help from",
      "got a glorious death from","is mourned by many because of",
      "was turned to maggot food by","was brutally slain by",
      "visits the deceased with regards from","was fed to maggots by",
      "was last sighted by","was declared dead by",
      "underwent an ultimate experience with help from",
      "had a strange feeling after a brief meeting with",
      "drifted away from","left behind many friends and",
      "rests in pieces thanks to",
      "kicked the bucket supplied by",
    })[random(25)];
}
