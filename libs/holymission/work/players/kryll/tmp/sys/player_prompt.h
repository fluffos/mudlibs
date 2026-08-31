#ifndef __PLAYER_PROMPT_H__

#define __PLAYER_PROMPT_H__

// Prototypes:

int c_prompt(string str);
int *conf_prompt();
varargs mixed query_prompt(int flag, int num);

// End prototypes.


// Global variables:

int    *prompt;             // how do we like the prompt?

// End global variables.

#endif // __PLAYER_PROMPT_H__
