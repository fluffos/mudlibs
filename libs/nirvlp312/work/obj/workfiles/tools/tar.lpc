/*
 * tar.c - LPC tar
 *
 * Copyright (C) 1997-1998 by Shasta@TUBMud <bus@fgan.de>
 * 
 * Released under the terms of the TUBmud copyright license
 */

// WARNING: REQUIRES THAT write_bytes() IS ABLE TO APPEND TO FILES!
// FIXME: Have a closer look at the privilege subsystem
// FIXME: Make sure no errors occur while executing job
// FIXME: Requires that remote machine's tar is able to create dirs on-the-fly
// ADD:   Filename globbing? -> There should be a generic shell-like glob
//        function somewhere

#pragma strong_types                  // Actually warnings are for wimps
#pragma combine_strings

#include <kernel.h>

inherit "complex/item";
inherit "basic/job";
inherit "basic/autoload";
inherit ACCESS;

#include <libs.h>
#include <is_wizard.h>
#include <message.h>
#include <limits.h>
#include <jobs.h>
#include <prop/item.h>

//
// Parameters for job
//
#define TAR_OWNER       "tar_owner"     // User of tar
#define TAR_VERBOSE     "tar_verbose"   // Verbose output?
#define TAR_BASEDIR     "tar_basedir"   // cwd of player at the time of exec
#define TAR_TARFILE     "tar_file"      // Tar file to operate with

// Used for extracting tar files
#define XTAR_FSIZE      "tar_fsize"     // Size of tar file (in blocks)
#define XTAR_FPOS       "tar_fpos"      // Current file position (blocks)
#define XTAR_FSPEC      "tar_fspec"     // List of RE to limit extraction

// Used for viewing tar archive
#define TTAR_FSIZE      "tar_fsize"     // Size of tar file (blks)
#define TTAR_FPOS       "tar_fpos"      // Current fp (blk)
#define TTAR_FSPEC      "tar_fspec"     // List of RE to limit extraction
