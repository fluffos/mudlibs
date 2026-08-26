/*The alignment code for Nightfall's Keep
**   Apr 30 '97 Coded by Zur
**              Use mod_morals() and mod_ethics to change the respective
**              aspect of alignment.
**              Use set_align("le") to set a monster's alignment
**              to "lawful evil"
**              Everything defaults to true neutral.
*/

mapping ali = ([ 0 : 0 ]);
void mod_ethics(int i);
void mod_morals(int i);

// Sets the true alignment (ie the interger mapping)
void set_true_alignment(int e, int m)
{
    ali = ([ e : m ]);
}
void set_true_align(int e, int m)
{
    set_true_alignment(e,m);
}


// Sets the alignment in the form cg == "chaotic good"
void set_align(string str)
{
    string *letters;
    int e, m;
    if(!str) return;
    if(str == "n" || str == "tn" || strlen(str) > 2 )
    {
	set_true_alignment(0, 0);
	return;
    }
    letters = explode(str, "");
    switch(letters[0])
    {
    case "l": e = 1; break;
    case "n": e = 0; break;
    case "c": e = -1; break;
    default:  e = 0; break;
    }
    switch(letters[1])
    {
    case "g": m = 1; break;
    case "n": m = 0; break;
    case "e": m = -1; break;
    default:  m = 0; break;
    }
    set_true_alignment(e, m);
}
void set_alignment(string str){ set_align(str); } 
void mod_ethics(int i)
{
    mapping changed;
    int e, olde;
    olde = keys(ali)[0];
    changed = ([ olde + i : ali[olde] ]);
ali = changed;
}

void mod_morals(int i)
{
    int e, oldm;
    e = keys(ali)[0];
    ali[e] += i;  
}

mapping query_true_alignment(){
    if(ali) return ali;
    return ([ 0 : 0 ]);
}
string process_morals(int i)
{
    string moral;
    switch(i)
    {

    case -1000..-1: moral = "evil"; break;
    case 0:         moral = "neutral"; break;
    case 1..1000:   moral = "good"; break;
    default:        moral = "unknown moral"; break;
    }
    return moral;
}

string process_ethics(int i)
{
    string ethic;
    switch(i)
    {
    case -1000..-1: ethic = "chaotic"; break;
    case 0:         ethic = "neutral"; break;        
    case 1..1000:   ethic = "lawful"; break;
    default:        ethic = "unknown ethic"; break;
    }
    return ethic;
}
string query_alignment()
{
    string align;
    string ethic, moral;
    if(ali && !wizardp(this_object()))
    {
	ethic = process_ethics(keys(ali)[0]);
	moral = process_morals(values(ali)[0]);
	if(ethic == moral)
	{
	    return "true neutral";
	}
	else
	{
	    return sprintf("%s %s", ethic, moral);
	}
    }
    if(wizardp(this_object())) {
	align = this_object()->query("al_title") ;
	if (!align) align = "Unknown Alignment";
	return align;
    }
}

string query_align(){ return query_alignment(); }
varargs
mixed query_ethics(int flag)
{
    if(ali)
    {
	if(flag)
	{
	    return (int)keys(ali)[0];
	}
	return process_ethics(keys(ali)[0]);
    }
    return 0;
}
varargs
mixed query_morals(int flag)
{
    int x;
    if(ali)
    {
	if(flag)
	{
	    return values(ali)[0];
	}
	return process_morals(values(ali)[0]);
    }
    return 0;
}


