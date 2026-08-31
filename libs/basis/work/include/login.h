/*
   mudlib: Basis
   file: login.h
   created: 1992/07/24
   purpose: definitions for /adm/obj/login.c
*/

#ifndef _LOGIN_H
#define _LOGIN_H

#include "log.h"

#define LOG_ENTER     /* define this to log entries/exits into/from game. */
#define ALLOW_COPIES /* allow duplicate wizard logins */

// define TIMEOUT to be zero (0) if you want to allow indefinite amount of time
// for people to login (not really a good idea).
#define TIMEOUT          240   /* 4 minutes */
#define MAX_NAME_LEN      12   /* maximum length of a character name */
#define MAX_LOGIN_TRIES    3   /* max login attemps before disconnect */

#define NEW_USER      "/adm/obj/new_user"
#define WELCOME_FILE    "/adm/news/welcome"
#define NEWS_FILE       "/adm/news/news"
#define SCHEDULE_FILE   "/adm/news/schedule"
#define NEW_USER_FILE   "/adm/news/new_user"
#define MOTD_DIR        "/adm/motd/"
#define LOCKED_MSG_FILE "/adm/news/locked"
#define NEW_PLAYER_NEWS "/adm/news/new_player"

#define no(x) (lower_case(x) == "n")
#define yes(x) (lower_case(x) == "y")

#ifdef LOG_ENTER
#define log_enter(message) log(ENTER, message)
#else
#define log_enter(message) 1
#endif

#define MSG_TIMED_OUT \
	"\nSorry, you took too long to login.\n"
#define MSG_BAD_NEW_PLAYER \
	"Unable to connect to the new player object.\n"
#define MSG_TRY_AGAIN \
	"Sorry, please try again.\n"
#define MSG_BAD_RECONNECT \
	"Unable to reconnect to your netdead login.\n"
#define MSG_IS_DUPLICATE \
        "Your other login is still active.\n"
#define MSG_ALLOWING_DUPLICATE \
	"Allowing login.\n"
#define MSG_BAD_PASSWORD \
	"Sorry, incorrect password.\n"
#define MSG_DEST_COPY \
	"Switching interactives--destructing this copy.\n"
#define MSG_BAD_NEW_PLAYER_OBJ \
	"Unable to switch to new player object.\n"

#define NAME_PROMPT "Login: "
#define NEW_NAME_PROMPT "Please enter your name: "
#define PASSWORD_PROMPT "Password: "
#define DIS_COPY_PROMPT "Disconnect your other copy? (y or n): "

#endif
