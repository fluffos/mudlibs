inherit "/cmd/std/command_driver";

#include <macros.h>
#include <stdproperties.h>
#include "defs.h"

#define SOULDESC(x) (this_player()->add_prop(LIVE_S_SOULEXTRA, x))

string
get_soul_id()
{
   return "spiczastousi";	/* Krotka nazwa gildii. */
}

int
query_cmd_soul()
{
    return 1;
}

mapping
query_cmdlist()
{
    return ([
    		"pomoc":"pomoc",
    		
		"strzyz":"strzyz",
		
		"ucho":"ucho",
            ]);
}

int
pomoc(string str)
{
    str = lower_case(str);
    
    if (str == "gildia" || str == "dla gildii" || str == "w spiczastouchych"
     || str == "spiczastousi" || str == "w gildii")
    {
        write("Nasza gildia spiczastouchych udostepnia ci dwa " +
            "wspaniale emoty:\n" +
            "\n strzyz [jak] - strzyzenie uszami" +
            "\n ucho [jak] [do kogo] - wachlowanie uszami" +
            "\n\nWszelkie komentarze prosze kierowac do Alvina.\n");
        
        return 1;
    }
    
    notify_fail("Do czego pomoc chcesz uzyskac?\n");
    

    return 0;
}

int 
strzyz(string str)
{
    string jak;
    
    jak = check_adverb_with_space(str, "demobilizujaco");
    
    
    if (jak == " ")
    {
        write("Jak chcesz zastrzyc uszami?\n");
        return 1;
    }
    
    write("Strzyzesz" + jak + " swymi spiszastymi uszami.\n");
    allbb("strzyze" + jak + " swymi spiczastymi uszami.");
    
    return 1;
}

int
ucho(string str)
{
    object *oblist;
    string *jak;
    
    jak = parse_adverb_with_space(str, "zamaszyscie", 0);
    
    SOULDESC("macha" + jak[1] + " uszami");
    
    if (!strlen(jak[0]))
    {
        write("Machasz" + jak[1] + " swymi wielkimi, spiczastymi uszami.\n");
        all("macha" + jak[1] + " swyim wielkimi, spiczastymi uszami.");
        
        return 1;
    }
    
    oblist = parse_this(jak[0], "[do] %l:" + PL_DOP);
    oblist -= ({ this_player() });
    
    if (!sizeof(oblist))
    {
        notify_fail("Do kogo chcesz pomachac uszami?\n");
        return 0;
    }
    
    actor("Machasz" + jak[1] + " do", oblist, PL_DOP, " swymi wielkimi, "+
        "spiczastymi uszami.");
    target("macha" + jak[1] + " do ciebie swymi wielkimi, spiczastymi " +
        "uszami.", oblist);
    all2actbb("macha" + jak[1] + " do", oblist, PL_DOP, " swymi "+
        "wielkimi, spiczastymi uszami.");
        
    return 1;
   
    
return 1;
}
