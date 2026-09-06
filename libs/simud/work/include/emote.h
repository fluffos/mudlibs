#define EMOTE_COLOR "~CEMO"

#define ATT_PHYSICAL   0x0001   // soul is physical, actually touches the target
#define ATT_VISUAL   0x0002   // soul is noticed visually
#define ATT_AUDIBLE   0x0004   // soul is heard
#define ATT_NICE   0x0008   // soul is generally pleasant/gentle
#define ATT_MEAN   0x0010   // soul is generally harsh/rough
#define ATT_HUMBLE   0x0020   // soul is lowering the actor
#define ATT_PROUD   0x0040   // soul is elevating the actor
#define ATT_YES      0x0080   // soul can be understood as an affirmative response
#define ATT_NO      0x0100   // soul can be understood as a negative response
#define ATT_FOOLISH   0x0200   // soul is silly...

#define EMOTE_ATTRIBUTE( bitmask ) \
int query_emote_attribute() { \
   return ( bitmask ); \
}

#define EMOTE( cself, ctarget ) \
main( param ) {\
   object *tlist, t, victim;\
   int attribute;\
   string doing, self, target;\
   if( param ) {\
      if( param == "all" ) { \
         foreach( t : all_inventory(environment(this_player())) ) \
         if( t != this_player() && t->query_is_player() ) { \
            set_target( t ); \
            if( sscanf(ctarget, "%s@@%s", target, doing) == 2 ) \
               this_player()->set_doing( doing, t ); \
            else target = ctarget; \
            if (this_player()->query_toad()) \
               msg(EMOTE_COLOR+target+"~CDEF"); \
            else \
               this_player()->msg_local(EMOTE_COLOR+target+"~CDEF"); \
         } \
      } \
      else { \
         tlist = all_present(param, environment(this_player())); \
         if( !tlist ) tlist = all_present(param, this_player()); \
         if( !tlist ) { notify_fail("Nothing here that matches '"+param+"'.\n"); return 0; } \
         foreach( t : tlist ) { \
            set_target(t);\
            if( sscanf(ctarget, "%s@@%s", target, doing) == 2 ) \
               this_player()->set_doing( doing, t ); \
            else target = ctarget; \
            if (this_player()->query_toad()) \
               msg(EMOTE_COLOR+target+"~CDEF"); \
            else \
               this_player()->msg_local(EMOTE_COLOR+target+"~CDEF"); \
            victim = t; \
         } \
      }\
   }\
   else {\
      if( sscanf(cself, "%s@@%s", self, doing) == 2 ) \
         this_player()->set_doing( doing ); \
      else \
         self = cself; \
      if (this_player()->query_toad()) \
         msg(EMOTE_COLOR+self+"~CDEF");\
      else \
         this_player()->msg_local(EMOTE_COLOR+self+"~CDEF");\
   }\
   if( attribute = this_object()->query_emote_attribute() ) \
      foreach( t : all_inventory(environment(this_player())) ) \
         if( t->query_is_living() && t != this_player() ) \
            t->on_soul( attribute, victim, this_player(), query_verb() ); \
   return 1;\
}\
\
string query_cself() { return cself; } \
string query_ctarget() { return ctarget; }
