#ifndef __spell__
#define __spell__

// ----- the various spell-kinds
#define AGGRESSIVE        1
#define NON_AGGRESSIVE    2
#define NO_COMBAT         3

#define KIND_STRING \
        ({ "undef", "aggressive", "non-aggressive", "not in combat" })

// ----- save versus shat
#define FIRE              1
#define ELECTRICITY       2
#define COLD              3
#define ACID              4
#define ENERGY            5
#define DRAIN             6
#define TOUCH             7
#define PETRIFICATION     8
#define POISON            9
#define BREATH            10
#define DEATHMAGIC        11
#define MAGIC             12
#define MINDEFFECTIVE     13
#define ILLUSION          14
#define SUMMONING         15        // incl. conjuration
#define NO_SAVE           16        // this one MUST be the last !

#define MAX_NO_OF_SAVE    16      // save with the highest number !!!


#define SAVE_VS_STRING \
        ({"undef","fire","electricity","cold","acid","energy","drain","touch",\
          "petrification","poison","breath","deathmagic","magic",\
          "mindeffective","illusion","summoning","none"})

// ----- time to release -----
#define INSTANT           -1
#define NEXT_HB            0

// ----- saving-results ------
#define IMMUNE             -1
#define SAVE_FAILED         0
#define SAVED               1


// ----- misc - defines

#ifndef TP
#define TP this_player()
#endif //TP
#ifndef TPPOS
#define TPPOS evaluate(call,TP,"query_possessive")
#endif
#ifndef TPNT
#define TPNT evaluate(call,TP,"query_name_true")
#endif
#ifndef TPL
#define TPL evaluate(call,TP,"query_level")
#endif
#ifndef TPRN
#define TPRN evaluate(call,TP,"query_real_name")
#endif
#ifndef TPN
#define TPN evaluate(call,TP,"query_name")
#endif
#ifndef TPPRO
#define TPPRO evaluate(call,TP,"query_pronoun")
#endif
#ifndef TPOBJ
#define TPOBJ evaluate(call,TP,"query_objective")
#endif

#ifndef SHOWDAM
#define SHOWDAM(O,D);\
   if(TPRN=="llort" || TPRN=="patience") {\
       write("  __..++'' "+O+" --> "+D+" ''++..__\n");\
   }
#endif

#define WINFO(x) if(TP->query_immortal()) write("WizInfo: "+x+"\n") 

#endif //__spell__
