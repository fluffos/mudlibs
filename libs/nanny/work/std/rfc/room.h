#ifndef STD_ROOM_H
#define STD_ROOM_H

/* Generic macros */
#define LIBCALL(FUN,ARG) ("@/std/rfc/roomlib->FUN("+(ARG)+")")
#define LINEBREAK(X) LIBCALL(do_linebreak,X)

/* Has yet to be documented */
#define HTML(X) ("/std/rfc/roomlib"->powerpre(X))

/* Arguments to add_command and add_item_cmd */
#define CMD_MOVETO(Y,X) LIBCALL(cmd_moveto,Y+"#"+expand_file_name(X))
#define CMD_TELEPORT(W) CMD_MOVETO("X",W)
#define CMD_MSG(X) (X)
#define CMD_FIND(X) LIBCALL(item_find,expand_file_name(X))

/* Arguments to add_item */
#define ITEM_FIND(X,DESC) LIBCALL(item_find,expand_file_name(X)+"\b"+(DESC))
#define ITEM_LINEBRAK(X) LINEBRAK(X)
#define ITEM_HTML(X) HTML(X)

/* Arguments for set_long */
#define LONG_LINEBRAK(X) LINEBRAK(X)
#define LONG_HTML(X) HTML(X)

/* Arguments to add_exit */
#define BLOCK_IF_PRESENT(X) LIBCALL(block_if_present,X)
#define BLOCK_WITH_MSG(X) LIBCALL(null,X)
#define RANDOM_EXIT(X) LIBCALL(random_file,X)

/* Macros simplifying the use of the above macros */
#define ADD_HIDDEN_EXIT(X,Y) add_command(X,CMD_MOVETO(X,Y))
#define REMOVE_HIDDEN_EXIT(X) remove_command(X)

/* Not finished */
#if 0
#define ITEM_OBJECT(X,Y) add_item_cmd(({"take","get",(X),LIBCALL(get_item,Y)})
#define ADD_SMELL()
#define ADD_LISTEN()
#endif

#endif
