/*
 * This is my define file.  * created on 7/14/91
 */
#define add(x,y) add_action(x); add_verb(y)

#define exit(player, dir, dest) call_other(player, "move_player", dir+"#"+dest)

#define print(a, b) write(a); write(b)

#define writeln(a, b) print(a, b); write("\n")

#define tell tell_object
