/* 
   @A == adverb
   @P == player to which 
   @S == query_possessive() // his/her/its/your
   @O == query_objective()  // him/her/it/your
   @R == query_pronoun()    // he/she/it/you
   $  == add "s" to feeling
   $$ == add "es" to feeling
   &  == continue on what is before
   |  == forget about what is before
   <>verb:verb<> == eg cry:cries
*/

#define SFEELINGS ([\
"ack" 		: ({ 0, "~$@A&at@P", "" }),\
"applaud" 	: ({ 0, "~$@A&at@P", "" }),\
"agree"		: ({ 0, "~$@A&with@P", "" }),\
"beg"		: ({ 0, " put$ up@S hand, and~$@A for money|"+\
			" put$ up@S hand, and@A~$@P for money", "" }),\
"brighten"	: ({ 1, "'s face~$ up", "" }),\
"blush"		: ({ 0, "~$$@A&at@P", "" }),\
"bounce"	: ({ 0, "~$@A&around@P", "" }),\
"bow"		: ({ 0, "~$@A to@S audience|~$@A to@P", "" }),\
"burp"		: ({ 0, "~$@A&at@P", "" }),\
"cackle"	: ({ 0, "~$@A&at@P", "" }),\
"cheer"		: ({ 0, "~$@A&for@P", "" }),\
"chuckle"	: ({ 0, "~$@A&at@P", "" }),\
"clap"		: ({ 0, "~$@A&at@P", "" }),\
"comfort"	: ({ 2, "~$@P@A", "" }),\
"confused"	: ({ 0, "~$@A&at@P", "" }),\
"congratulate"	: ({ 2, "~$@P@A", "" }),\
"cough"		: ({ 0, "~$@A&at@P", "" }),\
"cry"		: ({ 0, "<>cry:cries<>@A&at@P", "" }),\
"cuddle"	: ({ 2, "~$@A with@P", ""  }),\
"curse"		: ({ 0, "~$ '@(*&^@'@A&at@P", "" }),\
"cringe"	: ({ 1, "~$ in terror", "" }),\
"curtsey"	: ({ 0, "~$@A&at@P", "" }),\
"dance"		: ({ 0, "~$@A with@S imaginary friend|"+\
			"~$@A with@P", "" }),\
"dream"		: ({ 0, " stare$ at the sky, dreaming of@S own island|"+\
			"~$@A of@P", "" }),\
"die"		: ({ 1, "~$ acting dead", "" }),\
"duh"		: ({ 1, " go$$ duh", "" }),\
"eyebrow"	: ({ 0, "@A raise$ an eyebrow&at@P", "" }),\
"eeks"		: ({ 1, " go$$ EEEKKS!!!!!", "" }),\
"excuse"	: ({ 0, "~$@Oself&to@P", "" }),\
"fart"		: ({ 0, "~$@A&at@P", "" }),\
"flea"          : ({ 2, "@A search$$ for fleas on@P", "" }),\
"flip"		: ({ 1, "~$ head over heels", "" }),\
"fondle"	: ({ 2, "~$@P@A", "" }),\
"french"	: ({ 2, " give$@P a deep and passionate kiss..it seems "+\
			"to take forever...", "" }),\
"frown"		: ({ 0, "~$@A&at@P", "" }),\
"fume"		: ({ 0, "~$@A&at@P", "" }),\
"gasp"		: ({ 1, "~$@A in astonishment", "" }),\
"giggle"	: ({ 0, "~$@A&at@P", "" }),\
"glare"		: ({ 0, "~$@A at everyone in the room|~$@A at@P", "" }),\
"greet"		: ({ 0, "~$ everyone in the room@A| raise$@S hand in "+\
			"greeting to@P", "" }),\
"grin"		: ({ 0, "~$@A&at@P", "" }),\
"groan"		: ({ 0, "~$@A&at@P", "" }),\
"grope"		: ({ 2, "@A~$@P", "" }),\
"growl"		: ({ 0, "~$@A&at@P", "" }),\
"hiccup"	: ({ 1, "@A~$", "" }),\
"hug"		: ({ 2, "~$@P@A", "" }),\
"hop"		: ({ 0, "@A~$ around&@P", "" }),\
"kick"		: ({ 2, "~$@P@A", "" }),\
"kiss"		: ({ 2, "~$$@P@A", "" }),\
"laugh"		: ({ 0, "~$@A&at@P", "" }),\
"lick"		: ({ 0, "~$@Oself clean|@A~$@P all over", "" }),\
"love"		: ({ 2, " whisper$ sweet words of love to@P", "" }),\
"moan"		: ({ 0, "~$@A&at@P", "" }),\
"mount"		: ({ 2, "~$@P and ride$ off into the sunset", "" }),\
"nibble"	: ({ 2, "~$@A on@P's ear", "" }),\
"no"		: ({ 0, " shake$@S head 'no'&at@P", "" }),\
"nod"		: ({ 0, "~$@A&at@P", "" }),\
"nuzzle"	: ({ 2, "@A~$@P neck", "" }),\
"smile"		: ({ 0, "~$@A&at@P", "" }),\
])
/*
"oops"		:,
"panic"		:,
"point"		:,
"ponder"	:,
"poke"		:,
"pout"		:,
"puke"		:,
"purr"		:,
"ruffle"	:,
"rolleyes"	:,
"scream"	:,
"scratch"	:,
"shake"		:,
"shiver"	:,
"shrug"		:,
"sigh"		:,
"sing"		:,
"slap"		:,
"smirk"		:,
"snap"		:,
"sneeze"	:,
"snicker"	:,
"sniff"		:,
"snore"		:,
"snuggle"	:,
"spit"		:,
"squeeze"	:,
"stare"		:,
"strut"		:,
"sulk"		:,
"steam"		:,
"stomp"		:,
"stretch"	:,
"tap"		:,
"tongue"	:,
"thank"		:,
"twiddle"	:,
"tickle"	:,
"think"		:,
"wave"		:,
"whistle"	:,
"wiggle"	:,
"wink"		:,
"worship"	:,
"yawn"		:,
"yodel"		;,
*/	
