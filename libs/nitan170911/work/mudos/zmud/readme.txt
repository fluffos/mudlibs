Welcome to zMUD!

RELEASE NOTES for v4.62
=======================

This version contains support for the MUD Sound Protocol.
One important difference is the support for a folder/directory hierarchy for your
settings, maps, and sounds.  In fact, this hierarchy is required for MSP to work properly.
If you select the FILES tab in the character database, you will see a new field for
entering the Folder to contain your setting files for a character.  For new connections,
this folder name defaults to the title of the MUD (same name as the settings file).
When you enter a value into this field, all of your settings and maps will be properly
moved into the new directory structure, and a SOUNDS folder for MSP will be created.
Here is the directory structure:

zMUD Root Directory (eg C:\ZMUD)
  MEDIEVIA
    SOUNDS	<- MSP sounds go here.
    MAPS	<- zone .MAP files go here
    medievia.mud	<- main settings file
    medievia.zzz	<- master map file
  MIRKWOOD
    SOUNDS
    MAPS
    mirkwood.mud
    mirkwood.zzz
etc.

You can still keep everything in the main zmud directory if you want, but it will get
quickly cluttered with maps, sounds, settings, etc.  
Hope you like the new directory structure.  Just remember to move stuff around by
entering a value into the Folder field in the FILE tab of the character database.
A blank folder tells zmud to put everything in the main zmud directory.  Don't try to
move the files manually and create a different directory structure, or zmud might get
very confused.



Happy MUDding!

Zugg (9-Jun-97)

zugg@zuggsoft.com
http://www.zuggsoft.com/zmud