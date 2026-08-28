#ifndef MESSAGE_H
#define MESSAGE_H

#define PREV previous_object()

/* message definations for object */

#define o_line(x)         message (0, x + "\n", THOB)
#define o_error(x)        message (1, "\aError: ^cy" + x + "^c0\n", THOB)
#define o_fatal(x)        message (2, "\aFatal: ^cR" + x + "^c0\n", THOB)
#define o_room(x)         message (3, x + "\n", ENV(THOB), THOB)
#define o_prompt(x)       message (4, x + "\n", THOB);
#define o_you(x)          message (5, "You " + x + "\n", THOB);
#define o_your(x)         message (6, "Your " + x + "\n", THOB);
#define o_hear(x)         message (7, "You hear " + x + "\n", THOB);
#define o_feel(x)         message (8, "You feel " + x + "\n", THOB);

/* message definations for current user */

#define u_line(x)         message (0, x + "\n", THIS)
#define u_error(x)        message (1, "\aError: ^cy" + x + "^c0\n", THIS)
#define u_fatal(x)        message (2, "\aFatal: ^cR" + x + "^c0\n", THIS)
#define u_room(x)         message (3, x + "\n", ENV(THIS), THIS)
#define u_prompt(x)       message (4, x, THIS);
#define u_you(x)          message (5, "You " + x + "\n", THIS);
#define u_your(x)         message (6, "Your " + x + "\n", THIS);
#define u_hear(x)         message (7, "You hear " + x + "\n", THIS);
#define u_feel(x)         message (8, "You feel " + x + "\n", THIS);

/* message definations for previous object */

#define p_line(x)         message (0, x + "\n", PREV)
#define p_error(x)        message (1, "\aError: ^cy" + x + "^c0\n", PREV)
#define p_fatal(x)        message (2, "\aFatal: ^cR" + x + "^c0\n", PREV)
#define p_room(x,y)       message (3, x + "\n", y ? ENV(PREV), PREV : ENV(PREV))
#define p_prompt(x)       message (4, x, PREV);
#define p_you(x)          message (5, "You " + x + "\n", PREV);
#define p_your(x)         message (6, "Your " + x + "\n", PREV);
#define p_hear(x)         message (7, "You hear " + x + "\n", PREV);
#define p_feel(x)         message (8, "You feel " + x + "\n", PREV);

/* misc message definations */

#define tell(x,y,z)       message (9, z, x + "\n", z ? z : 0);

#endif /* MESSAGE_H */
