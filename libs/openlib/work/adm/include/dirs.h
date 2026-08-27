// file: dirs.h
#ifndef _DIRS_H
#define _DIRS_H

// MAIN directories
#define SECURE_DIR   "/adm"
#define CMD_DIR      "/cmd"
#define DOMAIN_DIR   "/d"
#define DATA_DIR     "/data"
#define DOC_DIR      "/doc"
#define PUB_DIR      "/ftp/pub"
#define FTP_DIR      "/ftp"
#define INCLUDE_DIR  "/include"
#define LOG_DIR      "/log"
#define OBJECT_DIR   "/obj"
#define CLONE_DIR    OBJECT_DIR "/clone"
#define DAEMON_DIR   OBJECT_DIR "/daemon"
#define INHERIT_DIR  OBJECT_DIR "/inherit"
#define MODULE_DIR   INHERIT_DIR "/modules"
#define TMP_DIR      "/tmp"
#define USER_DIR     "/u"
#define SAVE_DIR     DATA_DIR

// SECONDARY directories
#define CONFIG_DIR         SECURE_DIR "/etc"
#define SECURE_CMD_DIR     SECURE_DIR CMD_DIR
#define SECURE_DATA_DIR    SECURE_DIR DATA_DIR
#define SECURE_CLONE_DIR   SECURE_DIR CLONE_DIR
#define SECURE_DAEMON_DIR  SECURE_DIR DAEMON_DIR
#define SECURE_INHERIT_DIR SECURE_DIR INHERIT_DIR
#define SECURE_MODULE_DIR  SECURE_DIR MODULE_DIR
#define SECURE_TMP_DIR     SECURE_DIR TMP_DIR
#define SECURE_SAVE_DIR    SECURE_DIR SAVE_DIR

#endif /* _DIRS_H */
