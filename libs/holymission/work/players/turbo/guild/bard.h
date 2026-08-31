nosave object att;

#define GUILD "/players/turbo/guild/"
#define BIN "/players/turbo/guild/bin/"
#define DOC "/players/turbo/guild/docs/"
#define LOG "/players/turbo/guild/log/"
#define NEW "/players/turbo/guild/new/"
#define OBJ "/players/turbo/guild/obj/"
#define ROOM "/players/turbo/guild/rooms/"
#define SONG "/players/turbo/guild/songs/"
#define SPELL "/players/turbo/guild/spells/"
#define SUMMON "/players/turbo/guild/summon/"
#define ORB "/players/turbo/guild/summon/_orb.lpc"

#define GM "/guild/master"
#define CD "/sys/chatd"

#define CHK_ATT();\
if ( ( att = this_player()->query_attack() ) && present( att, environment( this_player() ) ) ) {\
write( "You are too preoccupied...\n" );\
say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + " performance.\n" );\
return ( 1 );\
}

#define CHK_LVL( x );\
if( this_player()->query_level() < x ) {\
write( "You are much too inexperienced for that!\n" );\
say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + " performance.\n" );\
return ( 1 );\
}

#define CHK_SP( x );\
if( this_player()->query_spell_points() < x ) {\
write( "You are too tired...\n" );\
say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + " performance.\n" );\
return ( 1 );\
}

#define CHK_GHOST();\
if( this_player()->query_ghost() ) {\
write( "That just is not possible...\n" );\
say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + " performance.\n" );\
return ( 1 );\
}
