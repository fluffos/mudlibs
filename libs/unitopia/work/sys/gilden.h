// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/gilden.h
// Description:	Defines fuer Gilden
// Author:	Francis
//
// $Log: gilden.h,v $
// Revision 1.4  2002/12/12 00:32:52  gnomi
// ORIG_*-Defines zur Abfrage unter Nutzung von real_gender.
//
// Revision 1.3  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef GILDEN_H
#define GILDEN_H 1

#define GILDEN_OB "/room/rathaus/gilden"

#define ENTRY(x) (GILDEN_OB->query_gilden_info(object_name(),x))

#define GILDEN_AUTH_NAME "gilden"

// Gildenflags
#define GLP_FLAG		0
#define GLP_NAME		1
#define GLP_SIZE		2

#define GLF_TEST		1
#define GLF_CONSTRUCTION	2

/*
 * Die Indices des Gilden-Mappings
 */
#define GILDEN_NAME		"g_n"
#define GILDEN_GESCHLECHT       "gg"
#define KUERZEL			"g_k"
#define GILDEN_MEISTER		"gm"
// #define GILDEN_MASTER_OB	"Gilden_Master_Ob"
#define PROGRAMMIERER		"gp"
#define VALID_CALLER		"v_c"
#define AUTO_LOADER		"al"
#define MITGLIED		"g_m"
#define FILE_NAME		"f_n"
#define STATUS			"stat"
#define REASON			"reas"
#define RAENGE			"g_r"
#define MAENNLICH		"m"
#define MAENNLICH_PLURAL	"m_p"
#define WEIBLICH		"w"
#define WEIBLICH_PLURAL		"w_p"
#define SAECHLICH		"s"
#define SAECHLICH_PLURAL	"s_p"
#define GILDEN_BRETTER          "g_b"
#define GILDEN_FINGER           "g_f"
#define GILDEN_TOD              "gt"

/*
 * Anfragen an query_gilden_info
 */
//      GILDEN_NAME
//      KUERZEL
//      GILDEN_MEISTER
//      GILDEN_MASTER_OB
//	VALID_CALLER
//      FILE_NAME
//      STATUS
//      REASON
//      AUTO_LOADER
//      MITGLIED
#define RANG_NAME		"rg_n"
#define MITGLIED_PLURAL		"mg_p"
#define RANG			"rg"
#define RANG_PLURAL		"rg_p"

// Abfragen unter Nutzung von real_gender
#define ORIG_RANG		"o_rg"
#define ORIG_RANG_PLURAL	"o_rg_p"
#define ORIG_MITGLIED		"o_mg"
#define ORIG_MITGLIED_PLURAL	"o_mg_p"

/*
 * Status einer Gilde
 */
#define OK			 0
#define NOT_ACTIVE		-1
#define NOT_LOADABLE		-2
#define INVALID_ENTRY		-3
#define TEST			-4

/*
 * Return-Codes von set_rang()
 */
//      OK
#define INVALID_CALLER		-5
#define NO_GUILD		-6
#define OTHER_GUILD		-7


/*
 * Return-Codes von enter_gilde()
 */
//      OK
//      INVALID_CALLER
//      OTHER_GUILD
#define ALREADY_MEMBER		-8

/*
 * Return-Codes von leave_gilde()
 */
//      OK
//      INVALID_CALLER
//      NO_GUILD
//      OTHER_GUILD

#endif // GILDEN_H
