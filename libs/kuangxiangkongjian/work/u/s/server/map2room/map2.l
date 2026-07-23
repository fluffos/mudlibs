
 
%{
/* Make: lex map.l , gcc -o map lex.yy.c */
/* direction
  8 1 2
  7   3
  6 5 4

  ex: 1: north
*/
char *dirmap[10]=
{
  "north","northeast","east","southeast","south","southwest","west",
  "northwest","up","down"
};
/* #include "map.h" */
#include <stdio.h>
/* #include "../str.h" */
char prefix[80];
struct path_struct
{
  int x;
  int y;
  int data;
};
typedef struct path_struct PATH;
struct room_struct
{
  int nameid;
  int x;
  int y;
  int data;
  int exits[11];
};
typedef struct room_struct ROOM;

ROOM *allroom;
PATH *allpath;

#define PATH_19 100
#define PATH_28 200
#define PATH_37 300
#define PATH_46 400

#define ROOM_NOR 1000

int my=1;
int mx=1;
int paths=0;
int rooms=0;

#define yywrap() 1

int StorePath(int x,int y,int path);
int StoreRoom(int x,int y,int room);
%}

letters [A-Za-z]

%%

\n    {my++; mx=1;}
\r    {};
\t    {printf("Never use tab(\t) in map!!! \n\r"); exit(3); }
-     {StorePath(mx,my, PATH_46); mx++;}
\/     {StorePath(mx,my, PATH_19); mx++;}
\\     {StorePath(mx,my, PATH_37); mx++;}
\|     {StorePath(mx,my, PATH_28); mx++;}
\+     {StoreRoom(mx,my, ROOM_NOR); mx++;}
{letters}  {StoreRoom(mx,my, (int)*yytext); mx++;}
" "   { mx++;}
.   { printf("Map analysis get a bad char %c at %d(char) %d(line) \n\r"
                  ,*yytext,mx,my); exit(6); }

%%

void main(int argc,int **argv)
{
  if (argc >1)
  {
    yyin=(FILE *)fopen( (char *) argv[1], "r");
    if ( yyin == NULL)
    {
      printf("Can't open this file %s \n\r",argv[1]);
      exit(0);
    };
  }
  else
  {
    printf("Usage: amap <map_filename> \n\r");
    exit(0);
  };
  allpath=calloc(sizeof(PATH),1000);
  allroom=calloc(sizeof(ROOM),1000);
  printf("Please input area name:");
  gets(prefix);
  printf("\n");
  yylex();
  RoomCollect();
  RoomOutput();
  printf("The map %s has %d rooms and %d paths \n\r",argv[1],rooms,paths);
  exit(1);
};

int StorePath(int x,int y,int path)
{
  allpath[paths].x=x;
  allpath[paths].y=y;
  allpath[paths].data=path;
  paths++;
/*  printf("Path %d in x:%d y:%d is %d\n\r",paths,x,y,path); */
  if ( ((x % 2)!=0) && ((y % 2)!=0) )
  {
    printf("Error path! x:%d y:%d \n\r",x,y);
    exit(8); 
  };
};
int StoreRoom(int x,int y,int room)
{
  allroom[rooms].x=x;
  allroom[rooms].y=y;
  allroom[rooms].data=room;
  rooms++;
/*  printf("Room %d in x:%d y:%d is %d\n\r",rooms,x,y,room); */
  if ( ((x % 2)==0) || ((y % 2)==0) )
  {
    printf("Error room! x:%d y:%d \n\r",x,y);
    exit(8); 
  };  
};

int Path1(int x,int y,int data,int *xo,int *yo)
{
  switch (data)
  {
    case PATH_19:
      *xo=x-1;
      *yo=y+1;
      break;
    case PATH_28:
      *xo=x;
      *yo=y+1;
      break;
    case PATH_37:
      *xo=x+1;
      *yo=y+1;
      break;
    case PATH_46:
      *xo=x-1;
      *yo=y;
      break;
  };
};
int Path2(int x,int y,int data,int *xo,int *yo)
{
  switch (data)
  {
    case PATH_19:
      *xo=x+1;
      *yo=y-1;
      break;
    case PATH_28:
      *xo=x;
      *yo=y-1;
      break;
    case PATH_37:
      *xo=x-1;
      *yo=y-1;
      break;
    case PATH_46:
      *xo=x+1;
      *yo=y;
      break;
  };
};

int RoomAdd(int r1,int dir,int r2)
{
  allroom[r1].exits[dir]=r2;
};

int RoomCollect()
{
  int i,j;
  int x1,y1,x2,y2,r1,r2;
  int check;

  for(i=0;i<paths;i++)
  {
    Path1(allpath[i].x, allpath[i].y, allpath[i].data, &x1, &y1);
    Path2(allpath[i].x, allpath[i].y, allpath[i].data, &x2, &y2);
    check=0;
    for(j=0;j<rooms;j++)
    {
      if ( (allroom[j].x == x1) && (allroom[j].y == y1) ) 
      {
        check++;
        r1 = j;
      };
      if ( (allroom[j].x == x2) && (allroom[j].y == y2) ) 
      {
        check++;
        r2 = j;
      };  
      if ( check == 2) break;    
    };
    if ( j==rooms)
    {
      printf("Warning! path %d x:%d y:%d no find room \n\r",i,
              allpath[i].x,allpath[i].y);
      continue;
    };
    switch (allpath[i].data)
    {
      case PATH_19:   /* north is 1 */
        RoomAdd(r1,2,r2+1);
        RoomAdd(r2,6,r1+1);
        break;
      case PATH_28:
        RoomAdd(r1,1,r2+1);
        RoomAdd(r2,5,r1+1);
        break;
      case PATH_37:
        RoomAdd(r1,8,r2+1);
        RoomAdd(r2,4,r1+1);
        break;
      case PATH_46:
        RoomAdd(r1,3,r2+1);
        RoomAdd(r2,7,r1+1);
        break;
    };
  };
};

int RoomOutput()
{
  int j,i;
  int pp;
  int count;
  for (j=0;j<rooms;j++)
  {
/*    printf("Room: %d ",j+1); */
/*    printf("setobj %s_%d_%d_%d : room = \n",prefix
               ,j+1,allroom[j].x,allroom[j].y);  */
   printf("setobj %s_%d_%d : room = \n",prefix
              ,allroom[j].x,allroom[j].y);  
    printf("exits : [");
    count=0;
    for (i=1;i<11;i++)
    {

      if (allroom[j].exits[i] != 0)
      {
/*        printf (" %d->%d ",i,allroom[j].exits[i]); */
/*        printf (" %s->%d ",dirmap[i-1],allroom[j].exits[i]);  */
        if (count!=0) 
        {
          printf(", ");
        };
          count++;
        pp=allroom[j].exits[i];
/*        printf (" %s : #%s_%d_%d_%d ",dirmap[i-1],prefix
             ,pp,allroom[pp-1].x,allroom[pp-1].y);   */
        printf (" %s : #%s_%d_%d ",dirmap[i-1],prefix
             ,allroom[pp-1].x,allroom[pp-1].y);   
        
      };

    };
    printf(" ] \n;\n");
  };
};
