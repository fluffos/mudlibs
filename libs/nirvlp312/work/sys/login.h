/*
 * login.h
 * Contains all available login locations
 */
#ifndef _sys_login_h
#define _sys_login_h

// Add login-locations here, but..
// IMPORTANT!!! Talk to the archwizards before doing that.
//              Every area that has enough services may become a
//              login-location. But we don't want login-locations
//              shooting up like mushrooms.

// The keys are the objects which are allowed to set the player's
// login-location to the values.

// Example: obj/leo is authorized to do a set_login_location-call
//          in the player. The login-location then is set to
//          room/church.

// Note: Add the new login-location also to /doc/helpdir/login

#define LOGIN_LOCATIONS ([ "obj/leo" : "room/church" ])

// There are some lfuns that can be defined by the login-locations,
// here follows a brief description:
// All functions are optional, if a login-point doesn't define them,
// the values of the default-login-location are used
//
// string query_ghost_location(); return wehre dead players shall arrive
// string query_guild_location(); return the program-name of the guild
// string query_shop_location(); same for the shop
// string query_post_direction();
//   This is the string which informs a login on player about arrival of mail.
//   Example for the village:
//   string query_post_direction() {
//     return "in the post office (south of ...)";
//   )
//   The messsage is prefixed by "There's <mail> for you", and
//   <mail> will be substituted wither by 'mail' or by 'NEW mail'.

// Setup the default-login-location.
#define DEFAULT_LOGIN_LOCATION "room/church"

#endif // _sys_login_h
