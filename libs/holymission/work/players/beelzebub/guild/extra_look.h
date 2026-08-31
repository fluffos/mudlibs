#include "/players/beelzebub/misc/defs.h"
extra_look()
{
    object myself;
    string text;

    myself = environment();

    if ( myself == TP) {
        text = "You can be really proud of your body:\n";
    }
    else {                                                       
        if ( TP->query_gender() == myself->query_gender() ) {     
            if ( myself->query_gender() == 2 )                    
                text = "She is about your age and has a body worthy of envy:\n";
            else                                                  
                text = "He is about your age and has a body worthy of envy:\n";
        }
        else {                                                    
            if ( myself->query_gender() == 2 )                       
                text = "She is about your age and has a very pretty body:\n";
            else
                text = "He is about your age and has a very handsome body:\n";
        }
    }

    if ( myself->query_gender() == 2 )
        text += "tall and well-built, with wide shoulders, a generous\n" +
        "bosom, slim waist, and long, tawny legs";
    else
        text += "tall and well-built, with wide shoulders, massive\n" +
        "pectorals, and thick, tawny legs";

    return text;
}

