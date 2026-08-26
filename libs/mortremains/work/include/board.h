// board.h
//
// Contributor: Zak and Inspiral
//
// Useful macros for accessing a player's board props.

#ifndef BOARD_H
#define BOARD_H

#define SET_CUR(x)      this_player()->set_temp("board/"+board_set, \
                            messages[x]["id"])
#define SET_CURID(x)	this_player()->set_temp("board/"+board_set, x)
#define SET_NEWID(x)	this_player()->set("board/"+board_set, x)
#define QUERY_CUR	(int)this_player()->query_temp("board/"+board_set)
#define SET_NEW(x)      this_player()->set("board/"+board_set, \
                            messages[x]["id"])
#define QUERY_NEW	(int)this_player()->query("board/"+board_set)

#endif
