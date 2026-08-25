.TH add_enter L
.SH NAME
add_enter() \- adds to an enter style exit to a room
.SH SYNOPSIS
inherit "/std/room"
.PP
varargs void add_enter(dir, dest, pre_fun, post_fun);
.PP
string dir
.br 
string dest
.br 
function pre_fun
.br 
function post_fun
.SH DESCRIPTION
Use add_enter() to add an exit to a room where the motion leaving the
room is motion into another object, as opposed to motion towards
another object, for which you use add_exit().
.PP
The first two arguments are mandatory.  The first argument, dir,
specifies the thing into which the player is moving.  For example, if
the player is entering a pub, they would naturally type "enter pub".
In this case, "pub" would be the dir argument.
.PP
The second argument, dest, is the file name of the room into which the
player will be moved.
.PP
The third argument (optional) is a function pointer to a function that
determines whether the player can actually use that exit.  If you do
not use this argument, it is assumed all players can use the exit as
they wish.  If you specify this argument, then when a player tries to
use the exit, the function will get called before the player is moved.
If your function returns 1, the player will be allowed to use the
exit.  If your function returns 0, the player will stay in the room.
.PP
The fourth argument (optional) is a function pointer to a function
that gets called after the player has left the room.  If you specify
this argument, you must also specify a third argument (which can be
0).  If you do not specify this argument, the player just gets moved
to the new room and all processing ends.  On the other hand, if the
fourth argument is specified, your function will get called once the
player is in the new room.
.SH SEE ALSO
add_exit() set_enters() set_exits() remove_enter() remove_exits()
.SH AUTHOR
Descartes of Borg
