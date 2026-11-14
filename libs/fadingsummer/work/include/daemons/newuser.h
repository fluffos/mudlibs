// mudlib: Fading Summer
// file:   newuser.h
// Museum: mud_name() never shipped; added PASS_NOMATCH; crypt needs salt.

#ifndef _H_newuser_d_
#define _H_newuser_d_

#define NEWUSER_PASS_MINLENGTH         5

#define NEWUSER_GREETING \
"Welcome to Lore of the Fading Summer, " +\
capitalize((string) user_ob->query("name")) + ".\n" +\
"Please take the time to answer the following questions so that we can create your character.\n\n"

#define NEWUSER_PASS_PROMPT \
"Please enter your passkey.  We recommend that you choose something that is not easy to guess.\n" +\
"Minimum passkey length is " + sprintf("%d", NEWUSER_PASS_MINLENGTH) + " characters.\n" +\
"Passkey: "

#define NEWUSER_PASS_CONFIRM \
"Please enter your passkey one more time for confirmation.\n" +\
"Passkey: "

#define NEWUSER_EMAIL_PROMPT \
"Please enter your email address.  Only the administration will be able to view it.\n" +\
"Email address: "

#define NEWUSER_NAME_PROMPT \
"Please enter your real name.  Only the administration will be able to view it.\n" +\
"Real name: "

#define NEWUSER_INVALID_PASS  "You must enter a passkey!\n"
#define NEWUSER_SHORT_PASS    "That passkey is too short.\n"
#define NEWUSER_PASS_NOMATCH  "Those passkeys do not match. Try again.\n"

#define NEWUSER_GET_PASS               0
#define NEWUSER_CONFIRM_PASS           1
#define NEWUSER_GET_EMAIL              2
#define NEWUSER_GET_NAME               3

#endif
