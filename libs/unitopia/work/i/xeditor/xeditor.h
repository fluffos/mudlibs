// This file is part of Avalon Mudlib.
// Copyright 1996-99 by Avatar@Avalon. All rights reserved.
// ----------------------------------------------------------------
// File:        /i/xeditor//xeditor.h
// Description: #defines fuer den xEd
// Author:      Avatar
// Modified:
//
// $Log: xeditor.h,v $
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#define EDITOR_VERSION             "1.3"

#ifdef AVALON_MUDLIB
#   define EDITOR_SHADOW              "/obj/editor_shadow"
#   define EDITOR_KEYRC               "/etc/editor/.keyrc"
#   define EDITOR_TEMPLATE_DIR        "/etc/editor/templates/"
#else
#   ifdef UNITOPIA_MUDLIB
#      define EDITOR_SHADOW              "/obj/editor_shadow"
#      define EDITOR_KEYRC               "/nosave/editor/.keyrc"
#      define EDITOR_TEMPLATE_DIR        "/nosave/editor/templates/"
#   else
#      define EDITOR_SHADOW              "/p/avatar/obj/editor_shadow"
#      define EDITOR_KEYRC               "/p/avatar/etc/.keyrc"
#      define EDITOR_TEMPLATE_DIR        "/p/avatar/etc/templates/"
#   endif
#endif

#define EDITOR_MAX_FILE_SIZE 150000


#define DEFAULT_MAX_X       80
#define DEFAULT_MAX_Y       23
#define DEFAULT_SPLIT_Y      0
#define DEFAULT_TAB_WIDTH    3

#define EDITOR_MODE_FILE     0
#define EDITOR_MODE_BUFFER   1

#define EDITOR_INPUT_TO_FLAGS   (INPUT_NOECHO|INPUT_CHARMODE|INPUT_IGNORE_BANG)

                             // Default
#define KEY_NOTHING       0  //
#define KEY_DOWN         -1  // CrsDown
#define KEY_UP           -2  // CrsUp
#define KEY_LEFT         -3  // CrsLeft
#define KEY_RIGHT        -4  // CrsRight
#define KEY_BACKSPACE    -5  // Space
#define KEY_DELETE       -6  // Delete
#define KEY_INSERT       -7  // Insert
#define KEY_SCR_DOWN     -8  // ScrDown und ^V
#define KEY_SCR_UP       -9  // ScrUp und ^U
#define KEY_HOME         -10 // ^A
#define KEY_END          -11 // ^E
#define KEY_FIRSTLINE    -12 // ^KU
#define KEY_LASTLINE     -13 // ^KV
#define KEY_DELETE_LINE  -14 // ^Y
#define KEY_GOTO_LINE    -15 // ^G
#define KEY_NEXT_WORD    -16 // ^W
#define KEY_LAST_WORD    -17 // ^Q
#define KEY_END_EDITOR   -21 // ^C und ^KX
#define KEY_SAVE         -22 // ^DS
#define KEY_LOAD         -23 // ^DL
#define KEY_MERGE        -24 // ^DE
#define KEY_M_TEMPLATE   -25 // ^DT
#define KEY_BLOCK_BEGIN  -30 // ^KB
#define KEY_BLOCK_END    -31 // ^KE und ^KK
#define KEY_BLOCK_DELETE -32 // ^KD
#define KEY_BLOCK_COPY   -33 // ^KC
#define KEY_BLOCK_MOVE   -34 // ^KM
#define KEY_BLOCK_LEFT   -35 // ^KL
#define KEY_BLOCK_RIGHT  -36 // ^KR
#define KEY_BLOCK_UNMARK -37 // ^KJ
#define KEY_BLOCK_SAVE   -38 // ^KS
#define KEY_HELP         -40 // ^O
#define KEY_REFRESH      -41 // ^R
#define KEY_FIND         -50 // ^F
#define KEY_FIND_NEXT    -51 // ^N
#define KEY_FIND_LAST    -52 // ^B
#define KEY_FIND_QUICK   -53 // ^X

#define ANSWER_YES 1
#define ANSWER_NO  2

