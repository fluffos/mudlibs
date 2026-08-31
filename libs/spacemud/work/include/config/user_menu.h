/* Do not remove the headers from this file! see /USAGE for more info. */

// Automatically generated file, do not edit by hand. Use admtool.
#ifndef __USER_MENU_H__
#define __USER_MENU_H__

// Use an MMO like user menu, where users can create many characters under the the same user.
// Default: yes
// Type: boolean
#define USE_USER_MENU

// Max number of characters allowed per user. If you want only one, set USE_USER_MENU=no.
// Default: 10
// Range: 2-20
// Type: integer
#define MAX_CHARACTERS_PER_USER 10

// If the user idles in the menu without selecting a character, log them in after X seconds.
// Default: 10
// Range: 10-60
// Type: integer
#define AUTO_LOGIN_AFTER 10

// Kick idle users out from the menu after X seconds.
// Default: 300
// Range: 60-600
// Type: integer
#define USER_MENU_TIMEOUT 300

#endif /* __USER_MENU_H__ */
