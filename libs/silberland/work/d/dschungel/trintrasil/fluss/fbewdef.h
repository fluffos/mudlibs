
//ooooooooooooooooooooooooooooooooo BEWEGUNG oooooooooooooooooooooooooooooooooooo

#define SUEDW AddExit("suedwesten", ([\
                       EX_FUNC:"suedwfunc"]));
#define SUEDWF(x) \
    int suedwfunc() { \
\
    int i, moveint;\
    object *inv;\
    inv=all_inventory(environment(this_player()));\
\
     if( (interactive(this_player())) ) {\
\
     	if( present("wasserschlange", environment(this_player())) ) {\
\
     		for(i=sizeof(inv)-1;i>=0;i--) {\
\
                        if( inv[i]->id("EVENTSCHLANGE") ) {\
\
                                if( inv[i]->QueryProp(""+this_player()->name()+"") ) {\
                                	moveint++;\
                                }\
                        }\
                        if( !inv[i]->id("EVENTSCHLANGE") ||\
                        (inv[i]->id("EVENTSCHLANGE") && !inv[i]->QueryProp(""+this_player()->name()+"")) ) {\
\
                        }\
                }\
                if(moveint>0) {\
                	write(BS("Die Schlange laesst Deinen Fisch nicht los! "\
                        "Du musst sie erst toeten!"));\
                }\
                if(moveint==0) {\
                        write("\nDu steuerst Deinen Fisch nach Suedwesten.\n\n");\
                        this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
                        "auf einem Fisch nach Suedwesten", "schwimmt", \
                        "schwimmt auf einem Fisch herein"); \
                }\
                moveint=0;\
         return 1;}\
\
         if( !present("wasserschlange", environment(this_player())) ) {\
               write("\nDu steuerst Deinen Fisch nach Suedwesten.\n\n");\
               this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
               "auf einem Fisch nach Suedwesten", "schwimmt", \
               "schwimmt auf einem Fisch herein"); \
         return 1;} \
    return 1;}\
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("insekt")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Suedwesten", "schwirrt", \
          "schwirrt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("vogel")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Suedwesten", "fliegt", \
          "fliegt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(!this_player()->QueryProp("insekt"))&& \
       (!this_player()->QueryProp("vogel"))) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Suedwesten", "schwimmt", \
          "schwimmt herein"); \
         return 1;} \
        return 0;}



#define SUED AddExit("sueden", ([\
                     EX_FUNC:"suedfunc"]));
#define SUEDF(x) \
    int suedfunc() { \
\
    int i, moveint;\
    object *inv;\
    inv=all_inventory(environment(this_player()));\
\
     if( (interactive(this_player())) ) {\
\
     	if( present("wasserschlange", environment(this_player())) ) {\
\
     		for(i=sizeof(inv)-1;i>=0;i--) {\
\
                        if( inv[i]->id("EVENTSCHLANGE") ) {\
\
                                if( inv[i]->QueryProp(""+this_player()->name()+"") ) {\
                                	moveint++;\
                                }\
                        }\
                        if( !inv[i]->id("EVENTSCHLANGE") ||\
                        (inv[i]->id("EVENTSCHLANGE") && !inv[i]->QueryProp(""+this_player()->name()+"")) ) {\
\
                        }\
                }\
                if(moveint>0) {\
                	write(BS("Die Schlange laesst Deinen Fisch nicht los! "\
                        "Du musst sie erst toeten!"));\
                }\
                if(moveint==0) {\
                        write("\nDu steuerst Deinen Fisch nach Sueden.\n\n");\
                        this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
                        "auf einem Fisch nach Sueden", "schwimmt", \
                        "schwimmt auf einem Fisch herein"); \
                }\
                moveint=0;\
         return 1;}\
\
         if( !present("wasserschlange", environment(this_player())) ) {\
               write("\nDu steuerst Deinen Fisch nach Sueden.\n\n");\
               this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
               "auf einem Fisch nach Sueden", "schwimmt", \
               "schwimmt auf einem Fisch herein"); \
         return 1;} \
    return 1;}\
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("insekt")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Sueden", "schwirrt", \
          "schwirrt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("vogel")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Sueden", "fliegt", \
          "fliegt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(!this_player()->QueryProp("insekt"))&& \
       (!this_player()->QueryProp("vogel"))) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Sueden", "schwimmt", \
          "schwimmt herein"); \
         return 1;} \
        return 0;} 

#define SUEDO AddExit("suedosten", ([\
                      EX_FUNC:"suedofunc"]) );
                      
#define SUEDOF(x) \
    int suedofunc() { \
\
    int i, moveint;\
    object *inv;\
    inv=all_inventory(environment(this_player()));\
\
     if( (interactive(this_player())) ) {\
\
     	if( present("wasserschlange", environment(this_player())) ) {\
\
     		for(i=sizeof(inv)-1;i>=0;i--) {\
\
                        if( inv[i]->id("EVENTSCHLANGE") ) {\
\
                                if( inv[i]->QueryProp(""+this_player()->name()+"") ) {\
                                	moveint++;\
                                }\
                        }\
                        if( !inv[i]->id("EVENTSCHLANGE") ||\
                        (inv[i]->id("EVENTSCHLANGE") && !inv[i]->QueryProp(""+this_player()->name()+"")) ) {\
\
                        }\
                }\
                if(moveint>0) {\
                	write(BS("Die Schlange laesst Deinen Fisch nicht los! "\
                        "Du musst sie erst toeten!"));\
                }\
                if(moveint==0) {\
                        write("\nDu steuerst Deinen Fisch nach Suedosten.\n\n");\
                        this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
                        "auf einem Fisch nach Suedosten", "schwimmt", \
                        "schwimmt auf einem Fisch herein"); \
                }\
                moveint=0;\
         return 1;}\
\
         if( !present("wasserschlange", environment(this_player())) ) {\
               write("\nDu steuerst Deinen Fisch nach Suedosten.\n\n");\
               this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
               "auf einem Fisch nach Suedosten", "schwimmt", \
               "schwimmt auf einem Fisch herein"); \
         return 1;} \
    return 1;}\
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("insekt")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Suedosten", "schwirrt", \
          "schwirrt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("vogel")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Suedosten", "fliegt", \
          "fliegt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(!this_player()->QueryProp("insekt"))&& \
       (!this_player()->QueryProp("vogel"))) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Suedosten", "schwimmt", \
          "schwimmt herein"); \
         return 1;} \
        return 0;}                         

#define OST AddExit("osten", ([ \
                     EX_FUNC:"ostfunc"]) );
                     
#define OSTF(x) \
    int ostfunc() { \
\
    int i, moveint;\
    object *inv;\
    inv=all_inventory(environment(this_player()));\
\
     if( (interactive(this_player())) ) {\
\
     	if( present("wasserschlange", environment(this_player())) ) {\
\
     		for(i=sizeof(inv)-1;i>=0;i--) {\
\
                        if( inv[i]->id("EVENTSCHLANGE") ) {\
\
                                if( inv[i]->QueryProp(""+this_player()->name()+"") ) {\
                                	moveint++;\
                                }\
                        }\
                        if( !inv[i]->id("EVENTSCHLANGE") ||\
                        (inv[i]->id("EVENTSCHLANGE") && !inv[i]->QueryProp(""+this_player()->name()+"")) ) {\
\
                        }\
                }\
                if(moveint>0) {\
                	write(BS("Die Schlange laesst Deinen Fisch nicht los! "\
                        "Du musst sie erst toeten!"));\
                }\
                if(moveint==0) {\
                        write("\nDu steuerst Deinen Fisch nach Osten.\n\n");\
                        this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
                        "auf einem Fisch nach Osten", "schwimmt", \
                        "schwimmt auf einem Fisch herein"); \
                }\
                moveint=0;\
         return 1;}\
\
         if( !present("wasserschlange", environment(this_player())) ) {\
               write("\nDu steuerst Deinen Fisch nach Osten.\n\n");\
               this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
               "auf einem Fisch nach Osten", "schwimmt", \
               "schwimmt auf einem Fisch herein"); \
         return 1;} \
    return 1;}\
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("insekt")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Osten", "schwirrt", \
          "schwirrt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("vogel")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Osten", "fliegt", \
          "fliegt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(!this_player()->QueryProp("insekt"))&& \
       (!this_player()->QueryProp("vogel"))) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Osten", "schwimmt", \
          "schwimmt herein"); \
         return 1;} \
        return 0;}                    
                       
#define NORDO AddExit("nordosten", ([ \
                     EX_FUNC:"nordofunc"]) );
                     
#define NORDOF(x) \
    int nordofunc() { \
\
    int i, moveint;\
    object *inv;\
    inv=all_inventory(environment(this_player()));\
\
     if( (interactive(this_player())) ) {\
\
     	if( present("wasserschlange", environment(this_player())) ) {\
\
     		for(i=sizeof(inv)-1;i>=0;i--) {\
\
                        if( inv[i]->id("EVENTSCHLANGE") ) {\
\
                                if( inv[i]->QueryProp(""+this_player()->name()+"") ) {\
                                	moveint++;\
                                }\
                        }\
                        if( !inv[i]->id("EVENTSCHLANGE") ||\
                        (inv[i]->id("EVENTSCHLANGE") && !inv[i]->QueryProp(""+this_player()->name()+"")) ) {\
\
                        }\
                }\
                if(moveint>0) {\
                	write(BS("Die Schlange laesst Deinen Fisch nicht los! "\
                        "Du musst sie erst toeten!"));\
                }\
                if(moveint==0) {\
                        write("\nDu steuerst Deinen Fisch nach Nordosten.\n\n");\
                        this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
                        "auf einem Fisch nach Nordosten", "schwimmt", \
                        "schwimmt auf einem Fisch herein"); \
                }\
                moveint=0;\
         return 1;}\
\
         if( !present("wasserschlange", environment(this_player())) ) {\
               write("\nDu steuerst Deinen Fisch nach Nordosten.\n\n");\
               this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
               "auf einem Fisch nach Nordosten", "schwimmt", \
               "schwimmt auf einem Fisch herein"); \
         return 1;} \
    return 1;}\
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("insekt")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Nordosten", "schwirrt", \
          "schwirrt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("vogel")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Nordosten", "fliegt", \
          "fliegt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(!this_player()->QueryProp("insekt"))&& \
       (!this_player()->QueryProp("vogel"))) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Nordosten", "schwimmt", \
          "schwimmt herein"); \
         return 1;} \
        return 0;}                     
                   
#define NORD AddExit("norden", ([ \
                     EX_FUNC:"nordfunc"]) );
                                          
#define NORDF(x) \
    int nordfunc() { \
\
    int i, moveint;\
    object *inv;\
    inv=all_inventory(environment(this_player()));\
\
     if( (interactive(this_player())) ) {\
\
     	if( present("wasserschlange", environment(this_player())) ) {\
\
     		for(i=sizeof(inv)-1;i>=0;i--) {\
\
                        if( inv[i]->id("EVENTSCHLANGE") ) {\
\
                                if( inv[i]->QueryProp(""+this_player()->name()+"") ) {\
                                	moveint++;\
                                }\
                        }\
                        if( !inv[i]->id("EVENTSCHLANGE") ||\
                        (inv[i]->id("EVENTSCHLANGE") && !inv[i]->QueryProp(""+this_player()->name()+"")) ) {\
\
                        }\
                }\
                if(moveint>0) {\
                	write(BS("Die Schlange laesst Deinen Fisch nicht los! "\
                        "Du musst sie erst toeten!"));\
                }\
                if(moveint==0) {\
                        write("\nDu steuerst Deinen Fisch nach Norden.\n\n");\
                        this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
                        "auf einem Fisch nach Norden", "schwimmt", \
                        "schwimmt auf einem Fisch herein"); \
                }\
                moveint=0;\
         return 1;}\
\
         if( !present("wasserschlange", environment(this_player())) ) {\
               write("\nDu steuerst Deinen Fisch nach Norden.\n\n");\
               this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
               "auf einem Fisch nach Norden", "schwimmt", \
               "schwimmt auf einem Fisch herein"); \
         return 1;} \
    return 1;}\
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("insekt")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Norden", "schwirrt", \
          "schwirrt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("vogel")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Norden", "fliegt", \
          "fliegt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(!this_player()->QueryProp("insekt"))&& \
       (!this_player()->QueryProp("vogel"))) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Norden", "schwimmt", \
          "schwimmt herein"); \
         return 1;} \
        return 0;}                     
                     
#define NORDW AddExit("nordwesten", ([ \
                     EX_FUNC:"nordwfunc"]) );
                     
#define NORDWF(x) \
    int nordwfunc() { \
    int i, moveint;\
    object *inv;\
    inv=all_inventory(environment(this_player()));\
\
     if( (interactive(this_player())) ) {\
\
     	if( present("wasserschlange", environment(this_player())) ) {\
\
     		for(i=sizeof(inv)-1;i>=0;i--) {\
\
                        if( inv[i]->id("EVENTSCHLANGE") ) {\
\
                                if( inv[i]->QueryProp(""+this_player()->name()+"") ) {\
                                	moveint++;\
                                }\
                        }\
                        if( !inv[i]->id("EVENTSCHLANGE") ||\
                        (inv[i]->id("EVENTSCHLANGE") && !inv[i]->QueryProp(""+this_player()->name()+"")) ) {\
\
                        }\
                }\
                if(moveint>0) {\
                	write(BS("Die Schlange laesst Deinen Fisch nicht los! "\
                        "Du musst sie erst toeten!"));\
                }\
                if(moveint==0) {\
                        write("\nDu steuerst Deinen Fisch nach Nordwesten.\n\n");\
                        this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
                        "auf einem Fisch nach Nordwesten", "schwimmt", \
                        "schwimmt auf einem Fisch herein"); \
                }\
                moveint=0;\
         return 1;}\
\
         if( !present("wasserschlange", environment(this_player())) ) {\
               write("\nDu steuerst Deinen Fisch nach Nordwesten.\n\n");\
               this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
               "auf einem Fisch nach Nordwesten", "schwimmt", \
               "schwimmt auf einem Fisch herein"); \
         return 1;} \
    return 1;}\
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("insekt")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Nordwesten", "schwirrt", \
          "schwirrt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("vogel")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Nordwesten", "fliegt", \
          "fliegt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(!this_player()->QueryProp("insekt"))&& \
       (!this_player()->QueryProp("vogel"))) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Nordwesten", "schwimmt", \
          "schwimmt herein"); \
         return 1;} \
        return 0;}                     

#define WEST AddExit("westen", ([ \
                     EX_FUNC:"westfunc"]) );
                     
#define WESTF(x) \
    int westfunc() { \
\
    int i, moveint;\
    object *inv;\
    inv=all_inventory(environment(this_player()));\
\
     if( (interactive(this_player())) ) {\
\
     	if( present("wasserschlange", environment(this_player())) ) {\
\
     		for(i=sizeof(inv)-1;i>=0;i--) {\
\
                        if( inv[i]->id("EVENTSCHLANGE") ) {\
\
                                if( inv[i]->QueryProp(""+this_player()->name()+"") ) {\
                                	moveint++;\
                                }\
                        }\
                        if( !inv[i]->id("EVENTSCHLANGE") ||\
                        (inv[i]->id("EVENTSCHLANGE") && !inv[i]->QueryProp(""+this_player()->name()+"")) ) {\
\
                        }\
                }\
                if(moveint>0) {\
                	write(BS("Die Schlange laesst Deinen Fisch nicht los! "\
                        "Du musst sie erst toeten!"));\
                }\
                if(moveint==0) {\
                        write("\nDu steuerst Deinen Fisch Westen.\n\n");\
                        this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
                        "auf einem Fisch nach Westen", "schwimmt", \
                        "schwimmt auf einem Fisch herein"); \
                }\
                moveint=0;\
         return 1;}\
\
         if( !present("wasserschlange", environment(this_player())) ) {\
               write("\nDu steuerst Deinen Fisch nach Westen.\n\n");\
               this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
               "auf einem Fisch nach Westen", "schwimmt", \
               "schwimmt auf einem Fisch herein"); \
         return 1;} \
    return 1;}\
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("insekt")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Westen", "schwirrt", \
          "schwirrt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(this_player()->QueryProp("vogel")==1)) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Westen", "fliegt", \
          "fliegt herein"); \
         return 1;} \
\
     if((!interactive(this_player()))&&(!this_player()->QueryProp("insekt"))&& \
       (!this_player()->QueryProp("vogel"))) { \
      this_player()->move("/d/dschungel/trintrasil/fluss/room/x", M_GO, \
          "nach Westen", "schwimmt", \
          "schwimmt herein"); \
         return 1;} \
        return 0;}                    
