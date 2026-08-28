#define TJ(x) if(find_player("jhary")) tell_object(find_player("jhary"),\
 "DEBUG: "+x+"\n")
#define DNPC(x) ("/wizards/jhary/npc/"+x)
#define DROOM(x) ("/wizards/jhary/room/"+x)
#define HOME(x) ("/wizards/jhary/"+x)

#define DEBUG(x)  write_file(HOME("bugs.log"),\
     file_name()[<50..<0]+sprintf(":%s\n %s TI:%O TP:%O\n",ctime(time()),x,TI,TP))

#define ENV(x)  environment(x)
#define TP      this_player()
#define TO      this_object()
#define TI      this_interactive()
#define PO      previous_object()

#define ALTITUDE  5           /* ALLTITUDE    = max. Y */
#define WIDTH 64              /* WIDTH-1      = max. X */
#define DEPTH  64             /* DEPTH-1      = max. Y */

     
 
