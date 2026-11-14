#ifndef _MAZE_H_
#define _MAZE_H_

#define MIN_EVAL 40000

#define IDX_NAME        0
#define IDX_SIZEY       1
#define IDX_SIZEX       2
#define IDX_CONNECTS    3

// minimum number of parameters in mazeconfig structure 
#define MIN_NR_OF_PARAMS    3

#define NAME     mconf[IDX_NAME]
#define SIZEY    mconf[IDX_SIZEY]
#define SIZEX    mconf[IDX_SIZEX]
#define CONNECTS mconf[IDX_CONNECTS]

// directions
#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

// maze chars
#define ROOM 0
#define WALL 1

// return codes from build_random_maze()
#define SUCCESS 0
#define ERR_PARAM 1
#define ERR_XSIZE 2
#define ERR_YSIZE 3
#define ERR_EVAL  4
#define ERR_PROC  5

#endif // _MAZE_H_
