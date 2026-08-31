#define PATH    		"/players/shadowmonk/area2/"
#define MAINROOM		"/players/shadowmonk/area2/main"

#define TP      		this_player()
#define TO      		this_object()

#define NAME    		query_name()
#define RNAME   		query_real_name()

#define LEVEL   		query_level()

#define FP      		find_player

#define CAP			capitalize
#define QOB			query_objective()

#define ENV			environment

#define CM(x)   		move_object(clone_object(x),this_object())
#define TELLME(x) 		tell_object( find_player( "shadowmonk" ), "Error: " + x + ".\n" )

#define SCREEN_WIDTH 		78
#define lw(x)        		sprintf("%-=*s",SCREEN_WIDTH,x)
#define lwnl(x)      		sprintf("%-=*s\n",SCREEN_WIDTH,x)
#define writelw(x)   		printf("%-=*s",SCREEN_WIDTH,x)
#define writelwnl(x) 		printf("%-=*s\n",SCREEN_WIDTH,x)

#define TTP(x)			printf("%-=*s\n",SCREEN_WIDTH,x)
#define TOP(x,y)        	say(sprintf("%-=*s\n",SCREEN_WIDTH,x), y)  
#define TAL(x)                  tell_room(TO, sprintf("%-=*s\n",SCREEN_WIDTH,x))
#define T_OB    		tell_object

// for(i=0;i<sz;i++) tell_room(environment(), sprintf("%d %O\n",i,inv[i] ) );
