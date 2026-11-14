/*
	This file's purpose is to linewrap overly long lines.
	Do not clone or load it, just include it in your files.
	This was designed to make chatlines like guild lines, wizlines,
	and all other communication lines much nicer to the
	eyes.
	Please comment all changes to this file and if you would
	like a copy, just mail Longshot of Sandpit, I will probably
	allow you to use it.
	Longshot 8/8/93
*/

#define SCREEN_WIDTH 78
#define lw(x) sprintf("%-=*s", SCREEN_WIDTH, x)
#define writelw(x) printf("%-=*s", SCREEN_WIDTH,x)
