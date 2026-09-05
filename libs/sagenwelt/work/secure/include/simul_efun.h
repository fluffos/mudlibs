/// @addtogroup sefun
/// @{
/// @file simul_efun.h
/// @brief simul_efun specific macros and function declaratios
/// @author Gwenhwyvar
/// @version 0.1.0
/// @date 2016-01-24

#ifndef __SEC_SIMUL_EFUN_H
#define  __SEC_SIMUL_EFUN_H

#include "pragmas.h"        // setting standard pragmas
#include "syslog.h"         // needed for logging
#include <message.h>        // needed for communication (archive said messages.h)

// preprocessor macros for sefuns
#define SEC_PWD_OK      0   // return code of sefun::check_pwd (all tests passed)
// error codes of sefun::check_pwd (bitfield[int])
#define SEC_PWD_SHORT   1
#define SEC_PWD_LOWER   2
#define SEC_PWD_UPPER   4
#define SEC_PWD_NUMBER  8
#define SEC_PWD_OTHER  16

// message digests supported by sefun::crypt
// depending on compiletime settings for openssl some might be not available
#define PWD_CRYPT_MD2       "md2"
#define PWD_CRYPT_MD4       "md4"
#define PWD_CRYPT_MD5       "md5"
#define PWD_CRYPT_MDC2      "mdc2"
#define PWD_CRYPT_RIPEMD160 "ripemd160"
#define PWD_CRYPT_SHA1      "sha1"
#define PWD_CRYPT_SHA224    "sha224"
#define PWD_CRYPT_SHA256    "sha256"
#define PWD_CRYPT_SHA384    "sha384"
#define PWD_CRYPT_SHA512    "sha512"

// function prototypes (ordered by groups)
// simul_efun_helper
public          void     done_startup(void);
// array
public          mixed   *distinct_array(mixed *arr);
public          mixed   *scramble_array(mixed *arr);
public varargs  mapping  unique_mapping(mixed *arr, mixed sep, mixed skip);
// communication
public          void     printf(string format, mixed *args...);
public          void     say(string msg, mixed *exclude, int msg_class = MSGCLASS_SYSTEM);
public          void     shout(string msg, int msg_class = MSGCLASS_SYSTEM);
public          void     tell_object(object ob, string msg, int msg_class = MSGCLASS_SYSTEM);
public          void     tell_room(mixed ob, string msg, object *exclude, int msg_class = MSGCLASS_SYSTEM);
public          void     write(string msg, int msg_class = MSGCLASS_SYSTEM);
// driver
public varargs  mixed    debug_info(int req, mixed *args...);
public          int      exec(object to, object from);
public          void     reset_eval_cost(void);
public          void     set_eval_limit(int limit);
public          void     shutdown(int ret, string msg);
// file_system
public          string   basename(string path);
public          string   canonical_path(string path);
public          string   dirname(string path);
public          string   get_cwd(object who);
// general
public          int      cmp(mixed a, mixed b);
public          int      get_debug(void);
public          int      set_debug(int val);
// logging
public varargs  void     syslog(int priority, string format, mixed *args...);
public varargs  void     m_syslog(string uid, string gid, int priority, string format, mixed *args...);
// math
public          int      fib(int n);
public          int      gcd(int a, int b);
public          int      lcm(int a, int b);
// objects
public          string   author_of(string file);
public          string   domain_of(string file);
public varargs  void     destruct(object ob);
public          string   file_name(object who = 0, int flag = 0);
public varargs  int      move_object(object ob1, object ob2);
public          object   simul_efun(void);
// passwd
public          int      check_valid_pwd(string pwd);
public          string   crypt(string pwd, string salt = "", string hash = PWD_CRYPT_DFLT);
public          string   oldcrypt(string pwd, mixed salt);
// regex_globbing
public          int      fnmatch(string name, string pattern);
public          string  *glob(mixed pathname);
public          string   gsub(string s, string pat, string repl);
public          int      has_magic(string s);
public          string   insensitive_pattern(string pat = "");
public          string  *insensitive_regexp(string* arr, string pat, int flag = 0);
public          string   reg_pat_translate(string pat, int flag = 0);
public          string  *regexplode(string str, string pat);
public          int      rsearch(string s, string pat);
public          int      search(string s, string pat);
public          string  *split(string str, string pattern);
public          string   sub(string s, string pat, string repl);
// room
public          string   opposite_dir(string str, int article = 0);
// security
public          int      init_eids(void);
public          string   getgid(mixed who);
public          string   getegid(mixed who);
public          string   setegid(string egid);
public          string   getuid(mixed who);
public          string   getugid(mixed who);
public          string   seteuid(string euid);
public          int      cred_cmp(object cred1, object cred2);

public          int      archp(object ob);
public          int      creatorp(object ob);
public          int      Dcreatorp(object ob, string domain = "@any@");
public          int      Dlordp(object ob, string domain = "@any@");
public          int      elder(object ob);
public          int      playerp(object ob);

public          int      check_pwd(string pwd);
// strings
public          int      atoi(string arg);
public          string   itoa(int arg);
public          string   add_article(string text, int flag = 0);
public          string   i_wrap(string text, int width = DFLT_SCR_WIDTH, int indent = DFLT_SCR_INDENT);
public          void     more(mixed arg, int height = DFLT_SCR_HEIGHT, string input = "");
public          string   remove_article(string text);
// terminal
public          string   blink(string str);
public          string   bold(string str);
public          string   clear_line(void);
public          string   clear_screen(int flag = 0);
public          string   erase_line(void);
public          string   inverse(string str);
public          string   normal(void);
public          string   set_bg_color(int color = COL_BLACK, int bright = 0);
public          string   set_fg_color(int color = COL_WHITE, int bright = 0);
public          string   underscore(string str);
public          string   up_line(void);
#endif // __SEC_SIMUL_EFUN_H
/// @}
