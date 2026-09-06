/*
** puzzle.c
**
** (C) Tron.
**
** - Get the numbers in order :)
**
*/


private mixed *arr;
private object call_ob;
private string call_fun;
private mixed moves;

status
id(string str) { return (str=="puzzle" || str=="game"); }

void
set_trigger_fun(object ob, string fun) {

  call_ob = ob;
  call_fun= fun;
}

private mixed
get_mvnum(int *blank) {

   switch(blank[1]) {
     case 0: if(blank[0] == 0) return ({ ({0, 1}), ({1, 0}) });
             if(blank[0] == 1) return ({ ({0, 0}), ({2, 0}), ({1, 1}) });
             if(blank[0] == 2) return ({ ({1, 0}), ({2, 1}) });
             break;
     case 1: if(blank[0] == 0) return ({ ({0, 0}), ({0, 2}), ({1, 1}) });
             if(blank[0] == 1) return ({ ({0, 1}), ({1, 0}), ({2, 1}), 
                                         ({1, 2}) });
             if(blank[0] == 2) return ({ ({1, 1}), ({2, 0}), ({2, 2}) });
             break;
     case 2: if(blank[0] == 0) return ({ ({0, 1}), ({1, 2}) });
             if(blank[0] == 1) return ({ ({0, 2}), ({2, 2}), ({1, 1}) });
             if(blank[0] == 2) return ({ ({2, 1}), ({1, 2}) });
             break;
     }
 return 0;
}

private void
shuffle() {
int i, a, b;
int mv;
int *blank;
int *tmp;
mixed mvnum;

 arr = ({ ({1, 2, 3}), ({4, 5, 6}), ({7, 8, 0}) });
 blank = ({2, 2});

 mv = random(50) + 25;
 while(mv--) {
   mvnum = get_mvnum(blank);     
   i = random(sizeof(mvnum));
   tmp = blank;
   blank = mvnum[i];
   arr[tmp[1]][tmp[0]] = arr[blank[1]][blank[0]];
   arr[blank[1]][blank[0]] = 0;
 }  
}

private void
print_board() {

int i, j;
mixed a;
string str;

 write("_______\n");
 for(i=0; i<3; i++) {
   write("|"); 
   for(j=0; j<3; j++) {
       if(a=arr[i][j]) str=a;
       else str = " "; 
       write(str+((j==2)?"":" "));
      }
    write("|\n");
  }
            
 write("-------\n");
}

private int *
fnd_xy(int i) {

int y;
int x;

   for(y=0; y < 3; y++) 
      if((x=member(arr[y], i))!=-1)
          return ({x, y});

return 0;
}

private int *
can_move(int *xy) {

int x, y;
int *tmp;
int i, a;

 if(!xy) return 0;

 x = xy[0]; y = xy[1];
 tmp=fnd_xy(0);
  
 for(i=0; i<3; i++) {
    a = y - 1 + i;
    if(a==tmp[1]) {
      if(y == tmp[1]) {
         if(x-1 == tmp[0])
              return ({x-1, a});
         if(x+1 == tmp[0])
              return ({x+1, a});
        }
        else if(x == tmp[0]) return ({x, a});
     }
   }

 return 0;
}

private status
board_ready() {

int i, j;
int count;

    for(i=0; i<3; i++) {
       for(j=0; j<3; j++) {
          count++;
          if(arr[i][j] == count) continue;
          else if(!arr[i][j] && count==9)
                  return 1;
          else break;
         }
      }
return 0;
}

string
short() {
 return "A puzzle game";
}

void
long() {

  write("The board looks like this:\n\n");
  print_board();
  write("\nYou could move the numbers to the empty slot.\n");
}
           
void
create() {

  shuffle();
}

void
init() {

 add_action("move", "move");
}

status
move(string str) {

int a;
int *tmp;
int *xy;

   if(!str) return 0;
   if(!sscanf(str, "%d",a)) return 0;

   if(a < 1 || a > 8) {
      write("There is no such number on the board.\n");
      return 1;
     }
   if(!(tmp=can_move(xy=fnd_xy(a)))) {
      write("You can't move that number.\n");
      return 1;
      }
   arr[tmp[1]][tmp[0]] = a;
   arr[xy[1]][xy[0]] = 0;
    
   print_board();
   moves++;

   if(!arr[2][2]) 
      if(board_ready()) {
         if(call_ob) call_other(call_ob, call_fun, 0);
         else
         write("You solve the puzzle with "+moves+" moves.\n");
         shuffle();
        }
     
return 1;
}
